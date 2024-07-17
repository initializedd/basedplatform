#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// Microcode Info
// https://en.wikipedia.org/wiki/CPUID#EAX=80000021h:_Extended_Feature_Identification_2

namespace based::platform::x86::detail {
    enum class cpu_microcode_info : std::uint8_t {
        microcode_patch_size_bit_0,
        microcode_patch_size_bit_1,
        microcode_patch_size_bit_2,
        microcode_patch_size_bit_3,
        microcode_patch_size_bit_4,
        microcode_patch_size_bit_5,
        microcode_patch_size_bit_6,
        microcode_patch_size_bit_7,
        microcode_patch_size_bit_8,
        microcode_patch_size_bit_9,
        microcode_patch_size_bit_10,
        microcode_patch_size_bit_11
        // bits 31:12 reserved
    }; // enum class cpu_microcode_info : std::uint8_t

    enum class cpu_microcode_info_mask : std::uint32_t {
        microcode_patch_size = 1u << std::to_underlying(cpu_microcode_info::microcode_patch_size_bit_0)
                             | 1u << std::to_underlying(cpu_microcode_info::microcode_patch_size_bit_1)
                             | 1u << std::to_underlying(cpu_microcode_info::microcode_patch_size_bit_2)
                             | 1u << std::to_underlying(cpu_microcode_info::microcode_patch_size_bit_3)
                             | 1u << std::to_underlying(cpu_microcode_info::microcode_patch_size_bit_4)
                             | 1u << std::to_underlying(cpu_microcode_info::microcode_patch_size_bit_5)
                             | 1u << std::to_underlying(cpu_microcode_info::microcode_patch_size_bit_6)
                             | 1u << std::to_underlying(cpu_microcode_info::microcode_patch_size_bit_7)
                             | 1u << std::to_underlying(cpu_microcode_info::microcode_patch_size_bit_8)
                             | 1u << std::to_underlying(cpu_microcode_info::microcode_patch_size_bit_9)
                             | 1u << std::to_underlying(cpu_microcode_info::microcode_patch_size_bit_10)
                             | 1u << std::to_underlying(cpu_microcode_info::microcode_patch_size_bit_11)
    }; // enum class cpu_microcode_info_mask : std::uint32_t

    [[nodiscard]]
    cpu_microcode_info_mask supported_cpu_microcode_info(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_microcode_info_mask{};

        if (max_leaf >= 0x80000021) {
            using enum cpu_microcode_info;
            const auto leaf8 = cpu_id(0x80000021, 0x00);

            // ebx register
            if (leaf8.ebx_bit( 0u)) result |= microcode_patch_size_bit_0;
            if (leaf8.ebx_bit( 1u)) result |= microcode_patch_size_bit_1;
            if (leaf8.ebx_bit( 2u)) result |= microcode_patch_size_bit_2;
            if (leaf8.ebx_bit( 3u)) result |= microcode_patch_size_bit_3;
            if (leaf8.ebx_bit( 4u)) result |= microcode_patch_size_bit_4;
            if (leaf8.ebx_bit( 5u)) result |= microcode_patch_size_bit_5;
            if (leaf8.ebx_bit( 6u)) result |= microcode_patch_size_bit_6;
            if (leaf8.ebx_bit( 7u)) result |= microcode_patch_size_bit_7;
            if (leaf8.ebx_bit( 8u)) result |= microcode_patch_size_bit_8;
            if (leaf8.ebx_bit( 9u)) result |= microcode_patch_size_bit_9;
            if (leaf8.ebx_bit(10u)) result |= microcode_patch_size_bit_10;
            if (leaf8.ebx_bit(11u)) result |= microcode_patch_size_bit_11;
        }

        return result;
    }
} // namespace based::platform::x86::detail

