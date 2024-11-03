#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// Monitor-Line Info
// https://en.wikipedia.org/wiki/CPUID#EAX=5:_MONITOR/MWAIT_Features

namespace based::platform::x86::detail {
    enum class cpu_smallest_monitor_line_info : std::uint8_t {
        smallest_monitor_line_bit_0,
        smallest_monitor_line_bit_1,
        smallest_monitor_line_bit_2,
        smallest_monitor_line_bit_3,
        smallest_monitor_line_bit_4,
        smallest_monitor_line_bit_5,
        smallest_monitor_line_bit_6,
        smallest_monitor_line_bit_7,
        smallest_monitor_line_bit_8,
        smallest_monitor_line_bit_9,
        smallest_monitor_line_bit_10,
        smallest_monitor_line_bit_11,
        smallest_monitor_line_bit_12,
        smallest_monitor_line_bit_13,
        smallest_monitor_line_bit_14,
        smallest_monitor_line_bit_15
        // bits 31:16 reserved
    }; // enum class cpu_smallest_monitor_line_info : std::uint8_t

    enum class cpu_smallest_monitor_line_info_mask : std::uint32_t {
        smallest_monitor_line_size = 1u << std::to_underlying(cpu_smallest_monitor_line_info::smallest_monitor_line_bit_0)
                                   | 1u << std::to_underlying(cpu_smallest_monitor_line_info::smallest_monitor_line_bit_1)
                                   | 1u << std::to_underlying(cpu_smallest_monitor_line_info::smallest_monitor_line_bit_2)
                                   | 1u << std::to_underlying(cpu_smallest_monitor_line_info::smallest_monitor_line_bit_3)
                                   | 1u << std::to_underlying(cpu_smallest_monitor_line_info::smallest_monitor_line_bit_4)
                                   | 1u << std::to_underlying(cpu_smallest_monitor_line_info::smallest_monitor_line_bit_5)
                                   | 1u << std::to_underlying(cpu_smallest_monitor_line_info::smallest_monitor_line_bit_6)
                                   | 1u << std::to_underlying(cpu_smallest_monitor_line_info::smallest_monitor_line_bit_7)
                                   | 1u << std::to_underlying(cpu_smallest_monitor_line_info::smallest_monitor_line_bit_8)
                                   | 1u << std::to_underlying(cpu_smallest_monitor_line_info::smallest_monitor_line_bit_9)
                                   | 1u << std::to_underlying(cpu_smallest_monitor_line_info::smallest_monitor_line_bit_10)
                                   | 1u << std::to_underlying(cpu_smallest_monitor_line_info::smallest_monitor_line_bit_11)
                                   | 1u << std::to_underlying(cpu_smallest_monitor_line_info::smallest_monitor_line_bit_12)
                                   | 1u << std::to_underlying(cpu_smallest_monitor_line_info::smallest_monitor_line_bit_13)
                                   | 1u << std::to_underlying(cpu_smallest_monitor_line_info::smallest_monitor_line_bit_14)
                                   | 1u << std::to_underlying(cpu_smallest_monitor_line_info::smallest_monitor_line_bit_15)
    }; // enum class cpu_smallest_monitor_line_info_mask : std::uint32_t

    [[nodiscard]]
    cpu_smallest_monitor_line_info_mask supported_cpu_smallest_monitor_line_info(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_smallest_monitor_line_info_mask{};

        if (max_leaf >= 0x05) {
            using enum cpu_smallest_monitor_line_info;
            const auto leaf_0x05 = cpu_id(0x05, 0x00);

            // eax register
            if (leaf_0x05.eax_bit( 0u)) result |= smallest_monitor_line_bit_0;
            if (leaf_0x05.eax_bit( 1u)) result |= smallest_monitor_line_bit_1;
            if (leaf_0x05.eax_bit( 2u)) result |= smallest_monitor_line_bit_2;
            if (leaf_0x05.eax_bit( 3u)) result |= smallest_monitor_line_bit_3;
            if (leaf_0x05.eax_bit( 4u)) result |= smallest_monitor_line_bit_4;
            if (leaf_0x05.eax_bit( 5u)) result |= smallest_monitor_line_bit_5;
            if (leaf_0x05.eax_bit( 6u)) result |= smallest_monitor_line_bit_6;
            if (leaf_0x05.eax_bit( 7u)) result |= smallest_monitor_line_bit_7;
            if (leaf_0x05.eax_bit( 8u)) result |= smallest_monitor_line_bit_8;
            if (leaf_0x05.eax_bit( 9u)) result |= smallest_monitor_line_bit_9;
            if (leaf_0x05.eax_bit(10u)) result |= smallest_monitor_line_bit_10;
            if (leaf_0x05.eax_bit(11u)) result |= smallest_monitor_line_bit_11;
            if (leaf_0x05.eax_bit(12u)) result |= smallest_monitor_line_bit_12;
            if (leaf_0x05.eax_bit(13u)) result |= smallest_monitor_line_bit_13;
            if (leaf_0x05.eax_bit(14u)) result |= smallest_monitor_line_bit_14;
            if (leaf_0x05.eax_bit(15u)) result |= smallest_monitor_line_bit_15;
        }

        return result;
    }

    enum class cpu_largest_monitor_line_info : std::uint8_t {
        largest_monitor_line_bit_0,
        largest_monitor_line_bit_1,
        largest_monitor_line_bit_2,
        largest_monitor_line_bit_3,
        largest_monitor_line_bit_4,
        largest_monitor_line_bit_5,
        largest_monitor_line_bit_6,
        largest_monitor_line_bit_7,
        largest_monitor_line_bit_8,
        largest_monitor_line_bit_9,
        largest_monitor_line_bit_10,
        largest_monitor_line_bit_11,
        largest_monitor_line_bit_12,
        largest_monitor_line_bit_13,
        largest_monitor_line_bit_14,
        largest_monitor_line_bit_15
        // bits 31:16 reserved
    }; // enum class cpu_largest_monitor_line_info : std::uint8_t

    enum class cpu_largest_monitor_line_info_mask : std::uint32_t {
        largest_monitor_line_size = 1u << std::to_underlying(cpu_largest_monitor_line_info::largest_monitor_line_bit_0)
                                  | 1u << std::to_underlying(cpu_largest_monitor_line_info::largest_monitor_line_bit_1)
                                  | 1u << std::to_underlying(cpu_largest_monitor_line_info::largest_monitor_line_bit_2)
                                  | 1u << std::to_underlying(cpu_largest_monitor_line_info::largest_monitor_line_bit_3)
                                  | 1u << std::to_underlying(cpu_largest_monitor_line_info::largest_monitor_line_bit_4)
                                  | 1u << std::to_underlying(cpu_largest_monitor_line_info::largest_monitor_line_bit_5)
                                  | 1u << std::to_underlying(cpu_largest_monitor_line_info::largest_monitor_line_bit_6)
                                  | 1u << std::to_underlying(cpu_largest_monitor_line_info::largest_monitor_line_bit_7)
                                  | 1u << std::to_underlying(cpu_largest_monitor_line_info::largest_monitor_line_bit_8)
                                  | 1u << std::to_underlying(cpu_largest_monitor_line_info::largest_monitor_line_bit_9)
                                  | 1u << std::to_underlying(cpu_largest_monitor_line_info::largest_monitor_line_bit_10)
                                  | 1u << std::to_underlying(cpu_largest_monitor_line_info::largest_monitor_line_bit_11)
                                  | 1u << std::to_underlying(cpu_largest_monitor_line_info::largest_monitor_line_bit_12)
                                  | 1u << std::to_underlying(cpu_largest_monitor_line_info::largest_monitor_line_bit_13)
                                  | 1u << std::to_underlying(cpu_largest_monitor_line_info::largest_monitor_line_bit_14)
                                  | 1u << std::to_underlying(cpu_largest_monitor_line_info::largest_monitor_line_bit_15)
    }; // enum class cpu_smallest_monitor_line_info_mask : std::uint32_t

    [[nodiscard]]
    cpu_largest_monitor_line_info_mask supported_cpu_largest_monitor_line_info(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_largest_monitor_line_info_mask{};

        if (max_leaf >= 0x05) {
            using enum cpu_largest_monitor_line_info;
            const auto leaf_0x05 = cpu_id(0x05, 0x00);

            // ebx register
            if (leaf_0x05.ebx_bit( 0u)) result |= largest_monitor_line_bit_0;
            if (leaf_0x05.ebx_bit( 1u)) result |= largest_monitor_line_bit_1;
            if (leaf_0x05.ebx_bit( 2u)) result |= largest_monitor_line_bit_2;
            if (leaf_0x05.ebx_bit( 3u)) result |= largest_monitor_line_bit_3;
            if (leaf_0x05.ebx_bit( 4u)) result |= largest_monitor_line_bit_4;
            if (leaf_0x05.ebx_bit( 5u)) result |= largest_monitor_line_bit_5;
            if (leaf_0x05.ebx_bit( 6u)) result |= largest_monitor_line_bit_6;
            if (leaf_0x05.ebx_bit( 7u)) result |= largest_monitor_line_bit_7;
            if (leaf_0x05.ebx_bit( 8u)) result |= largest_monitor_line_bit_8;
            if (leaf_0x05.ebx_bit( 9u)) result |= largest_monitor_line_bit_9;
            if (leaf_0x05.ebx_bit(10u)) result |= largest_monitor_line_bit_10;
            if (leaf_0x05.ebx_bit(11u)) result |= largest_monitor_line_bit_11;
            if (leaf_0x05.ebx_bit(12u)) result |= largest_monitor_line_bit_12;
            if (leaf_0x05.ebx_bit(13u)) result |= largest_monitor_line_bit_13;
            if (leaf_0x05.ebx_bit(14u)) result |= largest_monitor_line_bit_14;
            if (leaf_0x05.ebx_bit(15u)) result |= largest_monitor_line_bit_15;
        }

        return result;
    }
} // namespace based::platform::x86::detail

