//==================================================================================
// Project     : IPlug
// Version     : 1.0
//
// Category    : DSP
// Filename    : DSP/RAR_Saturation.h
// Created by  : RAR-AUDIO, JUL/2020
// Author      : Roberto Ramirez
// Description : Saturation
//
//---------------------------------------------------------------------------------
// LICENSE
// (c) 2020, RAR-AUDIO LLC, All Rights Reserved
//---------------------------------------------------------------------------------
//=================================================================================

#pragma once

#include "../Utils/RAR_Helpers.h"
#include <functional>

namespace RAR{
  namespace DSP{
    class RAR_Saturation{
    public:
      // If type definitions of type int needed:
      enum class ESaturationType{
        kMusicDSP = 0,
        kZoelzer,
        kPirkle,
        kPirkleMod,
        kSoftSat,
        kRectHalf,
        kRectFull,
        kNumTypes
        // ...
      };

      RAR_Saturation()
        : mType(ESaturationType::kMusicDSP)
        , mDriveNormalized(1.0)
        , mAmountNormalized(0.0)
        , mHarmonicsNormalized(1.0)
        , mPositive(true)
        , mSkewNormalized(0.0)
        , mWetNormalized(1.0)
        , mSamplerate(44100.0)
        , mAmount(0.){}

      RAR_Saturation(
        RAR_Saturation::ESaturationType pType,
        double pDriveDb,
        double pAmountNormalized,
        double pHarmonicsNormalized,
        bool pPositiveSide,
        double pSkewNormalized,
        double pWet,
        double pSamplerate
      )
        : prev(0.0)
        , dry(0.0){
        SetSaturation(pType, pDriveDb, pAmountNormalized, pHarmonicsNormalized, pPositiveSide, pSkewNormalized, pWet, pSamplerate);
      }

      ~RAR_Saturation(){}

      void SetType(RAR_Saturation::ESaturationType pType){ mType = pType; calcSaturation(); }
      void SetDrive(double pDriveDb){ mDriveNormalized = RAR::Utils::DBToAmp(pDriveDb); }
      void SetAmount(double pAmountNormalized){ mAmountNormalized = pAmountNormalized; calcSaturation(); }
      void SetHarmonics(double pHarmonicsNormalized){ mHarmonicsNormalized = pHarmonicsNormalized; }
      void SetPositive(bool pPositive){ mPositive = pPositive; }
      void SetSkew(double pSkewNormalized){ mSkewNormalized = pSkewNormalized; calcSaturation(); }
      void SetWet(double pWetNormalized){ mWetNormalized = pWetNormalized; }
      void SetSamplerate(double pSamplerate){ mSamplerate = pSamplerate; }
      void SetSaturation(
        RAR_Saturation::ESaturationType pType,
        double pDriveDb,
        double pAmountNormalized,
        double pHarmonicsNormalized,
        bool pPositive,
        double pSkewNormalized,
        double pWetNormalized,
        double pSamplerate
      ){
        mType = pType;
        mDriveNormalized = RAR::Utils::DBToAmp(pDriveDb);
        mAmountNormalized = pAmountNormalized;
        mHarmonicsNormalized = pHarmonicsNormalized;
        mPositive = pPositive;
        mSkewNormalized = pSkewNormalized;
        mWetNormalized = pWetNormalized;
        mSamplerate = pSamplerate;
        calcSaturation();
      }

      double Process(double in);

    protected:
      double processMusicDSP(double in);
      double processZoelzer(double in);
      double processPirkle(double in);
      double processPirkleModified(double in);
      double processSoftSat(double in);
      double processRectHalf(double in);
      double processRectFull(double in);
      void calcSaturation(){
        switch (mType){
          case ESaturationType::kMusicDSP:
            mAmount = (1. - mAmountNormalized);
            break;
            //case kZoelzer:
            //  break;
          case ESaturationType::kPirkle:
          case ESaturationType::kPirkleMod:
            mAmount = pow(mAmountNormalized, 3.);
            break;
          case ESaturationType::kSoftSat:
            mAmount = 1. / mAmountNormalized;
            break;
            //case kRectHalf:
            //  break;
            //case kRectFull:
            //  break;
          default:
            mAmount = mAmountNormalized;
            break;
        }
        return;
      }

      RAR_Saturation::ESaturationType mType;
      double mDriveNormalized;
      double mAmountNormalized;
      double mAmount;
      double mHarmonicsNormalized;
      bool mPositive; // if aiming for even harmonics, the positive side of the envelope will be affected if true, otherwise the negative side
      double mSkewNormalized;
      double mWetNormalized;
      double mSamplerate;

      double prev;
      double dry;
    };
    // end of class

    // INLINE PROCESSING FUNCTIONS
    // ----------------------------------------------------------------------------

    inline double RAR_Saturation::Process(double in){
      // Don't process if amount is zero, also preventing dividing zeros
      if (mAmountNormalized == 0.0)
        return in;

      // apply drive
      in *= mDriveNormalized;

      // create driven dry samples
      dry = in;

      // call specific inline functions
      switch (mType){
        case ESaturationType::kMusicDSP: in = processMusicDSP(in); break;
        case ESaturationType::kZoelzer: in = processZoelzer(in); break;
        case ESaturationType::kPirkle: in = processPirkle(in); break;
        case ESaturationType::kPirkleMod: in = processPirkleModified(in); break;
        case ESaturationType::kSoftSat: in = processSoftSat(in); break;
        case ESaturationType::kRectHalf: in = processRectHalf(in); break;
        case ESaturationType::kRectFull: in = processRectFull(in); break;
        default: break;
      }

      prev = dry;

      if (!mPositive && in < 0.) in = in * mHarmonicsNormalized + dry * (1. - mHarmonicsNormalized);
      if (mPositive && in > 0.) in = in * mHarmonicsNormalized + dry * (1. - mHarmonicsNormalized);

      // Apply Dry/Wet
      if (mWetNormalized < 1.0)
        in = mWetNormalized * in + (1. - mWetNormalized) * dry;

      // return to old drive level
      in *= (1. / mDriveNormalized);

      return in;
    }

    inline double RAR_Saturation::processMusicDSP(double in){
      if (fabs(in) > mAmount){
        in = (in > 0.)
          ? (mAmount + (fabs(in) - mAmount) / (1. + pow((fabs(in) - mAmount) / (1. - mAmount), 2.))) * (in / fabs(in))
          : (mAmount + (fabs(in) - mAmount) / (1. + pow((fabs(in) - mAmount) / (1. - mAmount), 2.))) * (in / fabs(in));
      }

      // Soften by (1 - Amount)
      in = (1. - mAmount) * in + mAmount * dry;

      // Saturation Normalization
      in *= (1. / ((mAmount + 1.) / 2.));

      return in;
    }

    inline double RAR_Saturation::processZoelzer(double in){
      in = (in > 0.)
        ? 1. - exp(-in)
        : -1. + exp(in);
      return in;
    }

    inline double RAR_Saturation::processPirkle(double in){
      in = tanh(mAmount * in) / tanh(mAmount);
      return in;
    }

    inline double RAR_Saturation::processPirkleModified(double in){
      const double a = mAmount * (1. + (in - prev) * (1. / mDriveNormalized) * mSkewNormalized);
      in = tanh(a * in) / tanh(a);
      return in;
    }

    inline double RAR_Saturation::processSoftSat(double in){
      in = (in > 1.)
        ? mAmount * (1. - mAmount / (in + (mAmount - 1.))) + 1.
        : (in < -1.)
        ? -mAmount * (1. + mAmount / (in - (mAmount - 1.))) - 1.
        : in;
      return in;
    }

    inline double RAR_Saturation::processRectHalf(double in){
      in = (in < 0.) ? 0. : in;
      return in;
    }

    inline double RAR_Saturation::processRectFull(double in){
      in = fabs(in);
      return in;
    }
  } //end namespace DSP
} //end namespace RAR