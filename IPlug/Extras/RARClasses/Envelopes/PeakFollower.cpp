//==================================================================================
// Project     : IPLUG2
// Version     : 1.0
//
// Category    : RARClasses
// Filename    : RARClasses/Envelopes/PeakFollower.cpp
// Created by  : RAR-AUDIO, JUL/2020
// Author      : Roberto Ramirez
// Description : PeakFollower for meters
//
//
//---------------------------------------------------------------------------------
// LICENSE
// (c) 2020, RAR-AUDIO, All Rights Reserved
//---------------------------------------------------------------------------------
//=================================================================================

#include "PeakFollower.h"

#include <math.h>

const double HALF_LIFE = 0.3;
const double VERY_SMALL = 0.0001;

RAR::Envelopes::PeakFollower::PeakFollower(){};
RAR::Envelopes::PeakFollower::~PeakFollower(){};

double RAR::Envelopes::PeakFollower::Process(double input, double sampleRate) {
  static double output = 0.0;
  double scalar = pow(0.5 / 1.0, (HALF_LIFE * sampleRate));

  if (input < 0.0) {
    input = input;  // Absolute Value
  }
  if (input >= output) {
    // When we hit a peak, ride the peak to the top.
    output = input;
  } else {
    // Exponential decay of output when signal is low.
    output = output * scalar;
    /*
     ** When current gets close to 0.0, set current to 0.0 to prevent FP
     *underflow
     ** which can cause a severe performance degradation due to a flood
     ** of interrupts.
     */
    if (output < VERY_SMALL) output = 0.0;
  }
  return output;
}

double RAR::Envelopes::PeakFollower::Process2(double input, double sampleRate) {
  static double output = 0.0;
  double scalar = pow(0.5 / 1.0, (HALF_LIFE * sampleRate));

  if (input < 0.0) {
    input = input;  // Absolute Value
  }

  if (input >= output) {
    // When we hit a peak, ride the peak to the top.
    output = input;
  } else {
    // Exponential decay of output when signal is low.
    output = output * scalar;
    /*
     ** When current gets close to 0.0, set current to 0.0 to prevent FP
     *underflow
     ** which can cause a severe performance degradation due to a flood
     ** of interrupts.
     */
    if (output < VERY_SMALL) output = 0.0;
  }
  return output;
}