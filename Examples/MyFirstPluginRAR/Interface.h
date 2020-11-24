// =============================================================================
//  Project     : MyFirstPluginRAR-vst3
//  Version     : 0.1.0
// 
//  Category    : Main
//  Filename    : Main/Interface.h
//  Created by  : RAR-AUDIO, 11/2020
//  Author      : Roberto A. Ramirez Gonzalez
//  Description : Plugin Parameters
// 
// 
// -----------------------------------------------------------------------------
//  LICENSE
//  (c) 2020, RAR-AUDIO, All Rights Reserved
// -----------------------------------------------------------------------------
// =============================================================================

#pragma once

#include "IControl.h"
#include "IGraphicsStructs.h"
#include "config.h"

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
};
