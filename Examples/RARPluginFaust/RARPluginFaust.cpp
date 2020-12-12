#include "RARPluginFaust.h"
#include "IPlug_include_in_plug_src.h"

RARPluginFaust::RARPluginFaust (const InstanceInfo& info)
    : Plugin (info, MakeConfig (KNumParameters, K_NUM_PRESETS)),
      mInterface { this }
{
    GetParam (KCutoff)->InitFrequency ("Cutoff", 20000, 100, 20000, 1.0);
    GetParam (KResonance)->InitDouble ("Resonance", 1.0, 1.0, 8.0, 0.1);
    GetParam (KDrive)->InitDouble ("Drive", 3.0, -10.0, 10.0, 0.1);
    GetParam (KSaturation)->InitDouble ("Saturation", 0.0, 0.0, 1.0, 0.1);
    GetParam (KCurve)->InitDouble ("Curve", 1.0, 0.1, 4.0, 0.1);
    GetParam (KFeedback)->InitGain ("Feedback", -60, -60, -24);
    GetParam (KLevel)->InitGain ("Level", -12, -24, 24);

    //InitParamRange (0, K_NUM_PARAMS - 1, 1, "Param %i", 0., 0., 1., 0.1, "", IParam::kFlagsNone); // initialize kNumParams generic iplug params

    mFaustProcessor.SetMaxChannelCount (MaxNChannels (kInput), MaxNChannels (kOutput));
    mFaustProcessor.Init();
    mFaustProcessor.CreateIPlugParameters (this, 0, 7, true); // in order to create iplug params, based on faust .dsp params, uncomment this
    mFaustProcessor.CompileCPP();
    mFaustProcessor.SetAutoRecompile (true);

#ifndef FAUST_COMPILED
    mFaustProcessor.SetCompileFunc ([&]() {
        OnParamReset (EParamSource::kRecompile);
    });
#endif

    initGraphics();
}

void RARPluginFaust::initGraphics()
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

void RARPluginFaust::ProcessBlock (sample** inputs, sample** outputs, int nFrames)
{
    mFaustProcessor.ProcessBlock (inputs, outputs, nFrames);
}

void RARPluginFaust::OnReset()
{
    mFaustProcessor.SetSampleRate (GetSampleRate());
    mFaustProcessor.SetOverSamplingRate (16);
}

void RARPluginFaust::OnParamChange (int paramIdx)
{
    mFaustProcessor.SetParameterValueNormalised (paramIdx, GetParam (paramIdx)->GetNormalized());
}
