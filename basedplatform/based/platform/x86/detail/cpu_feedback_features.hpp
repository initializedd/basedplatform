#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// Processor Feedback info
// https://en.wikipedia.org/wiki/CPUID#EAX=80000007h:_Processor_Power_Management_Information_and_RAS_Capabilities

namespace based::platform::x86::detail {
    enum class cpu_feedback_feature : std::uint8_t {
        num_of_monitors_bit_0,
        num_of_monitors_bit_1,
        num_of_monitors_bit_2,
        num_of_monitors_bit_3,
        num_of_monitors_bit_4,
        num_of_monitors_bit_5,
        num_of_monitors_bit_6,
        num_of_monitors_bit_7,
        version_bit_0,
        version_bit_1,
        version_bit_2,
        version_bit_3,
        version_bit_4,
        version_bit_5,
        version_bit_6,
        version_bit_7,
        max_wrap_time_bit_0,
        max_wrap_time_bit_1,
        max_wrap_time_bit_2,
        max_wrap_time_bit_3,
        max_wrap_time_bit_4,
        max_wrap_time_bit_5,
        max_wrap_time_bit_6,
        max_wrap_time_bit_7,
        max_wrap_time_bit_8,
        max_wrap_time_bit_9,
        max_wrap_time_bit_10,
        max_wrap_time_bit_11,
        max_wrap_time_bit_12,
        max_wrap_time_bit_13,
        max_wrap_time_bit_14,
        max_wrap_time_bit_15
    }; // enum class cpu_feedback_feature : std::uint8_t

    enum class cpu_feedback_feature_mask : std::uint32_t {
        num_of_monitors = 1u << std::to_underlying(cpu_feedback_feature::num_of_monitors_bit_0)
                        | 1u << std::to_underlying(cpu_feedback_feature::num_of_monitors_bit_1)
                        | 1u << std::to_underlying(cpu_feedback_feature::num_of_monitors_bit_2)
                        | 1u << std::to_underlying(cpu_feedback_feature::num_of_monitors_bit_3)
                        | 1u << std::to_underlying(cpu_feedback_feature::num_of_monitors_bit_4)
                        | 1u << std::to_underlying(cpu_feedback_feature::num_of_monitors_bit_5)
                        | 1u << std::to_underlying(cpu_feedback_feature::num_of_monitors_bit_6)
                        | 1u << std::to_underlying(cpu_feedback_feature::num_of_monitors_bit_7),
        version         = 1u << std::to_underlying(cpu_feedback_feature::version_bit_0)
                        | 1u << std::to_underlying(cpu_feedback_feature::version_bit_1)
                        | 1u << std::to_underlying(cpu_feedback_feature::version_bit_2)
                        | 1u << std::to_underlying(cpu_feedback_feature::version_bit_3)
                        | 1u << std::to_underlying(cpu_feedback_feature::version_bit_4)
                        | 1u << std::to_underlying(cpu_feedback_feature::version_bit_5)
                        | 1u << std::to_underlying(cpu_feedback_feature::version_bit_6)
                        | 1u << std::to_underlying(cpu_feedback_feature::version_bit_7),
        max_wrap_time   = 1u << std::to_underlying(cpu_feedback_feature::max_wrap_time_bit_0)
                        | 1u << std::to_underlying(cpu_feedback_feature::max_wrap_time_bit_1)
                        | 1u << std::to_underlying(cpu_feedback_feature::max_wrap_time_bit_2)
                        | 1u << std::to_underlying(cpu_feedback_feature::max_wrap_time_bit_3)
                        | 1u << std::to_underlying(cpu_feedback_feature::max_wrap_time_bit_4)
                        | 1u << std::to_underlying(cpu_feedback_feature::max_wrap_time_bit_5)
                        | 1u << std::to_underlying(cpu_feedback_feature::max_wrap_time_bit_6)
                        | 1u << std::to_underlying(cpu_feedback_feature::max_wrap_time_bit_7)
                        | 1u << std::to_underlying(cpu_feedback_feature::max_wrap_time_bit_8)
                        | 1u << std::to_underlying(cpu_feedback_feature::max_wrap_time_bit_9)
                        | 1u << std::to_underlying(cpu_feedback_feature::max_wrap_time_bit_10)
                        | 1u << std::to_underlying(cpu_feedback_feature::max_wrap_time_bit_11)
                        | 1u << std::to_underlying(cpu_feedback_feature::max_wrap_time_bit_12)
                        | 1u << std::to_underlying(cpu_feedback_feature::max_wrap_time_bit_13)
                        | 1u << std::to_underlying(cpu_feedback_feature::max_wrap_time_bit_14)
                        | 1u << std::to_underlying(cpu_feedback_feature::max_wrap_time_bit_15)
    }; // enum class cpu_feedback_feature_mask : std::uint32_t

    [[nodiscard]]
    cpu_feedback_feature_mask supported_cpu_feedback_features(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_feedback_feature_mask{};

        if (max_leaf >= 0x80000007) {
            using cpu_feedback_feature;
            const auto leaf8 = cpu_id(0x80000007, 0u);

            // eax register
            if (leaf8.eax_bit( 0u)) result |= num_of_monitors_bit_0;
            if (leaf8.eax_bit( 1u)) result |= num_of_monitors_bit_1;
            if (leaf8.eax_bit( 2u)) result |= num_of_monitors_bit_2;
            if (leaf8.eax_bit( 3u)) result |= num_of_monitors_bit_3;
            if (leaf8.eax_bit( 4u)) result |= num_of_monitors_bit_4;
            if (leaf8.eax_bit( 5u)) result |= num_of_monitors_bit_5;
            if (leaf8.eax_bit( 6u)) result |= num_of_monitors_bit_6;
            if (leaf8.eax_bit( 7u)) result |= num_of_monitors_bit_7;
            if (leaf8.eax_bit( 8u)) result |= version_bit_0;
            if (leaf8.eax_bit( 9u)) result |= version_bit_1;
            if (leaf8.eax_bit(10u)) result |= version_bit_2;
            if (leaf8.eax_bit(11u)) result |= version_bit_3;
            if (leaf8.eax_bit(12u)) result |= version_bit_4;
            if (leaf8.eax_bit(13u)) result |= version_bit_5;
            if (leaf8.eax_bit(14u)) result |= version_bit_6;
            if (leaf8.eax_bit(15u)) result |= version_bit_7;
            if (leaf8.eax_bit(16u)) result |= max_wrap_time_bit_0;
            if (leaf8.eax_bit(17u)) result |= max_wrap_time_bit_1;
            if (leaf8.eax_bit(18u)) result |= max_wrap_time_bit_2;
            if (leaf8.eax_bit(19u)) result |= max_wrap_time_bit_3;
            if (leaf8.eax_bit(20u)) result |= max_wrap_time_bit_4;
            if (leaf8.eax_bit(21u)) result |= max_wrap_time_bit_5;
            if (leaf8.eax_bit(22u)) result |= max_wrap_time_bit_6;
            if (leaf8.eax_bit(23u)) result |= max_wrap_time_bit_7;
            if (leaf8.eax_bit(24u)) result |= max_wrap_time_bit_8;
            if (leaf8.eax_bit(25u)) result |= max_wrap_time_bit_9;
            if (leaf8.eax_bit(26u)) result |= max_wrap_time_bit_10;
            if (leaf8.eax_bit(27u)) result |= max_wrap_time_bit_11;
            if (leaf8.eax_bit(28u)) result |= max_wrap_time_bit_12;
            if (leaf8.eax_bit(29u)) result |= max_wrap_time_bit_13;
            if (leaf8.eax_bit(30u)) result |= max_wrap_time_bit_14;
            if (leaf8.eax_bit(31u)) result |= max_wrap_time_bit_15;
        }

        return result;
    }
} // namespace based::platform::x86::detail

