
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

    IRECT Preset = b.GetFromTop (50.f);

    pGraphics->AttachPanelBackground (COLOR_GRAY);
    pGraphics->AttachCornerResizer (EUIResizerMode::Scale);
    pGraphics->LoadFont ("Roboto-Regular", ROBOTO_FN);

    for (int i = 0; i < KNumParameters; i++)
    {
        pGraphics->AttachControl (new RAR::Graphics::Controls::RarVectorKnob (knobs.GetGridCell (i, 1, KNumParameters).GetPadded (-5.f), i));
    }

    WDL_String presetpath;
    WDL_String fileExtension;

    
    //pGraphics->AttachControl (new RAR::Graphics::Controls::RarPresetControl(Preset.GetVShifted (300.f), RAR::Graphics::Layout::RAR_DEFAULT_STYLE));
    //pGraphics->AttachControl (new RAR::Graphics::Controls::RarDiskPresetManagerControl (Preset.GetVShifted (300.f), "%appdata%/Local/RAR-AUDIO/PLUG_NAME", ".rarap", RAR::Graphics::Controls::PresetControlStyle));
};
