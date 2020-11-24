// =============================================================================
//  Project     : MyFirstPluginRAR-vst3
//  Version     : 0.1.0
//
//  Category    : Main
//  Filename    : Main/MyFirstPluginRAR.h
//  Created by  : RAR-AUDIO, 11/2020
//  Author      : Roberto A. Ramirez Gonzalez
//  Description : Plugin Parameters
//
//
// -----------------------------------------------------------------------------
//  LICENSE
//  (c) 2020, RAR-AUDIO, All Rights Reserved
// -----------------------------------------------------------------------------
// =============================================================================

#pragma once

#include "IPlug_include_in_plug_hdr.h"
#include "Interface.h"
#include "Params.h" // Parameters

const int K_NUM_PRESETS = 1;

using namespace iplug;
using namespace igraphics;

class MyFirstPluginRAR final : public Plugin
{
public:
    MyFirstPluginRAR (const InstanceInfo& info);

    IParam* getParam (Parameters parameter);

    void ProcessBlock (sample** inputs, sample** outputs, int nFrames) override;

    void OnReset() override;
    void OnParamChange (int paramIdx) override;

    Interface mInterface;

private:
    void initParameters();
    void initGraphics();
    void cookVars();

    double gain;
};
