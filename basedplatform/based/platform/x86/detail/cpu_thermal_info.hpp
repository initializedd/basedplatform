#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// CPU Thermal Info
// https://en.wikipedia.org/wiki/CPUID#EAX=6:_Thermal_and_power_management

namespace based::platform::x86::detail {
    enum class cpu_thermal_info : std::uint8_t {
        num_of_interrupt_thresholds_bit_0,
        num_of_interrupt_thresholds_bit_1,
        num_of_interrupt_thresholds_bit_2,
        num_of_interrupt_thresholds_bit_3,
        // bits 31:4 reserved
    }; // enum class cpu_thermal_info : std::uint8_t

    enum class cpu_thermal_info_mask : std::uint32_t {
        num_of_interrupt_thresholds = 1u << std::to_underlying(cpu_thermal_info::num_of_interrupt_thresholds_bit_0)
                                    | 1u << std::to_underlying(cpu_thermal_info::num_of_interrupt_thresholds_bit_1)
                                    | 1u << std::to_underlying(cpu_thermal_info::num_of_interrupt_thresholds_bit_2)
                                    | 1u << std::to_underlying(cpu_thermal_info::num_of_interrupt_thresholds_bit_3)
    }; // enum class cpu_thermal_info_mask : std::uint32_t

    [[nodiscard]]
    cpu_thermal_info_mask supported_cpu_thermal_info(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_thermal_info_mask{};

        if (max_leaf >= 0x06) {
            using enum cpu_thermal_info;
            const auto leaf6 = cpu_id(0x06, 0x00);

            // ebx register
            if (leaf6.ebx_bit( 0u)) result |= num_of_interrupt_thresholds_bit_0;
            if (leaf6.ebx_bit( 1u)) result |= num_of_interrupt_thresholds_bit_1;
            if (leaf6.ebx_bit( 2u)) result |= num_of_interrupt_thresholds_bit_2;
            if (leaf6.ebx_bit( 3u)) result |= num_of_interrupt_thresholds_bit_3;
        }

        return result;
    }
} // namespace based::platform::x86::detail

