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

#ifndef BACKEND_GENESYS_ENUMS_H
#define BACKEND_GENESYS_ENUMS_H

#include <iostream>
#include "serialize.h"

namespace genesys {

enum class ScanMethod : unsigned {
    // normal scan method
    FLATBED = 0,
    // scan using transparency adaptor
    TRANSPARENCY = 1,
    // scan using transparency adaptor via infrared channel
    TRANSPARENCY_INFRARED = 2
};

inline std::ostream& operator<<(std::ostream& out, ScanMethod mode)
{
    switch (mode) {
        case ScanMethod::FLATBED: out << "FLATBED"; return out;
        case ScanMethod::TRANSPARENCY: out << "TRANSPARENCY"; return out;
        case ScanMethod::TRANSPARENCY_INFRARED: out << "TRANSPARENCY_INFRARED"; return out;
    }
    return out;
}

inline void serialize(std::istream& str, ScanMethod& x)
{
    unsigned value;
    serialize(str, value);
    x = static_cast<ScanMethod>(value);
}

inline void serialize(std::ostream& str, ScanMethod& x)
{
    unsigned value = static_cast<unsigned>(x);
    serialize(str, value);
}

const char* scan_method_to_option_string(ScanMethod method);
ScanMethod option_string_to_scan_method(const std::string& str);

enum class ScanColorMode : unsigned {
    LINEART = 0,
    HALFTONE,
    GRAY,
    COLOR_SINGLE_PASS
};

inline std::ostream& operator<<(std::ostream& out, ScanColorMode mode)
{
    switch (mode) {
        case ScanColorMode::LINEART: out << "LINEART"; return out;
        case ScanColorMode::HALFTONE: out << "HALFTONE"; return out;
        case ScanColorMode::GRAY: out << "GRAY"; return out;
        case ScanColorMode::COLOR_SINGLE_PASS: out << "COLOR_SINGLE_PASS"; return out;
    }
    return out;
}

inline void serialize(std::istream& str, ScanColorMode& x)
{
    unsigned value;
    serialize(str, value);
    x = static_cast<ScanColorMode>(value);
}

inline void serialize(std::ostream& str, ScanColorMode& x)
{
    unsigned value = static_cast<unsigned>(x);
    serialize(str, value);
}

const char* scan_color_mode_to_option_string(ScanColorMode mode);
ScanColorMode option_string_to_scan_color_mode(const std::string& str);

enum class ColorFilter : unsigned {
    RED = 0,
    GREEN,
    BLUE,
    NONE
};

std::ostream& operator<<(std::ostream& out, ColorFilter mode);

inline void serialize(std::istream& str, ColorFilter& x)
{
    unsigned value;
    serialize(str, value);
    x = static_cast<ColorFilter>(value);
}

inline void serialize(std::ostream& str, ColorFilter& x)
{
    unsigned value = static_cast<unsigned>(x);
    serialize(str, value);
}

enum class ColorOrder
{
    RGB,
    GBR,
    BGR,
};

/*  Enum value naming conventions:
    Full name must be included with the following exceptions:

    Canon scanners omit "Canoscan" if present
*/
enum class ModelId : unsigned
{
    UNKNOWN = 0,
    CANON_4400F,
    CANON_5600F,
    CANON_8400F,
    CANON_8600F,
    CANON_IMAGE_FORMULA_101,
    CANON_LIDE_50,
    CANON_LIDE_60,
    CANON_LIDE_80,
    CANON_LIDE_100,
    CANON_LIDE_110,
    CANON_LIDE_120,
    CANON_LIDE_200,
    CANON_LIDE_210,
    CANON_LIDE_220,
    CANON_LIDE_700F,
    DCT_DOCKETPORT_487,
    HP_SCANJET_2300C,
    HP_SCANJET_2400C,
    HP_SCANJET_3670C,
    HP_SCANJET_4850C,
    HP_SCANJET_G4010,
    HP_SCANJET_G4050,
    HP_SCANJET_N6310,
    MEDION_MD5345,
    PANASONIC_KV_SS080,
    PENTAX_DSMOBILE_600,
    PLUSTEK_OPTICBOOK_3800,
    PLUSTEK_OPTICFILM_7200I,
    PLUSTEK_OPTICFILM_7300,
    PLUSTEK_OPTICFILM_7500I,
    PLUSTEK_OPTICPRO_3600,
    PLUSTEK_OPTICPRO_ST12,
    PLUSTEK_OPTICPRO_ST24,
    SYSCAN_DOCKETPORT_465,
    SYSCAN_DOCKETPORT_467,
    SYSCAN_DOCKETPORT_485,
    SYSCAN_DOCKETPORT_665,
    SYSCAN_DOCKETPORT_685,
    UMAX_ASTRA_4500,
    VISIONEER_7100,
    VISIONEER_ROADWARRIOR,
    VISIONEER_STROBE_XP100_REVISION3,
    VISIONEER_STROBE_XP200,
    VISIONEER_STROBE_XP300,
    XEROX_2400,
    XEROX_TRAVELSCANNER_100,
};

enum class SensorId : unsigned
{
    UNKNOWN = 0,
    CCD_5345,
    CCD_CANON_4400F,
    CCD_CANON_8400F,
    CCD_CANON_8600F,
    CCD_DP665,
    CCD_DP685,
    CCD_DSMOBILE600,
    CCD_G4050,
    CCD_HP2300,
    CCD_HP2400,
    CCD_HP3670,
    CCD_HP_N6310,
    CCD_IMG101,
    CCD_KVSS080,
    CCD_PLUSTEK_OPTICBOOK_3800,
    CCD_PLUSTEK_OPTICFILM_7200I,
    CCD_PLUSTEK_OPTICFILM_7300,
    CCD_PLUSTEK_OPTICFILM_7500I,
    CCD_PLUSTEK_OPTICPRO_3600,
    CCD_ROADWARRIOR,
    CCD_ST12,         // SONY ILX548: 5340 Pixel  ???
    CCD_ST24,         // SONY ILX569: 10680 Pixel ???
    CCD_UMAX,
    CCD_XP300,
    CIS_CANON_LIDE_35,
    CIS_CANON_LIDE_80,
    CIS_CANON_LIDE_100,
    CIS_CANON_LIDE_110,
    CIS_CANON_LIDE_120,
    CIS_CANON_LIDE_200,
    CIS_CANON_LIDE_210,
    CIS_CANON_LIDE_220,
    CIS_CANON_LIDE_700F,
    CIS_XP200,
};

inline void serialize(std::istream& str, SensorId& x)
{
    unsigned value;
    serialize(str, value);
    x = static_cast<SensorId>(value);
}

inline void serialize(std::ostream& str, SensorId& x)
{
    unsigned value = static_cast<unsigned>(x);
    serialize(str, value);
}


enum class AdcId : unsigned
{
    UNKNOWN = 0,
    AD_XP200,
    CANON_LIDE_35,
    CANON_LIDE_80,
    CANON_LIDE_110,
    CANON_LIDE_120,
    CANON_LIDE_200,
    CANON_LIDE_700F,
    CANON_4400F,
    CANON_8400F,
    CANON_8600F,
    G4050,
    IMG101,
    KVSS080,
    PLUSTEK_OPTICBOOK_3800,
    PLUSTEK_OPTICFILM_7200I,
    PLUSTEK_OPTICFILM_7300,
    PLUSTEK_OPTICFILM_7500I,
    PLUSTEK_OPTICPRO_3600,
    WOLFSON_5345,
    WOLFSON_DSM600,
    WOLFSON_HP2300,
    WOLFSON_HP2400,
    WOLFSON_HP3670,
    WOLFSON_ST12,
    WOLFSON_ST24,
    WOLFSON_UMAX,
    WOLFSON_XP300,
};

inline void serialize(std::istream& str, AdcId& x)
{
    unsigned value;
    serialize(str, value);
    x = static_cast<AdcId>(value);
}

inline void serialize(std::ostream& str, AdcId& x)
{
    unsigned value = static_cast<unsigned>(x);
    serialize(str, value);
}

enum class GpioId : unsigned
{
    UNKNOWN = 0,
    CANON_LIDE_35,
    CANON_LIDE_80,
    CANON_LIDE_110,
    CANON_LIDE_120,
    CANON_LIDE_200,
    CANON_LIDE_210,
    CANON_LIDE_700F,
    CANON_4400F,
    CANON_8400F,
    CANON_8600F,
    DP665,
    DP685,
    G4050,
    HP2300,
    HP2400,
    HP3670,
    HP_N6310,
    IMG101,
    KVSS080,
    MD_5345,
    PLUSTEK_OPTICBOOK_3800,
    PLUSTEK_OPTICFILM_7200I,
    PLUSTEK_OPTICFILM_7300,
    PLUSTEK_OPTICFILM_7500I,
    PLUSTEK_OPTICPRO_3600,
    ST12,
    ST24,
    UMAX,
    XP200,
    XP300,
};

enum class MotorId : unsigned
{
    UNKNOWN = 0,
    CANON_LIDE_100,
    CANON_LIDE_110,
    CANON_LIDE_120,
    CANON_LIDE_200,
    CANON_LIDE_210,
    CANON_LIDE_35,
    CANON_LIDE_700,
    CANON_LIDE_80,
    CANON_4400F,
    CANON_8400F,
    CANON_8600F,
    DP665,
    DSMOBILE_600,
    G4050,
    HP2300,
    HP2400,
    HP3670,
    IMG101,
    KVSS080,
    MD_5345,
    PLUSTEK_OPTICBOOK_3800,
    PLUSTEK_OPTICFILM_7200I,
    PLUSTEK_OPTICFILM_7300,
    PLUSTEK_OPTICFILM_7500I,
    PLUSTEK_OPTICPRO_3600,
    ROADWARRIOR,
    ST24,
    UMAX,
    XP200,
    XP300,
};

enum class StepType : unsigned
{
    FULL = 0,
    HALF = 1,
    QUARTER = 2,
    EIGHTH = 3,
};

std::ostream& operator<<(std::ostream& out, StepType type);

inline bool operator<(StepType lhs, StepType rhs)
{
    return static_cast<unsigned>(lhs) < static_cast<unsigned>(rhs);
}
inline bool operator<=(StepType lhs, StepType rhs)
{
    return static_cast<unsigned>(lhs) <= static_cast<unsigned>(rhs);
}
inline bool operator>(StepType lhs, StepType rhs)
{
    return static_cast<unsigned>(lhs) > static_cast<unsigned>(rhs);
}
inline bool operator>=(StepType lhs, StepType rhs)
{
    return static_cast<unsigned>(lhs) >= static_cast<unsigned>(rhs);
}

enum class AsicType : unsigned
{
    UNKNOWN = 0,
    GL646,
    GL841,
    GL843,
    GL845,
    GL846,
    GL847,
    GL124,
};


enum class ScanFlag : unsigned
{
    NONE = 0,
    SINGLE_LINE = 1 << 0,
    DISABLE_SHADING = 1 << 1,
    DISABLE_GAMMA = 1 << 2,
    DISABLE_BUFFER_FULL_MOVE = 1 << 3,
    IGNORE_LINE_DISTANCE = 1 << 4,
    DISABLE_LAMP = 1 << 5,
    CALIBRATION = 1 << 6,
    FEEDING = 1 << 7,
    USE_XPA = 1 << 8,
    ENABLE_LEDADD = 1 << 9,
    USE_XCORRECTION = 1 << 10,
    REVERSE = 1 << 11,
};

inline ScanFlag operator|(ScanFlag left, ScanFlag right)
{
    return static_cast<ScanFlag>(static_cast<unsigned>(left) | static_cast<unsigned>(right));
}

inline ScanFlag& operator|=(ScanFlag& left, ScanFlag right)
{
    left = left | right;
    return left;
}

inline ScanFlag operator&(ScanFlag left, ScanFlag right)
{
    return static_cast<ScanFlag>(static_cast<unsigned>(left) & static_cast<unsigned>(right));
}

inline bool has_flag(ScanFlag flags, ScanFlag which)
{
    return (flags & which) == which;
}

inline void serialize(std::istream& str, ScanFlag& x)
{
    unsigned value;
    serialize(str, value);
    x = static_cast<ScanFlag>(value);
}

inline void serialize(std::ostream& str, ScanFlag& x)
{
    unsigned value = static_cast<unsigned>(x);
    serialize(str, value);
}

std::ostream& operator<<(std::ostream& out, ScanFlag flags);



enum class MotorFlag : unsigned
{
    NONE = 0,
    AUTO_GO_HOME = 1 << 0,
    DISABLE_BUFFER_FULL_MOVE = 1 << 2,
    FEED = 1 << 3,
    USE_XPA = 1 << 4,
    REVERSE = 1 << 5,
};

inline MotorFlag operator|(MotorFlag left, MotorFlag right)
{
    return static_cast<MotorFlag>(static_cast<unsigned>(left) | static_cast<unsigned>(right));
}

inline MotorFlag& operator|=(MotorFlag& left, MotorFlag right)
{
    left = left | right;
    return left;
}

inline MotorFlag operator&(MotorFlag left, MotorFlag right)
{
    return static_cast<MotorFlag>(static_cast<unsigned>(left) & static_cast<unsigned>(right));
}

inline bool has_flag(MotorFlag flags, MotorFlag which)
{
    return (flags & which) == which;
}


} // namespace genesys

#endif // BACKEND_GENESYS_ENUMS_H