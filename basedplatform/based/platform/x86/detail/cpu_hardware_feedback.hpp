#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// CPU Hardware Feedback
// https://en.wikipedia.org/wiki/CPUID#EAX=6:_Thermal_and_power_management

namespace based::platform::x86::detail {
    enum class cpu_hardware_feedback : std::uint8_t {
        performance_reporting,
        efficiency_reporting,
        // bits 7:2 reserved
        size_of_hardware_feedback_interface_bit_0 = 8u,
        size_of_hardware_feedback_interface_bit_1,
        size_of_hardware_feedback_interface_bit_2,
        size_of_hardware_feedback_interface_bit_3,
        // bits 15:12 reserved
        row_index_bit_0                           = 16u,
        row_index_bit_1,
        row_index_bit_2,
        row_index_bit_3,
        row_index_bit_4,
        row_index_bit_5,
        row_index_bit_6,
        row_index_bit_7,
        row_index_bit_8,
        row_index_bit_9,
        row_index_bit_10,
        row_index_bit_11,
        row_index_bit_12,
        row_index_bit_13,
        row_index_bit_14,
        row_index_bit_15
    }; // enum class cpu_hardware_feedback : std::uint8_t

    enum class cpu_hardware_feedback_mask : std::uint32_t {
        performance_reporting               = 1u << std::to_underlying(cpu_hardware_feedback::performance_reporting),
        efficiency_reporting                = 1u << std::to_underlying(cpu_hardware_feedback::efficiency_reporting),
        size_of_hardware_feedback_interface = 1u << std::to_underlying(cpu_hardware_feedback::size_of_hardware_feedback_interface_bit_0)
                                            | 1u << std::to_underlying(cpu_hardware_feedback::size_of_hardware_feedback_interface_bit_1)
                                            | 1u << std::to_underlying(cpu_hardware_feedback::size_of_hardware_feedback_interface_bit_2)
                                            | 1u << std::to_underlying(cpu_hardware_feedback::size_of_hardware_feedback_interface_bit_3),
        row_index                           = 1u << std::to_underlying(cpu_hardware_feedback::row_index_bit_0)
                                            | 1u << std::to_underlying(cpu_hardware_feedback::row_index_bit_1)
                                            | 1u << std::to_underlying(cpu_hardware_feedback::row_index_bit_2)
                                            | 1u << std::to_underlying(cpu_hardware_feedback::row_index_bit_3)
                                            | 1u << std::to_underlying(cpu_hardware_feedback::row_index_bit_4)
                                            | 1u << std::to_underlying(cpu_hardware_feedback::row_index_bit_5)
                                            | 1u << std::to_underlying(cpu_hardware_feedback::row_index_bit_6)
                                            | 1u << std::to_underlying(cpu_hardware_feedback::row_index_bit_7)
                                            | 1u << std::to_underlying(cpu_hardware_feedback::row_index_bit_8)
                                            | 1u << std::to_underlying(cpu_hardware_feedback::row_index_bit_9)
                                            | 1u << std::to_underlying(cpu_hardware_feedback::row_index_bit_10)
                                            | 1u << std::to_underlying(cpu_hardware_feedback::row_index_bit_11)
                                            | 1u << std::to_underlying(cpu_hardware_feedback::row_index_bit_12)
                                            | 1u << std::to_underlying(cpu_hardware_feedback::row_index_bit_13)
                                            | 1u << std::to_underlying(cpu_hardware_feedback::row_index_bit_14)
                                            | 1u << std::to_underlying(cpu_hardware_feedback::row_index_bit_15)
    }; // enum class cpu_hardware_feedback_mask : std::uint32_t

    [[nodiscard]]
    cpu_hardware_feedback_mask supported_cpu_hardware_feedback(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_hardware_feedback_mask{};

        if (max_leaf >= 0x06) {
            using enum cpu_hardware_feedback;
            const auto leaf6 = cpu_id(0x06, 0x00);

            // edx register
            if (leaf6.edx_bit( 0u)) result |= performance_reporting;
            if (leaf6.edx_bit( 1u)) result |= efficiency_reporting;
            if (leaf6.edx_bit( 8u)) result |= size_of_hardware_feedback_interface_bit_0;
            if (leaf6.edx_bit( 9u)) result |= size_of_hardware_feedback_interface_bit_1;
            if (leaf6.edx_bit(10u)) result |= size_of_hardware_feedback_interface_bit_2;
            if (leaf6.edx_bit(11u)) result |= size_of_hardware_feedback_interface_bit_3;
            if (leaf6.edx_bit(16u)) result |= row_index_bit_0;
            if (leaf6.edx_bit(17u)) result |= row_index_bit_1;
            if (leaf6.edx_bit(18u)) result |= row_index_bit_2;
            if (leaf6.edx_bit(19u)) result |= row_index_bit_3;
            if (leaf6.edx_bit(20u)) result |= row_index_bit_4;
            if (leaf6.edx_bit(21u)) result |= row_index_bit_5;
            if (leaf6.edx_bit(22u)) result |= row_index_bit_6;
            if (leaf6.edx_bit(23u)) result |= row_index_bit_7;
            if (leaf6.edx_bit(24u)) result |= row_index_bit_8;
            if (leaf6.edx_bit(25u)) result |= row_index_bit_9;
            if (leaf6.edx_bit(26u)) result |= row_index_bit_10;
            if (leaf6.edx_bit(27u)) result |= row_index_bit_11;
            if (leaf6.edx_bit(28u)) result |= row_index_bit_12;
            if (leaf6.edx_bit(29u)) result |= row_index_bit_13;
            if (leaf6.edx_bit(30u)) result |= row_index_bit_14;
            if (leaf6.edx_bit(31u)) result |= row_index_bit_15;
        }

        return result;
    }
} // namespace based::platform::x86::detail

