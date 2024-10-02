#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// XSAVE features and state-components
// https://en.wikipedia.org/wiki/CPUID#EAX=0Dh:_XSAVE_features_and_state-components

namespace based::platform::x86::detail {
    enum class cpu_state_component_size : std::uint8_t {
         size_bit_0,
         size_bit_1,
         size_bit_2,
         size_bit_3,
         size_bit_4,
         size_bit_5,
         size_bit_6,
         size_bit_7,
         size_bit_8,
         size_bit_9,
         size_bit_10,
         size_bit_11,
         size_bit_12,
         size_bit_13,
         size_bit_14,
         size_bit_15,
         size_bit_16,
         size_bit_17,
         size_bit_18,
         size_bit_19,
         size_bit_20,
         size_bit_21,
         size_bit_22,
         size_bit_23,
         size_bit_24,
         size_bit_25,
         size_bit_26,
         size_bit_27,
         size_bit_28,
         size_bit_29,
         size_bit_30,
         size_bit_31
    }; // enum class cpu_state_component_size : std::uint8_t

    enum class cpu_state_component_size_mask : std::uint32_t {
        size = 1u << std::to_underlying(cpu_state_component_size::size_bit_0)
             | 1u << std::to_underlying(cpu_state_component_size::size_bit_1)
             | 1u << std::to_underlying(cpu_state_component_size::size_bit_2)
             | 1u << std::to_underlying(cpu_state_component_size::size_bit_3)
             | 1u << std::to_underlying(cpu_state_component_size::size_bit_4)
             | 1u << std::to_underlying(cpu_state_component_size::size_bit_5)
             | 1u << std::to_underlying(cpu_state_component_size::size_bit_6)
             | 1u << std::to_underlying(cpu_state_component_size::size_bit_7)
             | 1u << std::to_underlying(cpu_state_component_size::size_bit_8)
             | 1u << std::to_underlying(cpu_state_component_size::size_bit_9)
             | 1u << std::to_underlying(cpu_state_component_size::size_bit_10)
             | 1u << std::to_underlying(cpu_state_component_size::size_bit_11)
             | 1u << std::to_underlying(cpu_state_component_size::size_bit_12)
             | 1u << std::to_underlying(cpu_state_component_size::size_bit_13)
             | 1u << std::to_underlying(cpu_state_component_size::size_bit_14)
             | 1u << std::to_underlying(cpu_state_component_size::size_bit_15)
             | 1u << std::to_underlying(cpu_state_component_size::size_bit_16)
             | 1u << std::to_underlying(cpu_state_component_size::size_bit_17)
             | 1u << std::to_underlying(cpu_state_component_size::size_bit_18)
             | 1u << std::to_underlying(cpu_state_component_size::size_bit_19)
             | 1u << std::to_underlying(cpu_state_component_size::size_bit_20)
             | 1u << std::to_underlying(cpu_state_component_size::size_bit_21)
             | 1u << std::to_underlying(cpu_state_component_size::size_bit_22)
             | 1u << std::to_underlying(cpu_state_component_size::size_bit_23)
             | 1u << std::to_underlying(cpu_state_component_size::size_bit_24)
             | 1u << std::to_underlying(cpu_state_component_size::size_bit_25)
             | 1u << std::to_underlying(cpu_state_component_size::size_bit_26)
             | 1u << std::to_underlying(cpu_state_component_size::size_bit_27)
             | 1u << std::to_underlying(cpu_state_component_size::size_bit_28)
             | 1u << std::to_underlying(cpu_state_component_size::size_bit_29)
             | 1u << std::to_underlying(cpu_state_component_size::size_bit_30)
             | 1u << std::to_underlying(cpu_state_component_size::size_bit_31)
    }; // enum class cpu_state_component_size_mask : std::uint32_t

    [[nodiscard]]
    cpu_state_component_size_mask supported_cpu_state_component_size(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_state_component_size_mask{};

        if (max_leaf >= 0x0D) {
            using cpu_state_component_size;
            const auto leaf13 = cpu_id(0x0D, 2u);

            // eax register
            if (leaf13.eax_bit( 0u)) result |= size_bit_0;
            if (leaf13.eax_bit( 1u)) result |= size_bit_1;
            if (leaf13.eax_bit( 2u)) result |= size_bit_2;
            if (leaf13.eax_bit( 3u)) result |= size_bit_3;
            if (leaf13.eax_bit( 4u)) result |= size_bit_4;
            if (leaf13.eax_bit( 5u)) result |= size_bit_5;
            if (leaf13.eax_bit( 6u)) result |= size_bit_6;
            if (leaf13.eax_bit( 7u)) result |= size_bit_7;
            if (leaf13.eax_bit( 8u)) result |= size_bit_8;
            if (leaf13.eax_bit( 9u)) result |= size_bit_9;
            if (leaf13.eax_bit(10u)) result |= size_bit_10;
            if (leaf13.eax_bit(11u)) result |= size_bit_11;
            if (leaf13.eax_bit(12u)) result |= size_bit_12;
            if (leaf13.eax_bit(13u)) result |= size_bit_13;
            if (leaf13.eax_bit(14u)) result |= size_bit_14;
            if (leaf13.eax_bit(15u)) result |= size_bit_15;
            if (leaf13.eax_bit(16u)) result |= size_bit_16;
            if (leaf13.eax_bit(17u)) result |= size_bit_17;
            if (leaf13.eax_bit(18u)) result |= size_bit_18;
            if (leaf13.eax_bit(19u)) result |= size_bit_19;
            if (leaf13.eax_bit(20u)) result |= size_bit_20;
            if (leaf13.eax_bit(21u)) result |= size_bit_21;
            if (leaf13.eax_bit(22u)) result |= size_bit_22;
            if (leaf13.eax_bit(23u)) result |= size_bit_23;
            if (leaf13.eax_bit(24u)) result |= size_bit_24;
            if (leaf13.eax_bit(25u)) result |= size_bit_25;
            if (leaf13.eax_bit(26u)) result |= size_bit_26;
            if (leaf13.eax_bit(27u)) result |= size_bit_27;
            if (leaf13.eax_bit(28u)) result |= size_bit_28;
            if (leaf13.eax_bit(29u)) result |= size_bit_29;
            if (leaf13.eax_bit(30u)) result |= size_bit_30;
            if (leaf13.eax_bit(31u)) result |= size_bit_31;
        }

        return result;
    }

    enum class cpu_state_component_offset : std::uint8_t {
        offset_bit_0,
        offset_bit_1,
        offset_bit_2,
        offset_bit_3,
        offset_bit_4,
        offset_bit_5,
        offset_bit_6,
        offset_bit_7,
        offset_bit_8,
        offset_bit_9,
        offset_bit_10,
        offset_bit_11,
        offset_bit_12,
        offset_bit_13,
        offset_bit_14,
        offset_bit_15,
        offset_bit_16,
        offset_bit_17,
        offset_bit_18,
        offset_bit_19,
        offset_bit_20,
        offset_bit_21,
        offset_bit_22,
        offset_bit_23,
        offset_bit_24,
        offset_bit_25,
        offset_bit_26,
        offset_bit_27,
        offset_bit_28,
        offset_bit_29,
        offset_bit_30,
        offset_bit_31
    }; // enum class cpu_state_component_offset : std::uint8_t

    enum class cpu_state_component_offset_mask : std::uint32_t {
        offset = 1u << std::to_underlying(cpu_state_component_offset::offset_bit_0)
               | 1u << std::to_underlying(cpu_state_component_offset::offset_bit_1)
               | 1u << std::to_underlying(cpu_state_component_offset::offset_bit_2)
               | 1u << std::to_underlying(cpu_state_component_offset::offset_bit_3)
               | 1u << std::to_underlying(cpu_state_component_offset::offset_bit_4)
               | 1u << std::to_underlying(cpu_state_component_offset::offset_bit_5)
               | 1u << std::to_underlying(cpu_state_component_offset::offset_bit_6)
               | 1u << std::to_underlying(cpu_state_component_offset::offset_bit_7)
               | 1u << std::to_underlying(cpu_state_component_offset::offset_bit_8)
               | 1u << std::to_underlying(cpu_state_component_offset::offset_bit_9)
               | 1u << std::to_underlying(cpu_state_component_offset::offset_bit_10)
               | 1u << std::to_underlying(cpu_state_component_offset::offset_bit_11)
               | 1u << std::to_underlying(cpu_state_component_offset::offset_bit_12)
               | 1u << std::to_underlying(cpu_state_component_offset::offset_bit_13)
               | 1u << std::to_underlying(cpu_state_component_offset::offset_bit_14)
               | 1u << std::to_underlying(cpu_state_component_offset::offset_bit_15)
               | 1u << std::to_underlying(cpu_state_component_offset::offset_bit_16)
               | 1u << std::to_underlying(cpu_state_component_offset::offset_bit_17)
               | 1u << std::to_underlying(cpu_state_component_offset::offset_bit_18)
               | 1u << std::to_underlying(cpu_state_component_offset::offset_bit_19)
               | 1u << std::to_underlying(cpu_state_component_offset::offset_bit_20)
               | 1u << std::to_underlying(cpu_state_component_offset::offset_bit_21)
               | 1u << std::to_underlying(cpu_state_component_offset::offset_bit_22)
               | 1u << std::to_underlying(cpu_state_component_offset::offset_bit_23)
               | 1u << std::to_underlying(cpu_state_component_offset::offset_bit_24)
               | 1u << std::to_underlying(cpu_state_component_offset::offset_bit_25)
               | 1u << std::to_underlying(cpu_state_component_offset::offset_bit_26)
               | 1u << std::to_underlying(cpu_state_component_offset::offset_bit_27)
               | 1u << std::to_underlying(cpu_state_component_offset::offset_bit_28)
               | 1u << std::to_underlying(cpu_state_component_offset::offset_bit_29)
               | 1u << std::to_underlying(cpu_state_component_offset::offset_bit_30)
               | 1u << std::to_underlying(cpu_state_component_offset::offset_bit_31)
    }; // enum class cpu_state_component_offset_mask : std::uint32_t

    [[nodiscard]]
    cpu_state_component_offset_mask supported_cpu_state_component_offset(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_state_component_offset_mask{};

        if (max_leaf >= 0x0D) {
            using cpu_state_component_offset;
            const auto leaf13 = cpu_id(0x0D, 2u);

            // ebx register
            if (leaf13.ebx_bit( 0u)) result |= offset_bit_0;
            if (leaf13.ebx_bit( 1u)) result |= offset_bit_1;
            if (leaf13.ebx_bit( 2u)) result |= offset_bit_2;
            if (leaf13.ebx_bit( 3u)) result |= offset_bit_3;
            if (leaf13.ebx_bit( 4u)) result |= offset_bit_4;
            if (leaf13.ebx_bit( 5u)) result |= offset_bit_5;
            if (leaf13.ebx_bit( 6u)) result |= offset_bit_6;
            if (leaf13.ebx_bit( 7u)) result |= offset_bit_7;
            if (leaf13.ebx_bit( 8u)) result |= offset_bit_8;
            if (leaf13.ebx_bit( 9u)) result |= offset_bit_9;
            if (leaf13.ebx_bit(10u)) result |= offset_bit_10;
            if (leaf13.ebx_bit(11u)) result |= offset_bit_11;
            if (leaf13.ebx_bit(12u)) result |= offset_bit_12;
            if (leaf13.ebx_bit(13u)) result |= offset_bit_13;
            if (leaf13.ebx_bit(14u)) result |= offset_bit_14;
            if (leaf13.ebx_bit(15u)) result |= offset_bit_15;
            if (leaf13.ebx_bit(16u)) result |= offset_bit_16;
            if (leaf13.ebx_bit(17u)) result |= offset_bit_17;
            if (leaf13.ebx_bit(18u)) result |= offset_bit_18;
            if (leaf13.ebx_bit(19u)) result |= offset_bit_19;
            if (leaf13.ebx_bit(20u)) result |= offset_bit_20;
            if (leaf13.ebx_bit(21u)) result |= offset_bit_21;
            if (leaf13.ebx_bit(22u)) result |= offset_bit_22;
            if (leaf13.ebx_bit(23u)) result |= offset_bit_23;
            if (leaf13.ebx_bit(24u)) result |= offset_bit_24;
            if (leaf13.ebx_bit(25u)) result |= offset_bit_25;
            if (leaf13.ebx_bit(26u)) result |= offset_bit_26;
            if (leaf13.ebx_bit(27u)) result |= offset_bit_27;
            if (leaf13.ebx_bit(28u)) result |= offset_bit_28;
            if (leaf13.ebx_bit(29u)) result |= offset_bit_29;
            if (leaf13.ebx_bit(30u)) result |= offset_bit_30;
            if (leaf13.ebx_bit(31u)) result |= offset_bit_31;
        }

        return result;
    }

    enum class cpu_state_component_meta : std::uint8_t {
        user_supervisor,
        alignment_64_bytes
        // bits 31:2 reserved
    }; // enum class cpu_state_component_meta : std::uint8_t

    enum class cpu_state_component_meta_mask : std::uint32_t {
        user_supervisor    = 1u << std::to_underlying(cpu_state_component_meta::user_supervisor),
        alignment_64_bytes = 1u << std::to_underlying(cpu_state_component_meta::alignment_64_bytes)
    }; // enum class cpu_state_component_meta_mask : std::uint32_t

    [[nodiscard]]
    cpu_state_component_meta_mask supported_cpu_state_component_meta(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_state_component_meta_mask{};

        if (max_leaf >= 0x0D) {
            using cpu_state_component_meta;
            const auto leaf13 = cpu_id(0x0D, 2u);

            // ecx register
            if (leaf13.ecx_bit(0u)) result |= user_supervisor;
            if (leaf13.ecx_bit(1u)) result |= alignment_64_bytes;
        }

        return result;
    }
} // namespace based::platform::x86::detail

