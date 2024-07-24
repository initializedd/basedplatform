#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// CPU Address Limits
// https://en.wikipedia.org/wiki/CPUID#EAX=80000008h:_Virtual_and_Physical_address_Sizes

namespace based::platform::x86::detail {
    enum class cpu_address_limit : std::uint8_t {
        invlpgb_max_page_count_bit_0,
        invlpgb_max_page_count_bit_1,
        invlpgb_max_page_count_bit_2,
        invlpgb_max_page_count_bit_3,
        invlpgb_max_page_count_bit_4,
        invlpgb_max_page_count_bit_5,
        invlpgb_max_page_count_bit_6,
        invlpgb_max_page_count_bit_7,
        invlpgb_max_page_count_bit_8,
        invlpgb_max_page_count_bit_9,
        invlpgb_max_page_count_bit_10,
        invlpgb_max_page_count_bit_11,
        invlpgb_max_page_count_bit_12,
        invlpgb_max_page_count_bit_13,
        invlpgb_max_page_count_bit_14,
        invlpgb_max_page_count_bit_15,
        rdpru_max_ecx_value_bit_0,
        rdpru_max_ecx_value_bit_1,
        rdpru_max_ecx_value_bit_2,
        rdpru_max_ecx_value_bit_3,
        rdpru_max_ecx_value_bit_4,
        rdpru_max_ecx_value_bit_5,
        rdpru_max_ecx_value_bit_6,
        rdpru_max_ecx_value_bit_7,
        rdpru_max_ecx_value_bit_8,
        rdpru_max_ecx_value_bit_9,
        rdpru_max_ecx_value_bit_10,
        rdpru_max_ecx_value_bit_11,
        rdpru_max_ecx_value_bit_12,
        rdpru_max_ecx_value_bit_13,
        rdpru_max_ecx_value_bit_14,
        rdpru_max_ecx_value_bit_15
    }; // enum class cpu_address_limit : std::uint8_t

    enum class cpu_address_limit_mask : std::uint32_t {
        invlpgb_max_page_count = 1u << std::to_underlying(cpu_address_limit::invlpgb_max_page_count_bit_0)
                               | 1u << std::to_underlying(cpu_address_limit::invlpgb_max_page_count_bit_1)
                               | 1u << std::to_underlying(cpu_address_limit::invlpgb_max_page_count_bit_2)
                               | 1u << std::to_underlying(cpu_address_limit::invlpgb_max_page_count_bit_3)
                               | 1u << std::to_underlying(cpu_address_limit::invlpgb_max_page_count_bit_4)
                               | 1u << std::to_underlying(cpu_address_limit::invlpgb_max_page_count_bit_5)
                               | 1u << std::to_underlying(cpu_address_limit::invlpgb_max_page_count_bit_6)
                               | 1u << std::to_underlying(cpu_address_limit::invlpgb_max_page_count_bit_7)
                               | 1u << std::to_underlying(cpu_address_limit::invlpgb_max_page_count_bit_8)
                               | 1u << std::to_underlying(cpu_address_limit::invlpgb_max_page_count_bit_9)
                               | 1u << std::to_underlying(cpu_address_limit::invlpgb_max_page_count_bit_10)
                               | 1u << std::to_underlying(cpu_address_limit::invlpgb_max_page_count_bit_11)
                               | 1u << std::to_underlying(cpu_address_limit::invlpgb_max_page_count_bit_12)
                               | 1u << std::to_underlying(cpu_address_limit::invlpgb_max_page_count_bit_13)
                               | 1u << std::to_underlying(cpu_address_limit::invlpgb_max_page_count_bit_14)
                               | 1u << std::to_underlying(cpu_address_limit::invlpgb_max_page_count_bit_15),
        rdpru_max_ecx_value    = 1u << std::to_underlying(cpu_address_limit::rdpru_max_ecx_value_bit_0)
                               | 1u << std::to_underlying(cpu_address_limit::rdpru_max_ecx_value_bit_1)
                               | 1u << std::to_underlying(cpu_address_limit::rdpru_max_ecx_value_bit_2)
                               | 1u << std::to_underlying(cpu_address_limit::rdpru_max_ecx_value_bit_3)
                               | 1u << std::to_underlying(cpu_address_limit::rdpru_max_ecx_value_bit_4)
                               | 1u << std::to_underlying(cpu_address_limit::rdpru_max_ecx_value_bit_5)
                               | 1u << std::to_underlying(cpu_address_limit::rdpru_max_ecx_value_bit_6)
                               | 1u << std::to_underlying(cpu_address_limit::rdpru_max_ecx_value_bit_7)
                               | 1u << std::to_underlying(cpu_address_limit::rdpru_max_ecx_value_bit_8)
                               | 1u << std::to_underlying(cpu_address_limit::rdpru_max_ecx_value_bit_9)
                               | 1u << std::to_underlying(cpu_address_limit::rdpru_max_ecx_value_bit_10)
                               | 1u << std::to_underlying(cpu_address_limit::rdpru_max_ecx_value_bit_11)
                               | 1u << std::to_underlying(cpu_address_limit::rdpru_max_ecx_value_bit_12)
                               | 1u << std::to_underlying(cpu_address_limit::rdpru_max_ecx_value_bit_13)
                               | 1u << std::to_underlying(cpu_address_limit::rdpru_max_ecx_value_bit_14)
                               | 1u << std::to_underlying(cpu_address_limit::rdpru_max_ecx_value_bit_15)
    }; // enum class cpu_address_limit_mask : std::uint32_t

    [[nodiscard]]
    cpu_address_limit_mask supported_cpu_address_limits(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_address_limit_mask{};

        if (max_leaf >= 0x80000008) {
            using cpu_address_limit;
            const auto leaf8 = cpu_id(0x80000008, 0u);

            // edx register
            if (leaf8.edx_bit( 0u)) result |= invlpgb_max_page_count_bit_0;
            if (leaf8.edx_bit( 1u)) result |= invlpgb_max_page_count_bit_1;
            if (leaf8.edx_bit( 2u)) result |= invlpgb_max_page_count_bit_2;
            if (leaf8.edx_bit( 3u)) result |= invlpgb_max_page_count_bit_3;
            if (leaf8.edx_bit( 4u)) result |= invlpgb_max_page_count_bit_4;
            if (leaf8.edx_bit( 5u)) result |= invlpgb_max_page_count_bit_5;
            if (leaf8.edx_bit( 6u)) result |= invlpgb_max_page_count_bit_6;
            if (leaf8.edx_bit( 7u)) result |= invlpgb_max_page_count_bit_7;
            if (leaf8.edx_bit( 8u)) result |= invlpgb_max_page_count_bit_8;
            if (leaf8.edx_bit( 9u)) result |= invlpgb_max_page_count_bit_9;
            if (leaf8.edx_bit(10u)) result |= invlpgb_max_page_count_bit_10;
            if (leaf8.edx_bit(11u)) result |= invlpgb_max_page_count_bit_11;
            if (leaf8.edx_bit(12u)) result |= invlpgb_max_page_count_bit_12;
            if (leaf8.edx_bit(13u)) result |= invlpgb_max_page_count_bit_13;
            if (leaf8.edx_bit(14u)) result |= invlpgb_max_page_count_bit_14;
            if (leaf8.edx_bit(15u)) result |= invlpgb_max_page_count_bit_15;
            if (leaf8.edx_bit(16u)) result |= rdpru_max_ecx_value_bit_0;
            if (leaf8.edx_bit(17u)) result |= rdpru_max_ecx_value_bit_1;
            if (leaf8.edx_bit(18u)) result |= rdpru_max_ecx_value_bit_2;
            if (leaf8.edx_bit(19u)) result |= rdpru_max_ecx_value_bit_3;
            if (leaf8.edx_bit(20u)) result |= rdpru_max_ecx_value_bit_4;
            if (leaf8.edx_bit(21u)) result |= rdpru_max_ecx_value_bit_5;
            if (leaf8.edx_bit(22u)) result |= rdpru_max_ecx_value_bit_6;
            if (leaf8.edx_bit(23u)) result |= rdpru_max_ecx_value_bit_7;
            if (leaf8.edx_bit(24u)) result |= rdpru_max_ecx_value_bit_8;
            if (leaf8.edx_bit(25u)) result |= rdpru_max_ecx_value_bit_9;
            if (leaf8.edx_bit(26u)) result |= rdpru_max_ecx_value_bit_10;
            if (leaf8.edx_bit(27u)) result |= rdpru_max_ecx_value_bit_11;
            if (leaf8.edx_bit(28u)) result |= rdpru_max_ecx_value_bit_12;
            if (leaf8.edx_bit(29u)) result |= rdpru_max_ecx_value_bit_13;
            if (leaf8.edx_bit(30u)) result |= rdpru_max_ecx_value_bit_14;
            if (leaf8.edx_bit(31u)) result |= rdpru_max_ecx_value_bit_15;
        }

        return result;
    }
} // namespace based::platform::x86::detail

