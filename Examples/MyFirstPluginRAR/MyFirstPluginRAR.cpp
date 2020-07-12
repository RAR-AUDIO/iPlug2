//==================================================================================
// Project     : Plugin
// Version     : 0.0.1
//
// Category    : Main
// Filename    : Main/MyFirstPluginRAR.cpp
// Created by  : RAR-AUDIO, JUL/2020
// Author      : Roberto Ramirez
// Description : Plugin Paramaters
//               
//
//---------------------------------------------------------------------------------
// LICENSE
// (c) 2020, RAR-AUDIO, All Rights Reserved
//---------------------------------------------------------------------------------
//=================================================================================

#include "MyFirstPluginRAR.h"
#include "IPlug_include_in_plug_src.h"
#include "IControls.h"


MyFirstPluginRAR::MyFirstPluginRAR (const InstanceInfo& info)
  : Plugin (info, MakeConfig (kNumParams, kNumPresets)), mInterface (this) {

  GetParam (kGain)->InitDouble ("Gain", 0., 0., 100.0, 0.01, "%");

  mMakeGraphicsFunc = [&]() {
    return MakeGraphics (*this, PLUG_WIDTH, PLUG_HEIGHT, PLUG_FPS, GetScaleForScreen (PLUG_HEIGHT));
  };

  mLayoutFunc = [&](IGraphics* pGraphics) {
    mInterface.CreateControls (pGraphics);
  };

}

void MyFirstPluginRAR::ProcessBlock (sample** inputs, sample** outputs, int nFrames) {
  const double gain = GetParam (kGain)->Value () / 100.;
  const int nChans = NOutChansConnected ();

  for (int s = 0; s < nFrames; s++) {
    for (int c = 0; c < nChans; c++) {
      outputs[c][s] = inputs[c][s] * gain;
    }
  }
}

//void MyFirstPluginRAR::OnReset () {}

//void MyFirstPluginRAR::OnParamChange (int paramIdx, EParamSource, int sampleOffset) {}
