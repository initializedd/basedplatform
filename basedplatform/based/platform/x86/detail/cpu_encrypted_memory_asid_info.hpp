#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// Encrypted Memory ASID Info
// https://en.wikipedia.org/wiki/CPUID#EAX=8000001Fh:_Encrypted_Memory_Capabilities

namespace based::platform::x86::detail {
    enum class cpu_encrypted_memory_max_asid_info : std::uint8_t {
        max_asid_value_bit_0,
        max_asid_value_bit_1,
        max_asid_value_bit_2,
        max_asid_value_bit_3,
        max_asid_value_bit_4,
        max_asid_value_bit_5,
        max_asid_value_bit_6,
        max_asid_value_bit_7,
        max_asid_value_bit_8,
        max_asid_value_bit_9,
        max_asid_value_bit_10,
        max_asid_value_bit_11,
        max_asid_value_bit_12,
        max_asid_value_bit_13,
        max_asid_value_bit_14,
        max_asid_value_bit_15,
        max_asid_value_bit_16,
        max_asid_value_bit_17,
        max_asid_value_bit_18,
        max_asid_value_bit_19,
        max_asid_value_bit_20,
        max_asid_value_bit_21,
        max_asid_value_bit_22,
        max_asid_value_bit_23,
        max_asid_value_bit_24,
        max_asid_value_bit_25,
        max_asid_value_bit_26,
        max_asid_value_bit_27,
        max_asid_value_bit_28,
        max_asid_value_bit_29,
        max_asid_value_bit_30,
        max_asid_value_bit_31
    }; // enum class cpu_encrypted_memory_max_asid_info : std::uint8_t

    enum class cpu_encrypted_memory_max_asid_info_mask : std::uint32_t {
        max_asid_value = 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_0)
                       | 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_1)
                       | 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_2)
                       | 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_3)
                       | 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_4)
                       | 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_5)
                       | 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_6)
                       | 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_7)
                       | 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_8)
                       | 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_9)
                       | 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_10)
                       | 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_11)
                       | 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_12)
                       | 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_13)
                       | 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_14)
                       | 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_15)
                       | 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_16)
                       | 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_17)
                       | 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_18)
                       | 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_19)
                       | 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_20)
                       | 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_21)
                       | 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_22)
                       | 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_23)
                       | 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_24)
                       | 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_25)
                       | 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_26)
                       | 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_27)
                       | 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_28)
                       | 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_29)
                       | 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_30)
                       | 1u << std::to_underlying(cpu_encrypted_memory_max_asid_info::max_asid_value_bit_31)
    }; // enum class cpu_encrypted_memory_max_asid_info_mask : std::uint32_t

    [[nodiscard]]
    cpu_encrypted_memory_max_asid_info_mask supported_cpu_encrypted_memory_max_asid_info(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_encrypted_memory_max_asid_info_mask{};

        if (max_leaf >= 0x8000001F) {
            using enum cpu_encrypted_memory_max_asid_info;
            const auto leaf8 = cpu_id(0x8000001F, 0x00);

            // ecx register
            if (leaf8.ecx_bit( 0u)) result |= max_asid_value_bit_0;
            if (leaf8.ecx_bit( 1u)) result |= max_asid_value_bit_1;
            if (leaf8.ecx_bit( 2u)) result |= max_asid_value_bit_2;
            if (leaf8.ecx_bit( 3u)) result |= max_asid_value_bit_3;
            if (leaf8.ecx_bit( 4u)) result |= max_asid_value_bit_4;
            if (leaf8.ecx_bit( 5u)) result |= max_asid_value_bit_5;
            if (leaf8.ecx_bit( 6u)) result |= max_asid_value_bit_6;
            if (leaf8.ecx_bit( 7u)) result |= max_asid_value_bit_7;
            if (leaf8.ecx_bit( 8u)) result |= max_asid_value_bit_8;
            if (leaf8.ecx_bit( 9u)) result |= max_asid_value_bit_9;
            if (leaf8.ecx_bit(10u)) result |= max_asid_value_bit_10;
            if (leaf8.ecx_bit(11u)) result |= max_asid_value_bit_11;
            if (leaf8.ecx_bit(12u)) result |= max_asid_value_bit_12;
            if (leaf8.ecx_bit(13u)) result |= max_asid_value_bit_13;
            if (leaf8.ecx_bit(14u)) result |= max_asid_value_bit_14;
            if (leaf8.ecx_bit(15u)) result |= max_asid_value_bit_15;
            if (leaf8.ecx_bit(16u)) result |= max_asid_value_bit_16;
            if (leaf8.ecx_bit(17u)) result |= max_asid_value_bit_17;
            if (leaf8.ecx_bit(18u)) result |= max_asid_value_bit_18;
            if (leaf8.ecx_bit(19u)) result |= max_asid_value_bit_19;
            if (leaf8.ecx_bit(20u)) result |= max_asid_value_bit_20;
            if (leaf8.ecx_bit(21u)) result |= max_asid_value_bit_21;
            if (leaf8.ecx_bit(22u)) result |= max_asid_value_bit_22;
            if (leaf8.ecx_bit(23u)) result |= max_asid_value_bit_23;
            if (leaf8.ecx_bit(24u)) result |= max_asid_value_bit_24;
            if (leaf8.ecx_bit(25u)) result |= max_asid_value_bit_25;
            if (leaf8.ecx_bit(26u)) result |= max_asid_value_bit_26;
            if (leaf8.ecx_bit(27u)) result |= max_asid_value_bit_27;
            if (leaf8.ecx_bit(28u)) result |= max_asid_value_bit_28;
            if (leaf8.ecx_bit(29u)) result |= max_asid_value_bit_29;
            if (leaf8.ecx_bit(30u)) result |= max_asid_value_bit_30;
            if (leaf8.ecx_bit(31u)) result |= max_asid_value_bit_31;
        }

        return result;
    }

    enum class cpu_encrypted_memory_min_asid_info : std::uint8_t {
        min_asid_value_bit_0,
        min_asid_value_bit_1,
        min_asid_value_bit_2,
        min_asid_value_bit_3,
        min_asid_value_bit_4,
        min_asid_value_bit_5,
        min_asid_value_bit_6,
        min_asid_value_bit_7,
        min_asid_value_bit_8,
        min_asid_value_bit_9,
        min_asid_value_bit_10,
        min_asid_value_bit_11,
        min_asid_value_bit_12,
        min_asid_value_bit_13,
        min_asid_value_bit_14,
        min_asid_value_bit_15,
        min_asid_value_bit_16,
        min_asid_value_bit_17,
        min_asid_value_bit_18,
        min_asid_value_bit_19,
        min_asid_value_bit_20,
        min_asid_value_bit_21,
        min_asid_value_bit_22,
        min_asid_value_bit_23,
        min_asid_value_bit_24,
        min_asid_value_bit_25,
        min_asid_value_bit_26,
        min_asid_value_bit_27,
        min_asid_value_bit_28,
        min_asid_value_bit_29,
        min_asid_value_bit_30,
        min_asid_value_bit_31
    }; // enum class cpu_encrypted_memory_min_asid_info : std::uint8_t

    enum class cpu_encrypted_memory_min_asid_info_mask : std::uint32_t {
        min_asid_value = 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_0)
                       | 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_1)
                       | 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_2)
                       | 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_3)
                       | 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_4)
                       | 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_5)
                       | 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_6)
                       | 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_7)
                       | 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_8)
                       | 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_9)
                       | 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_10)
                       | 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_11)
                       | 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_12)
                       | 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_13)
                       | 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_14)
                       | 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_15)
                       | 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_16)
                       | 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_17)
                       | 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_18)
                       | 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_19)
                       | 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_20)
                       | 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_21)
                       | 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_22)
                       | 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_23)
                       | 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_24)
                       | 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_25)
                       | 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_26)
                       | 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_27)
                       | 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_28)
                       | 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_29)
                       | 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_30)
                       | 1u << std::to_underlying(cpu_encrypted_memory_min_asid_info::min_asid_value_bit_31)
    }; // enum class cpu_encrypted_memory_min_asid_info_mask : std::uint32_t

    [[nodiscard]]
    cpu_encrypted_memory_min_asid_info_mask supported_cpu_encrypted_memory_min_asid_info(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_encrypted_memory_min_asid_info_mask{};

        if (max_leaf >= 0x8000001F) {
            using enum cpu_encrypted_memory_min_asid_info;
            const auto leaf8 = cpu_id(0x8000001F, 0x00);

            // edx register
            if (leaf8.edx_bit( 0u)) result |= min_asid_value_bit_0;
            if (leaf8.edx_bit( 1u)) result |= min_asid_value_bit_1;
            if (leaf8.edx_bit( 2u)) result |= min_asid_value_bit_2;
            if (leaf8.edx_bit( 3u)) result |= min_asid_value_bit_3;
            if (leaf8.edx_bit( 4u)) result |= min_asid_value_bit_4;
            if (leaf8.edx_bit( 5u)) result |= min_asid_value_bit_5;
            if (leaf8.edx_bit( 6u)) result |= min_asid_value_bit_6;
            if (leaf8.edx_bit( 7u)) result |= min_asid_value_bit_7;
            if (leaf8.edx_bit( 8u)) result |= min_asid_value_bit_8;
            if (leaf8.edx_bit( 9u)) result |= min_asid_value_bit_9;
            if (leaf8.edx_bit(10u)) result |= min_asid_value_bit_10;
            if (leaf8.edx_bit(11u)) result |= min_asid_value_bit_11;
            if (leaf8.edx_bit(12u)) result |= min_asid_value_bit_12;
            if (leaf8.edx_bit(13u)) result |= min_asid_value_bit_13;
            if (leaf8.edx_bit(14u)) result |= min_asid_value_bit_14;
            if (leaf8.edx_bit(15u)) result |= min_asid_value_bit_15;
            if (leaf8.edx_bit(16u)) result |= min_asid_value_bit_16;
            if (leaf8.edx_bit(17u)) result |= min_asid_value_bit_17;
            if (leaf8.edx_bit(18u)) result |= min_asid_value_bit_18;
            if (leaf8.edx_bit(19u)) result |= min_asid_value_bit_19;
            if (leaf8.edx_bit(20u)) result |= min_asid_value_bit_20;
            if (leaf8.edx_bit(21u)) result |= min_asid_value_bit_21;
            if (leaf8.edx_bit(22u)) result |= min_asid_value_bit_22;
            if (leaf8.edx_bit(23u)) result |= min_asid_value_bit_23;
            if (leaf8.edx_bit(24u)) result |= min_asid_value_bit_24;
            if (leaf8.edx_bit(25u)) result |= min_asid_value_bit_25;
            if (leaf8.edx_bit(26u)) result |= min_asid_value_bit_26;
            if (leaf8.edx_bit(27u)) result |= min_asid_value_bit_27;
            if (leaf8.edx_bit(28u)) result |= min_asid_value_bit_28;
            if (leaf8.edx_bit(29u)) result |= min_asid_value_bit_29;
            if (leaf8.edx_bit(30u)) result |= min_asid_value_bit_30;
            if (leaf8.edx_bit(31u)) result |= min_asid_value_bit_31;
        }

        return result;
    }
} // namespace based::platform::x86::detail

