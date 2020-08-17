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

#pragma once

#include "IControl.h"
#include "IGraphicsStructs.h"
#include "config.h"

class PLUG_CLASS_NAME;

namespace iplug {
class IEditorDelegate;
}

using namespace iplug;
using namespace igraphics;

class Interface {
 public:
  Interface(PLUG_CLASS_NAME* inPlug);
  ~Interface();

  void CreateControls(IGraphics* pGraphics);

 private:
  PLUG_CLASS_NAME* m_plug_;
  IControl* m_preset_control_ = nullptr;
};