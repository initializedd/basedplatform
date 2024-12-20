#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"
#include "../../util.hpp"

// SoC identification information
// https://en.wikipedia.org/wiki/CPUID#EAX=17h:_SoC_Vendor_Attribute_Enumeration

namespace based::platform::x86::detail {
    enum class cpu_soc_project_identifier : std::uint8_t {
        soc_project_id_bit_0,
        soc_project_id_bit_1,
        soc_project_id_bit_2,
        soc_project_id_bit_3,
        soc_project_id_bit_4,
        soc_project_id_bit_5,
        soc_project_id_bit_6,
        soc_project_id_bit_7,
        soc_project_id_bit_8,
        soc_project_id_bit_9,
        soc_project_id_bit_10,
        soc_project_id_bit_11,
        soc_project_id_bit_12,
        soc_project_id_bit_13,
        soc_project_id_bit_14,
        soc_project_id_bit_15,
        soc_project_id_bit_16,
        soc_project_id_bit_17,
        soc_project_id_bit_18,
        soc_project_id_bit_19,
        soc_project_id_bit_20,
        soc_project_id_bit_21,
        soc_project_id_bit_22,
        soc_project_id_bit_23,
        soc_project_id_bit_24,
        soc_project_id_bit_25,
        soc_project_id_bit_26,
        soc_project_id_bit_27,
        soc_project_id_bit_28,
        soc_project_id_bit_29,
        soc_project_id_bit_30,
        soc_project_id_bit_31
    }; // enum class cpu_soc_project_identifier : std::uint8_t

    enum class cpu_soc_project_id_feature_mask : std::uint32_t {
        soc_project_id = 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_0)
                       | 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_1)
                       | 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_2)
                       | 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_3)
                       | 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_4)
                       | 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_5)
                       | 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_6)
                       | 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_7)
                       | 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_8)
                       | 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_9)
                       | 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_10)
                       | 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_11)
                       | 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_12)
                       | 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_13)
                       | 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_14)
                       | 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_15)
                       | 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_16)
                       | 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_17)
                       | 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_18)
                       | 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_19)
                       | 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_20)
                       | 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_21)
                       | 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_22)
                       | 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_23)
                       | 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_24)
                       | 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_25)
                       | 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_26)
                       | 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_27)
                       | 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_28)
                       | 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_29)
                       | 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_30)
                       | 1u << std::to_underlying(cpu_soc_project_identifier::soc_project_id_bit_31)
    }; // enum class cpu_soc_project_identifier_mask : std::uint32_t

    [[nodiscard]]
    inline cpu_soc_project_identifier_mask supported_cpu_soc_project_identifiers(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_soc_project_identifier_mask{};

        if (max_leaf >= 0x17) {
            using enum cpu_soc_project_identifier;
            const auto leaf_0x17 = cpu_id(0x17, 0x00);

            // ecx register
            if (leaf_0x17.ecx_bit( 0u)) result |= soc_project_id_bit_0;
            if (leaf_0x17.ecx_bit( 1u)) result |= soc_project_id_bit_1;
            if (leaf_0x17.ecx_bit( 2u)) result |= soc_project_id_bit_2;
            if (leaf_0x17.ecx_bit( 3u)) result |= soc_project_id_bit_3;
            if (leaf_0x17.ecx_bit( 4u)) result |= soc_project_id_bit_4;
            if (leaf_0x17.ecx_bit( 5u)) result |= soc_project_id_bit_5;
            if (leaf_0x17.ecx_bit( 6u)) result |= soc_project_id_bit_6;
            if (leaf_0x17.ecx_bit( 7u)) result |= soc_project_id_bit_7;
            if (leaf_0x17.ecx_bit( 8u)) result |= soc_project_id_bit_8;
            if (leaf_0x17.ecx_bit( 9u)) result |= soc_project_id_bit_9;
            if (leaf_0x17.ecx_bit(10u)) result |= soc_project_id_bit_10;
            if (leaf_0x17.ecx_bit(11u)) result |= soc_project_id_bit_11;
            if (leaf_0x17.ecx_bit(12u)) result |= soc_project_id_bit_12;
            if (leaf_0x17.ecx_bit(13u)) result |= soc_project_id_bit_13;
            if (leaf_0x17.ecx_bit(14u)) result |= soc_project_id_bit_14;
            if (leaf_0x17.ecx_bit(15u)) result |= soc_project_id_bit_15;
            if (leaf_0x17.ecx_bit(16u)) result |= soc_project_id_bit_16;
            if (leaf_0x17.ecx_bit(17u)) result |= soc_project_id_bit_17;
            if (leaf_0x17.ecx_bit(18u)) result |= soc_project_id_bit_18;
            if (leaf_0x17.ecx_bit(19u)) result |= soc_project_id_bit_19;
            if (leaf_0x17.ecx_bit(20u)) result |= soc_project_id_bit_20;
            if (leaf_0x17.ecx_bit(21u)) result |= soc_project_id_bit_21;
            if (leaf_0x17.ecx_bit(22u)) result |= soc_project_id_bit_22;
            if (leaf_0x17.ecx_bit(23u)) result |= soc_project_id_bit_23;
            if (leaf_0x17.ecx_bit(24u)) result |= soc_project_id_bit_24;
            if (leaf_0x17.ecx_bit(25u)) result |= soc_project_id_bit_25;
            if (leaf_0x17.ecx_bit(26u)) result |= soc_project_id_bit_26;
            if (leaf_0x17.ecx_bit(27u)) result |= soc_project_id_bit_27;
            if (leaf_0x17.ecx_bit(28u)) result |= soc_project_id_bit_28;
            if (leaf_0x17.ecx_bit(29u)) result |= soc_project_id_bit_29;
            if (leaf_0x17.ecx_bit(30u)) result |= soc_project_id_bit_30;
            if (leaf_0x17.ecx_bit(31u)) result |= soc_project_id_bit_31;
        }

        return result;
    }
} // namespace based::platform::x86::detail

