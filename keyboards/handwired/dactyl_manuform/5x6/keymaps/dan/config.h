/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define USE_SERIAL

// This is how it has been for a while but has issues on startup where the slave side doesn't respond
//#define MASTER_LEFT

// New way
#define MASTER_RIGHT
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2500

// was always commented out
// #define MASTER_RIGHT
//#define EE_HANDS
// Rows are doubled-up

// When powering up the board you can hold the 0/1 key (top left plus one to the right)
// to put the board into DFU mode so it can be updated
#define BOOTMAGIC_LITE_ROW_LEFT 0
#define BOOTMAGIC_LITE_COLUMN_LEFT 1

// the length in milliseconds to treat as a tap or a hold
// https://thomasbaart.nl/2018/12/09/qmk-basics-tap-and-hold-actions/
#define TAPPING_TERM (150)  // 200ms is the default
