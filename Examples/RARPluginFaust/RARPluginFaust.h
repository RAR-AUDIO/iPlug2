#pragma once

#include "IPlug_include_in_plug_hdr.h"

#include "IPlugFaustGen.h"

#include "IControls.h"

#include "Interface.h"

#ifndef DSP_FILE
#define DSP_FILE ""
#endif



using namespace iplug;
using namespace igraphics;

class RARPluginFaust final : public Plugin
{
public:
    RARPluginFaust (const InstanceInfo& info);

    void ProcessBlock (sample** inputs, sample** outputs, int nFrames) override;
    void OnReset() override;
    void OnParamChange (int paramIdx) override;

    Interface mInterface;

private:
    FAUST_BLOCK (Faust1, mFaustProcessor, DSP_FILE, 1, 1);

    void initGraphics();
};
