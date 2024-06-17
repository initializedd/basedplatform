#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// RAS Capabilities
// https://en.wikipedia.org/wiki/CPUID#EAX=80000007h:_Processor_Power_Management_Information_and_RAS_Capabilities

namespace based::platform::x86::detail {
    enum class cpu_ras_feature : std::uint8_t {
        mca_overflow_recov,
        succor,
        hwa,
        scalable_mca
        // bits 31:4 reserved
    }; // enum class cpu_ras_feature

    enum class cpu_ras_feature_mask : std::uint32_t {
        mca_overflow_recov = 1u << std::to_underlying(cpu_ras_feature::mca_overflow_recov),
        succor             = 1u << std::to_underlying(cpu_ras_feature::succor),
        hwa                = 1u << std::to_underlying(cpu_ras_feature::hwa),
        scalable_mca       = 1u << std::to_underlying(cpu_ras_feature::scalable_mca)
    }; // enum class cpu_ras_feature_mask : std::uint32_t

    [[nodiscard]]
    cpu_ras_feature_mask supported_cpu_ras_features(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_ras_feature_mask{};

        if (max_leaf >= 0x80000007) {
            using enum cpu_ras_feature;
            const auto leaf8 = cpu_id(0x80000007, 0x00);

            // ebx register
            if (leaf8.ebx_bit(0u)) result |= mca_overflow_recov;
            if (leaf8.ebx_bit(1u)) result |= succor;
            if (leaf8.ebx_bit(2u)) result |= hwa;
            if (leaf8.ebx_bit(3u)) result |= scalable_mca;
        }

        return result;
    }
} // namespace based::platform::x86::detail

