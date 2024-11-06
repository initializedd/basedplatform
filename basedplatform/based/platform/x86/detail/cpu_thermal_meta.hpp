#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"
#include "../../util.hpp"

// CPU Thermal Meta
// https://en.wikipedia.org/wiki/CPUID#EAX=6:_Thermal_and_power_management

namespace based::platform::x86::detail {
    enum class cpu_thermal_meta : std::uint8_t {
        effective_frequency_interface,
        acnt2,
        // bit 2 reserved
        performance_energy_bias              = 3u,
        // bits 7:4 reserved
        num_of_thread_director_classes_bit_0 = 8u,
        num_of_thread_director_classes_bit_1,
        num_of_thread_director_classes_bit_2,
        num_of_thread_director_classes_bit_3,
        num_of_thread_director_classes_bit_4,
        num_of_thread_director_classes_bit_5,
        num_of_thread_director_classes_bit_6,
        num_of_thread_director_classes_bit_7,
        // bits 31:16 reserved
    }; // enum class cpu_thermal_meta : std::uint8_t

    enum class cpu_thermal_meta_mask : std::uint32_t {
        effective_frequency_interface  = 1u << std::to_underlying(cpu_thermal_meta::effective_frequency_interface),
        acnt2                          = 1u << std::to_underlying(cpu_thermal_meta::acnt2),
        performance_energy_bias        = 1u << std::to_underlying(cpu_thermal_meta::performance_energy_bias),
        num_of_thread_director_classes = 1u << std::to_underlying(cpu_thermal_meta::num_of_thread_director_classes_bit_0)
                                       | 1u << std::to_underlying(cpu_thermal_meta::num_of_thread_director_classes_bit_1)
                                       | 1u << std::to_underlying(cpu_thermal_meta::num_of_thread_director_classes_bit_2)
                                       | 1u << std::to_underlying(cpu_thermal_meta::num_of_thread_director_classes_bit_3)
                                       | 1u << std::to_underlying(cpu_thermal_meta::num_of_thread_director_classes_bit_4)
                                       | 1u << std::to_underlying(cpu_thermal_meta::num_of_thread_director_classes_bit_5)
                                       | 1u << std::to_underlying(cpu_thermal_meta::num_of_thread_director_classes_bit_6)
                                       | 1u << std::to_underlying(cpu_thermal_meta::num_of_thread_director_classes_bit_7)
    }; // enum class cpu_thermal_meta_mask : std::uint32_t

    [[nodiscard]]
    inline cpu_thermal_meta_mask supported_cpu_thermal_meta(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_thermal_meta_mask{};

        if (max_leaf >= 0x06) {
            using enum cpu_thermal_meta;
            const auto leaf_0x06 = cpu_id(0x06, 0x00);

            // ecx register
            if (leaf_0x06.ecx_bit( 0u)) result |= effective_frequency_interface;
            if (leaf_0x06.ecx_bit( 1u)) result |= acnt2;
            if (leaf_0x06.ecx_bit( 3u)) result |= performance_energy_bias;
            if (leaf_0x06.ecx_bit( 8u)) result |= num_of_thread_director_classes_bit_0;
            if (leaf_0x06.ecx_bit( 9u)) result |= num_of_thread_director_classes_bit_1;
            if (leaf_0x06.ecx_bit(10u)) result |= num_of_thread_director_classes_bit_2;
            if (leaf_0x06.ecx_bit(11u)) result |= num_of_thread_director_classes_bit_3;
            if (leaf_0x06.ecx_bit(12u)) result |= num_of_thread_director_classes_bit_4;
            if (leaf_0x06.ecx_bit(13u)) result |= num_of_thread_director_classes_bit_5;
            if (leaf_0x06.ecx_bit(14u)) result |= num_of_thread_director_classes_bit_6;
            if (leaf_0x06.ecx_bit(15u)) result |= num_of_thread_director_classes_bit_7;
        }

        return result;
    }
} // namespace based::platform::x86::detail

