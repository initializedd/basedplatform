#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// TLB Identifiers
// https://en.wikipedia.org/wiki/CPUID#EAX=80000005h:_L1_Cache_and_TLB_Identifiers

namespace based::platform::x86::detail {
    enum class cpu_tlb_identifier : std::uint8_t {
        num_of_instruction_tlb_entries_bit_0,
        num_of_instruction_tlb_entries_bit_1,
        num_of_instruction_tlb_entries_bit_2,
        num_of_instruction_tlb_entries_bit_3,
        num_of_instruction_tlb_entries_bit_4,
        num_of_instruction_tlb_entries_bit_5,
        num_of_instruction_tlb_entries_bit_6,
        num_of_instruction_tlb_entries_bit_7,
        instruction_tlb_associativity_bit_0,
        instruction_tlb_associativity_bit_1,
        instruction_tlb_associativity_bit_2,
        instruction_tlb_associativity_bit_3,
        instruction_tlb_associativity_bit_4,
        instruction_tlb_associativity_bit_5,
        instruction_tlb_associativity_bit_6,
        instruction_tlb_associativity_bit_7,
        num_of_data_tlb_entries_bit_0,
        num_of_data_tlb_entries_bit_1,
        num_of_data_tlb_entries_bit_2,
        num_of_data_tlb_entries_bit_3,
        num_of_data_tlb_entries_bit_4,
        num_of_data_tlb_entries_bit_5,
        num_of_data_tlb_entries_bit_6,
        num_of_data_tlb_entries_bit_7,
        data_tlb_associativity_bit_0,
        data_tlb_associativity_bit_1,
        data_tlb_associativity_bit_2,
        data_tlb_associativity_bit_3,
        data_tlb_associativity_bit_4,
        data_tlb_associativity_bit_5,
        data_tlb_associativity_bit_6,
        data_tlb_associativity_bit_7
    }; // enum class cpu_tlb_identifier : std::uint8_t

    enum class cpu_tlb_identifier_mask : std::uint32_t {
        num_of_instruction_tlb_entries = 1u << std::to_underlying(cpu_tlb_identifier::num_of_instruction_tlb_entries_bit_0)
                                       | 1u << std::to_underlying(cpu_tlb_identifier::num_of_instruction_tlb_entries_bit_1)
                                       | 1u << std::to_underlying(cpu_tlb_identifier::num_of_instruction_tlb_entries_bit_2)
                                       | 1u << std::to_underlying(cpu_tlb_identifier::num_of_instruction_tlb_entries_bit_3)
                                       | 1u << std::to_underlying(cpu_tlb_identifier::num_of_instruction_tlb_entries_bit_4)
                                       | 1u << std::to_underlying(cpu_tlb_identifier::num_of_instruction_tlb_entries_bit_5)
                                       | 1u << std::to_underlying(cpu_tlb_identifier::num_of_instruction_tlb_entries_bit_6)
                                       | 1u << std::to_underlying(cpu_tlb_identifier::num_of_instruction_tlb_entries_bit_7),
        instruction_tlb_associativity  = 1u << std::to_underlying(cpu_tlb_identifier::instruction_tlb_associativity_bit_0)
                                       | 1u << std::to_underlying(cpu_tlb_identifier::instruction_tlb_associativity_bit_1)
                                       | 1u << std::to_underlying(cpu_tlb_identifier::instruction_tlb_associativity_bit_2)
                                       | 1u << std::to_underlying(cpu_tlb_identifier::instruction_tlb_associativity_bit_3)
                                       | 1u << std::to_underlying(cpu_tlb_identifier::instruction_tlb_associativity_bit_4)
                                       | 1u << std::to_underlying(cpu_tlb_identifier::instruction_tlb_associativity_bit_5)
                                       | 1u << std::to_underlying(cpu_tlb_identifier::instruction_tlb_associativity_bit_6)
                                       | 1u << std::to_underlying(cpu_tlb_identifier::instruction_tlb_associativity_bit_7),
        num_of_data_tlb_entries        = 1u << std::to_underlying(cpu_tlb_identifier::num_of_data_tlb_entries_bit_0)
                                       | 1u << std::to_underlying(cpu_tlb_identifier::num_of_data_tlb_entries_bit_1)
                                       | 1u << std::to_underlying(cpu_tlb_identifier::num_of_data_tlb_entries_bit_2)
                                       | 1u << std::to_underlying(cpu_tlb_identifier::num_of_data_tlb_entries_bit_3)
                                       | 1u << std::to_underlying(cpu_tlb_identifier::num_of_data_tlb_entries_bit_4)
                                       | 1u << std::to_underlying(cpu_tlb_identifier::num_of_data_tlb_entries_bit_5)
                                       | 1u << std::to_underlying(cpu_tlb_identifier::num_of_data_tlb_entries_bit_6)
                                       | 1u << std::to_underlying(cpu_tlb_identifier::num_of_data_tlb_entries_bit_7),
        data_tlb_associativity         = 1u << std::to_underlying(cpu_tlb_identifier::data_tlb_associativity_bit_0)
                                       | 1u << std::to_underlying(cpu_tlb_identifier::data_tlb_associativity_bit_1)
                                       | 1u << std::to_underlying(cpu_tlb_identifier::data_tlb_associativity_bit_2)
                                       | 1u << std::to_underlying(cpu_tlb_identifier::data_tlb_associativity_bit_3)
                                       | 1u << std::to_underlying(cpu_tlb_identifier::data_tlb_associativity_bit_4)
                                       | 1u << std::to_underlying(cpu_tlb_identifier::data_tlb_associativity_bit_5)
                                       | 1u << std::to_underlying(cpu_tlb_identifier::data_tlb_associativity_bit_6)
                                       | 1u << std::to_underlying(cpu_tlb_identifier::data_tlb_associativity_bit_7)
    }; // enum class cpu_tlb_identifier_mask : std::uint32_t

    [[nodiscard]]
    cpu_tlb_identifier_mask supported_cpu_huge_page_tlb_identifiers(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_tlb_identifier_mask{};

        if (max_leaf >= 0x80000005) {
            using cpu_tlb_identifier;
            const auto leaf8 = cpu_id(0x80000005, 0u);

            // eax register
            if (leaf8.eax_bit( 0u)) result |= num_of_instruction_tlb_entries_bit_0;
            if (leaf8.eax_bit( 1u)) result |= num_of_instruction_tlb_entries_bit_1;
            if (leaf8.eax_bit( 2u)) result |= num_of_instruction_tlb_entries_bit_2;
            if (leaf8.eax_bit( 3u)) result |= num_of_instruction_tlb_entries_bit_3;
            if (leaf8.eax_bit( 4u)) result |= num_of_instruction_tlb_entries_bit_4;
            if (leaf8.eax_bit( 5u)) result |= num_of_instruction_tlb_entries_bit_5;
            if (leaf8.eax_bit( 6u)) result |= num_of_instruction_tlb_entries_bit_6;
            if (leaf8.eax_bit( 7u)) result |= num_of_instruction_tlb_entries_bit_7;
            if (leaf8.eax_bit( 8u)) result |= instruction_tlb_associativity_bit_0;
            if (leaf8.eax_bit( 9u)) result |= instruction_tlb_associativity_bit_1;
            if (leaf8.eax_bit(10u)) result |= instruction_tlb_associativity_bit_2;
            if (leaf8.eax_bit(11u)) result |= instruction_tlb_associativity_bit_3;
            if (leaf8.eax_bit(12u)) result |= instruction_tlb_associativity_bit_4;
            if (leaf8.eax_bit(13u)) result |= instruction_tlb_associativity_bit_5;
            if (leaf8.eax_bit(14u)) result |= instruction_tlb_associativity_bit_6;
            if (leaf8.eax_bit(15u)) result |= instruction_tlb_associativity_bit_7;
            if (leaf8.eax_bit(16u)) result |= num_of_data_tlb_entries_bit_0;
            if (leaf8.eax_bit(17u)) result |= num_of_data_tlb_entries_bit_1;
            if (leaf8.eax_bit(18u)) result |= num_of_data_tlb_entries_bit_2;
            if (leaf8.eax_bit(19u)) result |= num_of_data_tlb_entries_bit_3;
            if (leaf8.eax_bit(20u)) result |= num_of_data_tlb_entries_bit_4;
            if (leaf8.eax_bit(21u)) result |= num_of_data_tlb_entries_bit_5;
            if (leaf8.eax_bit(22u)) result |= num_of_data_tlb_entries_bit_6;
            if (leaf8.eax_bit(23u)) result |= num_of_data_tlb_entries_bit_7;
            if (leaf8.eax_bit(24u)) result |= data_tlb_associativity_bit_0;
            if (leaf8.eax_bit(25u)) result |= data_tlb_associativity_bit_1;
            if (leaf8.eax_bit(26u)) result |= data_tlb_associativity_bit_2;
            if (leaf8.eax_bit(27u)) result |= data_tlb_associativity_bit_3;
            if (leaf8.eax_bit(28u)) result |= data_tlb_associativity_bit_4;
            if (leaf8.eax_bit(29u)) result |= data_tlb_associativity_bit_5;
            if (leaf8.eax_bit(30u)) result |= data_tlb_associativity_bit_6;
            if (leaf8.eax_bit(31u)) result |= data_tlb_associativity_bit_7;
        }

        return result;
    }

    [[nodiscard]]
    cpu_tlb_identifier_mask supported_cpu_small_page_tlb_identifiers(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_tlb_identifier_mask{};

        if (max_leaf >= 0x80000005) {
            using cpu_tlb_identifier;
            const auto leaf8 = cpu_id(0x80000005, 0u);

            // ebx register
            if (leaf8.ebx_bit( 0u)) result |= num_of_instruction_tlb_entries_bit_0;
            if (leaf8.ebx_bit( 1u)) result |= num_of_instruction_tlb_entries_bit_1;
            if (leaf8.ebx_bit( 2u)) result |= num_of_instruction_tlb_entries_bit_2;
            if (leaf8.ebx_bit( 3u)) result |= num_of_instruction_tlb_entries_bit_3;
            if (leaf8.ebx_bit( 4u)) result |= num_of_instruction_tlb_entries_bit_4;
            if (leaf8.ebx_bit( 5u)) result |= num_of_instruction_tlb_entries_bit_5;
            if (leaf8.ebx_bit( 6u)) result |= num_of_instruction_tlb_entries_bit_6;
            if (leaf8.ebx_bit( 7u)) result |= num_of_instruction_tlb_entries_bit_7;
            if (leaf8.ebx_bit( 8u)) result |= instruction_tlb_associativity_bit_0;
            if (leaf8.ebx_bit( 9u)) result |= instruction_tlb_associativity_bit_1;
            if (leaf8.ebx_bit(10u)) result |= instruction_tlb_associativity_bit_2;
            if (leaf8.ebx_bit(11u)) result |= instruction_tlb_associativity_bit_3;
            if (leaf8.ebx_bit(12u)) result |= instruction_tlb_associativity_bit_4;
            if (leaf8.ebx_bit(13u)) result |= instruction_tlb_associativity_bit_5;
            if (leaf8.ebx_bit(14u)) result |= instruction_tlb_associativity_bit_6;
            if (leaf8.ebx_bit(15u)) result |= instruction_tlb_associativity_bit_7;
            if (leaf8.ebx_bit(16u)) result |= num_of_data_tlb_entries_bit_0;
            if (leaf8.ebx_bit(17u)) result |= num_of_data_tlb_entries_bit_1;
            if (leaf8.ebx_bit(18u)) result |= num_of_data_tlb_entries_bit_2;
            if (leaf8.ebx_bit(19u)) result |= num_of_data_tlb_entries_bit_3;
            if (leaf8.ebx_bit(20u)) result |= num_of_data_tlb_entries_bit_4;
            if (leaf8.ebx_bit(21u)) result |= num_of_data_tlb_entries_bit_5;
            if (leaf8.ebx_bit(22u)) result |= num_of_data_tlb_entries_bit_6;
            if (leaf8.ebx_bit(23u)) result |= num_of_data_tlb_entries_bit_7;
            if (leaf8.ebx_bit(24u)) result |= data_tlb_associativity_bit_0;
            if (leaf8.ebx_bit(25u)) result |= data_tlb_associativity_bit_1;
            if (leaf8.ebx_bit(26u)) result |= data_tlb_associativity_bit_2;
            if (leaf8.ebx_bit(27u)) result |= data_tlb_associativity_bit_3;
            if (leaf8.ebx_bit(28u)) result |= data_tlb_associativity_bit_4;
            if (leaf8.ebx_bit(29u)) result |= data_tlb_associativity_bit_5;
            if (leaf8.ebx_bit(30u)) result |= data_tlb_associativity_bit_6;
            if (leaf8.ebx_bit(31u)) result |= data_tlb_associativity_bit_7;
        }

        return result;
    }
} // namespace based::platform::x86::detail

