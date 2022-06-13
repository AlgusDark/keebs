/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR

#undef TAPPING_TERM
#define TAPPING_TERM 180
#define TAPPING_FORCE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD

#define USB_SUSPEND_WAKEUP_DELAY 0

#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM

#define CAPS_LOCK_STATUS
#define RGB_MATRIX_STARTUP_SPD 60
