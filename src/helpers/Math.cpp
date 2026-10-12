#include "Math.hpp"

Abyssutils::Math::eTransform wlTransformToAbyssutils(wl_output_transform t) {
    switch (t) {
        case WL_OUTPUT_TRANSFORM_NORMAL: return Abyssutils::Math::eTransform::ABYSSUTILS_TRANSFORM_NORMAL;
        case WL_OUTPUT_TRANSFORM_180: return Abyssutils::Math::eTransform::ABYSSUTILS_TRANSFORM_180;
        case WL_OUTPUT_TRANSFORM_90: return Abyssutils::Math::eTransform::ABYSSUTILS_TRANSFORM_90;
        case WL_OUTPUT_TRANSFORM_270: return Abyssutils::Math::eTransform::ABYSSUTILS_TRANSFORM_270;
        case WL_OUTPUT_TRANSFORM_FLIPPED: return Abyssutils::Math::eTransform::ABYSSUTILS_TRANSFORM_FLIPPED;
        case WL_OUTPUT_TRANSFORM_FLIPPED_180: return Abyssutils::Math::eTransform::ABYSSUTILS_TRANSFORM_FLIPPED_180;
        case WL_OUTPUT_TRANSFORM_FLIPPED_270: return Abyssutils::Math::eTransform::ABYSSUTILS_TRANSFORM_FLIPPED_270;
        case WL_OUTPUT_TRANSFORM_FLIPPED_90: return Abyssutils::Math::eTransform::ABYSSUTILS_TRANSFORM_FLIPPED_90;
        default: break;
    }
    return Abyssutils::Math::eTransform::ABYSSUTILS_TRANSFORM_NORMAL;
}

wl_output_transform invertTransform(wl_output_transform tr) {
    if ((tr & WL_OUTPUT_TRANSFORM_90) && !(tr & WL_OUTPUT_TRANSFORM_FLIPPED))
        tr = (wl_output_transform)(tr ^ (int)WL_OUTPUT_TRANSFORM_180);

    return tr;
}
