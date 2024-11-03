#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// Encrypted Memory Capabilities Info
// https://en.wikipedia.org/wiki/CPUID#EAX=8000001Fh:_Encrypted_Memory_Capabilities

namespace based::platform::x86::detail {
    enum class cpu_encrypted_memory_info : std::uint8_t {
        c_bit_location_bit_0,
        c_bit_location_bit_1,
        c_bit_location_bit_2,
        c_bit_location_bit_3,
        c_bit_location_bit_4,
        c_bit_location_bit_5,
        physical_address_width_reduction_bit_0,
        physical_address_width_reduction_bit_1,
        physical_address_width_reduction_bit_2,
        physical_address_width_reduction_bit_3,
        physical_address_width_reduction_bit_4,
        physical_address_width_reduction_bit_5,
        num_of_vmpls_bit_0,
        num_of_vmpls_bit_1,
        num_of_vmpls_bit_2,
        num_of_vmpls_bit_3
        // bits 31:16 reserved
    }; // enum class cpu_encrypted_memory_info : std::uint8_t

    enum class cpu_encrypted_memory_info_mask : std::uint32_t {
        c_bit_location                   = 1u << std::to_underlying(cpu_encrypted_memory_info::c_bit_location_bit_0)
                                         | 1u << std::to_underlying(cpu_encrypted_memory_info::c_bit_location_bit_1)
                                         | 1u << std::to_underlying(cpu_encrypted_memory_info::c_bit_location_bit_2)
                                         | 1u << std::to_underlying(cpu_encrypted_memory_info::c_bit_location_bit_3)
                                         | 1u << std::to_underlying(cpu_encrypted_memory_info::c_bit_location_bit_4)
                                         | 1u << std::to_underlying(cpu_encrypted_memory_info::c_bit_location_bit_5),
        physical_address_width_reduction = 1u << std::to_underlying(cpu_encrypted_memory_info::physical_address_width_reduction_bit_0)
                                         | 1u << std::to_underlying(cpu_encrypted_memory_info::physical_address_width_reduction_bit_1)
                                         | 1u << std::to_underlying(cpu_encrypted_memory_info::physical_address_width_reduction_bit_2)
                                         | 1u << std::to_underlying(cpu_encrypted_memory_info::physical_address_width_reduction_bit_3)
                                         | 1u << std::to_underlying(cpu_encrypted_memory_info::physical_address_width_reduction_bit_4)
                                         | 1u << std::to_underlying(cpu_encrypted_memory_info::physical_address_width_reduction_bit_5),
        num_of_vmpls                     = 1u << std::to_underlying(cpu_encrypted_memory_info::num_of_vmpls_bit_0)
                                         | 1u << std::to_underlying(cpu_encrypted_memory_info::num_of_vmpls_bit_1)
                                         | 1u << std::to_underlying(cpu_encrypted_memory_info::num_of_vmpls_bit_2)
                                         | 1u << std::to_underlying(cpu_encrypted_memory_info::num_of_vmpls_bit_3)
    }; // enum class cpu_encrypted_memory_info_mask : std::uint32_t

    [[nodiscard]]
    cpu_encrypted_memory_info_mask supported_cpu_encrypted_memory_info(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_encrypted_memory_info_mask{};

        if (max_leaf >= 0x8000001F) {
            using enum cpu_encrypted_memory_info;
            const auto leaf_0x8000001f = cpu_id(0x8000001F, 0x00);

            // ebx register
            if (leaf_0x8000001f.ebx_bit( 0u)) result |= c_bit_location_bit_0;
            if (leaf_0x8000001f.ebx_bit( 1u)) result |= c_bit_location_bit_1;
            if (leaf_0x8000001f.ebx_bit( 2u)) result |= c_bit_location_bit_2;
            if (leaf_0x8000001f.ebx_bit( 3u)) result |= c_bit_location_bit_3;
            if (leaf_0x8000001f.ebx_bit( 4u)) result |= c_bit_location_bit_4;
            if (leaf_0x8000001f.ebx_bit( 5u)) result |= c_bit_location_bit_5;
            if (leaf_0x8000001f.ebx_bit( 6u)) result |= physical_address_width_reduction_bit_0;
            if (leaf_0x8000001f.ebx_bit( 7u)) result |= physical_address_width_reduction_bit_1;
            if (leaf_0x8000001f.ebx_bit( 8u)) result |= physical_address_width_reduction_bit_2;
            if (leaf_0x8000001f.ebx_bit( 9u)) result |= physical_address_width_reduction_bit_3;
            if (leaf_0x8000001f.ebx_bit(10u)) result |= physical_address_width_reduction_bit_4;
            if (leaf_0x8000001f.ebx_bit(11u)) result |= physical_address_width_reduction_bit_5;
            if (leaf_0x8000001f.ebx_bit(12u)) result |= num_of_vmpls_bit_0;
            if (leaf_0x8000001f.ebx_bit(13u)) result |= num_of_vmpls_bit_1;
            if (leaf_0x8000001f.ebx_bit(14u)) result |= num_of_vmpls_bit_2;
            if (leaf_0x8000001f.ebx_bit(15u)) result |= num_of_vmpls_bit_3;
        }

        return result;
    }
} // namespace based::platform::x86::detail

