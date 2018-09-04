/*
  xnrg_interface.ino - Energy driver interface support for Sonoff-Tasmota

  Copyright (C) 2018  Theo Arends inspired by ESPEasy

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

int (* const xnrg_func_ptr[])(byte) PROGMEM = {   // Energy driver Function Pointers
#ifdef XNRG_01
  &Xnrg01,
#endif

#ifdef XNRG_02
  &Xnrg02,
#endif

#ifdef XNRG_03
  &Xnrg03,
#endif

#ifdef XNRG_04
  &Xnrg04,
#endif

#ifdef XNRG_05
  &Xnrg05,
#endif

#ifdef XNRG_06
  &Xnrg06
#endif
};

const uint8_t xnrg_present = sizeof(xnrg_func_ptr) / sizeof(xnrg_func_ptr[0]);  // Number of drivers found

int XnrgCall(byte Function)
{
  int result = 0;

  for (byte x = 0; x < xnrg_present; x++) {
    result = xnrg_func_ptr[x](Function);
    if (result) break;
  }
  return result;
}
