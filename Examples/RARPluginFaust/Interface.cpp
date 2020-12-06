
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

    for (int i = 0; i < K_NUM_PARAMS; i++)
    {
        pGraphics->AttachControl (new IVKnobControl (knobs.GetGridCell (i, 1, K_NUM_PARAMS).GetPadded (-5.f), i));
    }
};
