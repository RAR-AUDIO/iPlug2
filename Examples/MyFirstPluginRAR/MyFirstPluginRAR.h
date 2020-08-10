//=============================================================================
// Project     : Plugin
// Version     : 0.0.1
//
// Category    : Main
// Filename    : Main/MyFirstPluginRAR.h
// Created by  : RAR-AUDIO, JUL/2020
// Author      : Roberto Ramirez
// Description : Plugin Paramaters
//
//
//-----------------------------------------------------------------------------
// LICENSE
// (c) 2020, RAR-AUDIO, All Rights Reserved
//-----------------------------------------------------------------------------
//=============================================================================

#pragma once

#include "IPlug_include_in_plug_hdr.h"
#include "Interface.h"
#include "Params.h"

const int kNumPresets = 1;

using namespace iplug;
using namespace igraphics;

class MyFirstPluginRAR final : public Plugin {
 public:
  MyFirstPluginRAR(const InstanceInfo& info);

  IParam* GetParam(Parameters parameter);
  void ProcessBlock(sample** inputs, sample** outputs, int nFrames) override;
  void OnReset() override;
  void OnParamChange(int paramIdx) override;

 private:
  void InitParameters();
  void InitGraphics();
  void cookVars();

  char* versionString = "0.0.1";
  double gain;
  Interface mInterface;
  // CParamSmooth* mWidthSmoother; //OLD Smoother
};
