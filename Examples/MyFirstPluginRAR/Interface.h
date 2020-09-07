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

#include "config.h"
#include "IControl.h"
#include "IGraphicsStructs.h"

class PLUG_CLASS_NAME;

namespace iplug
{
    class IEditorDelegate;
} // namespace iplug

using namespace iplug;
using namespace igraphics;

class Interface
{
public:
    explicit Interface (PLUG_CLASS_NAME* inPlug);
    ~Interface ();

    static void createControls (IGraphics* pGraphics);

private:
    PLUG_CLASS_NAME* mPlug;
    IControl* mPresetControl = nullptr;
};
