#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"
#include "../../util.hpp"

// Processor Info
// https://en.wikipedia.org/wiki/CPUID#EAX=1:_Processor_Info_and_Feature_Bits

namespace based::platform::x86::detail {
    enum class cpu_info : std::uint8_t {
        brand_index_bit_0,
        brand_index_bit_1,
        brand_index_bit_2,
        brand_index_bit_3,
        brand_index_bit_4,
        brand_index_bit_5,
        brand_index_bit_6,
        brand_index_bit_7,
        clflush_line_size_bit_0,
        clflush_line_size_bit_1,
        clflush_line_size_bit_2,
        clflush_line_size_bit_3,
        clflush_line_size_bit_4,
        clflush_line_size_bit_5,
        clflush_line_size_bit_6,
        clflush_line_size_bit_7,
        max_num_of_logical_addressable_ids_bit_0,
        max_num_of_logical_addressable_ids_bit_1,
        max_num_of_logical_addressable_ids_bit_2,
        max_num_of_logical_addressable_ids_bit_3,
        max_num_of_logical_addressable_ids_bit_4,
        max_num_of_logical_addressable_ids_bit_5,
        max_num_of_logical_addressable_ids_bit_6,
        max_num_of_logical_addressable_ids_bit_7,
        local_apic_id_bit_0,
        local_apic_id_bit_1,
        local_apic_id_bit_2,
        local_apic_id_bit_3,
        local_apic_id_bit_4,
        local_apic_id_bit_5,
        local_apic_id_bit_6,
        local_apic_id_bit_7
    }; // enum class cpu_info : std::uint8_t

    enum class cpu_info_mask : std::uint32_t {
        brand_index                        = 1u << std::to_underlying(cpu_info::brand_index_bit_0)
                                           | 1u << std::to_underlying(cpu_info::brand_index_bit_1)
                                           | 1u << std::to_underlying(cpu_info::brand_index_bit_2)
                                           | 1u << std::to_underlying(cpu_info::brand_index_bit_3)
                                           | 1u << std::to_underlying(cpu_info::brand_index_bit_4)
                                           | 1u << std::to_underlying(cpu_info::brand_index_bit_5)
                                           | 1u << std::to_underlying(cpu_info::brand_index_bit_6)
                                           | 1u << std::to_underlying(cpu_info::brand_index_bit_7),
        clflush_line_size                  = 1u << std::to_underlying(cpu_info::clflush_line_size_bit_0)
                                           | 1u << std::to_underlying(cpu_info::clflush_line_size_bit_1)
                                           | 1u << std::to_underlying(cpu_info::clflush_line_size_bit_2)
                                           | 1u << std::to_underlying(cpu_info::clflush_line_size_bit_3)
                                           | 1u << std::to_underlying(cpu_info::clflush_line_size_bit_4)
                                           | 1u << std::to_underlying(cpu_info::clflush_line_size_bit_5)
                                           | 1u << std::to_underlying(cpu_info::clflush_line_size_bit_6)
                                           | 1u << std::to_underlying(cpu_info::clflush_line_size_bit_7),
        max_num_of_logical_addressable_ids = 1u << std::to_underlying(cpu_info::max_num_of_logical_addressable_ids_bit_0)
                                           | 1u << std::to_underlying(cpu_info::max_num_of_logical_addressable_ids_bit_1)
                                           | 1u << std::to_underlying(cpu_info::max_num_of_logical_addressable_ids_bit_2)
                                           | 1u << std::to_underlying(cpu_info::max_num_of_logical_addressable_ids_bit_3)
                                           | 1u << std::to_underlying(cpu_info::max_num_of_logical_addressable_ids_bit_4)
                                           | 1u << std::to_underlying(cpu_info::max_num_of_logical_addressable_ids_bit_5)
                                           | 1u << std::to_underlying(cpu_info::max_num_of_logical_addressable_ids_bit_6)
                                           | 1u << std::to_underlying(cpu_info::max_num_of_logical_addressable_ids_bit_7),
        local_apic_id                      = 1u << std::to_underlying(cpu_info::local_apic_id_bit_0)
                                           | 1u << std::to_underlying(cpu_info::local_apic_id_bit_1)
                                           | 1u << std::to_underlying(cpu_info::local_apic_id_bit_2)
                                           | 1u << std::to_underlying(cpu_info::local_apic_id_bit_3)
                                           | 1u << std::to_underlying(cpu_info::local_apic_id_bit_4)
                                           | 1u << std::to_underlying(cpu_info::local_apic_id_bit_5)
                                           | 1u << std::to_underlying(cpu_info::local_apic_id_bit_6)
                                           | 1u << std::to_underlying(cpu_info::local_apic_id_bit_7)
    }; // enum class cpu_info_mask : std::uint32_t

    [[nodiscard]]
    inline cpu_info_mask supported_cpu_info(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_info_mask{};

        if (max_leaf >= 0x01) {
            using enum cpu_info;
            const auto leaf_0x01 = cpu_id(0x01, 0x00);

            // ebx register
            if (leaf_0x01.ebx_bit( 0u)) result |= brand_index_bit_0;
            if (leaf_0x01.ebx_bit( 1u)) result |= brand_index_bit_1;
            if (leaf_0x01.ebx_bit( 2u)) result |= brand_index_bit_2;
            if (leaf_0x01.ebx_bit( 3u)) result |= brand_index_bit_3;
            if (leaf_0x01.ebx_bit( 4u)) result |= brand_index_bit_4;
            if (leaf_0x01.ebx_bit( 5u)) result |= brand_index_bit_5;
            if (leaf_0x01.ebx_bit( 6u)) result |= brand_index_bit_6;
            if (leaf_0x01.ebx_bit( 7u)) result |= brand_index_bit_7;
            if (leaf_0x01.ebx_bit( 8u)) result |= clflush_line_size_bit_0;
            if (leaf_0x01.ebx_bit( 9u)) result |= clflush_line_size_bit_1;
            if (leaf_0x01.ebx_bit(10u)) result |= clflush_line_size_bit_2;
            if (leaf_0x01.ebx_bit(11u)) result |= clflush_line_size_bit_3;
            if (leaf_0x01.ebx_bit(12u)) result |= clflush_line_size_bit_4;
            if (leaf_0x01.ebx_bit(13u)) result |= clflush_line_size_bit_5;
            if (leaf_0x01.ebx_bit(14u)) result |= clflush_line_size_bit_6;
            if (leaf_0x01.ebx_bit(15u)) result |= clflush_line_size_bit_7;
            if (leaf_0x01.ebx_bit(16u)) result |= max_num_of_logical_addressable_ids_bit_0;
            if (leaf_0x01.ebx_bit(17u)) result |= max_num_of_logical_addressable_ids_bit_1;
            if (leaf_0x01.ebx_bit(18u)) result |= max_num_of_logical_addressable_ids_bit_2;
            if (leaf_0x01.ebx_bit(19u)) result |= max_num_of_logical_addressable_ids_bit_3;
            if (leaf_0x01.ebx_bit(20u)) result |= max_num_of_logical_addressable_ids_bit_4;
            if (leaf_0x01.ebx_bit(21u)) result |= max_num_of_logical_addressable_ids_bit_5;
            if (leaf_0x01.ebx_bit(22u)) result |= max_num_of_logical_addressable_ids_bit_6;
            if (leaf_0x01.ebx_bit(23u)) result |= max_num_of_logical_addressable_ids_bit_7;
            if (leaf_0x01.ebx_bit(24u)) result |= local_apic_id_bit_0;
            if (leaf_0x01.ebx_bit(25u)) result |= local_apic_id_bit_1;
            if (leaf_0x01.ebx_bit(26u)) result |= local_apic_id_bit_2;
            if (leaf_0x01.ebx_bit(27u)) result |= local_apic_id_bit_3;
            if (leaf_0x01.ebx_bit(28u)) result |= local_apic_id_bit_4;
            if (leaf_0x01.ebx_bit(29u)) result |= local_apic_id_bit_5;
            if (leaf_0x01.ebx_bit(30u)) result |= local_apic_id_bit_6;
            if (leaf_0x01.ebx_bit(31u)) result |= local_apic_id_bit_7;
        }

        return result;
    }
} // namespace based::platform::x86::detail

