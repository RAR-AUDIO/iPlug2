
#include "Interface.h"

#include "IControls.h"


Interface::Interface (PLUG_CLASS_NAME* inPlug)
    : mPlug { inPlug }
{
}

Interface::~Interface()
{
}

void Interface::createControls (IGraphics* pGraphics)
{
    IRECT b = pGraphics->GetBounds().GetPadded (-20);

    IRECT knobs = b.GetFromTop (100.);

    pGraphics->AttachPanelBackground (COLOR_GRAY);
    pGraphics->AttachCornerResizer (EUIResizerMode::Scale);
    pGraphics->LoadFont ("Roboto-Regular", ROBOTO_FN);

    for (int i = 0; i < KNumParameters; i++)
    {
        pGraphics->AttachControl (new RAR::Graphics::Controls::RarVectorKnob (knobs.GetGridCell (i, 1, KNumParameters).GetPadded (-5.f), i));
    }
};
