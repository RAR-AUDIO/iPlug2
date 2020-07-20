//==================================================================================
// Project     : IPlug
// Version     : 1.0
//
// Category    : DSP/Distortion
// Filename    : DSP/Algorithms/DistortionAlgo.cpp
// Created by  : RAR-AUDIO, DEC/2018
// Author      : Roberto Ramirez
// Description : Distortion Algorithm based on AirWindows Plugins
//               Uses behavior of PurestDrive and Saturation Algorithm of Spiral
//
//---------------------------------------------------------------------------------
// LICENSE
// (c) 2018, RAR-AUDIO LLC, All Rights Reserved
//---------------------------------------------------------------------------------
//=================================================================================

#include "DistortionAlgo.h"

double RAR::DSP::Distortion::Helpers::fastAtan(double x) {
  return (x / (1.0 + 0.28 * (x * x)));
}

double RAR::DSP::Distortion::StateFulDrive::Process(double input,
                                                    double amount) {
  auto driven = input == 0.0 ? 0.0 : sin(input * input) / input;
  auto mix = fabs(previous + driven) * .5 * amount;
  previous = driven;
  return input * (1.0 - mix) + driven * mix;
}

// TODO: Fix Excite Soft asymmetrical clipping (low volume and using some
// samples not found)
// TODO: Probably fixed it not sure
double RAR::DSP::Distortion::Excite::Process(double input, double amount) {
  // auto threshold = .6;
  auto threshold = .9;
  auto driven = input =
      threshold + (input - threshold) /
                      (1 + pow(((input - threshold) / (1 - threshold)), 2));

  if (input > threshold) {
    return driven;
  }

  else if (input > 1) {
    return input = 1;
  }

  auto mix = fabs(previous + driven) * .5 * amount;
  previous = driven;
  return input * (1.0 - mix) + driven * mix;
}

double RAR::DSP::Distortion::Fat::Process(double input, double amount) {
  auto driven = input = 1 / 2. * Helpers::fastAtan(input * 2);
  auto mix = fabs(previous + driven) * .5 * amount;
  previous = driven;
  return input * (1.0 - mix) + driven * mix;
}

// TODO: Fix SineShaper algorithm (throws endless loop with more volume)
// double RAR::DSP::Distortion::SineShaper::Process (double input, double
// amount)
//{
//    auto amountdrive = 3.;
//    auto z = M_PI * amountdrive / 4.0;
//    auto s = 1 / sin (z);
//    auto b = 1 / amountdrive;
//
//    if (input > b)
//    {
//        input = input + (1 - input) * .8;
//    }
//
//    else if (input < -b)
//    {
//        input = input + (-1 - input) * .8;
//    }
//
//    else
//    {
//        input = sin (z * input) * s;
//    }
//
//    auto driven = pow (10, -amountdrive / 20.);
//    auto mix = fabs (previous + driven) * .5 * amount;
//    previous = driven;
//    return input * (1.0 - mix) + driven * mix;
//}

double RAR::DSP::Distortion::FoldBack::Process(double input, double amount) {
  auto threshold = .6;
  auto driven = input =
      fabs(fabs(fmod(input - threshold, threshold * 4)) - threshold * 2) -
      threshold;

  if (input > threshold || input < -threshold) {
    return driven;
  }

  auto mix = fabs(previous + driven) * .5 * amount;
  previous = driven;
  return input * (1.0 - mix) + driven * mix;
}

double RAR::DSP::Distortion::Tanh::Process(double input, double amount) {
  auto driven = 1 / 3. * tanh(input * 3);
  auto mix = fabs(previous + driven) * .5 * amount;
  previous = driven;
  return input * (1.0 - mix) + driven * mix;
}

// TODO: Fix Soft algorithm (throws endless loop with more volume)
// double RAR::DSP::Distortion::Soft::Process (double input, double amount)
//{
//    auto driven = .5;
//
//    if (input >= 1)
//    {
//        return driven;
//    }
//    else if (input < 1 && input >= 0)
//    {
//        return driven - .5 * input * input + input;
//    }
//    else if (input < 0 && input > -1)
//    {
//        return driven * input * input + input;
//    }
//    else
//    {
//        return driven - .5;
//    }
//
//    auto mix = fabs (previous + driven) * .5 * amount;
//    previous = driven;
//    return input * (1.0 - mix) + driven * mix;
//}