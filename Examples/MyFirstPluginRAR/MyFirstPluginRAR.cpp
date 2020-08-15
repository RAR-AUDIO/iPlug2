//=============================================================================
// Project     : Plugi
// Version     : 0.0.1
//
// Category    : Main
// Filename    : Main/MyFirstPluginRAR.cpp
// Created by  : RAR-AUDIO, JUL/2020
// Author      : Roberto Ramirez
// Description : Plugin Parameters
//
//
//-----------------------------------------------------------------------------
// LICENSE
// (c) 2020, RAR-AUDIO, All Rights Reserved
//-----------------------------------------------------------------------------
//=============================================================================

#include "MyFirstPluginRAR.h"

#include "IControls.h"
#include "IPlug_include_in_plug_src.h"

IParam* MyFirstPluginRAR::GetParam(Parameters parameter) {
  return IEditorDelegate::GetParam(static_cast<int>(parameter));
}

void MyFirstPluginRAR::InitParameters() {
  GetParam(Parameters::kGain)
      ->InitDouble("Gain", 0., 0.,
                   100.0, 0.01, "%");
}

void MyFirstPluginRAR::cookVars() {
  gain_ = GetParam(Parameters::kGain)->Value() / 100.;
}

void MyFirstPluginRAR::InitGraphics() {
  mMakeGraphicsFunc = [&]() {
    return MakeGraphics(*this, PLUG_WIDTH, PLUG_HEIGHT, PLUG_FPS,
                        GetScaleForScreen(PLUG_HEIGHT));
  };

  mLayoutFunc = [&](IGraphics* pGraphics) {
    m_interface_.CreateControls(pGraphics);
  };
}

MyFirstPluginRAR::MyFirstPluginRAR(const InstanceInfo& info)
  : Plugin(info,
           MakeConfig(static_cast<int>(Parameters::kNumParams),
                      kNumPresets)),
    gain_(0),
    m_interface_(this) {
  InitParameters();
  InitGraphics();
  cookVars();
}

void MyFirstPluginRAR::ProcessBlock(sample** inputs, sample** outputs,
                                    const int nFrames) {
  const int nChans = NOutChansConnected();

  for (auto s = 0; s < nFrames; s++) {
    for (auto c = 0; c < nChans; c++) { outputs[c][s] = inputs[c][s] * gain_; }
  }
}

void MyFirstPluginRAR::OnReset() { cookVars(); }

void MyFirstPluginRAR::OnParamChange(int paramIdx) { cookVars(); }
