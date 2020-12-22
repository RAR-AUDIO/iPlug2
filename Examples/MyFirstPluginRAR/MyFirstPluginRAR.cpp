// =============================================================================
//  Project     : MyFirstPluginRAR
//  Version     : 0.1.0
//
//  Category    : MyFirstPluginRAR-vst3
//  Filename    : MyFirstPluginRAR-vst3/MyFirstPluginRAR.cpp
//  Created by  : RAR-AUDIO, 11/2020
//  Author      : Roberto A. Ramirez Gonzalez
//  Description : Processor functions
//
//
// -----------------------------------------------------------------------------
//  LICENSE
//  (c) 2020, RAR-AUDIO, All Rights Reserved
// -----------------------------------------------------------------------------
// =============================================================================

#include "MyFirstPluginRAR.h"

#include "IControls.h"
#include "IPlug_include_in_plug_src.h"

void MyFirstPluginRAR::initParameters()
{
    GetParam (KGain)->InitDouble ("Gain",
                                  0.,
                                  0.,
                                  100.0,
                                  0.01,
                                  "%");
}

void MyFirstPluginRAR::initGraphics()
{
    mMakeGraphicsFunc = [&]() {
        return MakeGraphics (*this,
                             PLUG_WIDTH,
                             PLUG_HEIGHT,
                             PLUG_FPS,
                             GetScaleForScreen (PLUG_HEIGHT, PLUG_HEIGHT));
    };
    mLayoutFunc = [&] (IGraphics* pGraphics) {
        mInterface.createControls (pGraphics);
    };
}

MyFirstPluginRAR::MyFirstPluginRAR (const InstanceInfo& info)
    : Plugin (info, MakeConfig (KNumParameters, K_NUM_PRESETS)),
      gain (0),
      mInterface (this)
{
    initParameters();
    initGraphics();
}

void MyFirstPluginRAR::ProcessBlock (sample** inputs,
                                     sample** outputs,
                                     const int nFrames)
{
    const int nChans = NOutChansConnected();

    for (auto s = 0; s < nFrames; s++)
    {
        for (auto c = 0; c < nChans; c++)
        {
            outputs[c][s] = inputs[c][s] * gain;
        }
    }
}

void MyFirstPluginRAR::OnReset()
{
}

void MyFirstPluginRAR::OnParamChange (int paramIdx)
{
    switch (paramIdx)
    {
        case KGain:
            gain = GetParam (KGain)->Value() / 100.;
            break;
        default:
            break;
    }
}
