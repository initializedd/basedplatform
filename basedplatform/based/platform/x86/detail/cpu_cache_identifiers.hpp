#pragma once

#include <cstdint>
#include <utility>

// L1 Cache Identifiers
// https://en.wikipedia.org/wiki/CPUID#EAX=80000005h:_L1_Cache_and_TLB_Identifiers

namespace based::platform::x86::detail {
    enum class cpu_cache_identifier : std::uint8_t {
        cache_line_size_bit_0,
        cache_line_size_bit_1,
        cache_line_size_bit_2,
        cache_line_size_bit_3,
        cache_line_size_bit_4,
        cache_line_size_bit_5,
        cache_line_size_bit_6,
        cache_line_size_bit_7,
        num_of_cache_lines_per_tag_bit_0,
        num_of_cache_lines_per_tag_bit_1,
        num_of_cache_lines_per_tag_bit_2,
        num_of_cache_lines_per_tag_bit_3,
        num_of_cache_lines_per_tag_bit_4,
        num_of_cache_lines_per_tag_bit_5,
        num_of_cache_lines_per_tag_bit_6,
        num_of_cache_lines_per_tag_bit_7,
        cache_associativity_bit_0,
        cache_associativity_bit_1,
        cache_associativity_bit_2,
        cache_associativity_bit_3,
        cache_associativity_bit_4,
        cache_associativity_bit_5,
        cache_associativity_bit_6,
        cache_associativity_bit_7,
        cache_size_bit_0,
        cache_size_bit_1,
        cache_size_bit_2,
        cache_size_bit_3,
        cache_size_bit_4,
        cache_size_bit_5,
        cache_size_bit_6,
        cache_size_bit_7
    }; // enum class cpu_cache_identifier : std::uint8_t

    enum class cpu_cache_identifier_mask : std::uint32_t {
        cache_line_size            = 1u << std::to_underlying(cpu_cache_identifier::cache_line_size_bit_0)
                                   | 1u << std::to_underlying(cpu_cache_identifier::cache_line_size_bit_1)
                                   | 1u << std::to_underlying(cpu_cache_identifier::cache_line_size_bit_2)
                                   | 1u << std::to_underlying(cpu_cache_identifier::cache_line_size_bit_3)
                                   | 1u << std::to_underlying(cpu_cache_identifier::cache_line_size_bit_4)
                                   | 1u << std::to_underlying(cpu_cache_identifier::cache_line_size_bit_5)
                                   | 1u << std::to_underlying(cpu_cache_identifier::cache_line_size_bit_6)
                                   | 1u << std::to_underlying(cpu_cache_identifier::cache_line_size_bit_7),
        num_of_cache_lines_per_tag = 1u << std::to_underlying(cpu_cache_identifier::num_of_cache_lines_per_tag_bit_0)
                                   | 1u << std::to_underlying(cpu_cache_identifier::num_of_cache_lines_per_tag_bit_1)
                                   | 1u << std::to_underlying(cpu_cache_identifier::num_of_cache_lines_per_tag_bit_2)
                                   | 1u << std::to_underlying(cpu_cache_identifier::num_of_cache_lines_per_tag_bit_3)
                                   | 1u << std::to_underlying(cpu_cache_identifier::num_of_cache_lines_per_tag_bit_4)
                                   | 1u << std::to_underlying(cpu_cache_identifier::num_of_cache_lines_per_tag_bit_5)
                                   | 1u << std::to_underlying(cpu_cache_identifier::num_of_cache_lines_per_tag_bit_6)
                                   | 1u << std::to_underlying(cpu_cache_identifier::num_of_cache_lines_per_tag_bit_7),
        cache_associativity        = 1u << std::to_underlying(cpu_cache_identifier::cache_associativity_bit_0)
                                   | 1u << std::to_underlying(cpu_cache_identifier::cache_associativity_bit_1)
                                   | 1u << std::to_underlying(cpu_cache_identifier::cache_associativity_bit_2)
                                   | 1u << std::to_underlying(cpu_cache_identifier::cache_associativity_bit_3)
                                   | 1u << std::to_underlying(cpu_cache_identifier::cache_associativity_bit_4)
                                   | 1u << std::to_underlying(cpu_cache_identifier::cache_associativity_bit_5)
                                   | 1u << std::to_underlying(cpu_cache_identifier::cache_associativity_bit_6)
                                   | 1u << std::to_underlying(cpu_cache_identifier::cache_associativity_bit_7),
        cache_size                 = 1u << std::to_underlying(cpu_cache_identifier::cache_size_bit_0)
                                   | 1u << std::to_underlying(cpu_cache_identifier::cache_size_bit_1)
                                   | 1u << std::to_underlying(cpu_cache_identifier::cache_size_bit_2)
                                   | 1u << std::to_underlying(cpu_cache_identifier::cache_size_bit_3)
                                   | 1u << std::to_underlying(cpu_cache_identifier::cache_size_bit_4)
                                   | 1u << std::to_underlying(cpu_cache_identifier::cache_size_bit_5)
                                   | 1u << std::to_underlying(cpu_cache_identifier::cache_size_bit_6)
                                   | 1u << std::to_underlying(cpu_cache_identifier::cache_size_bit_7)
    }; // enum class cpu_cache_identifier_mask : std::uint32_t

    [[nodiscard]]
    cpu_cache_identifier_mask supported_cpu_data_cache_identifiers(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_cache_identifier_mask{};

        if (max_leaf >= 0x80000005) {
            using cpu_cache_identifier;
            const auto leaf8 = cpu_id(0x80000005, 0u);

            // ecx register
            if (leaf8.ecx_bit( 0u)) result |= cache_line_size_bit_0;
            if (leaf8.ecx_bit( 1u)) result |= cache_line_size_bit_1;
            if (leaf8.ecx_bit( 2u)) result |= cache_line_size_bit_2;
            if (leaf8.ecx_bit( 3u)) result |= cache_line_size_bit_3;
            if (leaf8.ecx_bit( 4u)) result |= cache_line_size_bit_4;
            if (leaf8.ecx_bit( 5u)) result |= cache_line_size_bit_5;
            if (leaf8.ecx_bit( 6u)) result |= cache_line_size_bit_6;
            if (leaf8.ecx_bit( 7u)) result |= cache_line_size_bit_7;
            if (leaf8.ecx_bit( 8u)) result |= num_of_cache_lines_per_tag_bit_0;
            if (leaf8.ecx_bit( 9u)) result |= num_of_cache_lines_per_tag_bit_1;
            if (leaf8.ecx_bit(10u)) result |= num_of_cache_lines_per_tag_bit_2;
            if (leaf8.ecx_bit(11u)) result |= num_of_cache_lines_per_tag_bit_3;
            if (leaf8.ecx_bit(12u)) result |= num_of_cache_lines_per_tag_bit_4;
            if (leaf8.ecx_bit(13u)) result |= num_of_cache_lines_per_tag_bit_5;
            if (leaf8.ecx_bit(14u)) result |= num_of_cache_lines_per_tag_bit_6;
            if (leaf8.ecx_bit(15u)) result |= num_of_cache_lines_per_tag_bit_7;
            if (leaf8.ecx_bit(16u)) result |= cache_associativity_bit_0;
            if (leaf8.ecx_bit(17u)) result |= cache_associativity_bit_1;
            if (leaf8.ecx_bit(18u)) result |= cache_associativity_bit_2;
            if (leaf8.ecx_bit(19u)) result |= cache_associativity_bit_3;
            if (leaf8.ecx_bit(20u)) result |= cache_associativity_bit_4;
            if (leaf8.ecx_bit(21u)) result |= cache_associativity_bit_5;
            if (leaf8.ecx_bit(22u)) result |= cache_associativity_bit_6;
            if (leaf8.ecx_bit(23u)) result |= cache_associativity_bit_7;
            if (leaf8.ecx_bit(24u)) result |= cache_size_bit_0;
            if (leaf8.ecx_bit(25u)) result |= cache_size_bit_1;
            if (leaf8.ecx_bit(26u)) result |= cache_size_bit_2;
            if (leaf8.ecx_bit(27u)) result |= cache_size_bit_3;
            if (leaf8.ecx_bit(28u)) result |= cache_size_bit_4;
            if (leaf8.ecx_bit(29u)) result |= cache_size_bit_5;
            if (leaf8.ecx_bit(30u)) result |= cache_size_bit_6;
            if (leaf8.ecx_bit(31u)) result |= cache_size_bit_7;
        }

        return result;
    }

    [[nodiscard]]
    cpu_cache_identifier_mask supported_cpu_instruction_cache_identifiers(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_cache_identifier_mask{};

        if (max_leaf >= 0x80000005) {
            using cpu_cache_identifier;
            const auto leaf8 = cpu_id(0x80000005, 0u);

            // edx register
            if (leaf8.edx_bit( 0u)) result |= cache_line_size_bit_0;
            if (leaf8.edx_bit( 1u)) result |= cache_line_size_bit_1;
            if (leaf8.edx_bit( 2u)) result |= cache_line_size_bit_2;
            if (leaf8.edx_bit( 3u)) result |= cache_line_size_bit_3;
            if (leaf8.edx_bit( 4u)) result |= cache_line_size_bit_4;
            if (leaf8.edx_bit( 5u)) result |= cache_line_size_bit_5;
            if (leaf8.edx_bit( 6u)) result |= cache_line_size_bit_6;
            if (leaf8.edx_bit( 7u)) result |= cache_line_size_bit_7;
            if (leaf8.edx_bit( 8u)) result |= num_of_cache_lines_per_tag_bit_0;
            if (leaf8.edx_bit( 9u)) result |= num_of_cache_lines_per_tag_bit_1;
            if (leaf8.edx_bit(10u)) result |= num_of_cache_lines_per_tag_bit_2;
            if (leaf8.edx_bit(11u)) result |= num_of_cache_lines_per_tag_bit_3;
            if (leaf8.edx_bit(12u)) result |= num_of_cache_lines_per_tag_bit_4;
            if (leaf8.edx_bit(13u)) result |= num_of_cache_lines_per_tag_bit_5;
            if (leaf8.edx_bit(14u)) result |= num_of_cache_lines_per_tag_bit_6;
            if (leaf8.edx_bit(15u)) result |= num_of_cache_lines_per_tag_bit_7;
            if (leaf8.edx_bit(16u)) result |= cache_associativity_bit_0;
            if (leaf8.edx_bit(17u)) result |= cache_associativity_bit_1;
            if (leaf8.edx_bit(18u)) result |= cache_associativity_bit_2;
            if (leaf8.edx_bit(19u)) result |= cache_associativity_bit_3;
            if (leaf8.edx_bit(20u)) result |= cache_associativity_bit_4;
            if (leaf8.edx_bit(21u)) result |= cache_associativity_bit_5;
            if (leaf8.edx_bit(22u)) result |= cache_associativity_bit_6;
            if (leaf8.edx_bit(23u)) result |= cache_associativity_bit_7;
            if (leaf8.edx_bit(24u)) result |= cache_size_bit_0;
            if (leaf8.edx_bit(25u)) result |= cache_size_bit_1;
            if (leaf8.edx_bit(26u)) result |= cache_size_bit_2;
            if (leaf8.edx_bit(27u)) result |= cache_size_bit_3;
            if (leaf8.edx_bit(28u)) result |= cache_size_bit_4;
            if (leaf8.edx_bit(29u)) result |= cache_size_bit_5;
            if (leaf8.edx_bit(30u)) result |= cache_size_bit_6;
            if (leaf8.edx_bit(31u)) result |= cache_size_bit_7;
        }

        return result;
    }
} // namespace based::platform::x86::detail

