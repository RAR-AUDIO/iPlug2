// =============================================================================
//  Project     : MyFirstPluginRAR
//  Version     : 0.1.0
//
//  Category    : MyFirstPluginRAR-vst3
//  Filename    : MyFirstPluginRAR-vst3/Interface.cpp
//  Created by  : RAR-AUDIO, 11/2020
//  Author      : Roberto A. Ramirez Gonzalez
//  Description : Interface Graphics
//
//
// -----------------------------------------------------------------------------
//  LICENSE
//  (c) 2020, RAR-AUDIO, All Rights Reserved
// -----------------------------------------------------------------------------
// =============================================================================

#include "Interface.h"

#include "IControls.h"

Interface::Interface (PLUG_CLASS_NAME* inPlug)
    : mPlug (inPlug)
{
}

Interface::~Interface()
{
}

void Interface::createControls (IGraphics* pGraphics)
{
    pGraphics->AttachCornerResizer (EUIResizerMode::Scale, false);

    pGraphics->AttachPanelBackground (COLOR_GRAY);

    pGraphics->LoadFont ("Roboto-Regular", ROBOTO_FN);

    const IRECT b = pGraphics->GetBounds();

    pGraphics->AttachControl (
        new ITextControl (b.GetMidVPadded (50),
                          "Hello iPlug 2!",
                          IText (50)));

    pGraphics->AttachControl (
        new IVKnobControl (
            b.GetCentredInside (100).GetVShifted (-100),
            static_cast<int> (KGain)));
};
