#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// CPU Extended Compat Features
// https://en.wikipedia.org/wiki/CPUID#EAX=7,_ECX=1:_Extended_Features

namespace based::platform::x86::detail {
    enum class cpu_extended_compat_feature : std::uint8_t {
        // bits 1:0 reserved
        legacy_reduced_isa = 2u,
        // bit 3 reserved
        sipi64             = 4u
        // bits 31:5 reserved
    }; // enum class cpu_extended_compat_feature : std::uint8_t

    enum class cpu_extended_compat_feature_mask : std::uint32_t {
        legacy_reduced_isa = 1u << std::to_underlying(cpu_extended_compat_feature::legacy_reduced_isa),
        sipi64             = 1u << std::to_underlying(cpu_extended_compat_feature::sipi64)
    }; // enum class cpu_extended_compat_feature_mask : std::uint32_t

    [[nodiscard]]
    cpu_extended_compat_feature_mask supported_extended_compat_features(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_extended_compat_feature_mask{};

        if (max_leaf >= 7u) {
            using cpu_extended_compat_feature;
            const auto leaf7 = cpu_id(7u, 1u);

            // ecx register
            if (leaf7.ecx_bit(2u)) result |= legacy_reduced_isa;
            if (leaf7.ecx_bit(4u)) result |= sipi64;
        }

        return result;
    }
} // namespace based::platform::x86::detail

