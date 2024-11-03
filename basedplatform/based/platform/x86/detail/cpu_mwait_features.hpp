#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// MWAIT Features
// https://en.wikipedia.org/wiki/CPUID#EAX=5:_MONITOR/MWAIT_Features

namespace based::platform::x86::detail {
    enum class cpu_mwait_feature : std::uint8_t {
        c0_sub_states_supported_bit_0,
        c0_sub_states_supported_bit_1,
        c0_sub_states_supported_bit_2,
        c0_sub_states_supported_bit_3,
        c1_sub_states_supported_bit_0,
        c1_sub_states_supported_bit_1,
        c1_sub_states_supported_bit_2,
        c1_sub_states_supported_bit_3,
        c2_sub_states_supported_bit_0,
        c2_sub_states_supported_bit_1,
        c2_sub_states_supported_bit_2,
        c2_sub_states_supported_bit_3,
        c3_sub_states_supported_bit_0,
        c3_sub_states_supported_bit_1,
        c3_sub_states_supported_bit_2,
        c3_sub_states_supported_bit_3,
        c4_sub_states_supported_bit_0,
        c4_sub_states_supported_bit_1,
        c4_sub_states_supported_bit_2,
        c4_sub_states_supported_bit_3,
        c5_sub_states_supported_bit_0,
        c5_sub_states_supported_bit_1,
        c5_sub_states_supported_bit_2,
        c5_sub_states_supported_bit_3,
        c6_sub_states_supported_bit_0,
        c6_sub_states_supported_bit_1,
        c6_sub_states_supported_bit_2,
        c6_sub_states_supported_bit_3,
        c7_sub_states_supported_bit_0,
        c7_sub_states_supported_bit_1,
        c7_sub_states_supported_bit_2,
        c7_sub_states_supported_bit_3
    }; // enum class cpu_mwait_feature : std::uint8_t

    enum class cpu_mwait_feature_edx_mask : std::uint32_t {
        c0_sub_states_supported = 1u << std::to_underlying(cpu_mwait_feature::c0_sub_states_supported_bit_0)
                                | 1u << std::to_underlying(cpu_mwait_feature::c0_sub_states_supported_bit_1)
                                | 1u << std::to_underlying(cpu_mwait_feature::c0_sub_states_supported_bit_2)
                                | 1u << std::to_underlying(cpu_mwait_feature::c0_sub_states_supported_bit_3),
        c1_sub_states_supported = 1u << std::to_underlying(cpu_mwait_feature::c1_sub_states_supported_bit_0)
                                | 1u << std::to_underlying(cpu_mwait_feature::c1_sub_states_supported_bit_1)
                                | 1u << std::to_underlying(cpu_mwait_feature::c1_sub_states_supported_bit_2)
                                | 1u << std::to_underlying(cpu_mwait_feature::c1_sub_states_supported_bit_3),
        c2_sub_states_supported = 1u << std::to_underlying(cpu_mwait_feature::c2_sub_states_supported_bit_0)
                                | 1u << std::to_underlying(cpu_mwait_feature::c2_sub_states_supported_bit_1)
                                | 1u << std::to_underlying(cpu_mwait_feature::c2_sub_states_supported_bit_2)
                                | 1u << std::to_underlying(cpu_mwait_feature::c2_sub_states_supported_bit_3),
        c3_sub_states_supported = 1u << std::to_underlying(cpu_mwait_feature::c3_sub_states_supported_bit_0)
                                | 1u << std::to_underlying(cpu_mwait_feature::c3_sub_states_supported_bit_1)
                                | 1u << std::to_underlying(cpu_mwait_feature::c3_sub_states_supported_bit_2)
                                | 1u << std::to_underlying(cpu_mwait_feature::c3_sub_states_supported_bit_3),
        c4_sub_states_supported = 1u << std::to_underlying(cpu_mwait_feature::c4_sub_states_supported_bit_0)
                                | 1u << std::to_underlying(cpu_mwait_feature::c4_sub_states_supported_bit_1)
                                | 1u << std::to_underlying(cpu_mwait_feature::c4_sub_states_supported_bit_2)
                                | 1u << std::to_underlying(cpu_mwait_feature::c4_sub_states_supported_bit_3),
        c5_sub_states_supported = 1u << std::to_underlying(cpu_mwait_feature::c5_sub_states_supported_bit_0)
                                | 1u << std::to_underlying(cpu_mwait_feature::c5_sub_states_supported_bit_1)
                                | 1u << std::to_underlying(cpu_mwait_feature::c5_sub_states_supported_bit_2)
                                | 1u << std::to_underlying(cpu_mwait_feature::c5_sub_states_supported_bit_3),
        c6_sub_states_supported = 1u << std::to_underlying(cpu_mwait_feature::c6_sub_states_supported_bit_0)
                                | 1u << std::to_underlying(cpu_mwait_feature::c6_sub_states_supported_bit_1)
                                | 1u << std::to_underlying(cpu_mwait_feature::c6_sub_states_supported_bit_2)
                                | 1u << std::to_underlying(cpu_mwait_feature::c6_sub_states_supported_bit_3),
        c7_sub_states_supported = 1u << std::to_underlying(cpu_mwait_feature::c7_sub_states_supported_bit_0)
                                | 1u << std::to_underlying(cpu_mwait_feature::c7_sub_states_supported_bit_1)
                                | 1u << std::to_underlying(cpu_mwait_feature::c7_sub_states_supported_bit_2)
                                | 1u << std::to_underlying(cpu_mwait_feature::c7_sub_states_supported_bit_3)
    }; // enum class cpu_mwait_feature_mask : std::uint32_t

    [[nodiscard]]
    cpu_mwait_feature_mask supported_cpu_mwait_features(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_mwait_feature_mask{};

        if (max_leaf >= 0x05) {
            using enum cpu_mwait_feature;
            const auto leaf_0x05 = cpu_id(0x05, 0x00);

            // edx register
            if (leaf_0x05.edx_bit( 0u)) result |= c0_sub_states_supported_bit_0;
            if (leaf_0x05.edx_bit( 1u)) result |= c0_sub_states_supported_bit_1;
            if (leaf_0x05.edx_bit( 2u)) result |= c0_sub_states_supported_bit_2;
            if (leaf_0x05.edx_bit( 3u)) result |= c0_sub_states_supported_bit_3;
            if (leaf_0x05.edx_bit( 4u)) result |= c1_sub_states_supported_bit_0;
            if (leaf_0x05.edx_bit( 5u)) result |= c1_sub_states_supported_bit_1;
            if (leaf_0x05.edx_bit( 6u)) result |= c1_sub_states_supported_bit_2;
            if (leaf_0x05.edx_bit( 7u)) result |= c1_sub_states_supported_bit_3;
            if (leaf_0x05.edx_bit( 8u)) result |= c2_sub_states_supported_bit_0;
            if (leaf_0x05.edx_bit( 9u)) result |= c2_sub_states_supported_bit_1;
            if (leaf_0x05.edx_bit(10u)) result |= c2_sub_states_supported_bit_2;
            if (leaf_0x05.edx_bit(11u)) result |= c2_sub_states_supported_bit_3;
            if (leaf_0x05.edx_bit(12u)) result |= c3_sub_states_supported_bit_0;
            if (leaf_0x05.edx_bit(13u)) result |= c3_sub_states_supported_bit_1;
            if (leaf_0x05.edx_bit(14u)) result |= c3_sub_states_supported_bit_2;
            if (leaf_0x05.edx_bit(15u)) result |= c3_sub_states_supported_bit_3;
            if (leaf_0x05.edx_bit(16u)) result |= c4_sub_states_supported_bit_0;
            if (leaf_0x05.edx_bit(17u)) result |= c4_sub_states_supported_bit_1;
            if (leaf_0x05.edx_bit(18u)) result |= c4_sub_states_supported_bit_2;
            if (leaf_0x05.edx_bit(19u)) result |= c4_sub_states_supported_bit_3;
            if (leaf_0x05.edx_bit(20u)) result |= c5_sub_states_supported_bit_0;
            if (leaf_0x05.edx_bit(21u)) result |= c5_sub_states_supported_bit_1;
            if (leaf_0x05.edx_bit(22u)) result |= c5_sub_states_supported_bit_2;
            if (leaf_0x05.edx_bit(23u)) result |= c5_sub_states_supported_bit_3;
            if (leaf_0x05.edx_bit(24u)) result |= c6_sub_states_supported_bit_0;
            if (leaf_0x05.edx_bit(25u)) result |= c6_sub_states_supported_bit_1;
            if (leaf_0x05.edx_bit(26u)) result |= c6_sub_states_supported_bit_2;
            if (leaf_0x05.edx_bit(27u)) result |= c6_sub_states_supported_bit_3;
            if (leaf_0x05.edx_bit(28u)) result |= c7_sub_states_supported_bit_0;
            if (leaf_0x05.edx_bit(29u)) result |= c7_sub_states_supported_bit_1;
            if (leaf_0x05.edx_bit(30u)) result |= c7_sub_states_supported_bit_2;
            if (leaf_0x05.edx_bit(31u)) result |= c7_sub_states_supported_bit_3;
        }

        return result;
    }
} // namespace based::platform::x86::detail

