//==================================================================================
/* iPlug Includes*/
#include "MyFirstPluginRAR.h"

#include "IPlug_include_in_plug_src.h"
//==================================================================================
/* RarClasses Includes*/
#include "Utils/RAR_Graphics.hpp"
//==================================================================================

MyFirstPluginRAR::MyFirstPluginRAR (const InstanceInfo& info)
    : Plugin (info, MakeConfig (kNumParams, K_NUM_PRESETS))
{
    GetParam (kGain)->InitDouble ("Gain", 0., 0., 100.0, 0.01, "%");

#if IPLUG_EDITOR // http://bit.ly/2S64BDd
    mMakeGraphicsFunc = [&]()
    { return MakeGraphics (*this, PLUG_WIDTH, PLUG_HEIGHT, PLUG_FPS, GetScaleForScreen (PLUG_WIDTH, PLUG_HEIGHT)); };

    mLayoutFunc = [&] (IGraphics* pGraphics)
    {
        pGraphics->AttachCornerResizer (EUIResizerMode::Scale, false);
        pGraphics->AttachPanelBackground (COLOR_GRAY);
        pGraphics->LoadFont ("Roboto-Regular", ROBOTO_FN);
        const auto b = pGraphics->GetBounds();
        pGraphics->AttachControl (new ITextControl (b.GetMidVPadded (50), "Hello iPlug 2!", IText (50)));
        pGraphics->AttachControl (new IVKnobControl (b.GetCentredInside (100).GetVShifted (-100), kGain));
    }; // layout
#endif
}

#if IPLUG_DSP
void MyFirstPluginRAR::ProcessBlock (sample** inputs, sample** outputs, int nFrames)
{
    const auto nChans = NOutChansConnected();

    const double gain = GetParam (kGain)->Value() / 100.;

    for (auto s = 0; s < nFrames; s++)
    {
        for (auto c = 0; c < nChans; c++)
            outputs[c][s] = inputs[c][s] * gain;
    }
}

void MyFirstPluginRAR::OnIdle()
{
    /* NO-OP */
    // get "idle" call on main thread
    // meters and such
}

void MyFirstPluginRAR::OnReset()
{
    /* NO-OP */
    // do something prior to playback
    // clear buffers, update internal DSP with latest sampleRate
}

#endif
