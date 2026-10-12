#pragma once

#include <abyssutils/memory/WeakPtr.hpp>
#include <abyssutils/memory/UniquePtr.hpp>
#include <abyssutils/memory/Atomic.hpp>
#include <abyssgraphics/color/Color.hpp>

using namespace Abyssutils::Memory;
using namespace Abyssgraphics;

using ResourceID = size_t;

#define SP CSharedPointer
#define WP CWeakPointer
#define UP CUniquePointer

#define ASP CAtomicSharedPointer
#define AWP CAtomicWeakPointer

typedef int64_t    OUTPUTID;
constexpr OUTPUTID OUTPUT_INVALID = -1;
