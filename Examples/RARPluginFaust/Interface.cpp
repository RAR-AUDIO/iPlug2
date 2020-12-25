#include "Interface.h"

#include "IControls.h"

Interface::Interface (PLUG_CLASS_NAME* inPlug)
    : mPlug { inPlug }
{
}

Interface::~Interface ()
{
}

void Interface::createControls (IGraphics* pGraphics)
{
    const IRECT b = pGraphics->GetBounds().GetPadded (-20);

    const IRECT knobs = b.GetFromTop (100.);

    const IRECT Preset = b.GetFromTop (50.f);

    pGraphics->AttachPanelBackground (Rar::Graphics::Layout::RAR_DEFAULT_BACKGROUNDCOLOR);

    pGraphics->AttachCornerResizer (EUIResizerMode::Scale);

    pGraphics->LoadFont ("Roboto-Regular", ROBOTO_FN);


    for (int i = 0; i < KNumParameters; i++)
    {
        //pGraphics->AttachControl (new HISSTools_Dial (i, 10, 10, 0));
        pGraphics->AttachControl (new Rar::Graphics::Controls::RarVectorKnob (knobs.GetGridCell (i, 1, KNumParameters).GetPadded (-5.f), i, "", Rar::Graphics::Layout::RAR_DEFAULT_STYLE, false, false));
    }

    //pGraphics->AttachControl (new Rar::Graphics::Controls::RarPresetControl (Preset.GetVShifted (300.f)));
};
