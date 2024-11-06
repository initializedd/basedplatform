#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"
#include "../../util.hpp"

// Processor Power Monitoring Interface info
// https://en.wikipedia.org/wiki/CPUID#EAX=80000007h:_Processor_Power_Management_Information_and_RAS_Capabilities

namespace based::platform::x86::detail {
    enum class cpu_power_monitoring_interface_feature : std::uint8_t {
        cpu_pwr_sample_time_ratio_bit_0,
        cpu_pwr_sample_time_ratio_bit_1,
        cpu_pwr_sample_time_ratio_bit_2,
        cpu_pwr_sample_time_ratio_bit_3,
        cpu_pwr_sample_time_ratio_bit_4,
        cpu_pwr_sample_time_ratio_bit_5,
        cpu_pwr_sample_time_ratio_bit_6,
        cpu_pwr_sample_time_ratio_bit_7,
        cpu_pwr_sample_time_ratio_bit_8,
        cpu_pwr_sample_time_ratio_bit_9,
        cpu_pwr_sample_time_ratio_bit_10,
        cpu_pwr_sample_time_ratio_bit_11,
        cpu_pwr_sample_time_ratio_bit_12,
        cpu_pwr_sample_time_ratio_bit_13,
        cpu_pwr_sample_time_ratio_bit_14,
        cpu_pwr_sample_time_ratio_bit_15,
        cpu_pwr_sample_time_ratio_bit_16,
        cpu_pwr_sample_time_ratio_bit_17,
        cpu_pwr_sample_time_ratio_bit_18,
        cpu_pwr_sample_time_ratio_bit_19,
        cpu_pwr_sample_time_ratio_bit_20,
        cpu_pwr_sample_time_ratio_bit_21,
        cpu_pwr_sample_time_ratio_bit_22,
        cpu_pwr_sample_time_ratio_bit_23,
        cpu_pwr_sample_time_ratio_bit_24,
        cpu_pwr_sample_time_ratio_bit_25,
        cpu_pwr_sample_time_ratio_bit_26,
        cpu_pwr_sample_time_ratio_bit_27,
        cpu_pwr_sample_time_ratio_bit_28,
        cpu_pwr_sample_time_ratio_bit_29,
        cpu_pwr_sample_time_ratio_bit_30,
        cpu_pwr_sample_time_ratio_bit_31
    }; // enum class cpu_power_monitoring_interface_feature : std::uint8_t

    enum class cpu_power_monitoring_interface_feature_mask : std::uint32_t {
        cpu_pwr_sample_time_ratio = 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_0)
                                  | 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_1)
                                  | 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_2)
                                  | 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_3)
                                  | 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_4)
                                  | 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_5)
                                  | 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_6)
                                  | 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_7)
                                  | 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_8)
                                  | 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_9)
                                  | 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_10)
                                  | 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_11)
                                  | 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_12)
                                  | 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_13)
                                  | 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_14)
                                  | 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_15)
                                  | 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_16)
                                  | 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_17)
                                  | 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_18)
                                  | 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_19)
                                  | 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_20)
                                  | 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_21)
                                  | 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_22)
                                  | 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_23)
                                  | 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_24)
                                  | 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_25)
                                  | 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_26)
                                  | 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_27)
                                  | 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_28)
                                  | 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_29)
                                  | 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_30)
                                  | 1u << std::to_underlying(cpu_power_monitoring_interface_feature::cpu_pwr_sample_time_ratio_bit_31)
    }; // enum class cpu_power_monitoring_interface_feature_mask : std::uint32_t

    [[nodiscard]]
    inline cpu_power_monitoring_interface_feature_mask supported_cpu_power_monitoring_interface_features(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_power_monitoring_interface_feature_mask{};

        if (max_leaf >= 0x80000007) {
            using enum cpu_power_monitoring_interface_feature;
            const auto leaf_0x80000007 = cpu_id(0x80000007, 0x00);

            // ecx register
            if (leaf_0x80000007.ecx_bit( 0u)) result |= cpu_pwr_sample_time_ratio_bit_0;
            if (leaf_0x80000007.ecx_bit( 1u)) result |= cpu_pwr_sample_time_ratio_bit_1;
            if (leaf_0x80000007.ecx_bit( 2u)) result |= cpu_pwr_sample_time_ratio_bit_2;
            if (leaf_0x80000007.ecx_bit( 3u)) result |= cpu_pwr_sample_time_ratio_bit_3;
            if (leaf_0x80000007.ecx_bit( 4u)) result |= cpu_pwr_sample_time_ratio_bit_4;
            if (leaf_0x80000007.ecx_bit( 5u)) result |= cpu_pwr_sample_time_ratio_bit_5;
            if (leaf_0x80000007.ecx_bit( 6u)) result |= cpu_pwr_sample_time_ratio_bit_6;
            if (leaf_0x80000007.ecx_bit( 7u)) result |= cpu_pwr_sample_time_ratio_bit_7;
            if (leaf_0x80000007.ecx_bit( 8u)) result |= cpu_pwr_sample_time_ratio_bit_8;
            if (leaf_0x80000007.ecx_bit( 9u)) result |= cpu_pwr_sample_time_ratio_bit_9;
            if (leaf_0x80000007.ecx_bit(10u)) result |= cpu_pwr_sample_time_ratio_bit_10;
            if (leaf_0x80000007.ecx_bit(11u)) result |= cpu_pwr_sample_time_ratio_bit_11;
            if (leaf_0x80000007.ecx_bit(12u)) result |= cpu_pwr_sample_time_ratio_bit_12;
            if (leaf_0x80000007.ecx_bit(13u)) result |= cpu_pwr_sample_time_ratio_bit_13;
            if (leaf_0x80000007.ecx_bit(14u)) result |= cpu_pwr_sample_time_ratio_bit_14;
            if (leaf_0x80000007.ecx_bit(15u)) result |= cpu_pwr_sample_time_ratio_bit_15;
            if (leaf_0x80000007.ecx_bit(16u)) result |= cpu_pwr_sample_time_ratio_bit_16;
            if (leaf_0x80000007.ecx_bit(17u)) result |= cpu_pwr_sample_time_ratio_bit_17;
            if (leaf_0x80000007.ecx_bit(18u)) result |= cpu_pwr_sample_time_ratio_bit_18;
            if (leaf_0x80000007.ecx_bit(19u)) result |= cpu_pwr_sample_time_ratio_bit_19;
            if (leaf_0x80000007.ecx_bit(20u)) result |= cpu_pwr_sample_time_ratio_bit_20;
            if (leaf_0x80000007.ecx_bit(21u)) result |= cpu_pwr_sample_time_ratio_bit_21;
            if (leaf_0x80000007.ecx_bit(22u)) result |= cpu_pwr_sample_time_ratio_bit_22;
            if (leaf_0x80000007.ecx_bit(23u)) result |= cpu_pwr_sample_time_ratio_bit_23;
            if (leaf_0x80000007.ecx_bit(24u)) result |= cpu_pwr_sample_time_ratio_bit_24;
            if (leaf_0x80000007.ecx_bit(25u)) result |= cpu_pwr_sample_time_ratio_bit_25;
            if (leaf_0x80000007.ecx_bit(26u)) result |= cpu_pwr_sample_time_ratio_bit_26;
            if (leaf_0x80000007.ecx_bit(27u)) result |= cpu_pwr_sample_time_ratio_bit_27;
            if (leaf_0x80000007.ecx_bit(28u)) result |= cpu_pwr_sample_time_ratio_bit_28;
            if (leaf_0x80000007.ecx_bit(29u)) result |= cpu_pwr_sample_time_ratio_bit_29;
            if (leaf_0x80000007.ecx_bit(30u)) result |= cpu_pwr_sample_time_ratio_bit_30;
            if (leaf_0x80000007.ecx_bit(31u)) result |= cpu_pwr_sample_time_ratio_bit_31;
        }

        return result;
    }
} // namespace based::platform::x86::detail

