/* sane - Scanner Access Now Easy.

   Copyright (C) 2019 Povilas Kanapickas <povilas@radix.lt>

   This file is part of the SANE package.

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330, Boston,
   MA 02111-1307, USA.

   As a special exception, the authors of SANE give permission for
   additional uses of the libraries contained in this release of SANE.

   The exception is that, if you link a SANE library with other files
   to produce an executable, this does not by itself cause the
   resulting executable to be covered by the GNU General Public
   License.  Your use of that executable is in no way restricted on
   account of linking the SANE library code into it.

   This exception does not, however, invalidate any other reasons why
   the executable file might be covered by the GNU General Public
   License.

   If you submit changes to SANE to the maintainers to be included in
   a subsequent release, you agree by submitting the changes that
   those changes may be distributed with this exception intact.

   If you write modifications of your own for SANE, it is your choice
   whether to permit this exception to apply to your modifications.
   If you do not wish that, delete this exception notice.
*/

#ifndef BACKEND_GENESYS_CALIBRATION_H
#define BACKEND_GENESYS_CALIBRATION_H

#include "genesys_sensor.h"
#include "genesys_settings.h"

struct Genesys_Calibration_Cache
{
    Genesys_Calibration_Cache() = default;
    ~Genesys_Calibration_Cache() = default;

    // used to check if entry is compatible
    Genesys_Current_Setup used_setup;
    SetupParams params;
    time_t last_calibration = 0;

    Genesys_Frontend frontend;
    Genesys_Sensor sensor;

    size_t calib_pixels = 0;
    size_t calib_channels = 0;
    size_t average_size = 0;
    std::vector<uint8_t> white_average_data;
    std::vector<uint8_t> dark_average_data;

    bool operator==(const Genesys_Calibration_Cache& other) const
    {
        return used_setup == other.used_setup &&
            params == other.params &&
            last_calibration == other.last_calibration &&
            frontend == other.frontend &&
            sensor == other.sensor &&
            calib_pixels == other.calib_pixels &&
            calib_channels == other.calib_channels &&
            average_size == other.average_size &&
            white_average_data == other.white_average_data &&
            dark_average_data == other.dark_average_data;
    }
};

template<class Stream>
void serialize(Stream& str, Genesys_Calibration_Cache& x)
{
    serialize(str, x.used_setup);
    serialize_newline(str);
    serialize(str, x.params);
    serialize_newline(str);
    serialize(str, x.last_calibration);
    serialize_newline(str);
    serialize(str, x.frontend);
    serialize_newline(str);
    serialize(str, x.sensor);
    serialize_newline(str);
    serialize(str, x.calib_pixels);
    serialize(str, x.calib_channels);
    serialize(str, x.average_size);
    serialize_newline(str);
    serialize(str, x.white_average_data);
    serialize_newline(str);
    serialize(str, x.dark_average_data);
}

#endif // BACKEND_GENESYS_CALIBRATION_H