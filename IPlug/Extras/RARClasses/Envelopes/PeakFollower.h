//==================================================================================
// Project     : IPLUG2
// Version     : 1.0
//
// Category    : RARClasses
// Filename    : RARClasses/Envelopes/PeakFollower.h
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

#ifndef _PEAKFOLLOWER_H_
#define _PEAKFOLLOWER_H_

class PeakFollower {
public:
  PeakFollower ();
  ~PeakFollower ();
  double Process (double input, double sampleRate);
  double Process2 (double input, double sampleRate);
};
#endif // !_PEAKFOLLOWER_H_
