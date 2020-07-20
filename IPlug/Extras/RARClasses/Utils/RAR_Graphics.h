//==================================================================================
// Project     : IPlug
// Version     : 1.0
//
// Category    : Utils
// Filename    : Utils/RAR_Graphics.h
// Created by  : RAR-AUDIO, JUL/2020
// Author      : Roberto Ramirez
// Description : Graphic Controls
//
//---------------------------------------------------------------------------------
// LICENSE
// (c) 2020, RAR-AUDIO LLC, All Rights Reserved
//---------------------------------------------------------------------------------
//=================================================================================

#pragma once

//#include "IPlug/IPlug_include_in_plug_hdr.h"
#include "../../../IPlugPluginBase.h"
#include "../Utils/RAR_Helpers.h"
#include "../../../../IGraphics/IControl.h"
// For meter, see IVMeterControl.h
#include "../../../IPlugQueue.h"
#include "../../../IPlugStructs.h"
#include "../../../../IGraphics/Controls/IVMeterControl.h"
#include "../config.h"

using namespace iplug;
using namespace igraphics;

namespace RAR{
  namespace Graphics{
    namespace Layout{
      // Colors
      const IColor RAR_DEFAULT_COLOR = COLOR_LIGHT_GRAY; // oder COLOR_MID_GRAY?
      const IColor RAR_DEFAULT_COLOR_BG = COLOR_TRANSPARENT;
      const IColor RAR_DEFAULT_COLOR_FG = RAR_DEFAULT_COLOR;
      const IColor RAR_DEFAULT_COLOR_PR = IColor(255, 234, 158, 19);
      const IColor RAR_DEFAULT_COLOR_FR = IColor(255, 150, 150, 150);
      const IColor RAR_DEFAULT_COLOR_HL = IColor(30, 255, 255, 255);
      const IColor RAR_DEFAULT_COLOR_SH = IColor(100, 0, 0, 0);
      const IColor RAR_DEFAULT_COLOR_X1 = IColor(255, 234, 158, 19);
      const IColor RAR_DEFAULT_COLOR_X2 = IColor(255, 48, 166, 186);
      const IColor RAR_DEFAULT_COLOR_X3 = IColor(255, 249, 206, 34);

      const IColor RAR_DEFAULT_COLOR_CUSTOM_PLUGIN_BG = IColor(255, 12, 17, 23);
      const IColor RAR_DEFAULT_COLOR_CUSTOM_PANEL_BG = IColor(255, 50, 75, 95);
      const IColor RAR_DEFAULT_COLOR_CUSTOM_BLUE = IColor(255, 62, 100, 121);
      const IColor RAR_DEFAULT_COLOR_CUSTOM_RED = IColor(255, 131, 18, 18);
      const IColor RAR_DEFAULT_COLOR_CUSTOM_GREEN = IColor(255, 103, 141, 52);
      const IColor RAR_DEFAULT_COLOR_CUSTOM_ORANGE = IColor(255, 234, 158, 19);
      const IColor RAR_DEFAULT_COLOR_CUSTOM_YELLOW = IColor(255, 219, 181, 30);
      const IColor RAR_DEFAULT_COLOR_CUSTOM_BLACK = IColor(255, 23, 23, 23);
      const IColor RAR_DEFAULT_COLOR_CUSTOM_WHITE = IColor(255, 243, 243, 243);

      // Texts
      const float RAR_DEFAULT_TEXT_SIZE = 20.f;

      const IText RAR_DEFAULT_TEXT = IText(20.f, RAR_DEFAULT_COLOR, nullptr, EAlign::Center, EVAlign::Top);
      const IText RAR_DEFAULT_TEXT_KNOB_LABEL = IText(24.f, RAR_DEFAULT_COLOR, nullptr, EAlign::Center, EVAlign::Top);
      const IText RAR_DEFAULT_TEXT_KNOB_VALUE = IText(20.f, COLOR_MID_GRAY, nullptr, EAlign::Center, EVAlign::Bottom);
      const IText RAR_DEFAULT_TEXT_BUTTON_LABEL = IText(16.f, RAR_DEFAULT_COLOR, nullptr, EAlign::Center, EVAlign::Bottom);
      const IText RAR_DEFAULT_TEXT_BUTTON_VALUE = IText(12.f, COLOR_MID_GRAY, nullptr, EAlign::Center, EVAlign::Bottom);;
      const IText RAR_DEFAULT_TEXT_VERSIONSTRING = IText(14.f, RAR_DEFAULT_COLOR, nullptr, EAlign::Near, EVAlign::Middle);
      const IText RAR_DEFAULT_TEXT_PRESETMENU = IText(30.f, RAR_DEFAULT_COLOR, nullptr, EAlign::Center, EVAlign::Middle);

      // Color Specs
      const IVColorSpec RAR_DEFAULT_COLOR_SPEC = IVColorSpec(
        {RAR_DEFAULT_COLOR_BG
        , RAR_DEFAULT_COLOR_FG
        , RAR_DEFAULT_COLOR_PR
        , RAR_DEFAULT_COLOR_FR
        , RAR_DEFAULT_COLOR_HL
        , RAR_DEFAULT_COLOR_SH
        , RAR_DEFAULT_COLOR_X1
        , RAR_DEFAULT_COLOR_X2
        , RAR_DEFAULT_COLOR_X3
        }
      );

      // Styles
      const IVStyle RAR_DEFAULT_STYLE = IVStyle(
        true,
        true,
        {RAR_DEFAULT_COLOR_BG
        , RAR_DEFAULT_COLOR_FG
        , RAR_DEFAULT_COLOR_PR
        , RAR_DEFAULT_COLOR_FR
        , RAR_DEFAULT_COLOR_HL
        , RAR_DEFAULT_COLOR_SH
        , RAR_DEFAULT_COLOR_X1
        , RAR_DEFAULT_COLOR_X2
        , RAR_DEFAULT_COLOR_X3
        },
        RAR_DEFAULT_TEXT_KNOB_LABEL,
        RAR_DEFAULT_TEXT_KNOB_VALUE,
        true,
        true,
        true,
        true,
        0.1f, // roundness
        2.f, // frame-thick, def: 1.f
        3.f, // shadow-off
        DEFAULT_WIDGET_FRAC,
        DEFAULT_WIDGET_ANGLE
      );
      const IVStyle RAR_DEFAULT_STYLE_KNOB = RAR_DEFAULT_STYLE;
      const IVStyle RAR_DEFAULT_STYLE_BUTTON = RAR_DEFAULT_STYLE
        /*.WithShowLabel(false)*/
        .WithColor(EVColor::kFG, IColor(255, 30, 50, 70))
        /*.WithDrawShadows(false)*/
        .WithWidgetFrac(0.8f);
      const IVStyle RAR_DEFAULT_STYLE_FADER = RAR_DEFAULT_STYLE.WithColor(EVColor::kFG, IColor(255, 30, 50, 70)).WithDrawFrame(false);
      const IVStyle RAR_DEFAULT_STYLE_METER = RAR_DEFAULT_STYLE_FADER;
      const IVStyle RAR_DEFAULT_STYLE_GRAPH = RAR_DEFAULT_STYLE_FADER;

      class RAR_CustomStyles{
      public:

        enum ECustomStyles{
          kDefault = 0,
          kKnob,
          kButton,
          kFader,
          kMeter,
          kGraph,
          kNumCustomStyles
        };

        RAR_CustomStyles(
          IVStyle defaultStyle = DEFAULT_STYLE,
          IVStyle knobStyle = DEFAULT_STYLE,
          IVStyle buttonStyle = DEFAULT_STYLE,
          IVStyle faderStyle = DEFAULT_STYLE,
          IVStyle meterStyle = DEFAULT_STYLE,
          IVStyle graphStyle = DEFAULT_STYLE
        )
          : mStyles{defaultStyle, knobStyle, buttonStyle, faderStyle, meterStyle, graphStyle}{}

        IVStyle GetStyle(ECustomStyles type) const{ return mStyles[type]; }
        void SetStyle(ECustomStyles type, IVStyle style){ mStyles[type] = style; }

      private:
        IVStyle mStyles[ECustomStyles::kNumCustomStyles];
      };

      // Colors
      class RAR_CustomColors{
      public:
        enum ECustomColors{
          kDefault = 0,
          kPluginBg,
          kPanelBg,
          kBlue,
          kRed,
          kGreen,
          kOrange,
          kYellow,
          kBlack,
          kWhite,
          kNumCustomColors
        };

        RAR_CustomColors(
          IVColorSpec colorSpec,
          IColor defaultColor,
          IColor pluginColor,
          IColor panelColor,
          IColor blue,
          IColor red,
          IColor green,
          IColor orange,
          IColor yellow,
          IColor black,
          IColor white
        )
          : mColorSpec(colorSpec)
          , mColors{defaultColor, pluginColor, panelColor, blue, red, green, orange, yellow, black, white}
        {}

        IColor GetColor(ECustomColors type = ECustomColors::kDefault) const{ return mColors[type]; }
        IColor GetColorWithAlpha(ECustomColors type = ECustomColors::kDefault, float alpha = 255.f) const{ IColor tempcolor = mColors[type]; tempcolor.A = alpha; return tempcolor; }
        IVColorSpec GetColorSpec() const{ return mColorSpec; }
        void SetColor(ECustomColors type, IColor& color){ mColors[type] = color; }
        void SetColorSpec(IVColorSpec& colorSpec){ mColorSpec = colorSpec; }

      private:
        IColor mColors[ECustomColors::kNumCustomColors];
        IVColorSpec mColorSpec;
      };

      class RAR_CustomTexts{
      public:

        enum ECustomTexts{
          kDefault = 0,
          kKnobLabel,
          kKnobValue,
          kButtonLabel,
          kButtonValue,
          kVersionString,
          kPresetMenu,
          kNumCustomTexts
        };

        RAR_CustomTexts(
          float size,
          IText defaultText,
          IText knobLabel,
          IText knobValue,
          IText buttonLabel,
          IText buttonValue,
          IText versionString,
          IText presetMenu
        )
          : mSize(size)
          , mTexts{defaultText, knobLabel, knobValue, buttonLabel, buttonValue, versionString, presetMenu}
        {}

        IText GetText(RAR::Graphics::Layout::RAR_CustomTexts::ECustomTexts type = RAR::Graphics::Layout::RAR_CustomTexts::ECustomTexts::kDefault) const{ return mTexts[type]; }
        void SetText(RAR::Graphics::Layout::RAR_CustomTexts::ECustomTexts type, IText& text){ mTexts[type] = text; }

      private:
        float mSize;
        IText mTexts[ECustomTexts::kNumCustomTexts];
      };

      class RAR_Layout
        : public RAR_CustomColors
        , public RAR_CustomTexts
        , public RAR_CustomStyles{
      public:
        RAR_Layout(RAR_CustomColors colors, RAR_CustomTexts texts, RAR_CustomStyles styles)
          : RAR_CustomColors(colors)
          , RAR_CustomTexts(texts)
          , RAR_CustomStyles(styles){};
        ~RAR_Layout(){};

        //IColor GetCustomColor(RAR_CustomColors::ECustomColors color = RAR_CustomColors::ECustomColors::kDefault) { return mColors.GetColor(color); }
        //IColor GetColorSpecColor(EVColor type) { return mColors.GetColorSpec().GetColor(type); }
        //IVColorSpec GetColorSpec() { return mColors.GetColorSpec(); }
        //IText GetCustomText(RAR_CustomTexts::ECustomTexts text = RAR_CustomTexts::ECustomTexts::kDefault) { return mTexts.GetText(text); }
        //IVStyle GetStyle() { return mStyles; }

      private:
      };

      const RAR_CustomColors RAR_DEFAULT_CUSTOM_COLORS = RAR_CustomColors(
        // Color Specs
        IVColorSpec{
          DEFAULT_BGCOLOR,            // Background (DEFAULT_BGCOLOR = COLOR_TRANSPARENT(0, 0, 0, 0))
          DEFAULT_FGCOLOR,            // Foreground (DEFAULT_FGCOLOR = COLOR_MID_GRAY(255, 200, 200, 200))
          IColor(255, 234, 158, 19), // Pressed    (DEFAULT_PRCOLOR = COLOR_LIGHT_GRAY(255, 240, 240, 240))
          IColor(255, 150, 150, 150),    // Frame      (DEFAULT_FRCOLOR = COLOR_DARK_GRAY(255, 70, 70, 70))
          IColor(30, 255, 255, 255),  // Higlight   (DEFAULT_HLCOLOR = COLOR_TRANSLUCENT(10, 0, 0, 0))
          IColor(100, 0, 0, 0),       // Shadow     (DEFAULT_SHCOLOR = IColor(60, 0, 0, 0)
          IColor(255, 234, 158, 19),  // Extra 1    (DEFAULT_X1COLOR = COLOR_RED(255, 255, 0, 0))
          IColor(255, 48, 166, 186),  // Extra 2    (DEFAULT_X2COLOR = COLOR_GREEN(255, 0, 255, 0))
          IColor(255, 249, 206, 34),  // Extra 3    (DEFAULT_X3COLOR = COLOR_BLUE(255, 0, 0, 255))
        },
        COLOR_LIGHT_GRAY,
        IColor(255, 12, 17, 23),
        IColor(255, 50, 75, 95),
        IColor(255, 62, 100, 121),
        IColor(255, 131, 18, 18),
        IColor(255, 103, 141, 52),
        IColor(255, 234, 158, 19),
        IColor(255, 219, 181, 30),
        IColor(255, 23, 23, 23),
        IColor(255, 243, 243, 243)
        );

      const RAR_CustomTexts RAR_DEFAULT_CUSTOM_TEXTS = RAR_CustomTexts(
        DEFAULT_TEXT_SIZE,
        IText(DEFAULT_TEXT_SIZE, RAR_DEFAULT_CUSTOM_COLORS.GetColor(RAR_CustomColors::ECustomColors::kDefault), nullptr, EAlign::Center, EVAlign::Top),
        IText(DEFAULT_TEXT_SIZE, RAR_DEFAULT_CUSTOM_COLORS.GetColor(RAR_CustomColors::ECustomColors::kDefault), nullptr, EAlign::Center, EVAlign::Top),
        IText(DEFAULT_TEXT_SIZE, RAR_DEFAULT_CUSTOM_COLORS.GetColor(RAR_CustomColors::ECustomColors::kDefault), nullptr, EAlign::Center, EVAlign::Bottom),
        IText(DEFAULT_TEXT_SIZE, RAR_DEFAULT_CUSTOM_COLORS.GetColor(RAR_CustomColors::ECustomColors::kDefault), nullptr, EAlign::Center, EVAlign::Bottom),
        IText(DEFAULT_TEXT_SIZE, RAR_DEFAULT_CUSTOM_COLORS.GetColor(RAR_CustomColors::ECustomColors::kDefault), nullptr, EAlign::Center, EVAlign::Bottom),
        IText(1.5f * DEFAULT_TEXT_SIZE, RAR_DEFAULT_CUSTOM_COLORS.GetColor(RAR_CustomColors::ECustomColors::kDefault), nullptr, EAlign::Near, EVAlign::Middle),
        IText(2.f * DEFAULT_TEXT_SIZE, RAR_DEFAULT_CUSTOM_COLORS.GetColor(RAR_CustomColors::ECustomColors::kDefault), nullptr, EAlign::Center, EVAlign::Middle)
      );

      const RAR_CustomStyles RAR_DEFAULT_CUSTOM_STYLE = RAR_CustomStyles(
        // DEFAULT:
        IVStyle(
          true,
          true,
          {
            DEFAULT_BGCOLOR,            // Background (DEFAULT_BGCOLOR = COLOR_TRANSPARENT(0, 0, 0, 0))
            DEFAULT_FGCOLOR,            // Foreground (DEFAULT_FGCOLOR = COLOR_MID_GRAY(255, 200, 200, 200))
            IColor(255, 234, 158, 19), // Pressed    (DEFAULT_PRCOLOR = COLOR_LIGHT_GRAY(255, 240, 240, 240))
            IColor(255, 150, 150, 150), // Frame      (DEFAULT_FRCOLOR = COLOR_DARK_GRAY(255, 70, 70, 70))
            IColor(30, 255, 255, 255),  // Higlight   (DEFAULT_HLCOLOR = COLOR_TRANSLUCENT(10, 0, 0, 0))
            IColor(100, 0, 0, 0),       // Shadow     (DEFAULT_SHCOLOR = IColor(60, 0, 0, 0)
            IColor(255, 234, 158, 19),  // Extra 1    (DEFAULT_X1COLOR = COLOR_RED(255, 255, 0, 0)
            IColor(255, 48, 166, 186),  // Extra 2    (DEFAULT_X2COLOR = COLOR_GREEN(255, 0, 255, 0))
            IColor(255, 249, 206, 34),  // Extra 3    (DEFAULT_X3COLOR = COLOR_BLUE(255, 0, 0, 255))
          },
          RAR_DEFAULT_CUSTOM_TEXTS.GetText(RAR_CustomTexts::ECustomTexts::kKnobLabel),
          RAR_DEFAULT_CUSTOM_TEXTS.GetText(RAR_CustomTexts::ECustomTexts::kKnobValue),
          true,
          true,
          true,
          0.1f, // roundness
          2.f, // frame-thick, def: 1.f
          3.f, // shadow-off
          DEFAULT_WIDGET_FRAC,
          DEFAULT_WIDGET_ANGLE
          ),

        // KNOB:
        IVStyle(
          true,
          true,
          {
            DEFAULT_BGCOLOR,            // Background (DEFAULT_BGCOLOR = COLOR_TRANSPARENT(0, 0, 0, 0))
            DEFAULT_FGCOLOR,            // Foreground (DEFAULT_FGCOLOR = COLOR_MID_GRAY(255, 200, 200, 200))
            IColor(255, 234, 158, 19), // Pressed    (DEFAULT_PRCOLOR = COLOR_LIGHT_GRAY(255, 240, 240, 240))
            IColor(255, 150, 150, 150), // Frame      (DEFAULT_FRCOLOR = COLOR_DARK_GRAY(255, 70, 70, 70))
            IColor(30, 255, 255, 255),  // Higlight   (DEFAULT_HLCOLOR = COLOR_TRANSLUCENT(10, 0, 0, 0))
            IColor(100, 0, 0, 0),       // Shadow     (DEFAULT_SHCOLOR = IColor(60, 0, 0, 0)
            IColor(255, 234, 158, 19),  // Extra 1    (DEFAULT_X1COLOR = COLOR_RED(255, 255, 0, 0)
            IColor(255, 48, 166, 186),  // Extra 2    (DEFAULT_X2COLOR = COLOR_GREEN(255, 0, 255, 0))
            IColor(255, 249, 206, 34),  // Extra 3    (DEFAULT_X3COLOR = COLOR_BLUE(255, 0, 0, 255))
          },
          RAR_DEFAULT_CUSTOM_TEXTS.GetText(RAR_CustomTexts::ECustomTexts::kKnobLabel),
          RAR_DEFAULT_CUSTOM_TEXTS.GetText(RAR_CustomTexts::ECustomTexts::kKnobValue),
          true,
          true,
          true,
          0.1f, // roundness
          2.f, // frame-thick, def: 1.f
          3.f, // shadow-off
          DEFAULT_WIDGET_FRAC,
          DEFAULT_WIDGET_ANGLE
          ),

        // BUTTON:
        IVStyle(
          false,
          true,
          {
            DEFAULT_BGCOLOR,            // Background (DEFAULT_BGCOLOR = COLOR_TRANSPARENT(0, 0, 0, 0))
            IColor(255, 30, 50, 70),            // Foreground (DEFAULT_FGCOLOR = COLOR_MID_GRAY(255, 200, 200, 200))
            IColor(255, 234, 158, 19), // Pressed    (DEFAULT_PRCOLOR = COLOR_LIGHT_GRAY(255, 240, 240, 240))
            IColor(255, 150, 150, 150),    // Frame      (DEFAULT_FRCOLOR = COLOR_DARK_GRAY(255, 70, 70, 70))
            IColor(30, 255, 255, 255),  // Higlight   (DEFAULT_HLCOLOR = COLOR_TRANSLUCENT(10, 0, 0, 0))
            IColor(100, 0, 0, 0),       // Shadow     (DEFAULT_SHCOLOR = IColor(60, 0, 0, 0)
            IColor(255, 234, 158, 19),  // Extra 1    (DEFAULT_X1COLOR = COLOR_RED(255, 255, 0, 0)
            IColor(255, 48, 166, 186),  // Extra 2    (DEFAULT_X2COLOR = COLOR_GREEN(255, 0, 255, 0))
            IColor(255, 249, 206, 34),  // Extra 3    (DEFAULT_X3COLOR = COLOR_BLUE(255, 0, 0, 255))
          },
          RAR_DEFAULT_CUSTOM_TEXTS.GetText(RAR_CustomTexts::ECustomTexts::kButtonLabel),
          RAR_DEFAULT_CUSTOM_TEXTS.GetText(RAR_CustomTexts::ECustomTexts::kButtonValue),
          true,
          false,
          true,
          0.5f, // roundness
          2.f, // frame-thick
          3.f, // shadow-off
          DEFAULT_WIDGET_FRAC,
          DEFAULT_WIDGET_ANGLE
          ),

        // FADER:
        IVStyle(
          false,
          true,
          {
            DEFAULT_BGCOLOR,            // Background (DEFAULT_BGCOLOR = COLOR_TRANSPARENT(0, 0, 0, 0))
            RAR_DEFAULT_CUSTOM_COLORS.GetColor(RAR_CustomColors::ECustomColors::kPluginBg),            // Foreground (DEFAULT_FGCOLOR = COLOR_MID_GRAY(255, 200, 200, 200))
            IColor(255, 234, 158, 19), // Pressed    (DEFAULT_PRCOLOR = COLOR_LIGHT_GRAY(255, 240, 240, 240))
            IColor(255, 150, 150, 150),    // Frame      (DEFAULT_FRCOLOR = COLOR_DARK_GRAY(255, 70, 70, 70))
            IColor(30, 255, 255, 255),  // Higlight   (DEFAULT_HLCOLOR = COLOR_TRANSLUCENT(10, 0, 0, 0))
            IColor(100, 0, 0, 0),       // Shadow     (DEFAULT_SHCOLOR = IColor(60, 0, 0, 0)
            IColor(255, 234, 158, 19),  // Extra 1    (DEFAULT_X1COLOR = COLOR_RED(255, 255, 0, 0)
            IColor(255, 48, 166, 186),  // Extra 2    (DEFAULT_X2COLOR = COLOR_GREEN(255, 0, 255, 0))
            IColor(255, 249, 206, 34),  // Extra 3    (DEFAULT_X3COLOR = COLOR_BLUE(255, 0, 0, 255))
          },
          RAR_DEFAULT_CUSTOM_TEXTS.GetText(RAR_CustomTexts::ECustomTexts::kButtonLabel),
          RAR_DEFAULT_CUSTOM_TEXTS.GetText(RAR_CustomTexts::ECustomTexts::kButtonValue),
          true,
          false,
          true,
          0.5f, // roundness
          2.f, // frame-thick
          3.f, // shadow-off
          DEFAULT_WIDGET_FRAC,
          DEFAULT_WIDGET_ANGLE
          ),

        // METER:
        IVStyle(
          false,
          true,
          {
            DEFAULT_BGCOLOR,            // Background (DEFAULT_BGCOLOR = COLOR_TRANSPARENT(0, 0, 0, 0))
            RAR_DEFAULT_CUSTOM_COLORS.GetColor(RAR_CustomColors::ECustomColors::kPluginBg),            // Foreground (DEFAULT_FGCOLOR = COLOR_MID_GRAY(255, 200, 200, 200))
            IColor(255, 234, 158, 19), // Pressed    (DEFAULT_PRCOLOR = COLOR_LIGHT_GRAY(255, 240, 240, 240))
            IColor(255, 150, 150, 150),    // Frame      (DEFAULT_FRCOLOR = COLOR_DARK_GRAY(255, 70, 70, 70))
            IColor(30, 255, 255, 255),  // Higlight   (DEFAULT_HLCOLOR = COLOR_TRANSLUCENT(10, 0, 0, 0))
            IColor(100, 0, 0, 0),       // Shadow     (DEFAULT_SHCOLOR = IColor(60, 0, 0, 0)
            IColor(255, 234, 158, 19),  // Extra 1    (DEFAULT_X1COLOR = COLOR_RED(255, 255, 0, 0)
            IColor(255, 48, 166, 186),  // Extra 2    (DEFAULT_X2COLOR = COLOR_GREEN(255, 0, 255, 0))
            IColor(255, 249, 206, 34),  // Extra 3    (DEFAULT_X3COLOR = COLOR_BLUE(255, 0, 0, 255))
          },
          RAR_DEFAULT_CUSTOM_TEXTS.GetText(RAR_CustomTexts::ECustomTexts::kButtonLabel),
          RAR_DEFAULT_CUSTOM_TEXTS.GetText(RAR_CustomTexts::ECustomTexts::kButtonValue),
          true,
          false,
          true,
          0.5f, // roundness
          2.f, // frame-thick
          3.f, // shadow-off
          DEFAULT_WIDGET_FRAC,
          DEFAULT_WIDGET_ANGLE
          ),

        // GRAPH:
        IVStyle(
          false,
          true,
          {
            DEFAULT_BGCOLOR,            // Background (DEFAULT_BGCOLOR = COLOR_TRANSPARENT(0, 0, 0, 0))
            RAR_DEFAULT_CUSTOM_COLORS.GetColor(RAR_CustomColors::ECustomColors::kPluginBg),            // Foreground (DEFAULT_FGCOLOR = COLOR_MID_GRAY(255, 200, 200, 200))
            RAR_DEFAULT_CUSTOM_COLORS.GetColorWithAlpha(RAR_CustomColors::ECustomColors::kGreen, 60.f), // Pressed    (DEFAULT_PRCOLOR = COLOR_LIGHT_GRAY(255, 240, 240, 240))
            IColor(255, 150, 150, 150),    // Frame      (DEFAULT_FRCOLOR = COLOR_DARK_GRAY(255, 70, 70, 70))
            RAR_DEFAULT_CUSTOM_COLORS.GetColorWithAlpha(RAR_CustomColors::ECustomColors::kGreen, 30.f),  // Higlight   (DEFAULT_HLCOLOR = COLOR_TRANSLUCENT(10, 0, 0, 0))
            IColor(100, 0, 0, 0),       // Shadow     (DEFAULT_SHCOLOR = IColor(60, 0, 0, 0)
            RAR_DEFAULT_CUSTOM_COLORS.GetColorWithAlpha(RAR_CustomColors::ECustomColors::kGreen, 60.f),  // Extra 1    (DEFAULT_X1COLOR = COLOR_RED(255, 255, 0, 0)
            IColor(255, 48, 166, 186),  // Extra 2    (DEFAULT_X2COLOR = COLOR_GREEN(255, 0, 255, 0))
            IColor(255, 249, 206, 34),  // Extra 3    (DEFAULT_X3COLOR = COLOR_BLUE(255, 0, 0, 255))
          },
          RAR_DEFAULT_CUSTOM_TEXTS.GetText(RAR_CustomTexts::ECustomTexts::kButtonLabel),
          RAR_DEFAULT_CUSTOM_TEXTS.GetText(RAR_CustomTexts::ECustomTexts::kButtonValue),
          true,
          false,
          true,
          0.5f, // roundness
          2.f, // frame-thick
          3.f, // shadow-off
          DEFAULT_WIDGET_FRAC,
          DEFAULT_WIDGET_ANGLE
          )
      );

      const RAR_Layout RAR_DEFAULT_LAYOUT = RAR_Layout(
        RAR_DEFAULT_CUSTOM_COLORS,
        RAR_DEFAULT_CUSTOM_TEXTS,
        RAR_DEFAULT_CUSTOM_STYLE
      );

      const RAR_Layout layout = RAR_DEFAULT_LAYOUT;

      // Maybe we can make something out of this?
      struct RAR_Style
        : public IVStyle{
        RAR_Style(bool showLabel = DEFAULT_SHOW_LABEL,
          bool showValue = DEFAULT_SHOW_VALUE,
          const std::initializer_list<IColor>& colors = {DEFAULT_BGCOLOR, DEFAULT_FGCOLOR, DEFAULT_PRCOLOR, DEFAULT_FRCOLOR, DEFAULT_HLCOLOR, DEFAULT_SHCOLOR, DEFAULT_X1COLOR, DEFAULT_X2COLOR, DEFAULT_X3COLOR},
          const IText& labelText = DEFAULT_LABEL_TEXT,
          const IText& valueText = DEFAULT_VALUE_TEXT,
          bool hideCursor = DEFAULT_HIDE_CURSOR,
          bool drawFrame = DEFAULT_DRAW_FRAME,
          bool drawShadows = DEFAULT_DRAW_SHADOWS,
          float roundness = DEFAULT_ROUNDNESS,
          float frameThickness = DEFAULT_FRAME_THICKNESS,
          float shadowOffset = DEFAULT_SHADOW_OFFSET,
          float widgetFrac = DEFAULT_WIDGET_FRAC,
          float angle = DEFAULT_WIDGET_ANGLE)
          : IVStyle(showLabel, showValue, colors, labelText, valueText, hideCursor, drawFrame, drawShadows, roundness, frameThickness, shadowOffset, widgetFrac, angle){}
      };
    }

    namespace Base{
      class RAR_RoomInfo{
      public:
        RAR_RoomInfo(float lightX = 0.f, float lightY = 0.f, float lightZ = 0.f, float plugHeight = 0.f, float plugWidth = 0.f)

        {
          Reset(lightX, lightY, lightZ);
        }
        ~RAR_RoomInfo(){};

        void Reset(float lightX = 0.f, float lightY = 0.f, float lightZ = 0.f, float plugHeight = 0.f, float plugWidth = 0.f){
          mPlugHeight = plugHeight;
          mPlugWidth = plugWidth;
          mLightX = lightX;
          mLightY = lightY;
          mLightZ = lightZ;
        }

        float GetLightPositionX(){ return mLightX; }
        float GetLightPositionY(){ return mLightY; }
        float GetLightPositionZ(){ return mLightZ; }

        float GetShadowOffsetX(float cx, float height) const{ return (cx - mLightX) * height / mLightZ; }
        float GetShadowOffsetY(float cy, float height) const{ return (cy - mLightY) * height / mLightZ; }
        IShadow GetShadowForPart(float cx, float cy, float height){
          return IShadow(EPatternType::Solid, 1.f, GetShadowOffsetX(cx, height), GetShadowOffsetY(cy, height), 0.5f, true);
        }
      private:
        float mPlugHeight;
        float mPlugWidth;
        float mLightX;
        float mLightY;
        float mLightZ;
      };

      const RAR_RoomInfo RAR_DEFAULT_ROOMINFO = RAR_RoomInfo();

      /** A base interface to be combined with IControl for vectorial controls "IVControls", in order for them to share a common style
   * If you need more flexibility, you're on your own! */
      class RAR_VectorBase
        : public IVectorBase
        , public RAR_RoomInfo{
      public:

        RAR_VectorBase(const IVStyle& style = DEFAULT_STYLE, bool labelInWidget = false, bool valueInWidget = false, RAR_RoomInfo roomInfo = RAR_DEFAULT_ROOMINFO)
          : IVectorBase(style, labelInWidget, valueInWidget)
          , RAR_RoomInfo(roomInfo){
          SetStyle(style);
        }

        IRECT GetAdjustedHandleBounds(IRECT handleBounds) const{
          if (mStyle.drawFrame)
            handleBounds.Pad(-0.5f * mStyle.frameThickness);

          if (mStyle.drawShadows)
            handleBounds.Alter(
              max(-GetShadowOffsetX(handleBounds.MW(), 10.f), 0.f),
              max(-GetShadowOffsetY(handleBounds.MH(), 10.f), 0.f),
              min(-GetShadowOffsetX(handleBounds.MW(), 10.f), 0.f),
              min(-GetShadowOffsetY(handleBounds.MH(), 10.f), 0.f)
            );

          return handleBounds;
        }

        float GetRoundedCornerRadius(const IRECT& bounds) const{
          if (bounds.W() < bounds.H())
            return mStyle.roundness * (bounds.W() / 2.f);
          else
            return mStyle.roundness * (bounds.H() / 2.f);
        }

        void DrawSplash(IGraphics& g){
          float mouseDownX, mouseDownY;
          g.GetMouseDownPoint(mouseDownX, mouseDownY);
          g.FillCircle(GetColor(kHL), mouseDownX, mouseDownY, mSplashRadius);
        }

        virtual void DrawBackGround(IGraphics& g, const IRECT& rect){
          g.FillRect(GetColor(kBG), rect);
        }

        virtual void DrawWidget(IGraphics& g){
          // no-op
        }

        virtual void DrawLabel(IGraphics& g){
          if (mLabelBounds.H() && mStyle.showLabel)
            g.DrawText(mStyle.labelText, mLabelStr.Get(), mLabelBounds);
        }

        virtual void DrawValue(IGraphics& g, bool mouseOver){
          if (mouseOver)
            g.FillRect(COLOR_TRANSLUCENT, mValueBounds);

          if (mStyle.showValue)
            g.DrawText(mStyle.valueText, mValueStr.Get(), mValueBounds);
        }

        void DrawHandle(IGraphics& g, EVShape shape, const IRECT& bounds, bool pressed, bool mouseOver){
          switch (shape){
            case EVShape::Ellipse:
              DrawPressableEllipse(g, bounds, pressed, mouseOver);
              break;
            case EVShape::Rectangle:
              DrawPressableRectangle(g, bounds, pressed, mouseOver);
              break;
            case EVShape::Triangle:
              DrawPressableTriangle(g, bounds, pressed, mouseOver, mStyle.angle);
              break;
            case EVShape::EndsRounded:
              DrawPressableRectangle(g, bounds, pressed, mouseOver, true, true, false, false);
              break;
            case EVShape::AllRounded:
              DrawPressableRectangle(g, bounds, pressed, mouseOver, true, true, true, true);
            default:
              break;
          }
        }

        void DrawPressableCircle(IGraphics& g, const IRECT& bounds, float radius, bool pressed, bool mouseOver){
          const float cx = bounds.MW(), cy = bounds.MH();

          if (!pressed && mStyle.drawShadows)
            g.FillCircle(GetColor(kSH), cx + mStyle.shadowOffset, cy + mStyle.shadowOffset, radius);

          //    if(pressed)
          //      g.DrawCircle(GetColor(kON), cx, cy, radius * 0.9f, 0, mStyle.frameThickness);
          //    else
          g.FillCircle(GetColor(kFG), cx, cy, radius);

          if (mouseOver)
            g.FillCircle(GetColor(kHL), cx, cy, radius * 0.8f);

          if (mStyle.drawFrame)
            g.DrawCircle(GetColor(kFR), cx, cy, radius, 0, mStyle.frameThickness);
        }

        void DrawPressableEllipse(IGraphics& g, const IRECT& bounds, bool pressed, bool mouseOver){
          if (!pressed && mStyle.drawShadows)
            g.FillEllipse(GetColor(kSH), bounds.GetTranslated(mStyle.shadowOffset, mStyle.shadowOffset));

          if (pressed)
            g.FillEllipse(GetColor(kON), bounds);
          else
            g.FillEllipse(GetColor(kFG), bounds);

          if (mouseOver)
            g.FillEllipse(GetColor(kHL), bounds);

          if (mStyle.drawFrame)
            g.DrawEllipse(GetColor(kFR), bounds, nullptr, mStyle.frameThickness);
        }

        /** /todo
         @param IGraphics&g /todo
         @param bounds /todo
         @param pressed /todo
         @param mouseOver /todo
         @return /todo */
        IRECT DrawPressableRectangle(IGraphics& g, const IRECT& bounds, bool pressed, bool mouseOver,
          bool roundTopLeft = true, bool roundTopRight = true, bool roundBottomLeft = true, bool roundBottomRight = true){
          IRECT handleBounds = GetAdjustedHandleBounds(bounds);
          float cR = GetRoundedCornerRadius(handleBounds);

          const float topLeftR = roundTopLeft ? cR : 0.f;
          const float topRightR = roundTopRight ? cR : 0.f;
          const float bottomLeftR = roundBottomLeft ? cR : 0.f;
          const float bottomRightR = roundBottomRight ? cR : 0.f;

          if (pressed)
            g.FillRoundRect(GetColor(kPR), handleBounds, topLeftR, topRightR, bottomLeftR, bottomRightR);
          else{
            //outer shadow
            if (mStyle.drawShadows)
              g.FillRoundRect(GetColor(kSH), handleBounds.GetTranslated(
                GetShadowOffsetX(handleBounds.L + handleBounds.W() * 0.5f, handleBounds.GetLengthOfShortestSide()),
                GetShadowOffsetY(handleBounds.T + handleBounds.H() * 0.5f, handleBounds.GetLengthOfShortestSide())),
                topLeftR, topRightR, bottomLeftR, bottomRightR);

            g.FillRoundRect(GetColor(kFG), handleBounds, topLeftR, topRightR, bottomLeftR, bottomRightR);
          }

          if (mouseOver)
            g.FillRoundRect(GetColor(kHL), handleBounds, topLeftR, topRightR, bottomLeftR, bottomRightR);

          if (mControl->GetAnimationFunction())
            DrawSplash(g);

          if (mStyle.drawFrame)
            g.DrawRoundRect(GetColor(kFR), handleBounds, topLeftR, topRightR, bottomLeftR, bottomRightR, 0, mStyle.frameThickness);

          return handleBounds;
        }

        /** Draw a triangle-shaped vector button
         * @param g The IGraphics context used for drawing
         * @param bounds Where to draw the button
         * @param pressed Whether to draw the button pressed or unpressed
         * @param mouseOver Whether mouse is currently hovering on control */
        IRECT DrawPressableTriangle(IGraphics& g, const IRECT& bounds, bool pressed, bool mouseOver, float angle){
          float x1, x2, x3, y1, y2, y3;

          float theta = DegToRad(angle);

          IRECT handleBounds = GetAdjustedHandleBounds(bounds);

          // Center bounds around origin for rotation
          float xT = handleBounds.L + handleBounds.W() * 0.5f;
          float yT = handleBounds.T + handleBounds.H() * 0.5f;
          IRECT centered = handleBounds.GetTranslated(-xT, -yT);

          // Do rotation and translate points back into view space
          float c = cosf(theta);
          float s = sinf(theta);
          x1 = centered.L * c - centered.B * s + xT;
          y1 = centered.L * s + centered.B * c + yT;
          x2 = centered.MW() * c - centered.T * s + xT;
          y2 = centered.MW() * s + centered.T * c + yT;
          x3 = centered.R * c - centered.B * s + xT;
          y3 = centered.R * s + centered.B * c + yT;

          if (pressed)
            g.FillTriangle(GetColor(kPR), x1, y1, x2, y2, x3, y3);
          else{
            //outer shadow
            if (mStyle.drawShadows)
              g.FillTriangle(GetColor(kSH), x1 + mStyle.shadowOffset, y1 + mStyle.shadowOffset, x2 + mStyle.shadowOffset, y2 + mStyle.shadowOffset, x3 + mStyle.shadowOffset, y3 + mStyle.shadowOffset);

            g.FillTriangle(GetColor(kFG), x1, y1, x2, y2, x3, y3);
          }

          if (mouseOver)
            g.FillTriangle(GetColor(kHL), x1, y1, x2, y2, x3, y3);

          if (mControl->GetAnimationFunction())
            DrawSplash(g);

          if (mStyle.drawFrame)
            g.DrawTriangle(GetColor(kFR), x1, y1, x2, y2, x3, y3, 0, mStyle.frameThickness);

          return handleBounds;
        }

        // MAKERECTS
        // ---------

        IRECT MakeRects(const IRECT& parent, bool hasHandle = false){
          IRECT clickableArea = parent;

          // Hannes:
          bool labelValueSame = false;
          if (mStyle.labelText.mVAlign == mStyle.valueText.mVAlign){
            labelValueSame = true;
          }

          if (!mLabelInWidget){
            if (mStyle.showLabel && CStringHasContents(mLabelStr.Get())){
              IRECT textRect;
              mControl->GetUI()->MeasureText(mStyle.labelText, mLabelStr.Get(), textRect);

              if (mStyle.labelText.mVAlign == EVAlign::Bottom){
                mLabelBounds = parent.GetFromBottom(textRect.H());
                clickableArea = parent.GetReducedFromBottom(mLabelBounds.H());
              } else{
                mLabelBounds = parent.GetFromTop(textRect.H());
                clickableArea = parent.GetReducedFromTop(mLabelBounds.H());
              }
            } else
              mLabelBounds = IRECT();
          }

          if (mStyle.showValue && !mValueInWidget){
            IRECT textRect;
            if (CStringHasContents(mValueStr.Get()))
              mControl->GetUI()->MeasureText(mStyle.valueText, mValueStr.Get(), textRect);

            const float valueDisplayWidth = textRect.W() * 0.5f;

            switch (mStyle.valueText.mVAlign){
              case EVAlign::Middle:
                mValueBounds = clickableArea.GetMidVPadded(textRect.H() / 2.f).GetMidHPadded(valueDisplayWidth);
                mWidgetBounds = clickableArea.GetScaledAboutCentre(mStyle.widgetFrac);
                break;
              case EVAlign::Bottom:
              {
                mValueBounds = clickableArea.GetFromBottom(textRect.H()).GetMidHPadded(valueDisplayWidth);
                mWidgetBounds = clickableArea.GetReducedFromBottom(textRect.H()).GetScaledAboutCentre(mStyle.widgetFrac);
                break;
              }
              case EVAlign::Top:
                mValueBounds = clickableArea.GetFromTop(textRect.H()).GetMidHPadded(valueDisplayWidth);
                mWidgetBounds = clickableArea.GetReducedFromTop(textRect.H()).GetScaledAboutCentre(mStyle.widgetFrac);
                break;
              default:
                break;
            }
          } else{
            mWidgetBounds = clickableArea.GetScaledAboutCentre(mStyle.widgetFrac);
          }

          if (hasHandle)
            mWidgetBounds = GetAdjustedHandleBounds(clickableArea).GetScaledAboutCentre(mStyle.widgetFrac);

          if (mLabelInWidget)
            mLabelBounds = mWidgetBounds;

          if (mValueInWidget)
            mValueBounds = mWidgetBounds;

          return clickableArea;
        }

      protected:
        //  IControl* mControl = nullptr;
        //  WDL_TypedBuf<IColor> mColors;
        //  IVStyle mStyle;
        //  bool mLabelInWidget = false;
        //  bool mValueInWidget = false;
        //  float mSplashRadius = 0.f;
        //  float mMaxSplashRadius = 50.f;
        //  IRECT mWidgetBounds; // The knob/slider/button
        //  IRECT mLabelBounds; // A piece of text above the control
        //  IRECT mValueBounds; // Text below the contol, usually displaying the value of a parameter
        //  WDL_String mLabelStr;
        //  WDL_String mValueStr;

        //  // Hannes:
          //RAR_RoomInfo mRoomInfo;
      };
    } //end namespace Base

    namespace Controls{
      // --------------------------------------------------------------------------------
      // KNOB PARTS
      // --------------------------------------------------------------------------------

      class RAR_KnobParts{
      public:
        enum EKnobParts{
          kLabelring = 0,
          kFrame,
          kHandle,
          kNumKnobParts
        };

        enum EKnobTypes{
          kSolid = 0,
          kChicken,
          kTec,
          kMoog,
          kNumKnobTypes
        };

        RAR_KnobParts(EKnobParts knobpart, EKnobTypes knobtype, float cx = 0.f, float cy = 0.f, float r = 50.f, float lightOffsetX = 0.f, float lightOffsetY = 0.f){
          SetProperties(knobpart, knobtype, cx, cy, r, lightOffsetX, lightOffsetY);
        }

        ~RAR_KnobParts(){}

        void SetProperties(EKnobParts knobpart, EKnobTypes knobtype, float cx, float cy, float r, float lightOffsetX, float lightOffsetY){
          mKnobtype = knobtype;
          mKnobpart = knobpart;
          mCx = cx;
          mCy = cy;
          mR = r;
          mLightOffsetX = lightOffsetX;
          mLightOffsetY = lightOffsetY;
        }

        void DrawPart(IGraphics& g){}

        struct Label{
          IColor mTextColor = DEFAULT_TEXT_FGCOLOR;
        } mLabel;

        struct Frame{
          IPattern mPattern = IPattern(DEFAULT_FRCOLOR);
        } mFrame;

        struct Handle{
          IPattern mPattern = IPattern(DEFAULT_FGCOLOR);
        } mHandle;

      protected:

      private:
        EKnobParts mKnobpart = EKnobParts::kFrame;
        EKnobTypes mKnobtype = EKnobTypes::kSolid;
        float mCx = 0.f;
        float mCy = 0.f;
        float mR = 50.f;
        float mLightOffsetX = 0.f;
        float mLightOffsetY = 0.f;
      };

      // --------------------------------------------------------------------------------
      // KNOB
      // --------------------------------------------------------------------------------

      /** A vector knob control drawn using graphics primitves */

      class RAR_VectorKnob
        : public IKnobControlBase
        , public RAR::Graphics::Base::RAR_VectorBase{
      public:
        RAR_VectorKnob(const IRECT& bounds, int paramIdx,
          const char* label = "",
          const IVStyle& style = DEFAULT_STYLE, Base::RAR_RoomInfo& lightInfo = Base::RAR_RoomInfo(), const IColor& uniqueColor = DEFAULT_FGCOLOR,
          bool valueIsEditable = false, bool valueInWidget = false,
          float aMin = -135.f, float aMax = 135.f, float aAnchor = -135.f,
          EDirection direction = EDirection::Vertical, double gearing = DEFAULT_GEARING);

        RAR_VectorKnob(const IRECT& bounds, IActionFunction actionFunction,
          const char* label = "",
          const IVStyle& style = DEFAULT_STYLE, Base::RAR_RoomInfo& lightInfo = Base::RAR_RoomInfo(), const IColor& uniqueColor = DEFAULT_FGCOLOR,
          bool valueIsEditable = false, bool valueInWidget = false,
          float aMin = -135.f, float aMax = 135.f, float aAnchor = -135.f,
          EDirection direction = EDirection::Vertical, double gearing = DEFAULT_GEARING);

        virtual ~RAR_VectorKnob(){}

        void Draw(IGraphics& g) override;
        virtual void DrawWidget(IGraphics& g) override;
        virtual void DrawLabel(IGraphics& g) override;
        virtual void DrawValue(IGraphics& g, bool mouseOver) override;

        void OnMouseDown(float x, float y, const IMouseMod& mod) override;
        void OnMouseUp(float x, float y, const IMouseMod& mod) override;
        void OnMouseOver(float x, float y, const IMouseMod& mod) override;
        void OnMouseOut() override{ mValueMouseOver = false; IKnobControlBase::OnMouseOut(); }

        //  void OnMouseDblClick(float x, float y, const IMouseMod& mod) override {  OnMouseDown(x, y, mod); }
        void OnResize() override;
        bool IsHit(float x, float y) const override;
        void SetDirty(bool push, int valIdx = kNoValIdx) override;
        void OnInit() override;
        //void DrawPressableCircle(IGraphics&g, const IRECT& bounds, float radius, bool pressed, bool mouseOver);

      protected:
        IColor mUniqueColor;
        float mAngleMin, mAngleMax;
        float mAnchorAngle; // for bipolar arc
        bool mValueMouseOver = false;
      };

      RAR_VectorKnob::RAR_VectorKnob(const IRECT& bounds, int paramIdx, const char* label, const IVStyle& style, Base::RAR_RoomInfo& lightInfo,
        const IColor& uniqueColor, bool valueIsEditable, bool valueInWidget, float aMin, float aMax, float aAnchor, EDirection direction,
        double gearing)
        : IKnobControlBase(bounds, paramIdx, direction, gearing)
        , RAR_VectorBase(style, false, valueInWidget, lightInfo)
        , mAngleMin(aMin)
        , mAngleMax(aMax)
        , mAnchorAngle(aAnchor)
        , mUniqueColor(uniqueColor){
        DisablePrompt(!valueIsEditable);
        mText = style.valueText;
        AttachIControl(this, label);
      }

      RAR_VectorKnob::RAR_VectorKnob(const IRECT& bounds, IActionFunction actionFunc, const char* label, const IVStyle& style, Base::RAR_RoomInfo& lightInfo, const IColor& uniqueColor, bool valueIsEditable, bool valueInWidget, float aMin, float aMax, float aAnchor, EDirection direction, double gearing)
        : IKnobControlBase(bounds, kNoParameter, direction, gearing)
        , RAR_VectorBase(style, false, valueInWidget, lightInfo)
        , mAngleMin(aMin)
        , mAngleMax(aMax)
        , mAnchorAngle(aAnchor)
        , mUniqueColor(uniqueColor){
        DisablePrompt(!valueIsEditable);
        mText = style.valueText;
        SetActionFunction(actionFunc);
        AttachIControl(this, label);
      }

      void RAR_VectorKnob::Draw(IGraphics& g){
        DrawBackGround(g, mRECT);
        DrawLabel(g);
        DrawWidget(g);
        DrawValue(g, mValueMouseOver);
      }

      void RAR_VectorKnob::DrawWidget(IGraphics& g){
        const float radius = (mWidgetBounds.W() > mWidgetBounds.H())
          ? (mWidgetBounds.H() / 2.f) * 0.8f
          : (mWidgetBounds.W() / 2.f) * 0.8f;
        const float cx = mWidgetBounds.MW(), cy = mWidgetBounds.MH();
        const IRECT knobRect = {cx - radius, cy - radius, cx + radius, cy + radius};
        const float shadowOffsetX = GetShadowOffsetX(cx, radius);
        const float shadowOffsetY = GetShadowOffsetY(cy, radius);
        const float frameThickness = radius * 0.1 * mStyle.frameThickness;
        const float arrowThickness = frameThickness * 0.5f;

        if (!IsDisabled()){
          // TODO: constants!
          const float v = mAngleMin + ((float)GetValue() * (mAngleMax - mAngleMin));

          // FRAME
          if (mStyle.drawFrame){
            // FRAME SHADOW
            if (mStyle.drawShadows)
              g.FillEllipse(
                GetColor(kSH),
                knobRect.GetPadded(0.5f * frameThickness).GetPadded(
                  max(-shadowOffsetX, 0.f),
                  max(-shadowOffsetY, 0.f),
                  max(shadowOffsetX, 0.f),
                  max(shadowOffsetY, 0.f)
                )
              );

            g.DrawCircle((!mMouseDown) ? GetColor(kFR) : GetColor(kX1), cx, cy, radius, 0, frameThickness);
          }

          // ARC
          g.DrawArc(mUniqueColor, cx, cy, (radius)+3.f, v >= mAnchorAngle ? mAnchorAngle : mAnchorAngle - (mAnchorAngle - v), v >= mAnchorAngle ? v : mAnchorAngle, 0, 2.f);

          // WIDGET

          // SHADOW
          if (mStyle.drawShadows)
            g.FillEllipse(
              GetColor(kSH),
              knobRect.GetPadded(
                max(-shadowOffsetX * 0.3f, 0.f),
                max(-shadowOffsetY * 0.3f, 0.f),
                max(shadowOffsetX * 0.3f, 0.f),
                max(shadowOffsetY * 0.3f, 0.f)
              )
            );

          // KNOB
          g.FillCircle(mUniqueColor, cx, cy, radius);

          // INNER RING
          g.DrawCircle(GetColor(kHL), cx, cy, radius * 0.9f);

          // ARROW
          if (mStyle.drawShadows)
            g.DrawRadialLine(GetColor(kSH), cx + shadowOffsetX * 0.1f, cy + shadowOffsetY * 0.1f, v, 0.0f, radius, 0, arrowThickness >= 1.f ? arrowThickness : 1.f);
          g.DrawRadialLine(GetColor(kFR), cx, cy, v, 0.0f, radius, 0, arrowThickness >= 1.f ? arrowThickness : 1.f);

          // LIGHTPATTERN, Should be optimized
          const IPattern patternLight = IPattern::CreateRadialGradient(
            cx - shadowOffsetX,
            cy - shadowOffsetY,
            radius,
            {
              IColorStop(IColor(200, 255, 200, 200), 0.1f),
              IColorStop(COLOR_TRANSLUCENT, 0.9f)
            }
          );
          g.PathCircle(cx, cy, radius);
          g.PathFill(patternLight);

          // MOUSEOVER
          if (mMouseIsOver & !mValueMouseOver)
            g.FillCircle(GetColor(kHL), cx, cy, radius);
        } else{
          // GRAYED
          g.FillCircle(GetColor(kOFF), cx, cy, radius);
        }
      }

      void RAR_VectorKnob::DrawLabel(IGraphics& g){
        if (mLabelBounds.H() && mStyle.showLabel)
          g.DrawText(mStyle.labelText, mLabelStr.Get(), mLabelBounds);
      }

      void RAR_VectorKnob::DrawValue(IGraphics& g, bool mouseOver){
        if (mouseOver)
          g.FillRect(COLOR_TRANSLUCENT, mValueBounds);

        if (mStyle.showValue)
          g.DrawText(mStyle.valueText, mValueStr.Get(), mValueBounds);
      }

      void RAR_VectorKnob::OnMouseDown(float x, float y, const IMouseMod& mod){
        if (mStyle.showValue && mValueBounds.Contains(x, y)){
          PromptUserInput(mValueBounds);
        } else{
          if (mStyle.hideCursor)
            GetUI()->HideMouseCursor(true, true);

          IKnobControlBase::OnMouseDown(x, y, mod);
        }
      }

      void RAR_VectorKnob::OnMouseUp(float x, float y, const IMouseMod& mod){
        if (mStyle.hideCursor)
          GetUI()->HideMouseCursor(false);

        IKnobControlBase::OnMouseUp(x, y, mod);

        SetDirty(true);
      }

      void RAR_VectorKnob::OnMouseOver(float x, float y, const IMouseMod& mod){
        if (mStyle.showValue && !mDisablePrompt)
          mValueMouseOver = mValueBounds.Contains(x, y);

        IKnobControlBase::OnMouseOver(x, y, mod);
      }

      void RAR_VectorKnob::OnResize(){
        SetTargetRECT(MakeRects(mRECT));
        SetDirty(false);
      }

      bool RAR_VectorKnob::IsHit(float x, float y) const{
        if (!mDisablePrompt){
          if (mValueBounds.Contains(x, y))
            return true;
        }

        return mWidgetBounds.Contains(x, y);
      }

      void RAR_VectorKnob::SetDirty(bool push, int valIdx){
        IKnobControlBase::SetDirty(push);

        const IParam* pParam = GetParam();

        if (pParam)
          pParam->GetDisplayForHostWithLabel(mValueStr);
      }

      void RAR_VectorKnob::OnInit(){
        const IParam* pParam = GetParam();

        if (pParam){
          pParam->GetDisplayForHostWithLabel(mValueStr);

          if (!mLabelStr.GetLength())
            mLabelStr.Set(pParam->GetNameForHost());
        }
      }

      class RAR_VectorSwitch
        : public ISwitchControlBase
        , public Base::RAR_VectorBase{
      public:
        RAR_VectorSwitch(const IRECT& bounds, int paramIdx = kNoParameter, const char* label = "", const IVStyle& style = DEFAULT_STYLE, Base::RAR_RoomInfo& roomInfo = Base::RAR_RoomInfo(), bool valueInButton = true);

        RAR_VectorSwitch(const IRECT& bounds, IActionFunction actionFunc = SplashClickActionFunc, const char* label = "", const IVStyle& style = DEFAULT_STYLE, Base::RAR_RoomInfo& roomInfo = Base::RAR_RoomInfo(), int numStates = 2, bool valueInButton = true);

        void Draw(IGraphics& g) override;
        virtual void DrawWidget(IGraphics& g) override;
        bool IsHit(float x, float y) const override;
        void SetDirty(bool push, int valIdx = kNoValIdx) override;
        void OnResize() override;
        void OnInit() override;
      };

      RAR_VectorSwitch::RAR_VectorSwitch(const IRECT& bounds, int paramIdx, const char* label, const IVStyle& style, Base::RAR_RoomInfo& roomInfo, bool valueInButton)
        : ISwitchControlBase(bounds, paramIdx, DefaultClickActionFunc)
        , RAR_VectorBase(style, false, valueInButton, roomInfo){
        AttachIControl(this, label);
        mText = style.valueText;

        if (valueInButton)
          mText.mVAlign = mStyle.valueText.mVAlign = EVAlign::Middle;

        mDblAsSingleClick = true;
      }

      RAR_VectorSwitch::RAR_VectorSwitch(const IRECT& bounds, IActionFunction actionFunc, const char* label, const IVStyle& style, Base::RAR_RoomInfo& roomInfo, int numStates, bool valueInButton)
        : ISwitchControlBase(bounds, kNoParameter, actionFunc, numStates)
        , RAR_VectorBase(style, false, valueInButton, roomInfo){
        AttachIControl(this, label);
        mText = style.valueText;

        if (valueInButton)
          mText.mVAlign = mStyle.valueText.mVAlign = EVAlign::Middle;

        mDblAsSingleClick = true;
      }

      void RAR_VectorSwitch::Draw(IGraphics& g){
        DrawBackGround(g, mRECT);
        DrawWidget(g);
        DrawLabel(g);
        DrawValue(g, false);
      }

      void RAR_VectorSwitch::DrawWidget(IGraphics& g){
        DrawPressableRectangle(g, mWidgetBounds, mMouseDown, mMouseIsOver);
      }

      void RAR_VectorSwitch::SetDirty(bool push, int valIdx){
        IControl::SetDirty(push);

        const IParam* pParam = GetParam();

        if (pParam)
          pParam->GetDisplayForHost(mValueStr);
      }

      void RAR_VectorSwitch::OnResize(){
        SetTargetRECT(MakeRects(mRECT, true));
        SetDirty(false);
      }

      bool RAR_VectorSwitch::IsHit(float x, float y) const{
        return mWidgetBounds.Contains(x, y);
      }

      void RAR_VectorSwitch::OnInit(){
        ISwitchControlBase::OnInit();

        const IParam* pParam = GetParam();

        if (pParam){
          pParam->GetDisplayForHostWithLabel(mValueStr);

          if (!mLabelStr.GetLength())
            mLabelStr.Set(pParam->GetNameForHost());
        }
      }

      /** A vector toggle control. Click to cycle through two states. */
      class RAR_VectorToggle
        : public RAR_VectorSwitch{
      public:
        RAR_VectorToggle(const IRECT& bounds, int paramIdx = kNoParameter, const char* label = "", const IVStyle& style = DEFAULT_STYLE, Base::RAR_RoomInfo& roomInfo = Base::RAR_RoomInfo(), const char* offText = "OFF", const char* onText = "ON");

        RAR_VectorToggle(const IRECT& bounds, IActionFunction actionFunc = SplashClickActionFunc, const char* label = "", const IVStyle& style = DEFAULT_STYLE, Base::RAR_RoomInfo& roomInfo = Base::RAR_RoomInfo(), const char* offText = "OFF", const char* onText = "ON", bool initialState = false);

        void DrawValue(IGraphics& g, bool mouseOver) override;
        void DrawWidget(IGraphics& g) override;
      protected:
        WDL_String mOffText;
        WDL_String mOnText;
      };

      RAR_VectorToggle::RAR_VectorToggle(const IRECT& bounds, int paramIdx, const char* label, const IVStyle& style, Base::RAR_RoomInfo& roomInfo, const char* offText, const char* onText)
        : RAR_VectorSwitch(bounds, paramIdx, label, style, roomInfo, true)
        , mOnText(onText)
        , mOffText(offText){
        //TODO: assert boolean?
      }

      RAR_VectorToggle::RAR_VectorToggle(const IRECT& bounds, IActionFunction actionFunc, const char* label, const IVStyle& style, Base::RAR_RoomInfo& roomInfo, const char* offText, const char* onText, bool initialState)
        : RAR_VectorSwitch(bounds, actionFunc, label, style, roomInfo, 2, true)
        , mOnText(onText)
        , mOffText(offText){
        SetValue((double)initialState);
      }

      void RAR_VectorToggle::DrawWidget(IGraphics& g){
        DrawPressableRectangle(g, mWidgetBounds, GetValue() > 0.5, mMouseIsOver);
      }

      void RAR_VectorToggle::DrawValue(IGraphics& g, bool mouseOver){
        if (mouseOver)
          g.FillRect(COLOR_TRANSLUCENT, mValueBounds);

        if (GetValue() > 0.5)
          g.DrawText(mStyle.valueText, mOnText.Get(), mValueBounds);
        else
          g.DrawText(mStyle.valueText, mOffText.Get(), mValueBounds);
      }

      /** A basic control to display some text */
      class RAR_Logo
        : public IControl{
      public:
        RAR_Logo(IRECT bounds, const char* str = "", const IText& text = DEFAULT_TEXT, const IColor& BGColor = DEFAULT_BGCOLOR)
          : IControl(bounds)
          , mStr(str)
          , mBGColor(BGColor){
          mIgnoreMouse = true;
          IControl::mText = text;
        }

        void Draw(IGraphics& g) override{
          g.FillRect(mBGColor, mRECT);

          if (mStr.GetLength())
            g.DrawText(mText, mStr.Get(), mRECT);
        }

        virtual void SetStr(const char* str){
          if (strcmp(mStr.Get(), str)){
            mStr.Set(str);
            SetDirty(false);
          }
        }
        virtual void SetStrFmt(int maxlen, const char* fmt, ...){
          va_list arglist;
          va_start(arglist, fmt);
          mStr.SetAppendFormattedArgs(false, maxlen, fmt, arglist);
          va_end(arglist);
          SetDirty(false);
        }
        virtual void ClearStr(){ SetStr(""); }

      protected:
        WDL_String mStr;
        IColor mBGColor;
      };

      /** A base class for mult-strip/track controls, such as multi-sliders, meters */
      class RAR_TrackControlBase
        : public IControl
        , public Base::RAR_VectorBase{
      public:
        RAR_TrackControlBase(IRECT bounds, int maxNTracks = 1, float minTrackValue = 0.f, float maxTrackValue = 1.f, const char* trackNames = 0, ...)
          : IControl(bounds)
          , mMaxNTracks(maxNTracks)
          , mMinTrackValue(minTrackValue)
          , mMaxTrackValue(maxTrackValue){
          for (int i = 0; i < maxNTracks; i++){
            mTrackData.Add(0.f);
            mTrackBounds.Add(IRECT());
          }

          AttachIControl(this, ""); // TODO: Should hand label
        }

        void MakeRects(){
          for (int ch = 0; ch < MaxNTracks(); ch++){
            mTrackBounds.Get()[ch] = mRECT.GetPadded(-mOuterPadding).
              SubRect(EDirection(!(bool)mDirection), MaxNTracks(), ch).
              GetPadded(0, -mTrackPadding * (float)mDirection, -mTrackPadding * (float)!(bool)mDirection, -mTrackPadding);
          }
        }

        void Draw(IGraphics& g) override{
          g.FillRect(GetColor(kBG), mRECT);

          for (int ch = 0; ch < MaxNTracks(); ch++){
            DrawTrack(g, mTrackBounds.Get()[ch], ch);
          }

          if (mStyle.drawFrame)
            DrawFrame(g);
        }

        int NTracks(){ return mNTracks; }
        int MaxNTracks(){ return mMaxNTracks; }
        void SetTrackData(int trackIdx, float val){ mTrackData.Get()[trackIdx] = Clip(val, mMinTrackValue, mMaxTrackValue); }
        float* GetTrackData(int trackIdx){ return &mTrackData.Get()[trackIdx]; }
        void SetAllTrackData(float val){ memset(mTrackData.Get(), (int)Clip(val, mMinTrackValue, mMaxTrackValue), mTrackData.GetSize() * sizeof(float)); }
      private:
        virtual void DrawFrame(IGraphics& g){
          g.DrawRect(GetColor(kFR), mRECT, nullptr, mStyle.frameThickness);
        }

        virtual void DrawTrack(IGraphics& g, IRECT& r, int chIdx){
          DrawTrackBG(g, r, chIdx);
          DrawTrackHandle(g, r, chIdx);

          if (mDrawTrackFrame)
            g.DrawRect(GetColor(kFR), r, nullptr, mStyle.frameThickness);
        }

        virtual void DrawTrackBG(IGraphics& g, IRECT& r, int chIdx){
          g.FillRect(GetColor(kSH), r);
        }

        virtual void DrawTrackHandle(IGraphics& g, IRECT& r, int chIdx){
          IRECT fillRect = r.FracRect(mDirection, *GetTrackData(chIdx));

          g.FillRect(GetColor(kFG), fillRect); // TODO: shadows!

          IRECT peakRect;

          if (mDirection == EDirection::Vertical)
            peakRect = IRECT(fillRect.L, fillRect.T, fillRect.R, fillRect.T + mPeakSize);
          else
            peakRect = IRECT(fillRect.R - mPeakSize, fillRect.T, fillRect.R, fillRect.B);

          DrawPeak(g, peakRect, chIdx);
        }

        virtual void DrawPeak(IGraphics& g, IRECT& r, int chIdx){
          g.FillRect(GetColor(kHL), r);
        }

        void OnResize() override{
          MakeRects();
        }

      protected:

        EDirection mDirection = EDirection::Vertical;
        int mMaxNTracks;
        WDL_TypedBuf<float> mTrackData; // real values of sliders/meters
        WDL_TypedBuf<IRECT> mTrackBounds;

        int mNTracks = 1;

        float mMinTrackValue;
        float mMaxTrackValue;
        float mOuterPadding = 10.;
        float mTrackPadding = 2;
        float mPeakSize = 5.;
        bool mDrawTrackFrame = true;
      };

      // End TrackControl class

      // METER CLASS
      // ------------

      template <int MAXNC = 1, int QUEUE_SIZE = 1024>
      class RAR_Meter
        : public RAR_TrackControlBase{
      public:

        static constexpr int kUpdateMessage = 0;

        /** Data packet */
        struct Data{
          int nchans = MAXNC;
          float vals[MAXNC] = {};
          bool AboveThreshold(){
            static const float threshold = (float)DBToAmp(-90.);
            float sum = 0.f;
            for (int i = 0; i < MAXNC; i++){
              sum += vals[i];
            }
            return std::abs(sum) > threshold;
          }
        };

        /** Used on the DSP side in order to queue sample values and transfer data to low priority thread. */
        class RAR_MeterBallistics{
        public:
          RAR_MeterBallistics(int controlTag)
            : mControlTag(controlTag){}

          void ProcessBlock(sample** inputs, int nFrames){
            Data d;

            for (auto s = 0; s < nFrames; s++){
              for (auto c = 0; c < MAXNC; c++){
                d.vals[c] += std::fabs((float)inputs[c][s]);
              }
            }

            for (auto c = 0; c < MAXNC; c++){
              d.vals[c] /= (float)nFrames;
            }

            if (mPrevAboveThreshold)
              mQueue.Push(d); // TODO: expensive?

            mPrevAboveThreshold = d.AboveThreshold();
          }

          // this must be called on the main thread - typically in MyPlugin::OnIdle()
          void TransmitData(IEditorDelegate& dlg){
            while (mQueue.ElementsAvailable()){
              Data d;
              mQueue.Pop(d);
              dlg.SendControlMsgFromDelegate(mControlTag, kUpdateMessage, sizeof(Data), (void*)&d);
            }
          }

        private:
          int mControlTag;
          bool mPrevAboveThreshold = true;
          IPlugQueue<Data> mQueue{QUEUE_SIZE};
        };

        struct LabelFrames{
          IRECT rectLabel = IRECT();
          WDL_String str = WDL_String();
          void SetLabelFrame(IRECT r, float val){
            str.SetFormatted(MAX_PARAM_DISPLAY_LEN, "%d", static_cast<int>(roundf(val)));
            rectLabel = r;
          }
        };

        struct LinePos{
          float position = 0.0f;
          float thickness = 1.0f;
          void SetLine(float pos, float thick){
            position = pos;
            thickness = thick;
          }
        };

        // If you want to create a meter with decibel values
        RAR_Meter(IRECT bounds, bool drawFromTop = false, bool drawInverted = false, float minDb = 90., float maxDb = 0., float shape = 1.0, int markStep = 1, int labelStep = 6, const char* trackNames = 0, ...)
          : RAR_TrackControlBase(bounds, MAXNC, DBToAmp(minDb), DBToAmp(maxDb), trackNames)
          , mDrawFromTop(drawFromTop)
          , mDrawInverted(drawInverted)
          , mMinDb(minDb)
          , mMaxDb(maxDb)
          , mShape(shape)
          , mMaxTrackValue(4.f)
          , mMarkStep(markStep)
          , mLabelStep(labelStep)
          , mText(14.f, COLOR_LIGHT_GRAY, DEFAULT_FONT, EAlign::Center, EVAlign::Middle, 0.f)
          , mNumLines(int(maxDb - minDb))
          , mNumLabels(int((maxDb - minDb) / labelStep))
          , rectLabelFrame(IRECT())
          //, mPattern(kLinearPattern)
          , mDrawDb(true){
          mLabelFrames = new LabelFrames[mNumLabels + 1];
          mLineCoord = new LinePos[mNumLines + 1];
        }

        // If you want to create a meter with normalized values 0..1
        RAR_Meter(IRECT bounds, bool drawFromTop = false, bool drawInverted = false, const char* trackNames = 0, ...)
          : IVTrackControlBase(bounds, MAXNC, 0, 1., trackNames)
          , mDrawFromTop(drawFromTop)
          , mDrawInverted(drawInverted)
          , mText(14.f, COLOR_LIGHT_GRAY, DEFAULT_FONT, EAlign::Center, EVAlign::Middle, 0.f)
          //, mPattern(kLinearPattern)
          , mDrawDb(false){}

        void OnResize() override{
          MakeRects();
          mText.mSize = max(12.f, min(mRECT.W() * 0.25f, mRECT.H() / mNumLabels));
        };

        //  void OnMouseDblClick(float x, float y, const IMouseMod& mod) override;
        //  void OnMouseDown(float x, float y, const IMouseMod& mod) override;

        void MakeRects(){
          for (int ch = 0; ch < MaxNTracks(); ch++){
            mTrackBounds.Get()[ch] = mRECT.GetPadded(-mOuterPadding).
              SubRect(EDirection::Horizontal, MaxNTracks(), ch).
              GetPadded(0, -mTrackPadding, -mTrackPadding * (float)EDirection::Horizontal, -mTrackPadding * (float)EDirection::Vertical);
          }

          if (mDrawDb){
            rectLabelFrame = mRECT.GetPadded(-mOuterPadding);

            for (int i = 0, j = 0; i <= mNumLines; i++){
              const float val = std::roundf(mMinDb + ((float)i / (float)mNumLines) * (mMaxDb - mMinDb));
              const float vPosition = std::pow<float>((val - mMinDb) / (mMaxDb - mMinDb), 1.0f / mShape);
              mLineCoord[i].SetLine(rectLabelFrame.B - rectLabelFrame.H() * vPosition, 1.f);
              if (i % mLabelStep == 0){
                mLineCoord[i].thickness = mStyle.frameThickness;
                mLabelFrames[j].SetLabelFrame(
                  IRECT(rectLabelFrame.L, -mText.mSize + rectLabelFrame.B - vPosition * rectLabelFrame.H(), rectLabelFrame.R, mText.mSize + rectLabelFrame.B - vPosition * rectLabelFrame.H()),
                  val
                );
                j++;
              }
            }
          }
        }

        void Draw(IGraphics& g) override{
          // Don't want to fill with transparent IColor
          // g.FillRect(GetColor(kBG), mRECT);

          for (int ch = 0; ch < MaxNTracks(); ch++){
            DrawTrack(g, mTrackBounds.Get()[ch], ch);
          }

          // Don't want to draw a Frame
          //if (mDrawFrame)
          //  DrawFrame(g);

          if (mDrawDb){
            for (int i = 0; i <= mNumLabels; i++){
              g.DrawText(mText, mLabelFrames[i].str.Get(), mLabelFrames[i].rectLabel);
            }
            for (int i = 0; i <= mNumLines; i++){
              g.DrawLine(GetColor(kHL), rectLabelFrame.L, mLineCoord[i].position, rectLabelFrame.R, mLineCoord[i].position, 0, mLineCoord[i].thickness);
            }
          }
        }

        //virtual void DrawFrame(IGraphics& g)
        //{
        //  //g.DrawRect(GetColor(kFR), mRECT, nullptr, mFrameThickness);
        //}

        virtual void DrawTrack(IGraphics& g, IRECT& r, int chIdx){
          DrawTrackBG(g, r, chIdx);
          DrawTrackHandle(g, r, chIdx);
          //if (mDrawTrackFrame)
          //  g.DrawRect(GetColor(kBG), r, nullptr, mFrameThickness);
        }

        virtual void DrawTrackBG(IGraphics& g, IRECT& r, int chIdx){
          g.FillRect(GetColor(kHL), r);
        }

        virtual void DrawTrackHandle(IGraphics& g, IRECT& r, int chIdx){
          IRECT fillRect;
          float value = *GetTrackData(chIdx);
          if (mDrawDb) value = std::pow<float>(((float)AmpToDB(value) - mMinDb) / (mMaxDb - mMinDb), 1.0f / mShape);
          fillRect = r.FracRect(mDirection, (!mDrawInverted) ? value : 1.f - value, mDrawFromTop); // HERE the value rect is drawn!
          g.FillRect(GetColor(kFG), fillRect); // TODO: shadows!

          IRECT peakRect;
          if (mDirection == EDirection::Vertical)
            peakRect = (!mDrawFromTop) ? fillRect.GetFromTop(mPeakSize) : fillRect.GetFromBottom(mPeakSize);
          else
            peakRect = (!mDrawFromTop) ? fillRect.GetFromRight(mPeakSize) : fillRect.GetFromLeft(mPeakSize);
          DrawPeak(g, peakRect, chIdx);
        }

        virtual void DrawPeak(IGraphics& g, IRECT& r, int chIdx){
          g.FillRect(GetColor(kX1), r);
        }

        void OnMsgFromDelegate(int messageTag, int dataSize, const void* pData) override{
          IByteStream stream(pData, dataSize);

          int pos = 0;
          Data data;
          pos = stream.Get(&data.nchans, pos);

          while (pos < stream.Size()){
            for (auto i = 0; i < data.nchans; i++){
              pos = stream.Get(&data.vals[i], pos);
              float* pVal = GetTrackData(i);
              *pVal = Clip(data.vals[i], 0.f, 1.f);
            }
          }

          SetDirty(false);
        }

      protected:
        bool mDrawFromTop;
        bool mDrawInverted;
        bool mDrawDb;
        float mMinDb;
        float mMaxDb;
        float mMaxTrackValue;
        int mLabelStep;
        int mMarkStep;
        int mNumLabels;
        int mNumLines;
        float mShape;
        IText mText;
        LabelFrames* mLabelFrames;
        LinePos* mLineCoord;
        IRECT rectLabelFrame;
        //IPattern mPattern;
      };

      /** A basic control to fill a rectangle with a color or gradient */
      class RAR_Panel
        : public IControl{
      public:
        RAR_Panel(IRECT bounds, const IColor& color, bool drawFrame = false)
          : IControl(bounds, kNoParameter)
          , mPattern(color)
          , mDrawFrame(drawFrame){
          mIgnoreMouse = true;
        }

        RAR_Panel(IRECT bounds, const IPattern& pattern, bool drawFrame = false)
          : IControl(bounds, kNoParameter)
          , mPattern(pattern)
          , mDrawFrame(drawFrame){
          mIgnoreMouse = true;
        }

        void Draw(IGraphics& g) override{
          if (g.HasPathSupport()){
            g.PathRect(mRECT);
            g.PathFill(mPattern);
          } else{
            g.FillRect(mPattern.GetStop(0).mColor, mRECT);
          }

          if (mDrawFrame){
            g.DrawRect(COLOR_LIGHT_GRAY, mRECT);
          }
        }

        void SetPattern(const IPattern& pattern){
          mPattern = pattern;
          SetDirty(false);
        }

      private:
        IPattern mPattern;
        bool mDrawFrame;
      };

      // TODO: THIS IS COMMENTED UNTIL CONFLICT WITH STEINBERG::IPLUGINBASE IS SOLVED

      // Preset Menu
      // -----------------------------------

      class RAR_PresetMenu
        : public IControl{
      public:
        RAR_PresetMenu(IRECT bounds, IText pText, const char** pNamedParams)
          : IControl(bounds, -1){
          mTextEntryLength = MAX_PRESET_NAME_LEN - 3;
          mText = pText;
          mNamedParams = pNamedParams;
        }
        void Draw(IGraphics& g) override{
          auto* pPluginBase = static_cast<iplug::IPluginBase*>(GetDelegate());
          int pNumber = pPluginBase->GetCurrentPresetIdx();

          mDisp.SetFormatted(32, "%02d: %s", pNumber + 1, pPluginBase->GetPresetName(pNumber));

          IColor colorBg = IColor(50, 0, 0, 0);
          IColor colorFrame = IColor(50, 255, 255, 255);
          g.FillRoundRect(colorBg, mRECT, 5.f);
          g.DrawRoundRect(colorFrame, mRECT, 5.f);

          if (mDisp.Get()){
            g.DrawText(mText, mDisp.Get(), mRECT);
          }
        }
        void OnMouseDown(float x, float y, const IMouseMod& mod) override{
          auto* pPluginBase = static_cast<iplug::IPluginBase*>(GetDelegate());
          if (mod.R){
            const char* pname = pPluginBase->GetPresetName(pPluginBase->GetCurrentPresetIdx());
            GetUI()->CreateTextEntry(*this, mText, mRECT, pname);
          } else{
            doPopupMenu(*GetUI());
          }
          //Redraw(); // seems to need this
          SetDirty();
        }
        void doPopupMenu(IGraphics& g){
          auto* pPluginBase = static_cast<iplug::IPluginBase*>(GetDelegate());

          const int numPresets = pPluginBase->NPresets();
          IPopupMenu menuMain;
          int currentPresetIdx = pPluginBase->GetCurrentPresetIdx();

          for (int i = 0; i < numPresets; i++){
            const char* str = pPluginBase->GetPresetName(i);
            if (i == currentPresetIdx)
              menuMain.AddItem(str, i, IPopupMenu::Item::Flags::kChecked);
            else
              menuMain.AddItem(str, i, IPopupMenu::Item::Flags::kNoFlags);
          }
          menuMain.AddItem("Export Preset", numPresets);

          menuMain.SetPrefix(0);

          g.CreatePopupMenu(*this, menuMain, mRECT);
          int itemChosen = menuMain.GetChosenItemIdx();

          if (itemChosen > -1 && itemChosen < numPresets){
            pPluginBase->RestorePreset(itemChosen);
            pPluginBase->InformHostOfProgramChange();
            pPluginBase->DirtyParametersFromUI();
          } else{
            //const int numParams = mPlug->NParams();
            //const char** enumNames = new const char*[numParams];
            //for (int i = 0; i < mPlug->NParams(); i++) {
            //  enumNames[i] = mPlug->GetParamGroupName(i);
            //}
            WDL_String filename, path;
            GetUI()->PromptForFile(filename, path, EFileAction::Save, "txt");
            pPluginBase->DumpPresetSrcCode(filename.Get(), mNamedParams);
          }
        }
        void TextFromTextEntry(const char* txt){
          auto* pPluginBase = static_cast<iplug::IPluginBase*>(GetDelegate());
          WDL_String safeName;
          safeName.Set(txt, MAX_PRESET_NAME_LEN);

          pPluginBase->ModifyCurrentPreset(safeName.Get());
          pPluginBase->InformHostOfProgramChange();
          pPluginBase->DirtyParametersFromUI();
          SetDirty(false);
        }
      private:
        WDL_String mDisp;
        const char** mNamedParams;
      };

      // TODO: Draw with PathConvexShape from ptr to member array updated from Updatefunction
      class RAR_GraphBase
        : public IControl
        , public IVectorBase{
      public:
        RAR_GraphBase(IRECT bounds, int numValues, float* values, const IVStyle& style = DEFAULT_STYLE)
          : IControl(bounds, -1)
          , IVectorBase(style)
          , mValues(values)
          , mNumValues(numValues)
          , mX(new float[numValues])
          , mY(new float[numValues]){
          AttachIControl(this, ""); // TODO: Should hand label
        }

        ~RAR_GraphBase(){
          //delete[] mX;
          //delete[] mY;
          //delete[] mValues;
        }

        void Draw(IGraphics& g) override{
          // Fill Graph
          g.PathClear();
          g.PathMoveTo(mRECT.L, mRECT.MH());
          for (int i = 0; i < mNumValues; i++){
            g.PathLineTo(mX[i], mY[i]);
          }
          g.PathLineTo(mRECT.R, mRECT.MH());
          g.PathClose();
          g.PathFill(GetColor(kHL));

          // Draw Graph
          g.PathClear();
          g.PathMoveTo(mRECT.L, mRECT.MH());
          for (int i = 0; i < mNumValues; i++){
            //if (mY[i] == mRECT.T && mY[i-1] == mRECT.T || mY[i] == mRECT.B && mY[i - 1] == mRECT.B)
            //  g.PathMoveTo(mX[i], mY[i]);
            //else
            g.PathLineTo(mX[i], mY[i]);
          }
          g.PathLineTo(mRECT.R, mRECT.MH());
          g.PathStroke(GetColor(kPR), mStyle.frameThickness);
        };

        void OnResize() override{
          for (int i = 0; i < mNumValues; i++){
            mX[i] = mRECT.L + (mRECT.W() / (mNumValues - 1.f)) * float(i);
            mY[i] = mRECT.MH() - (mRECT.H() * (float)mValues[i] * 0.5f);
          }
          SetDirty(false);
        }

        void Process(float* values){
          mValues = values;
          for (int i = 0; i < mNumValues; i++){
            mValues[i] = Clip<float>(mValues[i], -1.f, 1.f);
          }
          OnResize();
        };
        //void OnMouseDown(float x, float y, const IMouseMod& mod) override;
      private:
        //WDL_String mDisp;
        float* mValues;
        int mNumValues;
        float* mX;
        float* mY;
      };

      // TODO: Draw with PathConvexShape from ptr to member array updated from Updatefunction
      class RAR_FrequencyResponseMeter
        : public IControl
        , public IVectorBase{
      public:
        RAR_FrequencyResponseMeter(IRECT bounds, int numValues, double* values, double shape = 1.0, const IVStyle& style = DEFAULT_STYLE)
          : IControl(bounds, -1)
          , IVectorBase(style)
          , mValues(values)
          , mNumValues(numValues)
          , mShape(shape)
          , mPatternFill(IPattern(EPatternType::Solid))
          , mPatternStroke(IPattern(EPatternType::Solid)){
          mStrokeOptions.mPreserve = true;
          mFillOptions.mPreserve = true;
          mPatternStroke = IPattern(GetColor(kFG));
          mPatternFill = IPattern(GetColor(kHL));
          AttachIControl(this, ""); // TODO: shoud hand label
        }

        ~RAR_FrequencyResponseMeter(){}

        void Draw(IGraphics& g) override{
          g.PathClear();
          g.PathMoveTo(mRECT.L, mRECT.MH());

          for (int i = 0; i < mNumValues; i++){
            const float y = mRECT.MH() - ((float)mValues[i] * 0.5f * mRECT.H());
            const float x = mRECT.L + ((float)i / ((float)mNumValues - 1.f)) * mRECT.W();

            g.PathLineTo(x, y);
          }

          g.PathLineTo(mRECT.R, mRECT.MH());
          //g.PathClose();
          g.PathFill(mPatternFill, mFillOptions, 0);
          g.PathStroke(mPatternStroke, 1.f, mStrokeOptions, 0);
        };

        void Process(double* values){
          mValues = values;
          for (int i = 0; i < mNumValues; i++){
            mValues[i] = Clip<double>(mValues[i], -1, 1);
          }
          SetDirty(false);
        };
        //void OnMouseDown(float x, float y, const IMouseMod& mod) override;
      private:
        //WDL_String mDisp;
        double* mValues;
        int mNumValues;
        double mShape;
        IStrokeOptions mStrokeOptions;
        IFillOptions mFillOptions;
        IPattern mPatternFill;
        IPattern mPatternStroke;
      };
    }//end namespace Control
  } //end namespace Layout
} //end namespace Graphics
} //end namespace RAR