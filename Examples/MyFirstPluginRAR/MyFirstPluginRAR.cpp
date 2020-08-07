//==================================================================================
// Project     : Plugin
// Version     : 0.0.1
//
// Category    : Main
// Filename    : Main/MyFirstPluginRAR.cpp
// Created by  : RAR-AUDIO, JUL/2020
// Author      : Roberto Ramirez
// Description : Plugin Paramaters
//
//
//---------------------------------------------------------------------------------
// LICENSE
// (c) 2020, RAR-AUDIO, All Rights Reserved
//---------------------------------------------------------------------------------
//=================================================================================

#include "MyFirstPluginRAR.h"

#include "IControls.h"
#include "IPlug_include_in_plug_src.h"

IParam* MyFirstPluginRAR::GetParam(Parameters parameter) {
  return IEditorDelegate::GetParam((int)parameter);
}

void MyFirstPluginRAR::InitParameters() {
  GetParam(Parameters::kGain)->InitDouble("Gain", 0., 0., 100.0, 0.01, "%");
}

void MyFirstPluginRAR::SetParameterDisplayText() {
  GetParam(Parameters::kGain)->SetDisplayText(0, "0 %");
  GetParam(Parameters::kGain)->SetDisplayText(10, "10 %");
  GetParam(Parameters::kGain)->SetDisplayText(20, "20 %");
  GetParam(Parameters::kGain)->SetDisplayText(30, "30 %");
  GetParam(Parameters::kGain)->SetDisplayText(40, "40 %");
  GetParam(Parameters::kGain)->SetDisplayText(50, "50 %");
  GetParam(Parameters::kGain)->SetDisplayText(60, "60 %");
  GetParam(Parameters::kGain)->SetDisplayText(70, "70 %");
  GetParam(Parameters::kGain)->SetDisplayText(80, "80 %");
  GetParam(Parameters::kGain)->SetDisplayText(90, "90 %");
  GetParam(Parameters::kGain)->SetDisplayText(100, "100 %");
}

void MyFirstPluginRAR::InitGraphics() {
  mMakeGraphicsFunc = [&]() {
    return MakeGraphics(*this, PLUG_WIDTH, PLUG_HEIGHT, PLUG_FPS,
                        GetScaleForScreen(PLUG_HEIGHT));
  };

  mLayoutFunc = [&](IGraphics* pGraphics) {
    mInterface.CreateControls(pGraphics);
  };
}

MyFirstPluginRAR::MyFirstPluginRAR(const InstanceInfo& info)
    : Plugin(info, MakeConfig((int)Parameters::kNumParams, kNumPresets)),
      mInterface(this) {
  InitParameters();
  InitGraphics();
}

void MyFirstPluginRAR::ProcessBlock(sample** inputs, sample** outputs,
                                    int nFrames) {
  const double gain = GetParam(Parameters::kGain)->Value() / 100.;
  const int nChans = NOutChansConnected();

  for (int s = 0; s < nFrames; s++) {
    for (int c = 0; c < nChans; c++) {
      outputs[c][s] = inputs[c][s] * gain;
    }
  }
}

// void MyFirstPluginRAR::OnReset () {}

// void MyFirstPluginRAR::OnParamChange (int paramIdx, EParamSource, int
// sampleOffset) {}