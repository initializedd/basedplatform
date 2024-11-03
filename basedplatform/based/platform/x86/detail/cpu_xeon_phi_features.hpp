#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// Xeon Phi Features
// https://en.wikipedia.org/wiki/CPUID#EAX=2000'0001h:_Xeon_Phi_Feature_Bits

namespace based::platform::x86::detail {
    enum class cpu_xeon_phi_feature : std::uint8_t {
        // bits 3:0 reserved
        k1om = 4u
        // bits 31:5 reserved
    }; // enum class cpu_xeon_phi_feature : std::uint8_t

    enum class cpu_xeon_phi_feature_mask : std::uint32_t {
        k1om = 1u << std::to_underlying(cpu_xeon_phi_feature::k1om)
    }; // emum class cpu_xeon_phi_feature_mask : std::uint32_t

    [[nodiscard]]
    cpu_xeon_phi_feature_mask supported_cpu_xeon_phi_features(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_xeon_phi_feature_mask{};

        if (max_leaf >= 0x20000001) {
            using enum cpu_xeon_phi_feature;
            const auto leaf_0x20000001 = cpu_id(0x20000001, 0x00);

            // eax register
            if (leaf_0x20000001.eax_bit(4u)) result |= k1om;
        }

        return result;
    }
} // namespace based::platform::x86::detail

