#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

namespace based::platform::x86::detail {
    enum class cpu_soc_vendor_identifier : std::uint8_t {
        soc_vendor_id_bit_0,
        soc_vendor_id_bit_1,
        soc_vendor_id_bit_2,
        soc_vendor_id_bit_3,
        soc_vendor_id_bit_4,
        soc_vendor_id_bit_5,
        soc_vendor_id_bit_6,
        soc_vendor_id_bit_7,
        soc_vendor_id_bit_8,
        soc_vendor_id_bit_9,
        soc_vendor_id_bit_10,
        soc_vendor_id_bit_11,
        soc_vendor_id_bit_12,
        soc_vendor_id_bit_13,
        soc_vendor_id_bit_14,
        soc_vendor_id_bit_15,
        soc_vendor_id_scheme
        // bits 31:17 reserved
    }; // enum class cpu_soc_vendor_identifier : std::uint8_t

    enum class cpu_soc_vendor_identifier_mask : std::uint32_t {
        soc_vendor_id        = 1u << std::to_underlying(cpu_soc_vendor_identifier::soc_vendor_id_bit_0)
                             | 1u << std::to_underlying(cpu_soc_vendor_identifier::soc_vendor_id_bit_1)
                             | 1u << std::to_underlying(cpu_soc_vendor_identifier::soc_vendor_id_bit_2)
                             | 1u << std::to_underlying(cpu_soc_vendor_identifier::soc_vendor_id_bit_3)
                             | 1u << std::to_underlying(cpu_soc_vendor_identifier::soc_vendor_id_bit_4)
                             | 1u << std::to_underlying(cpu_soc_vendor_identifier::soc_vendor_id_bit_5)
                             | 1u << std::to_underlying(cpu_soc_vendor_identifier::soc_vendor_id_bit_6)
                             | 1u << std::to_underlying(cpu_soc_vendor_identifier::soc_vendor_id_bit_7)
                             | 1u << std::to_underlying(cpu_soc_vendor_identifier::soc_vendor_id_bit_8)
                             | 1u << std::to_underlying(cpu_soc_vendor_identifier::soc_vendor_id_bit_9)
                             | 1u << std::to_underlying(cpu_soc_vendor_identifier::soc_vendor_id_bit_10)
                             | 1u << std::to_underlying(cpu_soc_vendor_identifier::soc_vendor_id_bit_11)
                             | 1u << std::to_underlying(cpu_soc_vendor_identifier::soc_vendor_id_bit_12)
                             | 1u << std::to_underlying(cpu_soc_vendor_identifier::soc_vendor_id_bit_13)
                             | 1u << std::to_underlying(cpu_soc_vendor_identifier::soc_vendor_id_bit_14)
                             | 1u << std::to_underlying(cpu_soc_vendor_identifier::soc_vendor_id_bit_15),
        soc_vendor_id_scheme = 1u << std::to_underlying(cpu_soc_vendor_identifier::soc_vendor_id_scheme)
    }; // enum class cpu_soc_vendor_identifier_mask : std::uint32_t

    [[nodiscard]]
    cpu_soc_vendor_identifier_mask supported_cpu_soc_vendor_identifiers(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_soc_vendor_identifier_mask{};

        if (max_leaf >= 0x17) {
            using enum cpu_soc_vendor_identifier;
            const auto leaf17 = cpu_id(0x17, 0x00);

            // ebx register
            if (leaf17.ebx_bit( 0u)) result |= soc_vendor_id_bit_0;
            if (leaf17.ebx_bit( 1u)) result |= soc_vendor_id_bit_1;
            if (leaf17.ebx_bit( 2u)) result |= soc_vendor_id_bit_2;
            if (leaf17.ebx_bit( 3u)) result |= soc_vendor_id_bit_3;
            if (leaf17.ebx_bit( 4u)) result |= soc_vendor_id_bit_4;
            if (leaf17.ebx_bit( 5u)) result |= soc_vendor_id_bit_5;
            if (leaf17.ebx_bit( 6u)) result |= soc_vendor_id_bit_6;
            if (leaf17.ebx_bit( 7u)) result |= soc_vendor_id_bit_7;
            if (leaf17.ebx_bit( 8u)) result |= soc_vendor_id_bit_8;
            if (leaf17.ebx_bit( 9u)) result |= soc_vendor_id_bit_9;
            if (leaf17.ebx_bit(10u)) result |= soc_vendor_id_bit_10;
            if (leaf17.ebx_bit(11u)) result |= soc_vendor_id_bit_11;
            if (leaf17.ebx_bit(12u)) result |= soc_vendor_id_bit_12;
            if (leaf17.ebx_bit(13u)) result |= soc_vendor_id_bit_13;
            if (leaf17.ebx_bit(14u)) result |= soc_vendor_id_bit_14;
            if (leaf17.ebx_bit(15u)) result |= soc_vendor_id_bit_15;
            if (leaf17.ebx_bit(16u)) result |= soc_vendor_id_scheme;
        }

        return result;
    }
} // namespace based::platform::x86::detail

