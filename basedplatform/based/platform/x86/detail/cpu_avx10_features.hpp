#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// AVX10 Features
// https://en.wikipedia.org/wiki/CPUID#EAX=24h,_ECX=0:_AVX10_Features

namespace based::platform::x86::detail {
    enum class cpu_avx10_feature : std::uint8_t {
        avx10_converged_bit_0,
        avx10_converged_bit_1,
        avx10_converged_bit_2,
        avx10_converged_bit_3,
        avx10_converged_bit_4,
        avx10_converged_bit_5,
        avx10_converged_bit_6,
        avx10_converged_bit_7,
        // bits 16:8 reserved
        avx10_256             = 17u,
        avx10_512
        // bits 31:19 reserved
    }; // enum class cpu_avx10_feature

    enum class cpu_avx10_feature_mask : std::uint8_t {
        avx10_converged = 1u << std::to_underlying(cpu_avx10_feature::avx10_converged_bit_0)
                        | 1u << std::to_underlying(cpu_avx10_feature::avx10_converged_bit_1)
                        | 1u << std::to_underlying(cpu_avx10_feature::avx10_converged_bit_2)
                        | 1u << std::to_underlying(cpu_avx10_feature::avx10_converged_bit_3)
                        | 1u << std::to_underlying(cpu_avx10_feature::avx10_converged_bit_4)
                        | 1u << std::to_underlying(cpu_avx10_feature::avx10_converged_bit_5)
                        | 1u << std::to_underlying(cpu_avx10_feature::avx10_converged_bit_6)
                        | 1u << std::to_underlying(cpu_avx10_feature::avx10_converged_bit_7),
        avx10_256       = 1u << std::to_underlying(cpu_avx10_feature::avx10_256),
        avx10_512       = 1u << std::to_underlying(cpu_avx10_feature::avx10_512)
        // bits 31:19 reserved
    }; // enum class cpu_avx10_feature_mask

    [[nodiscard]]
    cpu_avx10_feature_mask supported_cpu_avx10_features(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_avx10_feature_mask{};

        if (max_leaf >= 0x24) {
            using enum cpu_avx10_feature;
            const auto leaf_0x24 = cpu_id(0x24, 0x00);

            // ebx register
            if (leaf_0x24.ebx_bit( 0u)) result |= avx10_converged_bit_0;
            if (leaf_0x24.ebx_bit( 1u)) result |= avx10_converged_bit_1;
            if (leaf_0x24.ebx_bit( 2u)) result |= avx10_converged_bit_2;
            if (leaf_0x24.ebx_bit( 3u)) result |= avx10_converged_bit_3;
            if (leaf_0x24.ebx_bit( 4u)) result |= avx10_converged_bit_4;
            if (leaf_0x24.ebx_bit( 5u)) result |= avx10_converged_bit_5;
            if (leaf_0x24.ebx_bit( 6u)) result |= avx10_converged_bit_6;
            if (leaf_0x24.ebx_bit( 7u)) result |= avx10_converged_bit_7;
            if (leaf_0x24.ebx_bit(17u)) result |= avx10_256;
            if (leaf_0x24.ebx_bit(18u)) result |= avx10_512;
        }

        return result;
    }
} // namespace based::platform::x86::detail

