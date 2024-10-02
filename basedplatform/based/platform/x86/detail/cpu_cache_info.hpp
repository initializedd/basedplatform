#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// CPU Cache Info
// https://en.wikipedia.org/wiki/CPUID#EAX=4_and_EAX=8000001Dh:_Cache_hierarchy_and_topology

namespace based::platform::x86::detail {
    enum class cpu_cache_info : std::uint8_t {
        cache_type_bit_0,
        cache_type_bit_1,
        cache_type_bit_2,
        cache_type_bit_3,
        cache_type_bit_4,
        cache_level_bit_0,
        cache_level_bit_1,
        cache_level_bit_2,
        self_init_cache_level,
        fully_associative_cache,
        wbinvd_cache_invalidation_execution_scope,
        cache_inclusiveness,
        // bits 13:12 reserved
        max_num_of_addressable_ids_logical_shared_cache_bit_0 = 14u,
        max_num_of_addressable_ids_logical_shared_cache_bit_1,
        max_num_of_addressable_ids_logical_shared_cache_bit_2,
        max_num_of_addressable_ids_logical_shared_cache_bit_3,
        max_num_of_addressable_ids_logical_shared_cache_bit_4,
        max_num_of_addressable_ids_logical_shared_cache_bit_5,
        max_num_of_addressable_ids_logical_shared_cache_bit_6,
        max_num_of_addressable_ids_logical_shared_cache_bit_7,
        max_num_of_addressable_ids_logical_shared_cache_bit_8,
        max_num_of_addressable_ids_logical_shared_cache_bit_9,
        max_num_of_addressable_ids_logical_shared_cache_bit_10,
        max_num_of_addressable_ids_logical_shared_cache_bit_11,
        max_num_of_addressable_ids_cores_phys_package_bit_0,
        max_num_of_addressable_ids_cores_phys_package_bit_1,
        max_num_of_addressable_ids_cores_phys_package_bit_2,
        max_num_of_addressable_ids_cores_phys_package_bit_3,
        max_num_of_addressable_ids_cores_phys_package_bit_4,
        max_num_of_addressable_ids_cores_phys_package_bit_5
    }; // enum class cpu_cache_info : std::uint8_t

    enum class cpu_cache_info_mask : std::uint32_t {
        cache_type                                      = 1u << std::to_underlying(cpu_cache_info::cache_type_bit_0)
                                                        | 1u << std::to_underlying(cpu_cache_info::cache_type_bit_1)
                                                        | 1u << std::to_underlying(cpu_cache_info::cache_type_bit_2)
                                                        | 1u << std::to_underlying(cpu_cache_info::cache_type_bit_3)
                                                        | 1u << std::to_underlying(cpu_cache_info::cache_type_bit_4),
        cache_level                                     = 1u << std::to_underlying(cpu_cache_info::cache_level_bit_0)
                                                        | 1u << std::to_underlying(cpu_cache_info::cache_level_bit_1)
                                                        | 1u << std::to_underlying(cpu_cache_info::cache_level_bit_2),
        self_init_cache_level                           = 1u << std::to_underlying(cpu_cache_info::self_init_cache_level),
        fully_associative_cache                         = 1u << std::to_underlying(cpu_cache_info::fully_associative_cache),
        wbinvd_cache_invalidation_execution_scope       = 1u << std::to_underlying(cpu_cache_info::wbinvd_cache_invalidation_execution_scope),
        cache_inclusiveness                             = 1u << std::to_underlying(cpu_cache_info::cache_inclusiveness),
        max_num_of_addressable_ids_logical_shared_cache = 1u << std::to_underlying(cpu_cache_info::max_num_of_addressable_ids_logical_shared_cache_bit_0)
                                                        | 1u << std::to_underlying(cpu_cache_info::max_num_of_addressable_ids_logical_shared_cache_bit_1)
                                                        | 1u << std::to_underlying(cpu_cache_info::max_num_of_addressable_ids_logical_shared_cache_bit_2)
                                                        | 1u << std::to_underlying(cpu_cache_info::max_num_of_addressable_ids_logical_shared_cache_bit_3)
                                                        | 1u << std::to_underlying(cpu_cache_info::max_num_of_addressable_ids_logical_shared_cache_bit_4)
                                                        | 1u << std::to_underlying(cpu_cache_info::max_num_of_addressable_ids_logical_shared_cache_bit_5)
                                                        | 1u << std::to_underlying(cpu_cache_info::max_num_of_addressable_ids_logical_shared_cache_bit_6)
                                                        | 1u << std::to_underlying(cpu_cache_info::max_num_of_addressable_ids_logical_shared_cache_bit_7)
                                                        | 1u << std::to_underlying(cpu_cache_info::max_num_of_addressable_ids_logical_shared_cache_bit_8)
                                                        | 1u << std::to_underlying(cpu_cache_info::max_num_of_addressable_ids_logical_shared_cache_bit_9)
                                                        | 1u << std::to_underlying(cpu_cache_info::max_num_of_addressable_ids_logical_shared_cache_bit_10)
                                                        | 1u << std::to_underlying(cpu_cache_info::max_num_of_addressable_ids_logical_shared_cache_bit_11),
        max_num_of_addressable_ids_cores_phys_package   = 1u << std::to_underlying(cpu_cache_info::max_num_of_addressable_ids_cores_phys_package_bit_0)
                                                        | 1u << std::to_underlying(cpu_cache_info::max_num_of_addressable_ids_cores_phys_package_bit_1)
                                                        | 1u << std::to_underlying(cpu_cache_info::max_num_of_addressable_ids_cores_phys_package_bit_2)
                                                        | 1u << std::to_underlying(cpu_cache_info::max_num_of_addressable_ids_cores_phys_package_bit_3)
                                                        | 1u << std::to_underlying(cpu_cache_info::max_num_of_addressable_ids_cores_phys_package_bit_4)
                                                        | 1u << std::to_underlying(cpu_cache_info::max_num_of_addressable_ids_cores_phys_package_bit_5)
    }; // enum class cpu_cache_info_mask : std::uint32_t

    [[nodiscard]]
    cpu_cache_info_mask supported_cpu_cache_info(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_cache_info_mask{};

        if (max_leaf >= 4u) {
            using cpu_cache_info;
            const auto leaf4 = cpu_id(4u, 0u);

            // eax register
            if (leaf4.eax_bit( 0u)) result |= cache_type_bit_0;
            if (leaf4.eax_bit( 1u)) result |= cache_type_bit_1;
            if (leaf4.eax_bit( 2u)) result |= cache_type_bit_2;
            if (leaf4.eax_bit( 3u)) result |= cache_type_bit_3;
            if (leaf4.eax_bit( 4u)) result |= cache_type_bit_4;
            if (leaf4.eax_bit( 5u)) result |= cache_level_bit_0;
            if (leaf4.eax_bit( 6u)) result |= cache_level_bit_1;
            if (leaf4.eax_bit( 7u)) result |= cache_level_bit_2;
            if (leaf4.eax_bit( 8u)) result |= self_init_cache_level;
            if (leaf4.eax_bit( 9u)) result |= fully_associative_cache;
            if (leaf4.eax_bit(10u)) result |= wbinvd_cache_invalidation_execution_scope;
            if (leaf4.eax_bit(11u)) result |= cache_inclusiveness;
            if (leaf4.eax_bit(14u)) result |= max_num_of_addressable_ids_logical_shared_cache_bit_0;
            if (leaf4.eax_bit(15u)) result |= max_num_of_addressable_ids_logical_shared_cache_bit_1;
            if (leaf4.eax_bit(16u)) result |= max_num_of_addressable_ids_logical_shared_cache_bit_2;
            if (leaf4.eax_bit(17u)) result |= max_num_of_addressable_ids_logical_shared_cache_bit_3;
            if (leaf4.eax_bit(18u)) result |= max_num_of_addressable_ids_logical_shared_cache_bit_4;
            if (leaf4.eax_bit(19u)) result |= max_num_of_addressable_ids_logical_shared_cache_bit_5;
            if (leaf4.eax_bit(20u)) result |= max_num_of_addressable_ids_logical_shared_cache_bit_6;
            if (leaf4.eax_bit(21u)) result |= max_num_of_addressable_ids_logical_shared_cache_bit_7;
            if (leaf4.eax_bit(22u)) result |= max_num_of_addressable_ids_logical_shared_cache_bit_8;
            if (leaf4.eax_bit(23u)) result |= max_num_of_addressable_ids_logical_shared_cache_bit_9;
            if (leaf4.eax_bit(24u)) result |= max_num_of_addressable_ids_logical_shared_cache_bit_10;
            if (leaf4.eax_bit(25u)) result |= max_num_of_addressable_ids_logical_shared_cache_bit_11;
            if (leaf4.eax_bit(26u)) result |= max_num_of_addressable_ids_cores_phys_package_bit_0;
            if (leaf4.eax_bit(27u)) result |= max_num_of_addressable_ids_cores_phys_package_bit_1;
            if (leaf4.eax_bit(28u)) result |= max_num_of_addressable_ids_cores_phys_package_bit_2;
            if (leaf4.eax_bit(29u)) result |= max_num_of_addressable_ids_cores_phys_package_bit_3;
            if (leaf4.eax_bit(30u)) result |= max_num_of_addressable_ids_cores_phys_package_bit_4;
            if (leaf4.eax_bit(31u)) result |= max_num_of_addressable_ids_cores_phys_package_bit_5;
        }

        return result;
    }
} // namespace based::platform::x86::detail

