#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// XSAVE feature flags in EAX
// https://en.wikipedia.org/wiki/CPUID#EAX=0Dh:_XSAVE_features_and_state-components

namespace based::platform::x86::detail {
    enum class cpu_xsave_feature_flag : std::uint8_t {
        xsaveopt,
        xsavec,
        xgetbv_ecx1,
        xss,
        xfd
        // bits 31:5 reserved
    }; // enum class cpu_xsave_feature_flag : std::uint8_t

    enum class cpu_xsave_feature_flag_mask : std::uint32_t {
        xsaveopt    = 1u << std::to_underlying(cpu_xsave_feature_flag::xsaveopt),
        xsavec      = 1u << std::to_underlying(cpu_xsave_feature_flag::xsavec),
        xgetbv_ecx1 = 1u << std::to_underlying(cpu_xsave_feature_flag::xgetbv_ecx1),
        xss         = 1u << std::to_underlying(cpu_xsave_feature_flag::xss),
        xfd         = 1u << std::to_underlying(cpu_xsave_feature_flag::xfd)
    }; // enum class cpu_xsave_feature_flag_mask : std::uint32_t

    [[nodiscard]]
    cpu_xsave_feature_flag_mask supported_cpu_xsave_feature_flags(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_xsave_feature_flag_mask{};

        if (max_leaf >= 0x0D) {
            using enum cpu_xsave_feature_flag;
            const auto leaf13 = cpu_id(0x0D, 0x01);

            // eax register
            if (leaf13.eax_bit(0u)) result |= xsaveopt;
            if (leaf13.eax_bit(1u)) result |= xsavec;
            if (leaf13.eax_bit(2u)) result |= xgetbv_ecx1;
            if (leaf13.eax_bit(3u)) result |= xss;
            if (leaf13.eax_bit(4u)) result |= xfd;
        }

        return result;
    }
} // namespace based::platform::x86::detail

