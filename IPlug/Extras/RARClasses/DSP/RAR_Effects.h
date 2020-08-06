//==================================================================================
// Project     : IPlug
// Version     : 1.0
//
// Category    : DSP
// Filename    : DSP/RAR_Effects.h
// Created by  : RAR-AUDIO, JUL/2020
// Author      : Roberto Ramirez
// Description : Effects algorithm (lofi, phaser, etc)
//
//---------------------------------------------------------------------------------
// LICENSE
// (c) 2020, RAR-AUDIO LLC, All Rights Reserved
//---------------------------------------------------------------------------------
//=================================================================================

#ifndef _RAR_DSP_EFFECTS_H_
#define _RAR_DSP_EFFECTS_H_

#pragma once

#include <cmath>
#include <functional>

#include "../Utils/RAR_Helpers.h"

namespace RAR {
namespace DSP {
class RAR_Lofi {
 public:
  // RAR_Lofi();
  //~RAR_Lofi();

  // RAR_Lofi(){};
  //~RAR_Lofi(){};

  double Process(double dt, double input, double speed);

 private:
  double phase = 0.0;
  double previous = 0.0;
  double current = 0.0;
};  // end of class

// INLINE PROCESSING FUNCTIONS
// ----------------------------------------------------------------------------

inline double RAR_Lofi::Process(double dt, double input, double speed) {
  phase += dt;
  while (phase >= speed) {
    phase -= speed;
    previous = current;
    current = input;
  }
  auto position = phase == 0.0 ? 0.0 : sin(phase * phase) / phase;
  return current + (previous - current) * position;
}
}  // namespace DSP
}  // namespace RAR
#endif  // !_RAR_DSP_EFFECTS_H_
