#pragma once

#include <wayland-client.h>

#include <abyssutils/math/Box.hpp>
#include <abyssutils/math/Vector2D.hpp>
#include <abyssutils/math/Mat3x3.hpp>

using namespace Abyssutils::Math;

eTransform          wlTransformToAbyssutils(wl_output_transform t);
wl_output_transform invertTransform(wl_output_transform tr);
