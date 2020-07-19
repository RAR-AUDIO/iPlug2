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

#ifndef _RAR_ENVELOPES_PEAKFOLLOWER_H_
#define _RAR_ENVELOPES_PEAKFOLLOWER_H_

namespace RAR{
    namespace Envelopes{
        class PeakFollower{
        public:
            PeakFollower();
            ~PeakFollower();
            double Process(double input, double sampleRate);
            double Process2(double input, double sampleRate);
        };
    } //end namespace Envelopes
} //end namespace RAR
#endif // !_RAR_ENVELOPES_PEAKFOLLOWER_H_
