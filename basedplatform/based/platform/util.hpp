#pragma once

#include <type_traits>
#include <utility>

namespace based::platform {
    template <typename T, typename U> requires std::is_enum_v<T> && std::is_enum_v<U>
    T operator|(const T lhs, const U rhs) {
        return static_cast<T>(std::to_underlying(lhs) | (1u << std::to_underlying(rhs)));
    }

    template <typename T, typename U> requires std::is_enum_v<T> && std::is_enum_v<U>
    T operator|=(T& lhs, const U rhs) noexcept {
        return lhs = lhs | rhs;
    }
} // namespace based::platform

