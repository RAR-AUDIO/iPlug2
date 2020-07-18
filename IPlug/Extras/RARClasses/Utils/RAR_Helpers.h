//==================================================================================
// Project     : IPlug
// Version     : 1.0
//
// Category    : Utils
// Filename    : RARHelpers.h
// Created by  : RAR-AUDIO, JUL/2020
// Author      : Roberto Ramirez
// Description : Helpers for RAR-AUDIO Plugins
//
//---------------------------------------------------------------------------------
// LICENSE
// (c) 2020, RAR-AUDIO LLC, All Rights Reserved
//---------------------------------------------------------------------------------
//=================================================================================

#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>
#include <string>

namespace RAR{
    namespace Utils{
        //CONVERSION
        static const double PI = 3.1415926535897932384626433832795;

        /** @brief Magic number for gain to dB conversion.
         * Approximates \f$ 20*log_{10}(x) \f$
         * @see AmpToDB
        */
        static const double AMP_DB = 8.685889638065036553;

        /** @brief Magic number for dB to gain conversion.
         * Approximates \f$ 10^{\frac{x}{20}} \f$
         * @see DBToAmp
        */
        static const double IAMP_DB = 0.11512925464970;

        //Decibel(db) - Linear Conversion
        /** @brief Calculates gain from a given dB value
         * @param dB Value in dB
         * @ return Gain calculated as an approximation of
         * \f$ 10^{\frac{x}{20}} \f$
         * @see #IAMP_DB
        */

        static inline double DBToAmp(double db){
            return exp(IAMP_DB * db);
        }

        static inline double AmpToDB(double amp){
            return AMP_DB * log(std::fabs(amp));
        }

        //DSP
        // tanh
        inline double fast_tanh(double x){
            x = exp(x + x);
            return (x - 1) / (x + 1);
        }

        inline double vox_fasttanh2(const double x){
            const double ax = fabs(x);
            const double x2 = x * x;

            return(x * (2.45550750702956 + 2.45550750702956 * ax +
                (0.893229853513558 + 0.821226666969744 * ax) * x2) /
                (2.44506634652299 + (2.44506634652299 + x2) *
                    fabs(x + 0.814642734961073 * x * ax)));
        }
    }
}