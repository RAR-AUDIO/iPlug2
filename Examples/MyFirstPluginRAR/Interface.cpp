//=============================================================================
// Project     : Plugin
// Version     : 0.0.1
//
// Category    : Interface
// Filename    : Interface/Interface.h
// Created by  : RAR-AUDIO, JUL/2020
// Author      : Roberto Ramirez
// Description : GUI
//
//
//-----------------------------------------------------------------------------
// LICENSE
// (c) 2020, RAR-AUDIO, All Rights Reserved
//-----------------------------------------------------------------------------
//=============================================================================

#include "Interface.h"

Interface::Interface(PLUG_CLASS_NAME* inPlug)
    : mPlug(inPlug), mPresetControl(nullptr) {}

Interface::~Interface() { mPresetControl = nullptr; }

void Interface::CreateControls(IGraphics* pGraphics) {
  pGraphics->AttachCornerResizer(EUIResizerMode::Scale, false);
  pGraphics->AttachPanelBackground(COLOR_GRAY);
  pGraphics->LoadFont("Roboto-Regular", ROBOTO_FN);
  const IRECT b = pGraphics->GetBounds();
  pGraphics->AttachControl(
      new ITextControl(b.GetMidVPadded(50), "Hello iPlug 2!", IText(50)));
  pGraphics->AttachControl(new IVKnobControl(
      b.GetCentredInside(100).GetVShifted(-100), (int)Parameters::kGain));
};