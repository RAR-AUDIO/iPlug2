//==================================================================================
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
//---------------------------------------------------------------------------------
// LICENSE
// (c) 2020, RAR-AUDIO, All Rights Reserved
//---------------------------------------------------------------------------------
//=================================================================================


#include "Interface.h"


enum Elayout {
  kPeaksControl_W = 200,
  kPeaksControl_H = 200,
  kPeaksControl_X = 100,
  kPeaksControl_Y = 100,

  kControlSurface_W = kPeaksControl_W,
  kControlSurface_H = kControlSurface_W,
  kControlSurface_X = kPeaksControl_X,
  kControlSurface_Y = kPeaksControl_Y
};

namespace Color {
  const IColor Background (255, 10, 10, 10);

  const IColor KnobLine (255, 255, 255, 255);
  const IColor KnobCorona (255, 255, 255, 255);

  const IColor Label (255, 208, 208, 216);

  const IColor EnumBackground (255, 90, 90, 90);
  const IColor EnumBorder = KnobLine;

  const IColor BangOn (255, 200, 200, 200);
  const IColor BangOff (EnumBackground);

  const IColor Title (255, 30, 30, 30);

  const IColor PeaksForeground (255, 100, 100, 100);
  const IColor PeaksBackground (255, 60, 60, 60);

  const IColor ControlSurfaceBackground (255, 60, 60, 60);
  const IColor ControlPointA (255, 170, 170, 0);
  const IColor ControlPointB (255, 0, 170, 170);

  const IColor ShaperBracket (255, 0, 200, 200);
  const IColor ShaperLine (255, 200, 200);

  const IColor SnapshotSliderLine (255, 200, 200, 200);
  const IColor SnapshotSliderHandle (128, 255, 255, 255);
  const IColor SnapshotSliderHandleHighlight (200, 255, 255, 255);

  const IVColorSpec SnapshotSliderColors ({ DEFAULT_BGCOLOR, SnapshotSliderHandle, DEFAULT_PRCOLOR, DEFAULT_FRCOLOR, DEFAULT_HLCOLOR, SnapshotSliderLine, DEFAULT_X1COLOR, DEFAULT_X2COLOR, DEFAULT_X3COLOR });

  const IColor PlayStopBackground (EnumBackground);
  const IColor PlayStopForeground (EnumBorder);
}


Interface::Interface (PLUG_CLASS_NAME* inPlug) :mPlug (inPlug), mPresetControl (nullptr) {}

Interface::~Interface () {
  mPresetControl = nullptr;
}

void Interface::CreateControls (IGraphics* pGraphics) {
  pGraphics->AttachCornerResizer (EUIResizerMode::Scale, false);
  pGraphics->AttachPanelBackground (COLOR_GRAY);
  pGraphics->LoadFont ("Roboto-Regular", ROBOTO_FN);
  const IRECT b = pGraphics->GetBounds ();
  pGraphics->AttachControl (new ITextControl (b.GetMidVPadded (50), "Hello iPlug 2!", IText (50)));
  pGraphics->AttachControl (new IVKnobControl (b.GetCentredInside (100).GetVShifted (-100), kGain));
};