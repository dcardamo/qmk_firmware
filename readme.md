# DAN NOTES

# Mac Setup

`brew qmk/qmk/qmk`
`qmk setup`

## GMMK Pro
My keymap is based off gourdo1
`qmk compile -kb gmmk/pro/rev1/ansi -km dcardamo`

Enter bootmode by holding FN+\ while plugging in power
If its the first time then use space+b to enter boot mode.

### Notable keymaps
Encoder:
    LSHIFT+encoder = page up/down
    RSHIFT+encoder = Layer Change
    RCTRL+encoder = RGB Colour change
    LCTRL+encoder = media next/prev


Function Key Combos:
    FN+UP/DOWN = RGB mode change
    FN+LEFT/RIGHT = RGB Colour Change
    FN+WIN = Disable windows button.  Do it again to re-enable.
    FN+DELETE = RGB Toggle
    FN+PGUP = Media next
    FN+PGDN = Media prev
    FN+~ = print config as text


## Dactyl Manuform


# OLD Notes

This repo has the firmware setup for my Dactyl Manuform keyboard.

Flashing:

-   To Flash the keyboard you hold the 0:1 key (top left and one to the right) while
    plugging it into USB-C. This will put it into DFU mode.
-   compile: at root of this repo and run: 'make handwired/dactyl_manuform/5x6:dan'
-   install: at root of this repo and run: 'make handwired/dactyl_manuform/5x6:dan:dfu'


