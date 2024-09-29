#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// Processor and Bus specification frequencies
// https://en.wikipedia.org/wiki/CPUID#EAX=15h_and_EAX=16h:_CPU,_TSC,_Bus_and_Core_Crystal_Clock_frequencies

namespace based::platform::x86::detail {
    enum class cpu_base_frequency : std::uint8_t {
        base_frequency_bit_0,
        base_frequency_bit_1,
        base_frequency_bit_2,
        base_frequency_bit_3,
        base_frequency_bit_4,
        base_frequency_bit_5,
        base_frequency_bit_6,
        base_frequency_bit_7,
        base_frequency_bit_8,
        base_frequency_bit_9,
        base_frequency_bit_10,
        base_frequency_bit_11,
        base_frequency_bit_12,
        base_frequency_bit_13,
        base_frequency_bit_14,
        base_frequency_bit_15
        // bits 31:16 reserved
    }; // enum class cpu_base_frequency : std::uint8_t

    enum class cpu_base_frequency_mask : std::uint32_t {
        base_frequency = 1u << std::to_underlying(cpu_base_frequency::base_frequency_bit_0)
                       | 1u << std::to_underlying(cpu_base_frequency::base_frequency_bit_1)
                       | 1u << std::to_underlying(cpu_base_frequency::base_frequency_bit_2)
                       | 1u << std::to_underlying(cpu_base_frequency::base_frequency_bit_3)
                       | 1u << std::to_underlying(cpu_base_frequency::base_frequency_bit_4)
                       | 1u << std::to_underlying(cpu_base_frequency::base_frequency_bit_5)
                       | 1u << std::to_underlying(cpu_base_frequency::base_frequency_bit_6)
                       | 1u << std::to_underlying(cpu_base_frequency::base_frequency_bit_7)
                       | 1u << std::to_underlying(cpu_base_frequency::base_frequency_bit_8)
                       | 1u << std::to_underlying(cpu_base_frequency::base_frequency_bit_9)
                       | 1u << std::to_underlying(cpu_base_frequency::base_frequency_bit_10)
                       | 1u << std::to_underlying(cpu_base_frequency::base_frequency_bit_11)
                       | 1u << std::to_underlying(cpu_base_frequency::base_frequency_bit_12)
                       | 1u << std::to_underlying(cpu_base_frequency::base_frequency_bit_13)
                       | 1u << std::to_underlying(cpu_base_frequency::base_frequency_bit_14)
                       | 1u << std::to_underlying(cpu_base_frequency::base_frequency_bit_15)
    }; // enum class cpu_base_frequency_mask : std::uint32_t

    [[nodiscard]]
    cpu_base_frequency_mask supported_cpu_base_frequency(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_base_frequency_mask{};

        if (max_leaf >= 0x16) {
            using cpu_base_frequency;
            const auto leaf16 = cpu_id(0x16, 0u);

            // eax register
            if (leaf16.eax_bit( 0u)) result |= base_frequency_bit_0;
            if (leaf16.eax_bit( 1u)) result |= base_frequency_bit_1;
            if (leaf16.eax_bit( 2u)) result |= base_frequency_bit_2;
            if (leaf16.eax_bit( 3u)) result |= base_frequency_bit_3;
            if (leaf16.eax_bit( 4u)) result |= base_frequency_bit_4;
            if (leaf16.eax_bit( 5u)) result |= base_frequency_bit_5;
            if (leaf16.eax_bit( 6u)) result |= base_frequency_bit_6;
            if (leaf16.eax_bit( 7u)) result |= base_frequency_bit_7;
            if (leaf16.eax_bit( 8u)) result |= base_frequency_bit_8;
            if (leaf16.eax_bit( 9u)) result |= base_frequency_bit_9;
            if (leaf16.eax_bit(10u)) result |= base_frequency_bit_10;
            if (leaf16.eax_bit(11u)) result |= base_frequency_bit_11;
            if (leaf16.eax_bit(12u)) result |= base_frequency_bit_12;
            if (leaf16.eax_bit(13u)) result |= base_frequency_bit_13;
            if (leaf16.eax_bit(14u)) result |= base_frequency_bit_14;
            if (leaf16.eax_bit(15u)) result |= base_frequency_bit_15;
        }

        return result;
    }

    enum class cpu_max_frequency : std::uint8_t {
        max_frequency_bit_0,
        max_frequency_bit_1,
        max_frequency_bit_2,
        max_frequency_bit_3,
        max_frequency_bit_4,
        max_frequency_bit_5,
        max_frequency_bit_6,
        max_frequency_bit_7,
        max_frequency_bit_8,
        max_frequency_bit_9,
        max_frequency_bit_10,
        max_frequency_bit_11,
        max_frequency_bit_12,
        max_frequency_bit_13,
        max_frequency_bit_14,
        max_frequency_bit_15
        // bits 31:16 reserved
    }; // enum class cpu_max_frequency : std::uint8_t

    enum class cpu_max_frequency_mask : std::uint32_t {
        max_frequency = 1u << std::to_underlying(cpu_max_frequency::max_frequency_bit_0)
                      | 1u << std::to_underlying(cpu_max_frequency::max_frequency_bit_1)
                      | 1u << std::to_underlying(cpu_max_frequency::max_frequency_bit_2)
                      | 1u << std::to_underlying(cpu_max_frequency::max_frequency_bit_3)
                      | 1u << std::to_underlying(cpu_max_frequency::max_frequency_bit_4)
                      | 1u << std::to_underlying(cpu_max_frequency::max_frequency_bit_5)
                      | 1u << std::to_underlying(cpu_max_frequency::max_frequency_bit_6)
                      | 1u << std::to_underlying(cpu_max_frequency::max_frequency_bit_7)
                      | 1u << std::to_underlying(cpu_max_frequency::max_frequency_bit_8)
                      | 1u << std::to_underlying(cpu_max_frequency::max_frequency_bit_9)
                      | 1u << std::to_underlying(cpu_max_frequency::max_frequency_bit_10)
                      | 1u << std::to_underlying(cpu_max_frequency::max_frequency_bit_11)
                      | 1u << std::to_underlying(cpu_max_frequency::max_frequency_bit_12)
                      | 1u << std::to_underlying(cpu_max_frequency::max_frequency_bit_13)
                      | 1u << std::to_underlying(cpu_max_frequency::max_frequency_bit_14)
                      | 1u << std::to_underlying(cpu_max_frequency::max_frequency_bit_15)
    }; // enum class cpu_max_frequency_mask : std::uint32_t

    [[nodiscard]]
    cpu_max_frequency_mask supported_cpu_max_frequency(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_base_frequency_mask{};

        if (max_leaf >= 0x16) {
            using cpu_max_frequency;
            const auto leaf16 = cpu_id(0x16, 0u);

            // ebx register
            if (leaf16.ebx_bit( 0u)) result |= max_frequency_bit_0;
            if (leaf16.ebx_bit( 1u)) result |= max_frequency_bit_1;
            if (leaf16.ebx_bit( 2u)) result |= max_frequency_bit_2;
            if (leaf16.ebx_bit( 3u)) result |= max_frequency_bit_3;
            if (leaf16.ebx_bit( 4u)) result |= max_frequency_bit_4;
            if (leaf16.ebx_bit( 5u)) result |= max_frequency_bit_5;
            if (leaf16.ebx_bit( 6u)) result |= max_frequency_bit_6;
            if (leaf16.ebx_bit( 7u)) result |= max_frequency_bit_7;
            if (leaf16.ebx_bit( 8u)) result |= max_frequency_bit_8;
            if (leaf16.ebx_bit( 9u)) result |= max_frequency_bit_9;
            if (leaf16.ebx_bit(10u)) result |= max_frequency_bit_10;
            if (leaf16.ebx_bit(11u)) result |= max_frequency_bit_11;
            if (leaf16.ebx_bit(12u)) result |= max_frequency_bit_12;
            if (leaf16.ebx_bit(13u)) result |= max_frequency_bit_13;
            if (leaf16.ebx_bit(14u)) result |= max_frequency_bit_14;
            if (leaf16.ebx_bit(15u)) result |= max_frequency_bit_15;
        }

        return result;
    }

    enum class bus_frequency : std::uint8_t {
        frequency_bit_0,
        frequency_bit_1,
        frequency_bit_2,
        frequency_bit_3,
        frequency_bit_4,
        frequency_bit_5,
        frequency_bit_6,
        frequency_bit_7,
        frequency_bit_8,
        frequency_bit_9,
        frequency_bit_10,
        frequency_bit_11,
        frequency_bit_12,
        frequency_bit_13,
        frequency_bit_14,
        frequency_bit_15
        // bits 31:16 reserved
    }; // enum class bus_frequency : std::uint8_t

    enum class bus_frequency_mask : std::uint32_t {
        frequency = 1u << std::to_underlying(bus_frequency::frequency_bit_0)
                  | 1u << std::to_underlying(bus_frequency::frequency_bit_1)
                  | 1u << std::to_underlying(bus_frequency::frequency_bit_2)
                  | 1u << std::to_underlying(bus_frequency::frequency_bit_3)
                  | 1u << std::to_underlying(bus_frequency::frequency_bit_4)
                  | 1u << std::to_underlying(bus_frequency::frequency_bit_5)
                  | 1u << std::to_underlying(bus_frequency::frequency_bit_6)
                  | 1u << std::to_underlying(bus_frequency::frequency_bit_7)
                  | 1u << std::to_underlying(bus_frequency::frequency_bit_8)
                  | 1u << std::to_underlying(bus_frequency::frequency_bit_9)
                  | 1u << std::to_underlying(bus_frequency::frequency_bit_10)
                  | 1u << std::to_underlying(bus_frequency::frequency_bit_11)
                  | 1u << std::to_underlying(bus_frequency::frequency_bit_12)
                  | 1u << std::to_underlying(bus_frequency::frequency_bit_13)
                  | 1u << std::to_underlying(bus_frequency::frequency_bit_14)
                  | 1u << std::to_underlying(bus_frequency::frequency_bit_15)
    }; // enum class bus_frequency_mask : std::uint32_t

    [[nodiscard]]
    bus_frequency_mask supported_bus_frequency(const std::uint32_t max_leaf) noexcept {
        auto result = bus_frequency_mask{};

        if (max_leaf >= 0x16) {
            using bus_frequency;
            const auto leaf16 = cpu_id(0x16, 0u);

            // ecx register
            if (leaf16.ecx_bit( 0u)) result |= frequency_bit_0;
            if (leaf16.ecx_bit( 1u)) result |= frequency_bit_1;
            if (leaf16.ecx_bit( 2u)) result |= frequency_bit_2;
            if (leaf16.ecx_bit( 3u)) result |= frequency_bit_3;
            if (leaf16.ecx_bit( 4u)) result |= frequency_bit_4;
            if (leaf16.ecx_bit( 5u)) result |= frequency_bit_5;
            if (leaf16.ecx_bit( 6u)) result |= frequency_bit_6;
            if (leaf16.ecx_bit( 7u)) result |= frequency_bit_7;
            if (leaf16.ecx_bit( 8u)) result |= frequency_bit_8;
            if (leaf16.ecx_bit( 9u)) result |= frequency_bit_9;
            if (leaf16.ecx_bit(10u)) result |= frequency_bit_10;
            if (leaf16.ecx_bit(11u)) result |= frequency_bit_11;
            if (leaf16.ecx_bit(12u)) result |= frequency_bit_12;
            if (leaf16.ecx_bit(13u)) result |= frequency_bit_13;
            if (leaf16.ecx_bit(14u)) result |= frequency_bit_14;
            if (leaf16.ecx_bit(15u)) result |= frequency_bit_15;
        }

        return result;
    }
} // namespace::based::platform::x86::detail

