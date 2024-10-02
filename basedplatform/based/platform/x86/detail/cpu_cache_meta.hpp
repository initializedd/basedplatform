#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// CPU Cache Meta
// https://en.wikipedia.org/wiki/CPUID#EAX=4_and_EAX=80000001Dh:_Cache_hierarchy_and_topology

namespace based::platform::x86::detail {
    enum class cpu_cache_meta : std::uint8_t {
        system_coherency_bytes_bit_0,
        system_coherency_bytes_bit_1,
        system_coherency_bytes_bit_2,
        system_coherency_bytes_bit_3,
        system_coherency_bytes_bit_4,
        system_coherency_bytes_bit_5,
        system_coherency_bytes_bit_6,
        system_coherency_bytes_bit_7,
        system_coherency_bytes_bit_8,
        system_coherency_bytes_bit_9,
        system_coherency_bytes_bit_10,
        system_coherency_bytes_bit_11,
        phys_line_partitions_bit_0,
        phys_line_partitions_bit_1,
        phys_line_partitions_bit_2,
        phys_line_partitions_bit_3,
        phys_line_partitions_bit_4,
        phys_line_partitions_bit_5,
        phys_line_partitions_bit_6,
        phys_line_partitions_bit_7,
        phys_line_partitions_bit_8,
        phys_line_partitions_bit_9,
        ways_of_cache_associativity_bit_0,
        ways_of_cache_associativity_bit_1,
        ways_of_cache_associativity_bit_2,
        ways_of_cache_associativity_bit_3,
        ways_of_cache_associativity_bit_4,
        ways_of_cache_associativity_bit_5,
        ways_of_cache_associativity_bit_6,
        ways_of_cache_associativity_bit_7,
        ways_of_cache_associativity_bit_8,
        ways_of_cache_associativity_bit_9
    }; // enum class cpu_cache_meta : std::uint8_t

    enum class cpu_cache_meta_mask : std::uint32_t {
        system_coherency_bytes      = 1u << std::to_underlying(cpu_cache_meta::system_coherency_bytes_bit_0)
                                    | 1u << std::to_underlying(cpu_cache_meta::system_coherency_bytes_bit_1)
                                    | 1u << std::to_underlying(cpu_cache_meta::system_coherency_bytes_bit_2)
                                    | 1u << std::to_underlying(cpu_cache_meta::system_coherency_bytes_bit_3)
                                    | 1u << std::to_underlying(cpu_cache_meta::system_coherency_bytes_bit_4)
                                    | 1u << std::to_underlying(cpu_cache_meta::system_coherency_bytes_bit_5)
                                    | 1u << std::to_underlying(cpu_cache_meta::system_coherency_bytes_bit_6)
                                    | 1u << std::to_underlying(cpu_cache_meta::system_coherency_bytes_bit_7)
                                    | 1u << std::to_underlying(cpu_cache_meta::system_coherency_bytes_bit_8)
                                    | 1u << std::to_underlying(cpu_cache_meta::system_coherency_bytes_bit_9)
                                    | 1u << std::to_underlying(cpu_cache_meta::system_coherency_bytes_bit_10)
                                    | 1u << std::to_underlying(cpu_cache_meta::system_coherency_bytes_bit_11),
        phys_line_partition         = 1u << std::to_underlying(cpu_cache_meta::phys_line_partitions_bit_0)
                                    | 1u << std::to_underlying(cpu_cache_meta::phys_line_partitions_bit_1)
                                    | 1u << std::to_underlying(cpu_cache_meta::phys_line_partitions_bit_2)
                                    | 1u << std::to_underlying(cpu_cache_meta::phys_line_partitions_bit_3)
                                    | 1u << std::to_underlying(cpu_cache_meta::phys_line_partitions_bit_4)
                                    | 1u << std::to_underlying(cpu_cache_meta::phys_line_partitions_bit_5)
                                    | 1u << std::to_underlying(cpu_cache_meta::phys_line_partitions_bit_6)
                                    | 1u << std::to_underlying(cpu_cache_meta::phys_line_partitions_bit_7)
                                    | 1u << std::to_underlying(cpu_cache_meta::phys_line_partitions_bit_8)
                                    | 1u << std::to_underlying(cpu_cache_meta::phys_line_partitions_bit_9),
        ways_of_cache_associativity = 1u << std::to_underlying(cpu_cache_meta::ways_of_cache_associativity_bit_0)
                                    | 1u << std::to_underlying(cpu_cache_meta::ways_of_cache_associativity_bit_1)
                                    | 1u << std::to_underlying(cpu_cache_meta::ways_of_cache_associativity_bit_2)
                                    | 1u << std::to_underlying(cpu_cache_meta::ways_of_cache_associativity_bit_3)
                                    | 1u << std::to_underlying(cpu_cache_meta::ways_of_cache_associativity_bit_4)
                                    | 1u << std::to_underlying(cpu_cache_meta::ways_of_cache_associativity_bit_5)
                                    | 1u << std::to_underlying(cpu_cache_meta::ways_of_cache_associativity_bit_6)
                                    | 1u << std::to_underlying(cpu_cache_meta::ways_of_cache_associativity_bit_7)
                                    | 1u << std::to_underlying(cpu_cache_meta::ways_of_cache_associativity_bit_8)
                                    | 1u << std::to_underlying(cpu_cache_meta::ways_of_cache_associativity_bit_9)
    }; // enum class cpu_cache_meta_mask : std::uint32_t

    [[nodiscard]]
    cpu_cache_meta_mask supported_cpu_cache_meta(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_cache_meta_mask{};

        if (max_leaf >= 0x04) {
            using enum cpu_cache_meta;
            const auto leaf4 = cpu_id(0x04, 0x00);

            // ebx register
            if (leaf4.ebx_bit( 0u)) result |= system_coherency_bytes_bit_0;
            if (leaf4.ebx_bit( 1u)) result |= system_coherency_bytes_bit_1;
            if (leaf4.ebx_bit( 2u)) result |= system_coherency_bytes_bit_2;
            if (leaf4.ebx_bit( 3u)) result |= system_coherency_bytes_bit_3;
            if (leaf4.ebx_bit( 4u)) result |= system_coherency_bytes_bit_4;
            if (leaf4.ebx_bit( 5u)) result |= system_coherency_bytes_bit_5;
            if (leaf4.ebx_bit( 6u)) result |= system_coherency_bytes_bit_6;
            if (leaf4.ebx_bit( 7u)) result |= system_coherency_bytes_bit_7;
            if (leaf4.ebx_bit( 8u)) result |= system_coherency_bytes_bit_8;
            if (leaf4.ebx_bit( 9u)) result |= system_coherency_bytes_bit_9;
            if (leaf4.ebx_bit(10u)) result |= system_coherency_bytes_bit_10;
            if (leaf4.ebx_bit(11u)) result |= system_coherency_bytes_bit_11;
            if (leaf4.ebx_bit(12u)) result |= phys_line_partition_bit_0;
            if (leaf4.ebx_bit(13u)) result |= phys_line_partition_bit_1;
            if (leaf4.ebx_bit(14u)) result |= phys_line_partition_bit_2;
            if (leaf4.ebx_bit(15u)) result |= phys_line_partition_bit_3;
            if (leaf4.ebx_bit(16u)) result |= phys_line_partition_bit_4;
            if (leaf4.ebx_bit(17u)) result |= phys_line_partition_bit_5;
            if (leaf4.ebx_bit(18u)) result |= phys_line_partition_bit_6;
            if (leaf4.ebx_bit(19u)) result |= phys_line_partition_bit_7;
            if (leaf4.ebx_bit(20u)) result |= phys_line_partition_bit_8;
            if (leaf4.ebx_bit(21u)) result |= phys_line_partition_bit_9;
            if (leaf4.ebx_bit(22u)) result |= ways_of_cache_associativity_bit_0;
            if (leaf4.ebx_bit(23u)) result |= ways_of_cache_associativity_bit_1;
            if (leaf4.ebx_bit(24u)) result |= ways_of_cache_associativity_bit_2;
            if (leaf4.ebx_bit(25u)) result |= ways_of_cache_associativity_bit_3;
            if (leaf4.ebx_bit(26u)) result |= ways_of_cache_associativity_bit_4;
            if (leaf4.ebx_bit(27u)) result |= ways_of_cache_associativity_bit_5;
            if (leaf4.ebx_bit(28u)) result |= ways_of_cache_associativity_bit_6;
            if (leaf4.ebx_bit(29u)) result |= ways_of_cache_associativity_bit_7;
            if (leaf4.ebx_bit(30u)) result |= ways_of_cache_associativity_bit_8;
            if (leaf4.ebx_bit(31u)) result |= ways_of_cache_associativity_bit_9;
        }

        return result;
    }
} // namespace based::platform::x86::detail

