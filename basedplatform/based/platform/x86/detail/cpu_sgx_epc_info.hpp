#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// SGX Enclave Page Cache section information
// https://en.wikipedia.org/wiki/CPUID#EAX=12h:_SGX_capabilities

namespace based::platform::x86::detail {
    enum class cpu_sgx_epc_info : std::uint8_t {
        sub_leaf_type_bit_0,
        sub_leaf_type_bit_1,
        sub_leaf_type_bit_2,
        sub_leaf_type_bit_3,
        // bits 11:4 reserved
        physical_base_address_bit_0 = 12u,
        physical_base_address_bit_1,
        physical_base_address_bit_2,
        physical_base_address_bit_3,
        physical_base_address_bit_4,
        physical_base_address_bit_5,
        physical_base_address_bit_6,
        physical_base_address_bit_7,
        physical_base_address_bit_8,
        physical_base_address_bit_9,
        physical_base_address_bit_10,
        physical_base_address_bit_11,
        physical_base_address_bit_12,
        physical_base_address_bit_13,
        physical_base_address_bit_14,
        physical_base_address_bit_15,
        physical_base_address_bit_16,
        physical_base_address_bit_17,
        physical_base_address_bit_18,
        physical_base_address_bit_19
    }; // enum class cpu_sgx_epc_info : std::uint8_t

    enum class cpu_sgx_epc_info_mask : std::uint32_t {
        sub_leaf_type         = 1u << std::to_underlying(cpu_sgx_epc_info::sub_leaf_type_bit_0)
                              | 1u << std::to_underlying(cpu_sgx_epc_info::sub_leaf_type_bit_1)
                              | 1u << std::to_underlying(cpu_sgx_epc_info::sub_leaf_type_bit_2)
                              | 1u << std::to_underlying(cpu_sgx_epc_info::sub_leaf_type_bit_3),
        physical_base_address = 1u << std::to_underlying(cpu_sgx_epc_info::physical_base_address_bit_0)
                              | 1u << std::to_underlying(cpu_sgx_epc_info::physical_base_address_bit_1)
                              | 1u << std::to_underlying(cpu_sgx_epc_info::physical_base_address_bit_2)
                              | 1u << std::to_underlying(cpu_sgx_epc_info::physical_base_address_bit_3)
                              | 1u << std::to_underlying(cpu_sgx_epc_info::physical_base_address_bit_4)
                              | 1u << std::to_underlying(cpu_sgx_epc_info::physical_base_address_bit_5)
                              | 1u << std::to_underlying(cpu_sgx_epc_info::physical_base_address_bit_6)
                              | 1u << std::to_underlying(cpu_sgx_epc_info::physical_base_address_bit_7)
                              | 1u << std::to_underlying(cpu_sgx_epc_info::physical_base_address_bit_8)
                              | 1u << std::to_underlying(cpu_sgx_epc_info::physical_base_address_bit_9)
                              | 1u << std::to_underlying(cpu_sgx_epc_info::physical_base_address_bit_10)
                              | 1u << std::to_underlying(cpu_sgx_epc_info::physical_base_address_bit_11)
                              | 1u << std::to_underlying(cpu_sgx_epc_info::physical_base_address_bit_12)
                              | 1u << std::to_underlying(cpu_sgx_epc_info::physical_base_address_bit_13)
                              | 1u << std::to_underlying(cpu_sgx_epc_info::physical_base_address_bit_14)
                              | 1u << std::to_underlying(cpu_sgx_epc_info::physical_base_address_bit_15)
                              | 1u << std::to_underlying(cpu_sgx_epc_info::physical_base_address_bit_16)
                              | 1u << std::to_underlying(cpu_sgx_epc_info::physical_base_address_bit_17)
                              | 1u << std::to_underlying(cpu_sgx_epc_info::physical_base_address_bit_18)
                              | 1u << std::to_underlying(cpu_sgx_epc_info::physical_base_address_bit_19)
    }; // enum class cpu_sgx_epc_info_mask : std::uint32_t

    [[nodiscard]]
    cpu_sgx_epc_info_mask supported_cpu_sgx_epc_info(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_sgx_epc_info_mask{};

        if (max_leaf >= 0x12) {
            using cpu_sgx_epc_info;
            const auto leaf18 = cpu_id(0x12, 0x02);

            // eax register
            if (leaf18.eax_bit( 0u)) result |= sub_leaf_type_bit_0;
            if (leaf18.eax_bit( 1u)) result |= sub_leaf_type_bit_1;
            if (leaf18.eax_bit( 2u)) result |= sub_leaf_type_bit_2;
            if (leaf18.eax_bit( 3u)) result |= sub_leaf_type_bit_3;
            if (leaf18.eax_bit(12u)) result |= physical_base_address_bit_0;
            if (leaf18.eax_bit(13u)) result |= physical_base_address_bit_1;
            if (leaf18.eax_bit(14u)) result |= physical_base_address_bit_2;
            if (leaf18.eax_bit(15u)) result |= physical_base_address_bit_3;
            if (leaf18.eax_bit(16u)) result |= physical_base_address_bit_4;
            if (leaf18.eax_bit(17u)) result |= physical_base_address_bit_5;
            if (leaf18.eax_bit(18u)) result |= physical_base_address_bit_6;
            if (leaf18.eax_bit(19u)) result |= physical_base_address_bit_7;
            if (leaf18.eax_bit(20u)) result |= physical_base_address_bit_8;
            if (leaf18.eax_bit(21u)) result |= physical_base_address_bit_9;
            if (leaf18.eax_bit(22u)) result |= physical_base_address_bit_10;
            if (leaf18.eax_bit(23u)) result |= physical_base_address_bit_11;
            if (leaf18.eax_bit(24u)) result |= physical_base_address_bit_12;
            if (leaf18.eax_bit(25u)) result |= physical_base_address_bit_13;
            if (leaf18.eax_bit(26u)) result |= physical_base_address_bit_14;
            if (leaf18.eax_bit(27u)) result |= physical_base_address_bit_15;
            if (leaf18.eax_bit(28u)) result |= physical_base_address_bit_16;
            if (leaf18.eax_bit(29u)) result |= physical_base_address_bit_17;
            if (leaf18.eax_bit(30u)) result |= physical_base_address_bit_18;
            if (leaf18.eax_bit(31u)) result |= physical_base_address_bit_19;
        }

        return result;
    }

    enum class cpu_sgx_epc_physical_base_address_remainder : std::uint8_t {
        physical_base_address_bit_0,
        physical_base_address_bit_1,
        physical_base_address_bit_2,
        physical_base_address_bit_3,
        physical_base_address_bit_4,
        physical_base_address_bit_5,
        physical_base_address_bit_6,
        physical_base_address_bit_7,
        physical_base_address_bit_8,
        physical_base_address_bit_9,
        physical_base_address_bit_10,
        physical_base_address_bit_11,
        physical_base_address_bit_12,
        physical_base_address_bit_13,
        physical_base_address_bit_14,
        physical_base_address_bit_15,
        physical_base_address_bit_16,
        physical_base_address_bit_17,
        physical_base_address_bit_18,
        physical_base_address_bit_19
        // bits 31:20 reserved
    }; // enum class cpu_sgx_epc_physical_base_address_remainder : std::uint8_t

    enum class cpu_sgx_epc_physical_base_address_remainder_mask : std::uint32_t {
        physical_base_address = 1u << std::to_underlying(cpu_sgx_epc_physical_base_address_remainder::physical_base_address_bit_0)
                              | 1u << std::to_underlying(cpu_sgx_epc_physical_base_address_remainder::physical_base_address_bit_1)
                              | 1u << std::to_underlying(cpu_sgx_epc_physical_base_address_remainder::physical_base_address_bit_2)
                              | 1u << std::to_underlying(cpu_sgx_epc_physical_base_address_remainder::physical_base_address_bit_3)
                              | 1u << std::to_underlying(cpu_sgx_epc_physical_base_address_remainder::physical_base_address_bit_4)
                              | 1u << std::to_underlying(cpu_sgx_epc_physical_base_address_remainder::physical_base_address_bit_5)
                              | 1u << std::to_underlying(cpu_sgx_epc_physical_base_address_remainder::physical_base_address_bit_6)
                              | 1u << std::to_underlying(cpu_sgx_epc_physical_base_address_remainder::physical_base_address_bit_7)
                              | 1u << std::to_underlying(cpu_sgx_epc_physical_base_address_remainder::physical_base_address_bit_8)
                              | 1u << std::to_underlying(cpu_sgx_epc_physical_base_address_remainder::physical_base_address_bit_9)
                              | 1u << std::to_underlying(cpu_sgx_epc_physical_base_address_remainder::physical_base_address_bit_10)
                              | 1u << std::to_underlying(cpu_sgx_epc_physical_base_address_remainder::physical_base_address_bit_11)
                              | 1u << std::to_underlying(cpu_sgx_epc_physical_base_address_remainder::physical_base_address_bit_12)
                              | 1u << std::to_underlying(cpu_sgx_epc_physical_base_address_remainder::physical_base_address_bit_13)
                              | 1u << std::to_underlying(cpu_sgx_epc_physical_base_address_remainder::physical_base_address_bit_14)
                              | 1u << std::to_underlying(cpu_sgx_epc_physical_base_address_remainder::physical_base_address_bit_15)
                              | 1u << std::to_underlying(cpu_sgx_epc_physical_base_address_remainder::physical_base_address_bit_16)
                              | 1u << std::to_underlying(cpu_sgx_epc_physical_base_address_remainder::physical_base_address_bit_17)
                              | 1u << std::to_underlying(cpu_sgx_epc_physical_base_address_remainder::physical_base_address_bit_18)
                              | 1u << std::to_underlying(cpu_sgx_epc_physical_base_address_remainder::physical_base_address_bit_19)
    }; // enum class cpu_sgx_epc_physical_base_address_remainder_mask : std::uint32_t

    [[nodiscard]]
    cpu_sgx_epc_physical_base_address_remainder_mask supported_cpu_sgx_epc_physical_base_address_remainder(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_sgx_epc_physical_base_address_remainder_mask{};

        if (max_leaf >= 0x12) {
            using cpu_sgx_epc_physical_base_address_remainder;
            const auto leaf18 = cpu_id(0x12, 0x02);

            // ebx register
            if (leaf18.ebx_bit( 0u)) result |= physical_base_address_bit_0;
            if (leaf18.ebx_bit( 1u)) result |= physical_base_address_bit_1;
            if (leaf18.ebx_bit( 2u)) result |= physical_base_address_bit_2;
            if (leaf18.ebx_bit( 3u)) result |= physical_base_address_bit_3;
            if (leaf18.ebx_bit( 4u)) result |= physical_base_address_bit_4;
            if (leaf18.ebx_bit( 5u)) result |= physical_base_address_bit_5;
            if (leaf18.ebx_bit( 6u)) result |= physical_base_address_bit_6;
            if (leaf18.ebx_bit( 7u)) result |= physical_base_address_bit_7;
            if (leaf18.ebx_bit( 8u)) result |= physical_base_address_bit_8;
            if (leaf18.ebx_bit( 9u)) result |= physical_base_address_bit_9;
            if (leaf18.ebx_bit(10u)) result |= physical_base_address_bit_10;
            if (leaf18.ebx_bit(11u)) result |= physical_base_address_bit_11;
            if (leaf18.ebx_bit(12u)) result |= physical_base_address_bit_12;
            if (leaf18.ebx_bit(13u)) result |= physical_base_address_bit_13;
            if (leaf18.ebx_bit(14u)) result |= physical_base_address_bit_14;
            if (leaf18.ebx_bit(15u)) result |= physical_base_address_bit_15;
            if (leaf18.ebx_bit(16u)) result |= physical_base_address_bit_16;
            if (leaf18.ebx_bit(17u)) result |= physical_base_address_bit_17;
            if (leaf18.ebx_bit(18u)) result |= physical_base_address_bit_18;
            if (leaf18.ebx_bit(19u)) result |= physical_base_address_bit_19;
        }

        return result;
    }

    enum class cpu_sgx_epc_section_property : std::uint8_t {
        property_bit_0,
        property_bit_1,
        property_bit_2,
        property_bit_3,
        // bits 11:4 reserved
        section_size_bit_0 = 12u,
        section_size_bit_1,
        section_size_bit_2,
        section_size_bit_3,
        section_size_bit_4,
        section_size_bit_5,
        section_size_bit_6,
        section_size_bit_7,
        section_size_bit_8,
        section_size_bit_9,
        section_size_bit_10,
        section_size_bit_11,
        section_size_bit_12,
        section_size_bit_13,
        section_size_bit_14,
        section_size_bit_15,
        section_size_bit_16,
        section_size_bit_17,
        section_size_bit_18,
        section_size_bit_19
    }; // enum class cpu_sgx_epc_section_property : std::uint8_t

    enum class cpu_sgx_epc_section_property_mask : std::uint32_t {
        properties   = 1u << std::to_underlying(cpu_sgx_epc_section_property::property_bit_0)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_property::property_bit_1)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_property::property_bit_2)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_property::property_bit_3),
        section_size = 1u << std::to_underlying(cpu_sgx_epc_section_property::section_size_bit_0)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_property::section_size_bit_1)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_property::section_size_bit_2)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_property::section_size_bit_3)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_property::section_size_bit_4)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_property::section_size_bit_5)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_property::section_size_bit_6)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_property::section_size_bit_7)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_property::section_size_bit_8)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_property::section_size_bit_9)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_property::section_size_bit_10)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_property::section_size_bit_11)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_property::section_size_bit_12)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_property::section_size_bit_13)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_property::section_size_bit_14)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_property::section_size_bit_15)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_property::section_size_bit_16)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_property::section_size_bit_17)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_property::section_size_bit_18)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_property::section_size_bit_19)
    }; // enum class cpu_sgx_epc_section_property_mask : std::uint32_t

    [[nodiscard]]
    cpu_sgx_epc_section_property_mask supported_cpu_sgx_epc_section_properties(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_sgx_epc_section_property_mask{};

        if (max_leaf >= 0x12) {
            using cpu_sgx_epc_section_property;
            const auto leaf18 = cpu_id(0x12, 0x02);

            // ecx register
            if (leaf18.ecx_bit( 0u)) result |= property_bit_0;
            if (leaf18.ecx_bit( 1u)) result |= property_bit_1;
            if (leaf18.ecx_bit( 2u)) result |= property_bit_2;
            if (leaf18.ecx_bit( 3u)) result |= property_bit_3;
            if (leaf18.ecx_bit(12u)) result |= section_size_bit_0;
            if (leaf18.ecx_bit(13u)) result |= section_size_bit_1;
            if (leaf18.ecx_bit(14u)) result |= section_size_bit_2;
            if (leaf18.ecx_bit(15u)) result |= section_size_bit_3;
            if (leaf18.ecx_bit(16u)) result |= section_size_bit_4;
            if (leaf18.ecx_bit(17u)) result |= section_size_bit_5;
            if (leaf18.ecx_bit(18u)) result |= section_size_bit_6;
            if (leaf18.ecx_bit(19u)) result |= section_size_bit_7;
            if (leaf18.ecx_bit(20u)) result |= section_size_bit_8;
            if (leaf18.ecx_bit(21u)) result |= section_size_bit_9;
            if (leaf18.ecx_bit(22u)) result |= section_size_bit_10;
            if (leaf18.ecx_bit(23u)) result |= section_size_bit_11;
            if (leaf18.ecx_bit(24u)) result |= section_size_bit_12;
            if (leaf18.ecx_bit(25u)) result |= section_size_bit_13;
            if (leaf18.ecx_bit(26u)) result |= section_size_bit_14;
            if (leaf18.ecx_bit(27u)) result |= section_size_bit_15;
            if (leaf18.ecx_bit(28u)) result |= section_size_bit_16;
            if (leaf18.ecx_bit(29u)) result |= section_size_bit_17;
            if (leaf18.ecx_bit(30u)) result |= section_size_bit_18;
            if (leaf18.ecx_bit(31u)) result |= section_size_bit_19;
        }

        return result;
    }

    enum class cpu_sgx_epc_section_size_remainder : std::uint8_t {
        section_size_bit_0,
        section_size_bit_1,
        section_size_bit_2,
        section_size_bit_3,
        section_size_bit_4,
        section_size_bit_5,
        section_size_bit_6,
        section_size_bit_7,
        section_size_bit_8,
        section_size_bit_9,
        section_size_bit_10,
        section_size_bit_11,
        section_size_bit_12,
        section_size_bit_13,
        section_size_bit_14,
        section_size_bit_15,
        section_size_bit_16,
        section_size_bit_17,
        section_size_bit_18,
        section_size_bit_19
        // bits 31:20 reserved
    }; // enum class cpu_sgx_epc_section_size_remainder : std::uint8_t

    enum class cpu_sgx_epc_section_size_remainder_mask : std::uint32_t {
        section_size = 1u << std::to_underlying(cpu_sgx_epc_section_size_remainder::section_size_bit_0)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_size_remainder::section_size_bit_1)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_size_remainder::section_size_bit_2)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_size_remainder::section_size_bit_3)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_size_remainder::section_size_bit_4)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_size_remainder::section_size_bit_5)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_size_remainder::section_size_bit_6)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_size_remainder::section_size_bit_7)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_size_remainder::section_size_bit_8)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_size_remainder::section_size_bit_9)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_size_remainder::section_size_bit_10)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_size_remainder::section_size_bit_11)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_size_remainder::section_size_bit_12)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_size_remainder::section_size_bit_13)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_size_remainder::section_size_bit_14)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_size_remainder::section_size_bit_15)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_size_remainder::section_size_bit_16)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_size_remainder::section_size_bit_17)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_size_remainder::section_size_bit_18)
                     | 1u << std::to_underlying(cpu_sgx_epc_section_size_remainder::section_size_bit_19)
    }; // enum class cpu_sgx_epc_section_size_remainder_mask : std::uint32_t

    [[nodiscard]]
    cpu_sgx_epc_section_size_remainder_mask supported_cpu_sgx_epc_section_size_remainder(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_sgx_epc_section_size_remainder_mask{};

        if (max_leaf >= 0x12) {
            using cpu_sgx_epc_section_size_remainder;
            const auto leaf18 = cpu_id(0x12, 0x02);

            // edx register
            if (leaf18.edx_bit( 0u)) result |= section_size_bit_0;
            if (leaf18.edx_bit( 1u)) result |= section_size_bit_1;
            if (leaf18.edx_bit( 2u)) result |= section_size_bit_2;
            if (leaf18.edx_bit( 3u)) result |= section_size_bit_3;
            if (leaf18.edx_bit( 4u)) result |= section_size_bit_4;
            if (leaf18.edx_bit( 5u)) result |= section_size_bit_5;
            if (leaf18.edx_bit( 6u)) result |= section_size_bit_6;
            if (leaf18.edx_bit( 7u)) result |= section_size_bit_7;
            if (leaf18.edx_bit( 8u)) result |= section_size_bit_8;
            if (leaf18.edx_bit( 9u)) result |= section_size_bit_9;
            if (leaf18.edx_bit(10u)) result |= section_size_bit_10;
            if (leaf18.edx_bit(11u)) result |= section_size_bit_11;
            if (leaf18.edx_bit(12u)) result |= section_size_bit_12;
            if (leaf18.edx_bit(13u)) result |= section_size_bit_13;
            if (leaf18.edx_bit(14u)) result |= section_size_bit_14;
            if (leaf18.edx_bit(15u)) result |= section_size_bit_15;
            if (leaf18.edx_bit(16u)) result |= section_size_bit_16;
            if (leaf18.edx_bit(17u)) result |= section_size_bit_17;
            if (leaf18.edx_bit(18u)) result |= section_size_bit_18;
            if (leaf18.edx_bit(19u)) result |= section_size_bit_19;
        }

        return result;
    }
} // namespace based::platform::x86::detail

