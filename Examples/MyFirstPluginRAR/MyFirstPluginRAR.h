//=============================================================================
// Project     : Plugin
// Version     : 0.0.1
//
// Category    : Main
// Filename    : Main/MyFirstPluginRAR.h
// Created by  : RAR-AUDIO, JUL/2020
// Author      : Roberto Ramirez
// Description : Plugin Parameters
//
//
//-----------------------------------------------------------------------------
// LICENSE
// (c) 2020, RAR-AUDIO, All Rights Reserved
//-----------------------------------------------------------------------------
//=============================================================================

#pragma once

#include "Interface.h"
#include "IPlug_include_in_plug_hdr.h"
#include "Params.h"

const int kNumPresets = 1;

using namespace iplug;
using namespace igraphics;

class MyFirstPluginRAR final : public Plugin {
public:
 explicit MyFirstPluginRAR(const InstanceInfo& info);

 IParam* GetParam(Parameters parameter);
 void ProcessBlock(sample** inputs, sample** outputs, int nFrames) override;
 void OnReset() override;
 void OnParamChange(int paramIdx) override;

private:
 void InitParameters();
 void InitGraphics();
 void cookVars();

 char* version_string_ = "0.0.1";
 double gain_;
 Interface m_interface_;
};
