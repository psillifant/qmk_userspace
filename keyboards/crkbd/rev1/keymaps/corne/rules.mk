RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = no
# RGB_MATRIX_CUSTOM_USER = yes

# --------------------------------------------------
# Space Saving Options: https://qmk.github.io/qmk-11ty/faqs/squeezing-the-most-out-of-avr/
# Enable Link Time Optimisation.  Slower compile, smaller size.  Saves about 2700 bytes
LTO_ENABLE = yes
# Disables the console for debugging.  I'm not using advanced enough features / designing 
# my own board, so let's save the space.
CONSOLE_ENABLE = no
# Command seems to be a feature that I just don't use, and shouldn't be used, if Magic Keycodes
# Provide the same functionality (which we're also going to disable below.):
# https://docusaurus.qmk.fm/feature_command/
COMMAND_ENABLE = no
# Disable Mousekeys, I don't use mouse interface on this keyboard.
MOUSEKEY_ENABLE = yes
# Space Cadet is used to provide extra functions for shift, namely parantheses.
# https://docusaurus.qmk.fm/feature_space_cadet
SPACE_CADET_ENABLE = no
# Grave escape means ` is typed when you press Shift + ESC, which I have already mapped in a way
# I'm happy with: https://docusaurus.qmk.fm/feature_grave_esc
GRAVE_ESC_ENABLE = no
# Magic codes seem to help with swapping keys or similar, which I'd rather handle explicitly
# through layers: https://docusaurus.qmk.fm/keycodes_magic
MAGIC_ENABLE = no
# Disabling music. Pairs with NO_MUSIC_MODE in config.h
MUSIC_ENABLE = no