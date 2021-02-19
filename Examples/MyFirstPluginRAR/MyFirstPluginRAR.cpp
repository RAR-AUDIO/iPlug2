#include "MyFirstPluginRAR.h"
#include "IPlug_include_in_plug_src.h"

#include "Utils/RAR_Graphics.hpp"

PLUG_CLASS_NAME::PLUG_CLASS_NAME (const InstanceInfo& info)
    : Plugin (info, MakeConfig (KNumParams, K_NUM_PRESETS))
{
    GetParam (KGain)->InitDouble ("Gain", 0., 0., 100.0, 0.01, "%");

#if IPLUG_EDITOR // http://bit.ly/2S64BDd
    mMakeGraphicsFunc = [&] ()
    {
        return MakeGraphics (*this, PLUG_WIDTH, PLUG_HEIGHT, PLUG_FPS, GetScaleForScreen (PLUG_WIDTH, PLUG_HEIGHT));
    };

    mLayoutFunc = [&] (IGraphics* pGraphics)
    {
        pGraphics->AttachCornerResizer (EUIResizerMode::Scale, false);
        pGraphics->AttachPanelBackground (COLOR_GRAY);
        pGraphics->LoadFont ("Roboto-Regular", ROBOTO_FN);
        const auto b = pGraphics->GetBounds ();
        pGraphics->AttachControl (new ITextControl (b.GetMidVPadded (50), "Hello iPlug 2!", IText (50)));
        pGraphics->AttachControl (new IVKnobControl (b.GetCentredInside (100).GetVShifted (-100), KGain));
    }; // layout
#endif
}

#if IPLUG_DSP
void PLUG_CLASS_NAME::ProcessBlock (sample** inputs, sample** outputs, int nFrames)
{
    const auto nChans = NOutChansConnected ();

    for (auto s = 0; s < nFrames; s++)
    {
        for (auto c = 0; c < nChans; c++)
        {
            outputs[c][s] = inputs[c][s] * gain;
        }
    }
}

void PLUG_CLASS_NAME::OnIdle ()
{
    /* NO-OP */
    // get "idle" call on main thread
    // meters and such
}

void PLUG_CLASS_NAME::OnReset ()
{
    /* NO-OP */
    // do something prior to playback
    // clear buffers, update internal DSP with latest sampleRate
}

void PLUG_CLASS_NAME::OnParamChange (int paramIdx)
{
    switch (paramIdx)
    {
        case KGain:
            gain = GetParam (paramIdx)->Value () / 100;
            break;
        default:
            break;
    }
}

#endif
