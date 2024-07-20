#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// CPU Extended Protection Features
// https://en.wikipedia.org/wiki/CPUID#EAX=7,_ECX=1:_Extended_Features

namespace based::platform::x86::detail {
    enum class cpu_extended_protection_feature : std::uint8_t {
        ppin,
        pbndkb
        // bits 31:2 reserved
    }; // enum class cpu_extended_protection_feature : std::uint8_t

    enum class cpu_extended_protection_feature_mask : std::uint32_t {
        ppin   = 1u << std::to_underlying(cpu_extended_protection_feature::ppin),
        pbndkb = 1u << std::to_underlying(cpu_extended_protection_feature::pbndkb)
    }; // enum class cpu_extended_protection_feature_mask : std::uint32_t

    [[nodiscard]]
    cpu_extended_protection_feature_mask supported_extended_protection_features(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_extended_protection_feature_mask{};

        if (max_leaf >= 0x07) {
            using enum cpu_extended_protection_feature;
            const auto leaf7 = cpu_id(0x07, 0x01);

            // ebx register
            if (leaf7.ebx_bit(0u)) result |= ppin;
            if (leaf7.ebx_bit(1u)) result |= pbndkb;
        }

        return result;
    }
} // namespace based::platform::x86::detail

