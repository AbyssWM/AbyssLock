#pragma once

#include <cstdint>
#include "../helpers/Log.hpp"
#include <abyssgraphics/color/Color.hpp>

class CAbyssColor {
  public:
    CAbyssColor();
    CAbyssColor(float r, float g, float b, float a);
    CAbyssColor(const Abyssgraphics::CColor& col, float a);
    CAbyssColor(uint64_t);

    // AR32
    uint32_t                     getAsHex() const;
    Abyssgraphics::CColor::SSRGB  asRGB() const;
    Abyssgraphics::CColor::SOkLab asOkLab() const;
    Abyssgraphics::CColor::SHSL   asHSL() const;
    CAbyssColor                   stripA() const;

    //
    bool operator==(const CAbyssColor& c2) const {
        return c2.r == r && c2.g == g && c2.b == b && c2.a == a;
    }

    // stubs for the AnimationMgr
    CAbyssColor operator-(const CAbyssColor& c2) const {
        RASSERT(false, "CAbyssColor: - is a STUB");
        return {};
    }

    CAbyssColor operator+(const CAbyssColor& c2) const {
        RASSERT(false, "CAbyssColor: + is a STUB");
        return {};
    }

    CAbyssColor operator*(const float& c2) const {
        RASSERT(false, "CAbyssColor: * is a STUB");
        return {};
    }

    double r = 0, g = 0, b = 0, a = 0;

  private:
    Abyssgraphics::CColor::SOkLab okLab; // cache for the OkLab representation
};
