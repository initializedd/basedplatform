#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// Tile Information
// https://en.wikipedia.org/wiki/CPUID#EAX=1Dh:_Tile_Information

namespace based::platform::x86::detail {
    enum class cpu_tile_info : std::uint8_t {
        total_tile_bytes_bit_0,
        total_tile_bytes_bit_1,
        total_tile_bytes_bit_2,
        total_tile_bytes_bit_3,
        total_tile_bytes_bit_4,
        total_tile_bytes_bit_5,
        total_tile_bytes_bit_6,
        total_tile_bytes_bit_7,
        total_tile_bytes_bit_8,
        total_tile_bytes_bit_9,
        total_tile_bytes_bit_10,
        total_tile_bytes_bit_11,
        total_tile_bytes_bit_12,
        total_tile_bytes_bit_13,
        total_tile_bytes_bit_14,
        total_tile_bytes_bit_15,
        bytes_per_tile_bit_0,
        bytes_per_tile_bit_1,
        bytes_per_tile_bit_2,
        bytes_per_tile_bit_3,
        bytes_per_tile_bit_4,
        bytes_per_tile_bit_5,
        bytes_per_tile_bit_6,
        bytes_per_tile_bit_7,
        bytes_per_tile_bit_8,
        bytes_per_tile_bit_9,
        bytes_per_tile_bit_10,
        bytes_per_tile_bit_11,
        bytes_per_tile_bit_12,
        bytes_per_tile_bit_13,
        bytes_per_tile_bit_14,
        bytes_per_tile_bit_15
    }; // enum class cpu_tile_info : std::uint8_t

    enum class cpu_tile_info_mask : std::uint32_t {
        total_tile_bytes = 1u << std::to_underlying(cpu_tile_info::total_tile_bytes_bit_0)
                         | 1u << std::to_underlying(cpu_tile_info::total_tile_bytes_bit_1)
                         | 1u << std::to_underlying(cpu_tile_info::total_tile_bytes_bit_2)
                         | 1u << std::to_underlying(cpu_tile_info::total_tile_bytes_bit_3)
                         | 1u << std::to_underlying(cpu_tile_info::total_tile_bytes_bit_4)
                         | 1u << std::to_underlying(cpu_tile_info::total_tile_bytes_bit_5)
                         | 1u << std::to_underlying(cpu_tile_info::total_tile_bytes_bit_6)
                         | 1u << std::to_underlying(cpu_tile_info::total_tile_bytes_bit_7)
                         | 1u << std::to_underlying(cpu_tile_info::total_tile_bytes_bit_8)
                         | 1u << std::to_underlying(cpu_tile_info::total_tile_bytes_bit_9)
                         | 1u << std::to_underlying(cpu_tile_info::total_tile_bytes_bit_10)
                         | 1u << std::to_underlying(cpu_tile_info::total_tile_bytes_bit_11)
                         | 1u << std::to_underlying(cpu_tile_info::total_tile_bytes_bit_12)
                         | 1u << std::to_underlying(cpu_tile_info::total_tile_bytes_bit_13)
                         | 1u << std::to_underlying(cpu_tile_info::total_tile_bytes_bit_14)
                         | 1u << std::to_underlying(cpu_tile_info::total_tile_bytes_bit_15),
        bytes_per_tile   = 1u << std::to_underlying(cpu_tile_info::bytes_per_tile_bit_0)
                         | 1u << std::to_underlying(cpu_tile_info::bytes_per_tile_bit_1)
                         | 1u << std::to_underlying(cpu_tile_info::bytes_per_tile_bit_2)
                         | 1u << std::to_underlying(cpu_tile_info::bytes_per_tile_bit_3)
                         | 1u << std::to_underlying(cpu_tile_info::bytes_per_tile_bit_4)
                         | 1u << std::to_underlying(cpu_tile_info::bytes_per_tile_bit_5)
                         | 1u << std::to_underlying(cpu_tile_info::bytes_per_tile_bit_6)
                         | 1u << std::to_underlying(cpu_tile_info::bytes_per_tile_bit_7)
                         | 1u << std::to_underlying(cpu_tile_info::bytes_per_tile_bit_8)
                         | 1u << std::to_underlying(cpu_tile_info::bytes_per_tile_bit_9)
                         | 1u << std::to_underlying(cpu_tile_info::bytes_per_tile_bit_10)
                         | 1u << std::to_underlying(cpu_tile_info::bytes_per_tile_bit_11)
                         | 1u << std::to_underlying(cpu_tile_info::bytes_per_tile_bit_12)
                         | 1u << std::to_underlying(cpu_tile_info::bytes_per_tile_bit_13)
                         | 1u << std::to_underlying(cpu_tile_info::bytes_per_tile_bit_14)
                         | 1u << std::to_underlying(cpu_tile_info::bytes_per_tile_bit_15)
    }; // enum class cpu_tile_info_mask : std::uint32_t

    [[nodiscard]]
    cpu_tile_info_mask supported_cpu_tile_info(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_tile_info_mask{};

        if (max_leaf >= 0x1D) {
            using enum cpu_tile_info;
            const auto leaf_0x1d = cpu_id(0x1D, 0x01);

            // eax register
            if (leaf_0x1d.eax_bit( 0u)) result |= total_tile_bytes_bit_0;
            if (leaf_0x1d.eax_bit( 1u)) result |= total_tile_bytes_bit_1;
            if (leaf_0x1d.eax_bit( 2u)) result |= total_tile_bytes_bit_2;
            if (leaf_0x1d.eax_bit( 3u)) result |= total_tile_bytes_bit_3;
            if (leaf_0x1d.eax_bit( 4u)) result |= total_tile_bytes_bit_4;
            if (leaf_0x1d.eax_bit( 5u)) result |= total_tile_bytes_bit_5;
            if (leaf_0x1d.eax_bit( 6u)) result |= total_tile_bytes_bit_6;
            if (leaf_0x1d.eax_bit( 7u)) result |= total_tile_bytes_bit_7;
            if (leaf_0x1d.eax_bit( 8u)) result |= total_tile_bytes_bit_8;
            if (leaf_0x1d.eax_bit( 9u)) result |= total_tile_bytes_bit_9;
            if (leaf_0x1d.eax_bit(10u)) result |= total_tile_bytes_bit_10;
            if (leaf_0x1d.eax_bit(11u)) result |= total_tile_bytes_bit_11;
            if (leaf_0x1d.eax_bit(12u)) result |= total_tile_bytes_bit_12;
            if (leaf_0x1d.eax_bit(13u)) result |= total_tile_bytes_bit_13;
            if (leaf_0x1d.eax_bit(14u)) result |= total_tile_bytes_bit_14;
            if (leaf_0x1d.eax_bit(15u)) result |= total_tile_bytes_bit_15;
            if (leaf_0x1d.eax_bit(16u)) result |= bytes_per_tile_bit_0;
            if (leaf_0x1d.eax_bit(17u)) result |= bytes_per_tile_bit_1;
            if (leaf_0x1d.eax_bit(18u)) result |= bytes_per_tile_bit_2;
            if (leaf_0x1d.eax_bit(19u)) result |= bytes_per_tile_bit_3;
            if (leaf_0x1d.eax_bit(20u)) result |= bytes_per_tile_bit_4;
            if (leaf_0x1d.eax_bit(21u)) result |= bytes_per_tile_bit_5;
            if (leaf_0x1d.eax_bit(22u)) result |= bytes_per_tile_bit_6;
            if (leaf_0x1d.eax_bit(23u)) result |= bytes_per_tile_bit_7;
            if (leaf_0x1d.eax_bit(24u)) result |= bytes_per_tile_bit_8;
            if (leaf_0x1d.eax_bit(25u)) result |= bytes_per_tile_bit_9;
            if (leaf_0x1d.eax_bit(26u)) result |= bytes_per_tile_bit_10;
            if (leaf_0x1d.eax_bit(27u)) result |= bytes_per_tile_bit_11;
            if (leaf_0x1d.eax_bit(28u)) result |= bytes_per_tile_bit_12;
            if (leaf_0x1d.eax_bit(29u)) result |= bytes_per_tile_bit_13;
            if (leaf_0x1d.eax_bit(30u)) result |= bytes_per_tile_bit_14;
            if (leaf_0x1d.eax_bit(31u)) result |= bytes_per_tile_bit_15;

        }

        return result;
    }

    enum class cpu_tile_row_info : std::uint8_t {
        bytes_per_row_bit_0,
        bytes_per_row_bit_1,
        bytes_per_row_bit_2,
        bytes_per_row_bit_3,
        bytes_per_row_bit_4,
        bytes_per_row_bit_5,
        bytes_per_row_bit_6,
        bytes_per_row_bit_7,
        bytes_per_row_bit_8,
        bytes_per_row_bit_9,
        bytes_per_row_bit_10,
        bytes_per_row_bit_11,
        bytes_per_row_bit_12,
        bytes_per_row_bit_13,
        bytes_per_row_bit_14,
        bytes_per_row_bit_15,
        max_names_bit_0,
        max_names_bit_1,
        max_names_bit_2,
        max_names_bit_3,
        max_names_bit_4,
        max_names_bit_5,
        max_names_bit_6,
        max_names_bit_7,
        max_names_bit_8,
        max_names_bit_9,
        max_names_bit_10,
        max_names_bit_11,
        max_names_bit_12,
        max_names_bit_13,
        max_names_bit_14,
        max_names_bit_15
    }; // enum class cpu_tile_row_info : std::uint8_t

    enum class cpu_tile_row_info_mask : std::uint32_t {
        bytes_per_row = 1u << std::to_underlying(cpu_tile_row_info::bytes_per_row_bit_0)
                      | 1u << std::to_underlying(cpu_tile_row_info::bytes_per_row_bit_1)
                      | 1u << std::to_underlying(cpu_tile_row_info::bytes_per_row_bit_2)
                      | 1u << std::to_underlying(cpu_tile_row_info::bytes_per_row_bit_3)
                      | 1u << std::to_underlying(cpu_tile_row_info::bytes_per_row_bit_4)
                      | 1u << std::to_underlying(cpu_tile_row_info::bytes_per_row_bit_5)
                      | 1u << std::to_underlying(cpu_tile_row_info::bytes_per_row_bit_6)
                      | 1u << std::to_underlying(cpu_tile_row_info::bytes_per_row_bit_7)
                      | 1u << std::to_underlying(cpu_tile_row_info::bytes_per_row_bit_8)
                      | 1u << std::to_underlying(cpu_tile_row_info::bytes_per_row_bit_9)
                      | 1u << std::to_underlying(cpu_tile_row_info::bytes_per_row_bit_10)
                      | 1u << std::to_underlying(cpu_tile_row_info::bytes_per_row_bit_11)
                      | 1u << std::to_underlying(cpu_tile_row_info::bytes_per_row_bit_12)
                      | 1u << std::to_underlying(cpu_tile_row_info::bytes_per_row_bit_13)
                      | 1u << std::to_underlying(cpu_tile_row_info::bytes_per_row_bit_14)
                      | 1u << std::to_underlying(cpu_tile_row_info::bytes_per_row_bit_15),
        max_names     = 1u << std::to_underlying(cpu_tile_row_info::max_names_bit_0)
                      | 1u << std::to_underlying(cpu_tile_row_info::max_names_bit_1)
                      | 1u << std::to_underlying(cpu_tile_row_info::max_names_bit_2)
                      | 1u << std::to_underlying(cpu_tile_row_info::max_names_bit_3)
                      | 1u << std::to_underlying(cpu_tile_row_info::max_names_bit_4)
                      | 1u << std::to_underlying(cpu_tile_row_info::max_names_bit_5)
                      | 1u << std::to_underlying(cpu_tile_row_info::max_names_bit_6)
                      | 1u << std::to_underlying(cpu_tile_row_info::max_names_bit_7)
                      | 1u << std::to_underlying(cpu_tile_row_info::max_names_bit_8)
                      | 1u << std::to_underlying(cpu_tile_row_info::max_names_bit_9)
                      | 1u << std::to_underlying(cpu_tile_row_info::max_names_bit_10)
                      | 1u << std::to_underlying(cpu_tile_row_info::max_names_bit_11)
                      | 1u << std::to_underlying(cpu_tile_row_info::max_names_bit_12)
                      | 1u << std::to_underlying(cpu_tile_row_info::max_names_bit_13)
                      | 1u << std::to_underlying(cpu_tile_row_info::max_names_bit_14)
                      | 1u << std::to_underlying(cpu_tile_row_info::max_names_bit_15)
    }; // enum class cpu_tile_row_info_mask : std::uint32_t

    [[nodiscard]]
    cpu_tile_info_mask supported_cpu_tile_row_info(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_tile_row_info_mask{};

        if (max_leaf >= 0x1D) {
            using enum cpu_tile_row_info;
            const auto leaf_0x1d = cpu_id(0x1D, 0x01);

            // ebx register
            if (leaf_0x1d.ebx_bit( 0u)) result |= bytes_per_row_bit_0;
            if (leaf_0x1d.ebx_bit( 1u)) result |= bytes_per_row_bit_1;
            if (leaf_0x1d.ebx_bit( 2u)) result |= bytes_per_row_bit_2;
            if (leaf_0x1d.ebx_bit( 3u)) result |= bytes_per_row_bit_3;
            if (leaf_0x1d.ebx_bit( 4u)) result |= bytes_per_row_bit_4;
            if (leaf_0x1d.ebx_bit( 5u)) result |= bytes_per_row_bit_5;
            if (leaf_0x1d.ebx_bit( 6u)) result |= bytes_per_row_bit_6;
            if (leaf_0x1d.ebx_bit( 7u)) result |= bytes_per_row_bit_7;
            if (leaf_0x1d.ebx_bit( 8u)) result |= bytes_per_row_bit_8;
            if (leaf_0x1d.ebx_bit( 9u)) result |= bytes_per_row_bit_9;
            if (leaf_0x1d.ebx_bit(10u)) result |= bytes_per_row_bit_10;
            if (leaf_0x1d.ebx_bit(11u)) result |= bytes_per_row_bit_11;
            if (leaf_0x1d.ebx_bit(12u)) result |= bytes_per_row_bit_12;
            if (leaf_0x1d.ebx_bit(13u)) result |= bytes_per_row_bit_13;
            if (leaf_0x1d.ebx_bit(14u)) result |= bytes_per_row_bit_14;
            if (leaf_0x1d.ebx_bit(15u)) result |= bytes_per_row_bit_15;
            if (leaf_0x1d.ebx_bit(16u)) result |= max_names_bit_0;
            if (leaf_0x1d.ebx_bit(17u)) result |= max_names_bit_1;
            if (leaf_0x1d.ebx_bit(18u)) result |= max_names_bit_2;
            if (leaf_0x1d.ebx_bit(19u)) result |= max_names_bit_3;
            if (leaf_0x1d.ebx_bit(20u)) result |= max_names_bit_4;
            if (leaf_0x1d.ebx_bit(21u)) result |= max_names_bit_5;
            if (leaf_0x1d.ebx_bit(22u)) result |= max_names_bit_6;
            if (leaf_0x1d.ebx_bit(23u)) result |= max_names_bit_7;
            if (leaf_0x1d.ebx_bit(24u)) result |= max_names_bit_8;
            if (leaf_0x1d.ebx_bit(25u)) result |= max_names_bit_9;
            if (leaf_0x1d.ebx_bit(26u)) result |= max_names_bit_10;
            if (leaf_0x1d.ebx_bit(27u)) result |= max_names_bit_11;
            if (leaf_0x1d.ebx_bit(28u)) result |= max_names_bit_12;
            if (leaf_0x1d.ebx_bit(29u)) result |= max_names_bit_13;
            if (leaf_0x1d.ebx_bit(30u)) result |= max_names_bit_14;
            if (leaf_0x1d.ebx_bit(31u)) result |= max_names_bit_15;

        }

        return result;
    }

    enum class cpu_tile_max_row_info : std::uint8_t {
        max_rows_bit_0,
        max_rows_bit_1,
        max_rows_bit_2,
        max_rows_bit_3,
        max_rows_bit_4,
        max_rows_bit_5,
        max_rows_bit_6,
        max_rows_bit_7,
        max_rows_bit_8,
        max_rows_bit_9,
        max_rows_bit_10,
        max_rows_bit_11,
        max_rows_bit_12,
        max_rows_bit_13,
        max_rows_bit_14,
        max_rows_bit_15
        // bits 31:16 reserved
    }; // enum class cpu_tile_max_row_info : std::uint8_t

    enum class cpu_tile_max_row_info_mask : std::uint32_t {
        max_rows = 1u << std::to_underlying(cpu_tile_max_row_info::max_rows_bit_0)
                 | 1u << std::to_underlying(cpu_tile_max_row_info::max_rows_bit_1)
                 | 1u << std::to_underlying(cpu_tile_max_row_info::max_rows_bit_2)
                 | 1u << std::to_underlying(cpu_tile_max_row_info::max_rows_bit_3)
                 | 1u << std::to_underlying(cpu_tile_max_row_info::max_rows_bit_4)
                 | 1u << std::to_underlying(cpu_tile_max_row_info::max_rows_bit_5)
                 | 1u << std::to_underlying(cpu_tile_max_row_info::max_rows_bit_6)
                 | 1u << std::to_underlying(cpu_tile_max_row_info::max_rows_bit_7)
                 | 1u << std::to_underlying(cpu_tile_max_row_info::max_rows_bit_8)
                 | 1u << std::to_underlying(cpu_tile_max_row_info::max_rows_bit_9)
                 | 1u << std::to_underlying(cpu_tile_max_row_info::max_rows_bit_10)
                 | 1u << std::to_underlying(cpu_tile_max_row_info::max_rows_bit_11)
                 | 1u << std::to_underlying(cpu_tile_max_row_info::max_rows_bit_12)
                 | 1u << std::to_underlying(cpu_tile_max_row_info::max_rows_bit_13)
                 | 1u << std::to_underlying(cpu_tile_max_row_info::max_rows_bit_14)
                 | 1u << std::to_underlying(cpu_tile_max_row_info::max_rows_bit_15),
    }; // enum class cpu_tile_max_row_info_mask : std::uint32_t

    [[nodiscard]]
    cpu_tile_info_mask supported_cpu_tile_row_info(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_tile_row_info_mask{};

        if (max_leaf >= 0x1D) {
            using enum cpu_tile_max_row_info;
            const auto leaf_0x1d = cpu_id(0x1D, 0x01);

            // ecx register
            if (leaf_0x1d.ecx_bit( 0u)) result |= max_rows_bit_0;
            if (leaf_0x1d.ecx_bit( 1u)) result |= max_rows_bit_1;
            if (leaf_0x1d.ecx_bit( 2u)) result |= max_rows_bit_2;
            if (leaf_0x1d.ecx_bit( 3u)) result |= max_rows_bit_3;
            if (leaf_0x1d.ecx_bit( 4u)) result |= max_rows_bit_4;
            if (leaf_0x1d.ecx_bit( 5u)) result |= max_rows_bit_5;
            if (leaf_0x1d.ecx_bit( 6u)) result |= max_rows_bit_6;
            if (leaf_0x1d.ecx_bit( 7u)) result |= max_rows_bit_7;
            if (leaf_0x1d.ecx_bit( 8u)) result |= max_rows_bit_8;
            if (leaf_0x1d.ecx_bit( 9u)) result |= max_rows_bit_9;
            if (leaf_0x1d.ecx_bit(10u)) result |= max_rows_bit_10;
            if (leaf_0x1d.ecx_bit(11u)) result |= max_rows_bit_11;
            if (leaf_0x1d.ecx_bit(12u)) result |= max_rows_bit_12;
            if (leaf_0x1d.ecx_bit(13u)) result |= max_rows_bit_13;
            if (leaf_0x1d.ecx_bit(14u)) result |= max_rows_bit_14;
            if (leaf_0x1d.ecx_bit(15u)) result |= max_rows_bit_15;

        }

        return result;
    }
} // namespace based::platform::x86::detail

