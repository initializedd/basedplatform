#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"
#include "../../util.hpp"

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
        microcode_patch_size_bit_11,
        microcode_patch_size_bit_12,
        microcode_patch_size_bit_13,
        microcode_patch_size_bit_14,
        microcode_patch_size_bit_15,
        rap_size_bit_0,
        rap_size_bit_1,
        rap_size_bit_2,
        rap_size_bit_3,
        rap_size_bit_4,
        rap_size_bit_5,
        rap_size_bit_6,
        rap_size_bit_7,
        // bits 31:24 reserved
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
                             | 1u << std::to_underlying(cpu_microcode_info::microcode_patch_size_bit_12)
                             | 1u << std::to_underlying(cpu_microcode_info::microcode_patch_size_bit_13)
                             | 1u << std::to_underlying(cpu_microcode_info::microcode_patch_size_bit_14)
                             | 1u << std::to_underlying(cpu_microcode_info::microcode_patch_size_bit_15),
        rap_size             = 1u << std::to_underlying(cpu_microcode_info::rap_size_bit_0)
                             | 1u << std::to_underlying(cpu_microcode_info::rap_size_bit_1)
                             | 1u << std::to_underlying(cpu_microcode_info::rap_size_bit_2)
                             | 1u << std::to_underlying(cpu_microcode_info::rap_size_bit_3)
                             | 1u << std::to_underlying(cpu_microcode_info::rap_size_bit_4)
                             | 1u << std::to_underlying(cpu_microcode_info::rap_size_bit_5)
                             | 1u << std::to_underlying(cpu_microcode_info::rap_size_bit_6)
                             | 1u << std::to_underlying(cpu_microcode_info::rap_size_bit_7)
    }; // enum class cpu_microcode_info_mask : std::uint32_t

    [[nodiscard]]
    inline cpu_microcode_info_mask supported_cpu_microcode_info(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_microcode_info_mask{};

        if (max_leaf >= 0x80000021) {
            using enum cpu_microcode_info;
            const auto leaf_0x80000021 = cpu_id(0x80000021, 0x00);

            // ebx register
            if (leaf_0x80000021.ebx_bit( 0u)) result |= microcode_patch_size_bit_0;
            if (leaf_0x80000021.ebx_bit( 1u)) result |= microcode_patch_size_bit_1;
            if (leaf_0x80000021.ebx_bit( 2u)) result |= microcode_patch_size_bit_2;
            if (leaf_0x80000021.ebx_bit( 3u)) result |= microcode_patch_size_bit_3;
            if (leaf_0x80000021.ebx_bit( 4u)) result |= microcode_patch_size_bit_4;
            if (leaf_0x80000021.ebx_bit( 5u)) result |= microcode_patch_size_bit_5;
            if (leaf_0x80000021.ebx_bit( 6u)) result |= microcode_patch_size_bit_6;
            if (leaf_0x80000021.ebx_bit( 7u)) result |= microcode_patch_size_bit_7;
            if (leaf_0x80000021.ebx_bit( 8u)) result |= microcode_patch_size_bit_8;
            if (leaf_0x80000021.ebx_bit( 9u)) result |= microcode_patch_size_bit_9;
            if (leaf_0x80000021.ebx_bit(10u)) result |= microcode_patch_size_bit_10;
            if (leaf_0x80000021.ebx_bit(11u)) result |= microcode_patch_size_bit_11;
            if (leaf_0x80000021.ebx_bit(12u)) result |= microcode_patch_size_bit_12;
            if (leaf_0x80000021.ebx_bit(13u)) result |= microcode_patch_size_bit_13;
            if (leaf_0x80000021.ebx_bit(14u)) result |= microcode_patch_size_bit_14;
            if (leaf_0x80000021.ebx_bit(15u)) result |= microcode_patch_size_bit_15;
            if (leaf_0x80000021.ebx_bit(16u)) result |= rap_size_bit_0;
            if (leaf_0x80000021.ebx_bit(17u)) result |= rap_size_bit_1;
            if (leaf_0x80000021.ebx_bit(18u)) result |= rap_size_bit_2;
            if (leaf_0x80000021.ebx_bit(19u)) result |= rap_size_bit_3;
            if (leaf_0x80000021.ebx_bit(20u)) result |= rap_size_bit_4;
            if (leaf_0x80000021.ebx_bit(21u)) result |= rap_size_bit_5;
            if (leaf_0x80000021.ebx_bit(22u)) result |= rap_size_bit_6;
            if (leaf_0x80000021.ebx_bit(23u)) result |= rap_size_bit_7;
        }

        return result;
    }
} // namespace based::platform::x86::detail

