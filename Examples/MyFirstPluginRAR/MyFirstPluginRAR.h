//=============================================================================
// Project     : Plugin
// Version     : 0.1.0
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

#include "IPlug_include_in_plug_hdr.h"
#include "Interface.h"
#include "Params.h"

const int K_NUM_PRESETS = 1;

using namespace iplug;
using namespace igraphics;

class MyFirstPluginRAR final : public Plugin
{
public:
    explicit MyFirstPluginRAR (const InstanceInfo& info);

    auto getParam (Parameters parameter) -> IParam*;
    void ProcessBlock (sample** inputs, sample** outputs, int nFrames) override;
    void OnReset() override;
    void OnParamChange (int paramIdx) override;

private:
    void initParameters();
    void initGraphics();
    void cookVars();

    double gain;
    Interface mInterface;
};
