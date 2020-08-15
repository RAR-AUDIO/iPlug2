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

#include "IControls.h"
#include "Params.h"

Interface::Interface(PLUG_CLASS_NAME* inPlug)
  : m_plug_(inPlug) {}

Interface::~Interface() { m_preset_control_ = nullptr; }

void Interface::CreateControls(IGraphics* pGraphics) {
  pGraphics->AttachCornerResizer(EUIResizerMode::Scale, false);
  pGraphics->AttachPanelBackground(COLOR_GRAY);
  pGraphics->LoadFont("Roboto-Regular", ROBOTO_FN);
  const IRECT b = pGraphics->GetBounds();
  pGraphics->AttachControl(
      new ITextControl(b.GetMidVPadded(50), "Hello iPlug 2!",
                       IText(50)));
  pGraphics->AttachControl(new IVKnobControl(
      b.GetCentredInside(100).GetVShifted(-100),
      static_cast<int>(Parameters::kGain)));
};
