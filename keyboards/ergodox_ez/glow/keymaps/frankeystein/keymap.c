#include QMK_KEYBOARD_H
#include "version.h"

extern keymap_config_t keymap_config; // It contains useful keymap configuration. Used for get the swap_lctl_lgui flag

bool lctl_lalt_swapped = false;       // Flag for 'soft swap' ctrl with alt.
bool lalt_lctl_swapped = false;       // Flag for 'soft swap' alt with ctrl.
uint8_t mod_state;                    // Flag for keeping the modifiers state

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_MAC_REDO LGUI(LSFT(KC_Z))

#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define KC_PC_REDO LCTL(KC_Y)

#define HOME_A LT(SPANISH,KC_A)
#define HOME_Z MT(MOD_LCTL, KC_Z)
#define HOME_S MT(MOD_LALT, KC_S)
#define HOME_D MT(MOD_LGUI, KC_D)
#define HOME_F MT(MOD_LSFT, KC_F)

#define HOME_J MT(MOD_LSFT, KC_J)
#define HOME_K MT(MOD_LGUI, KC_K)
#define HOME_L MT(MOD_LALT, KC_L)
#define HOME_SLASH MT(MOD_LCTL, KC_SLASH)
#define HOME_SCOLON LT(DIGITS,KC_SCOLON)

#define ACCENT_A KC_A
#define ACCENT_E KC_E
#define ACCENT_I KC_I
#define ACCENT_O KC_O
#define ACCENT_U KC_U
#define TILDE_N KC_N

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  UMLAUT_U,
};

/*****
// A useful map for unicode. Not used as we should change the input mode for different OS
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_unicode.md
enum unicode_names {
    ES_A,
    ES_A_CAPS,
    ES_E,
    ES_E_CAPS,
    ES_I,
    ES_I_CAPS,
    ES_O,
    ES_O_CAPS,
    ES_U,
    ES_U_CAPS,
    ES_NTIL,
    ES_NTIL_CAPS,
    ES_UMLAUT,
    ES_UMLAUT_CAPS,
};

const uint32_t PROGMEM unicode_map[] = {
  [ES_A]  = 0x00E1,  // 0 á
  [ES_A_CAPS] = 0x00C1,  // 1 Á
  [ES_E]  = 0x00E9,  // 2 é
  [ES_E_CAPS] = 0x00C9,  // 3 É
  [ES_I]  = 0x00ED,  // 4 í
  [ES_I_CAPS] = 0x00CD,  // 5 Í
  [ES_O]  = 0x00F3,  // 6 ó
  [ES_O_CAPS] = 0x00D3,  // 7 Ó
  [ES_U]  = 0x00FA,  // 8 ú
  [ES_U_CAPS] = 0x00DA,  // 9 Ú
  [ES_NTIL]  = 0x00F1,  // 10 ñ
  [ES_NTIL_CAPS] = 0x00D1,  // 11 Ñ
  [ES_UMLAUT]  = 0x00FC,  // 12 ü
  [ES_UMLAUT_CAPS] = 0x00DC,  // 13 Ü
};
******/

#define BASE 0 
#define NAV 1 
#define SYMBOL 2
#define DIGITS 3
#define SPANISH 4
#define LAYERS 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_EQUAL,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           LGUI(LCTL(LSFT(KC_4))),                                       KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLASH,
    KC_GRAVE,       HOME_A,         HOME_S,         HOME_D,         HOME_F,         KC_G,                                                                           KC_H,           HOME_J,         HOME_K,         HOME_L,         HOME_SCOLON,    KC_QUOTE,
    KC_EQUAL,       HOME_Z,         KC_X,           KC_C,           KC_V,           KC_B,           KC_ENTER,                                       KC_TRANSPARENT, KC_N,           KC_M,           KC_COMMA,       KC_DOT,         HOME_SLASH,     KC_MINUS,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LT(NAV,KC_ESCAPE),                                                                              LT(SYMBOL, KC_DELETE),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MO(LAYERS),
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,       KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT,       KC_MEDIA_NEXT_TRACK,
                                                                             KC_SPACE, KC_BSPACE,KC_TRANSPARENT,    KC_MEDIA_PLAY_PAUSE,  KC_TAB,       KC_ENTER
  ),
  [NAV] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT,      KC_TRANSPARENT,    KC_TRANSPARENT,  KC_TRANSPARENT,      KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT,  KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_NEXT_TRACK, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LCTRL,       KC_LALT,        KC_LGUI,        KC_LSHIFT,      KC_TRANSPARENT,                                                                 LCTL(KC_PGUP),   KC_LEFT,             KC_DOWN,           KC_UP,           KC_RIGHT,            KC_CAPSLOCK,
    KC_TRANSPARENT, KC_MAC_UNDO,    KC_MAC_CUT,     KC_MAC_COPY,    KC_MAC_PASTE,   KC_MAC_REDO,    KC_TRANSPARENT,                                 KC_TRANSPARENT, LCTL(KC_PGDOWN), KC_HOME,             KC_PGDOWN,         KC_PGUP,         KC_END,              KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                  KC_DELETE,           KC_TRANSPARENT,    KC_TRANSPARENT,  KC_TRANSPARENT,      KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TAB,         KC_ENTER
  ),
  [SYMBOL] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_ASTR,        KC_LPRN,        KC_RPRN,        KC_PERC,        KC_EXLM,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TILD,        KC_CIRC,        KC_LCBR,        KC_RCBR,        KC_DLR,         KC_AT,                                                                          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_PLUS,        KC_HASH,        KC_LBRACKET,    KC_RBRACKET,    KC_AMPR,        KC_PIPE,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [DIGITS] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_4,           KC_5,           KC_6,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_COMMA,       KC_1,           KC_2,           KC_3,           KC_DOT,         KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_0,                                                                                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [SPANISH] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ACCENT_E,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, UMLAUT_U,       ACCENT_U,       ACCENT_I,       ACCENT_O,       KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_LALT,        ACCENT_A,       KC_LSFT,        KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_LSHIFT,      KC_LGUI,        KC_LALT,        KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, TILDE_N,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
    [LAYERS] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, LCG_SWP,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, LCG_NRM,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188}, {128,61,188} },

    [1] = { {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208}, {138,88,208} },

    [2] = { {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193}, {150,84,193} },

    [3] = { {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240}, {156,11,240} },

    [4] = { {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172}, {152,115,172} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
    case 5:
      set_layer_color(4);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  mod_state = get_mods();
  bool isMAC = !keymap_config.swap_lctl_lgui; // MAC has the default ctl && gui layout

  if(!isMAC){
    if(mod_state & MOD_MASK_CTRL){
      // This block has the logic for keep the CTRL mod if we still are using it with tab. Combo used for tab switch.
      if(lalt_lctl_swapped) {
        switch(keycode){
          case KC_LALT:
          case HOME_S:
          case HOME_L:
          if (!record->event.pressed) { // On releasing original LALT key, let's remove the CTRL mod
            lalt_lctl_swapped = false;
            unregister_mods(MOD_LCTL);
          }
          return true;
          break;

          case KC_A ... KC_EXSEL:
          if (keycode == KC_TAB){
            return true; // No changes on TAB when having the Ctrl+Tab registered
          }

          // if we press other key while LALT is being hold
          // then we need to swap again
          if(record->event.pressed){
            lctl_lalt_swapped = false;
            unregister_mods(MOD_LCTL);
            register_mods(MOD_LALT);
          }
          return true;
          break;

        }
      } else {
        // TODO: Maybe this one can be a function so it can keep the bindings regarding the next TODO about losing these bindings
        // These are custom key bindings for keeping a cross-platform handy shortcuts
        switch (keycode){
          case KC_Q: // Alt + F4 for clossing apps
          if (record->event.pressed) {
            unregister_mods(MOD_LCTL);
            tap_code16(LALT(KC_F4));
            set_mods(mod_state);
          }
          return false;
          break;

          case KC_R: // F5 for refreshing
          if (record->event.pressed) {
            unregister_mods(MOD_LCTL);
            tap_code(KC_F5);
            set_mods(mod_state);
          }
          return false;
          break;

          case KC_TAB: // ALT + TAB for switching apps
          if (record->event.pressed) {
            unregister_mods(MOD_LCTL);
            register_mods(MOD_LALT);
            lctl_lalt_swapped = true;
          }
          return true;
          break;
        }
      }
    }

    if(mod_state & MOD_MASK_ALT) {
      // This block has the logic for keep the Alt mod if we still are using it with tab. Combo used for app switch.
      if(lctl_lalt_swapped){
        switch(keycode){
          case KC_LCTRL:
          case HOME_D:
          case HOME_K:
          if (!record->event.pressed) { // On releasing original LCTRL key, let's remove the ALT mod
            lctl_lalt_swapped = false;
            unregister_mods(MOD_LALT);
          }
          return true;
          break;

          case KC_A ... KC_EXSEL:
          if (keycode == KC_TAB){
            return true; // No changes on TAB when having the Alt+Tab registered 
          }
          
          // if we press other key while LCTL is being hold
          // then we need to swap again
          if(record->event.pressed){
            // TODO: We lose the custom actions we bind to ctrl. E.g. ctrl + q => alt+f4 (A solution is to call a function with these keybinds)
            lctl_lalt_swapped = false;
            unregister_mods(MOD_LALT);
            register_mods(MOD_LCTL);
          }
          return true;
          break;
        }
      } else {
        // Since we want to keep using the original ctrl+tab, we will soft swap alt with ctl
        switch(keycode){
          case KC_TAB: // CTRL + TAB
          if (record->event.pressed) {
            unregister_mods(MOD_LALT);
            register_mods(MOD_LCTL);
            lalt_lctl_swapped = true;
          }
          return true;
          break;
        }

      }
    }

    // For this to work:
    // - Windows needs to have wincompose: https://github.com/samhocevar/wincompose)
    // - Linux has to set the compose key to RALT (A.K.A. AltGr): https://en.wikipedia.org/wiki/Compose_key
    if(IS_LAYER_ON(SPANISH)){
      switch (keycode) {
        case ACCENT_A:
        case ACCENT_E:
        case ACCENT_I:
        case ACCENT_O:
        case ACCENT_U:
          if (record->event.pressed) {
            del_mods(mod_state);
            tap_code16(RALT(KC_QUOTE));
            set_mods(mod_state);
          }
          break;

        case UMLAUT_U:
          if (record->event.pressed) {
            del_mods(mod_state);
            tap_code16(LSFT(RALT(KC_QUOTE)));
            set_mods(mod_state);
            tap_code(KC_U);
          }
          break;

        case TILDE_N:
          if (record->event.pressed) {
            del_mods(mod_state);
            tap_code16(LSFT(RALT(KC_GRAVE)));
            set_mods(mod_state);
          }
          break;
      }
    }

    switch (keycode) {
      case KC_MAC_UNDO: 
        tap_code16(KC_PC_UNDO);
        return false;
        break;

      case KC_MAC_CUT: 
        tap_code16(KC_PC_CUT);
        return false;
        break;

      case KC_MAC_COPY: 
        tap_code16(KC_PC_COPY);
        return false;
        break;

      case KC_MAC_PASTE: 
        tap_code16(KC_PC_PASTE);
        return false;
        break;

      case KC_MAC_REDO: 
        tap_code16(KC_PC_REDO);
        return false;
        break;
    }
  } else {
    if(IS_LAYER_ON(SPANISH)){
      switch (keycode) {
        // Mac use the alt+e to get the dead code of accute (´)
        case ACCENT_A:
        case ACCENT_E:
        case ACCENT_I:
        case ACCENT_O:
        case ACCENT_U:
        if (record->event.pressed) {
          del_mods(mod_state);
          tap_code16(LALT(KC_E));
          set_mods(mod_state);
        }
        break;

        // Mac use the alt+u to get the dead code of accute (¨)
        case UMLAUT_U:
        if (record->event.pressed) {
          del_mods(mod_state);
          tap_code16(LALT(KC_U));
          set_mods(mod_state);
          tap_code(KC_U);
        }
        break;

        // Mac use the alt+e to get the dead code of accute (˜)
        case TILDE_N:
        if (record->event.pressed) {
          del_mods(mod_state);
          tap_code16(LALT(KC_N));
          set_mods(mod_state);
        }
        break;
      }
    }
  }

  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }

  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

  uint8_t layer = biton32(state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 0:
      if(keymap_config.swap_lctl_lgui){ // indicator that we have a swapped ctrl && gui
        ergodox_right_led_1_on();
      }
      break;
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};
