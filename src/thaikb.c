/* -*- Mode: C; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/*
 *  Copyright (C) 2012 Theppitak Karoonboonyanan <theppitak@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

#include "thaikb.h"

#define N_KEYCODES  54

static const unsigned char tis_keycode_map[3][N_KEYCODES] =
{
  { /* level 1 */
    0x00, 0x00, 0xdf, 0x2f, 0x2d, 0xc0, 0xb6, 0xd8, /* 00 */
    0xd6, 0xa4, 0xb5, 0xa8, 0xa2, 0xaa, 0x08, 0x09,
    0xe6, 0xe4, 0xd3, 0xbe, 0xd0, 0xd1, 0xd5, 0xc3, /* 10 */
    0xb9, 0xc2, 0xba, 0xc5, 0x0d, 0x00, 0xbf, 0xcb,
    0xa1, 0xb4, 0xe0, 0xe9, 0xe8, 0xd2, 0xca, 0xc7, /* 20 */
    0xa7, 0xef, 0x00, 0xa5, 0xbc, 0xbb, 0xe1, 0xcd,
    0xd4, 0xd7, 0xb7, 0xc1, 0xe3, 0xbd,             /* 30 */
  },
  { /* level 2 */
    0x00, 0x00, 0xe5, 0xf1, 0xf2, 0xf3, 0xf4, 0xd9, /* 00 */
    0xee, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0x08, 0x09,
    0xf0, 0x22, 0xae, 0xb1, 0xb8, 0xed, 0xea, 0xb3, /* 10 */
    0xcf, 0xad, 0xb0, 0x2c, 0x0d, 0x00, 0xc4, 0xa6,
    0xaf, 0xe2, 0xac, 0xe7, 0xeb, 0xc9, 0xc8, 0xab, /* 20 */
    0x2e, 0xfb, 0x00, 0xa3, 0x28, 0x29, 0xa9, 0xce,
    0xda, 0xec, 0x3f, 0xb2, 0xcc, 0xc6,             /* 30 */
  },
  { /* level 3 */
    0x00, 0x00, 0xe5, 0xf1, 0xf2, 0xf3, 0xf4, 0xd9, /* 00 */
    0xee, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0x08, 0x09,
    0xf0, 0x22, 0xae, 0xb1, 0xb8, 0xed, 0xea, 0xb3, /* 10 */
    0xfa, 0xad, 0xb0, 0x2c, 0x0d, 0x00, 0xc4, 0xa6,
    0xaf, 0xe2, 0xac, 0xe7, 0xeb, 0xc9, 0xc8, 0xab, /* 20 */
    0x2e, 0xfb, 0x00, 0xa3, 0x28, 0x29, 0xa9, 0xce,
    0xda, 0xec, 0x3f, 0xb2, 0xcc, 0xc6,             /* 30 */
  },
};

static const unsigned char ketmanee_keycode_map[3][N_KEYCODES] =
{
  { /* level 1 */
    0x00, 0x00, 0xe5, 0x2f, 0x2d, 0xc0, 0xb6, 0xd8, /* 00 */
    0xd6, 0xa4, 0xb5, 0xa8, 0xa2, 0xaa, 0x08, 0x09,
    0xe6, 0xe4, 0xd3, 0xbe, 0xd0, 0xd1, 0xd5, 0xc3, /* 10 */
    0xb9, 0xc2, 0xba, 0xc5, 0x0d, 0x00, 0xbf, 0xcb,
    0xa1, 0xb4, 0xe0, 0xe9, 0xe8, 0xd2, 0xca, 0xc7, /* 20 */
    0xa7, 0x5f, 0x00, 0xa3, 0xbc, 0xbb, 0xe1, 0xcd,
    0xd4, 0xd7, 0xb7, 0xc1, 0xe3, 0xbd,             /* 30 */
  },
  { /* level 2 */
    0x00, 0x00, 0x2b, 0xf1, 0xf2, 0xf3, 0xf4, 0xd9, /* 00 */
    0xdf, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0x08, 0x09,
    0xf0, 0x22, 0xae, 0xb1, 0xb8, 0xed, 0xea, 0xb3, /* 10 */
    0xcf, 0xad, 0xb0, 0x2c, 0x0d, 0x00, 0xc4, 0xa6,
    0xaf, 0xe2, 0xac, 0xe7, 0xeb, 0xc9, 0xc8, 0xab, /* 20 */
    0x2e, 0x25, 0x00, 0xa5, 0x28, 0x29, 0xa9, 0xce,
    0xda, 0xec, 0x3f, 0xb2, 0xcc, 0xc6,             /* 30 */
  },
  { /* level 3 */
    0x00, 0x00, 0x2b, 0xf1, 0xf2, 0xf3, 0xf4, 0xd9, /* 00 */
    0xdf, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0x08, 0x09,
    0xf0, 0x22, 0xae, 0xb1, 0xb8, 0xed, 0xea, 0xb3, /* 10 */
    0xcf, 0xad, 0xb0, 0x2c, 0x0d, 0x00, 0xc4, 0xa6,
    0xaf, 0xe2, 0xac, 0xe7, 0xeb, 0xc9, 0xc8, 0xab, /* 20 */
    0x2e, 0x25, 0x00, 0xa5, 0x28, 0x29, 0xa9, 0xce,
    0xda, 0xec, 0x3f, 0xb2, 0xcc, 0xc6,             /* 30 */
  },
};

static const unsigned char pattachote_keycode_map[3][N_KEYCODES] =
{
  { /* level 1 */
    0x00, 0x00, 0x3d, 0xf2, 0xf3, 0xf4, 0xf5, 0xd9, /* 00 */
    0xf7, 0xf8, 0xf9, 0xf0, 0xf1, 0xf6, 0x08, 0x09,
    0xe7, 0xb5, 0xc2, 0xcd, 0xc3, 0xe8, 0xb4, 0xc1, /* 10 */
    0xc7, 0xe1, 0xe3, 0xac, 0x0d, 0x00, 0xe9, 0xb7,
    0xa7, 0xa1, 0xd1, 0xd5, 0xd2, 0xb9, 0xe0, 0xe4, /* 20 */
    0xa2, 0x5f, 0x00, 0xe5, 0xba, 0xbb, 0xc5, 0xcb,
    0xd4, 0xa4, 0xca, 0xd0, 0xa8, 0xbe,             /* 30 */
  },
  { /* level 2 */
    0x00, 0x00, 0x2b, 0x22, 0x2f, 0x2c, 0x3f, 0xd8, /* 00 */
    0x5f, 0x2e, 0x28, 0x29, 0x2d, 0x25, 0x08, 0x09,
    0xea, 0xc4, 0xe6, 0xad, 0xc9, 0xd6, 0xbd, 0xab, /* 10 */
    0xb6, 0xb2, 0xcf, 0x2c, 0x0d, 0x00, 0xeb, 0xb8,
    0xd3, 0xb3, 0xec, 0xd7, 0xbc, 0xaa, 0xe2, 0xa6, /* 20 */
    0xb1, 0xdf, 0x00, 0xed, 0xae, 0xaf, 0xb0, 0xc0,
    0xda, 0xc8, 0xce, 0xbf, 0xa9, 0xcc,             /* 30 */
  },
  { /* level 3 */
    0x00, 0x00, 0x2b, 0x22, 0x2f, 0x2c, 0x3f, 0xd8, /* 00 */
    0x5f, 0x2e, 0x28, 0x29, 0x2d, 0x25, 0x08, 0x09,
    0xea, 0xc4, 0xe6, 0xad, 0xc9, 0xd6, 0xbd, 0xab, /* 10 */
    0xb6, 0xb2, 0xcf, 0x2c, 0x0d, 0x00, 0xeb, 0xb8,
    0xd3, 0xb3, 0xec, 0xd7, 0xbc, 0xaa, 0xe2, 0xa6, /* 20 */
    0xb1, 0xdf, 0x00, 0xed, 0xae, 0xaf, 0xb0, 0xc0,
    0xda, 0xc8, 0xce, 0xbf, 0xa9, 0xcc,             /* 30 */
  },
};

static const unsigned char (* const thai_keycode_map[])[N_KEYCODES] =
{
  ketmanee_keycode_map,
  pattachote_keycode_map,
  tis_keycode_map
};

unsigned char
thai_map_keycode (ThaiKBMap map, int keycode, int shift_lv)
{
  if (map > THAI_KB_TIS820_2538 || shift_lv >= 3 || keycode >= N_KEYCODES)
    return 0;

  return thai_keycode_map[map][shift_lv][keycode];
}

