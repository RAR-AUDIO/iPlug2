// =============================================================================
//  Project     : MyFirstPluginRAR
//  Version     : 0.1.0
//
//  Category    : MyFirstPluginRAR-vst3
//  Filename    : MyFirstPluginRAR-vst3/MyFirstPluginRAR.h
//  Created by  : RAR-AUDIO, 02/2021
//  Author      : Roberto A. Ramirez Gonzalez
//  Description :
//
//
// -----------------------------------------------------------------------------
//  LICENSE
//  (c) 2021, RAR-AUDIO, All Rights Reserved
// -----------------------------------------------------------------------------
// =============================================================================

#ifndef MYFIRSTPLUGINRAR_H
#define MYFIRSTPLUGINRAR_H

//==================================================================================
/* iPlug Includes */
#include "IPlug_include_in_plug_hdr.h"
//==================================================================================

const int K_NUM_PRESETS = 1;

enum EParams
{
    KGain = 0,
    KNumParams
};

using namespace iplug;
using namespace igraphics;

class PLUG_CLASS_NAME final : public Plugin
{
public:
    PLUG_CLASS_NAME (const InstanceInfo& info);

#if IPLUG_DSP // http://bit.ly/2S64BDd
    void ProcessBlock (sample** inputs, sample** outputs, int nFrames) override;
    void OnReset() override;
    void OnIdle() override;
#endif

private:
};

#endif // MYFIRSTPLUGINRAR_H