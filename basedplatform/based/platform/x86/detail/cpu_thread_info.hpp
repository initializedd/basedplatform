#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// CPU Thread Info
// https://en.wikipedia.org/wiki/CPUID#EAX=80000008h:_Virtual_and_Physical_address_Sizes

namespace based::platform::x86::detail {
    enum class cpu_thread_info : std::uint8_t {
        num_of_physical_threads_bit_0,
        num_of_physical_threads_bit_1,
        num_of_physical_threads_bit_2,
        num_of_physical_threads_bit_3,
        num_of_physical_threads_bit_4,
        num_of_physical_threads_bit_5,
        num_of_physical_threads_bit_6,
        num_of_physical_threads_bit_7,
        // bits 11:8 reserved
        apic_id_size_bit_0                       = 12u,
        apic_id_size_bit_1,
        apic_id_size_bit_2,
        apic_id_size_bit_3,
        performance_timestamp_counter_size_bit_0,
        performance_timestamp_counter_size_bit_1
        // bits 31:18 reserved
    }; // enum class cpu_thread_info : std::uint8_t

    enum class cpu_thread_info_mask : std::uint32_t {
        num_of_physical_threads            = 1u << std::to_underlying(cpu_thread_info::num_of_physical_threads_bit_0)
                                           | 1u << std::to_underlying(cpu_thread_info::num_of_physical_threads_bit_1)
                                           | 1u << std::to_underlying(cpu_thread_info::num_of_physical_threads_bit_2)
                                           | 1u << std::to_underlying(cpu_thread_info::num_of_physical_threads_bit_3)
                                           | 1u << std::to_underlying(cpu_thread_info::num_of_physical_threads_bit_4)
                                           | 1u << std::to_underlying(cpu_thread_info::num_of_physical_threads_bit_5)
                                           | 1u << std::to_underlying(cpu_thread_info::num_of_physical_threads_bit_6)
                                           | 1u << std::to_underlying(cpu_thread_info::num_of_physical_threads_bit_7),
        apic_id_size                       = 1u << std::to_underlying(cpu_thread_info::apic_id_size_bit_0)
                                           | 1u << std::to_underlying(cpu_thread_info::apic_id_size_bit_1)
                                           | 1u << std::to_underlying(cpu_thread_info::apic_id_size_bit_2)
                                           | 1u << std::to_underlying(cpu_thread_info::apic_id_size_bit_3),
        performance_timestamp_counter_size = 1u << std::to_underlying(cpu_thread_info::performance_timestamp_counter_size_bit_0)
                                           | 1u << std::to_underlying(cpu_thread_info::performance_timestamp_counter_size_bit_1)
    }; // enum class cpu_thread_info_mask : std::uint32_t

    [[nodiscard]]
    cpu_thread_info_mask supported_cpu_thread_info(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_thread_info_mask{};

        if (max_leaf >= 0x80000008) {
            using cpu_thread_info;
            const auto leaf8 = cpu_id(0x80000008, 0u);

            // ecx register
            if (leaf8.ecx_bit( 0u)) result |= num_of_physical_address_bit_0;
            if (leaf8.ecx_bit( 1u)) result |= num_of_physical_address_bit_1;
            if (leaf8.ecx_bit( 2u)) result |= num_of_physical_address_bit_2;
            if (leaf8.ecx_bit( 3u)) result |= num_of_physical_address_bit_3;
            if (leaf8.ecx_bit( 4u)) result |= num_of_physical_address_bit_4;
            if (leaf8.ecx_bit( 5u)) result |= num_of_physical_address_bit_5;
            if (leaf8.ecx_bit( 6u)) result |= num_of_physical_address_bit_6;
            if (leaf8.ecx_bit( 7u)) result |= num_of_physical_address_bit_7;
            if (leaf8.ecx_bit(12u)) result |= apic_id_size_bit_0;
            if (leaf8.ecx_bit(13u)) result |= apic_id_size_bit_1;
            if (leaf8.ecx_bit(14u)) result |= apic_id_size_bit_2;
            if (leaf8.ecx_bit(15u)) result |= apic_id_size_bit_3;
            if (leaf8.ecx_bit(16u)) result |= performance_timestamp_counter_size_bit_0;
            if (leaf8.ecx_bit(17u)) result |= performance_timestamp_counter_size_bit_1;
        }

        return result;
    }
} // namespace based::platform::x86::detail

