#define PLUG_NAME "MyFirstPluginRAR"
#define PLUG_MFR "RAR-AUDIO"
#define PLUG_VERSION_HEX 0x00000100
#define PLUG_VERSION_STR "0.1.0"
#define PLUG_UNIQUE_ID 'NaTD'
#define PLUG_MFR_ID 'Acme'
#define PLUG_URL_STR "https://raraudio.net"
#define PLUG_EMAIL_STR "spam@me.com"
#define PLUG_COPYRIGHT_STR "Copyright 2020 RAR-AUDIO"
#define PLUG_CLASS_NAME MyFirstPluginRAR

#define BUNDLE_NAME "MyFirstPluginRAR"
#define BUNDLE_MFR "RAR-AUDIO"
#define BUNDLE_DOMAIN "net"

#define SHARED_RESOURCES_SUBPATH "MyFirstPluginRAR"

#define PLUG_CHANNEL_IO "1-1 2-2"

#define PLUG_LATENCY 0
#define PLUG_TYPE 0
#define PLUG_DOES_MIDI_IN 0
#define PLUG_DOES_MIDI_OUT 0
#define PLUG_DOES_MPE 0
#define PLUG_DOES_STATE_CHUNKS 0
#define PLUG_HAS_UI 1
#define PLUG_WIDTH 600
#define PLUG_HEIGHT 600
#define PLUG_FPS 60
#define PLUG_SHARED_RESOURCES 0
#define PLUG_HOST_RESIZE 0

#define AUV2_ENTRY MyFirstPluginRAR_Entry
#define AUV2_ENTRY_STR "MyFirstPluginRAR_Entry"
#define AUV2_FACTORY MyFirstPluginRAR_Factory
#define AUV2_VIEW_CLASS MyFirstPluginRAR_View
#define AUV2_VIEW_CLASS_STR "MyFirstPluginRAR_View"

#define AAX_TYPE_IDS 'IEF1', 'IEF2'
#define AAX_TYPE_IDS_AUDIOSUITE 'IEA1', 'IEA2'
#define AAX_PLUG_MFR_STR "Acme"
#define AAX_PLUG_NAME_STR "MyFirstPluginRAR\nIPEF"
#define AAX_PLUG_CATEGORY_STR "Effect"
#define AAX_DOES_AUDIOSUITE 1

#define VST3_SUBCATEGORY "Fx"

#define APP_NUM_CHANNELS 2
#define APP_N_VECTOR_WAIT 0
#define APP_MULT 1
#define APP_COPY_AUV3 0
#define APP_SIGNAL_VECTOR_SIZE 64

#define ROBOTO_FN "Roboto-Regular.ttf"

#define IBM_PLEX_SANS_THIN_FN "IBMPlexSans-Thin.ttf"
#define IBM_PLEX_SANS_FN "IBMPlexSans.ttf"
#define DSEG17_FN "DSEG14Classic-Regular.ttf"

#define FONTAUDIO_FN "fontaudio.ttf"
#define FORK_AWESOME_FN "forkawesome-webfont.ttf"

//==================================================================================
// Add Background and switches

#define OnSwitch_FN "Switches/SW_Toggle_2.svg" // ON switch
#define OffSwitch_FN "Switches/SW_Toggle_0.svg" // OFF switch

#define BlackScrew_FN "Misc/ScrewBlack.svg" // Black Screw
#define LedBezel_FN "Misc/LEDBezel.svg" // LED Bezel
#define Logo_FN "Misc/logowobackground.svg" // Logo
