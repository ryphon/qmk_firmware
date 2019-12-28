# Keycode Options
EXTRAKEY_ENABLE         = yes       # Audio control and System control

# RGB
RGB_MATRIX_ENABLE       = WS2812    # Enable per-key coordinate based RGB effects. Do not enable with RGBlight
RGB_MATRIX_KEYPRESSES   = yes        # Enable reactive per-key effects.
RGB_MATRIX_FRAMEBUFFER_EFFECTS = yes # Enable frame buffer effects like the typing heatmap.

# Misc
OLED_DRIVER_ENABLE      = yes       # Enable the OLED Driver
LINK_TIME_OPTIMIZATION_ENABLE = yes # Enable Link Time Optimizations greatly reducing firmware size by disabling the old Macros and Functions features

# Special RGB Matrix, OLED, & Encoder Control Menu!
RGB_OLED_MENU           = yes     # Enabled by setting this to the encoder index (0-5) you wish to use to control the menu.
                                # Use the RGB_MENU keycode in the keymap for the encoder to advance the menu to the next option.
