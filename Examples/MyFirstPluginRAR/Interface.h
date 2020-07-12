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


#pragma once

#include "config.h"
#include "IGraphicsStructs.h"
#include "Params.h"
#include "IControls.h"
#include "IControl.h"

class PLUG_CLASS_NAME;

namespace iplug {
  class IEditorDelegate;
}

using namespace iplug;
using namespace igraphics;

class Interface {
public:
  Interface (PLUG_CLASS_NAME* inPlug);
  ~Interface ();

  void CreateControls (IGraphics* pGraphics);

private:
  //IControl* AttachEnum (IGraphics* pGraphics, IRECT rect, const int paramIdx, const char* label = nullptr);
  //IControl* AttachTextBox (IGraphics* pGraphics, IRECT rect, const int paramIdx, const float scrollSpeed, const char* maxValue, const char* label = nullptr);

  PLUG_CLASS_NAME* mPlug;

  IControl* mPresetControl;
};