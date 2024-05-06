RGB_MATRIX_EFFECT(all_keys_white)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#define gamecolour RGB_GREEN

static bool all_keys_white(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  rgb_matrix_set_color_all(RGB_WHITE);
  return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS