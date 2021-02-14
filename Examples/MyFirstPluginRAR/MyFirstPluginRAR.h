#pragma once

#include "IPlug_include_in_plug_hdr.h"

const int K_NUM_PRESETS = 1;

enum EParams
{
    KGain = 0,
    KNumParams
};

class PLUG_CLASS_NAME final : public iplug::Plugin
{
public:
    PLUG_CLASS_NAME (const iplug::InstanceInfo& info);

#if IPLUG_DSP // http://bit.ly/2S64BDd
    virtual void ProcessBlock (iplug::sample** inputs, iplug::sample** outputs, int nFrames) override;
    virtual void OnReset () override;
    virtual void OnParamChange (int paramIdx) override;
    virtual void OnIdle () override;
#endif

private:
    double gain;
};
