# Optimization options for smaller builds
LTO_ENABLE = yes
# AVR_USE_MINIMAL_PRINTF = yes # only needed if using sprintf or snprintf

# Debug features, turn off after debugging
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
BOOTMAGIC_ENABLE = no

# Never disable
SPLIT_KEYBOARD = yes

# Actual features in use
MOUSEKEY_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
CAPS_WORD_ENABLE = yes
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
SEND_STRING_ENABLE = yes

# Removed features to save space
EXTRAKEY_ENABLE = no
GRAVE_ESC_ENABLE = no 
MAGIC_ENABLE = no
SPACE_CADET_ENABLE = yes
