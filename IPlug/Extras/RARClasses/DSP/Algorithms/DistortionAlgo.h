//==================================================================================
// Project     : IPlug
// Version     : 1.0
//
// Category    : DSP/Distortion
// Filename    : DSP/Algorithms/DistortionAlgo.h
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

#ifndef _RAR_DSP_DISTORTIONALGO_H_
#define _RAR_DSP_DISTORTIONALGO_H_

#pragma once
#include <cmath>

#define _USE_MATH_DEFINES
#include <math.h>

namespace RAR {
namespace DSP  // DSP Namespace for all DSP
{
namespace Distortion  // Distortion Algorithms for DSP
{
class Helpers {
 public:
  static double fastAtan(double x);
};

class StateFulDrive {
 public:
  double Process(double input, double amount);

 private:
  double previous = 0.0;
};

// TODO: Add new Saturation/Distortion Algorithm for analog style plugins

class Excite  // Soft asymmetrical clipping
{
 public:
  double Process(double input, double amount);

 private:
  double previous = 0.0;
};

class Fat  // inverse Tangent Waveshaper
{
 public:
  double Process(double input, double amount);

 private:
  double previous = 0.0;
};

// class SineShaper  // based on Jon Watte's Waveshaper algorith
//{
// public:
//    double Process (double input, double amount);

// private:
//    double previous = 0.0;
//};

class FoldBack  //  FoldBack Distortion by hellfire@upb.de from musicdsp.org
{
 public:
  double Process(double input, double amount);

 private:
  double previous = 0.0;
};

class Tanh  // Hyperbolic Tangent Waveshaper
{
 public:
  double Process(double input, double amout);

 private:
  double previous = 0.0;
};

// class Soft // Soft Saturation
//{
// public:
//    double Process (double input, double amount);

// private:
//    double previous = 0.0;
//};
}  // namespace Distortion
}  // namespace DSP
}  // namespace RAR
#endif  // !_RAR_DSP_DISTORTIONALGO_H_
