// =============================================================================
//  Project     : MyFirstPluginRAR
//  Version     : 0.1.0
//
//  Category    : MyFirstPluginRAR-vst3
//  Filename    : MyFirstPluginRAR-vst3/Interface.h
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

#pragma once

#include "IControl.h"
#include "IControls.h"
#include "IGraphicsStructs.h"
#include "RARClasses/Utils/RAR_Graphics.h"
#include "config.h"

const int K_NUM_PARAMS = 7;
const int K_NUM_PRESETS = 1;

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
    ~Interface();

    static void createControls (IGraphics* pGraphics);

private:
    PLUG_CLASS_NAME* mPlug;
};
