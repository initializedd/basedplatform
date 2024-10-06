#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// XSAVE features
// https://en.wikipedia.org/wiki/CPUID#EAX=0Dh:_XSAVE_features_and_state-components

namespace based::platform::x86::detail {
    enum class cpu_distinct_max_xsave_save_area : std::uint8_t {
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
    }; // enum class cpu_distinct_max_xsave_save_area : std::uint8_t

    enum class cpu_distinct_max_xsave_save_area_mask : std::uint32_t {
        size = 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_0)
             | 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_1)
             | 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_2)
             | 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_3)
             | 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_4)
             | 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_5)
             | 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_6)
             | 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_7)
             | 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_8)
             | 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_9)
             | 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_10)
             | 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_11)
             | 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_12)
             | 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_13)
             | 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_14)
             | 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_15)
             | 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_16)
             | 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_17)
             | 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_18)
             | 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_19)
             | 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_20)
             | 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_21)
             | 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_22)
             | 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_23)
             | 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_24)
             | 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_25)
             | 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_26)
             | 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_27)
             | 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_28)
             | 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_29)
             | 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_30)
             | 1u << std::to_underlying(cpu_distinct_max_xsave_save_area::size_bit_31)
    }; // enum class cpu_distinct_max_xsave_save_area_mask : std::uint32_t

    [[nodiscard]]
    cpu_distinct_max_xsave_save_area_mask supported_cpu_distinct_max_save_save_area(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_distinct_max_xsave_save_area_mask{};

        if (max_leaf >= 0x0D) {
            using cpu_distinct_max_xsave_save_area;
            const auto leaf13 = cpu_id(0x0D, 0u);

            // ebx register
            if (leaf13.ebx_bit( 0u)) result |= size_bit_0;
            if (leaf13.ebx_bit( 1u)) result |= size_bit_1;
            if (leaf13.ebx_bit( 2u)) result |= size_bit_2;
            if (leaf13.ebx_bit( 3u)) result |= size_bit_3;
            if (leaf13.ebx_bit( 4u)) result |= size_bit_4;
            if (leaf13.ebx_bit( 5u)) result |= size_bit_5;
            if (leaf13.ebx_bit( 6u)) result |= size_bit_6;
            if (leaf13.ebx_bit( 7u)) result |= size_bit_7;
            if (leaf13.ebx_bit( 8u)) result |= size_bit_8;
            if (leaf13.ebx_bit( 9u)) result |= size_bit_9;
            if (leaf13.ebx_bit(10u)) result |= size_bit_10;
            if (leaf13.ebx_bit(11u)) result |= size_bit_11;
            if (leaf13.ebx_bit(12u)) result |= size_bit_12;
            if (leaf13.ebx_bit(13u)) result |= size_bit_13;
            if (leaf13.ebx_bit(14u)) result |= size_bit_14;
            if (leaf13.ebx_bit(15u)) result |= size_bit_15;
            if (leaf13.ebx_bit(16u)) result |= size_bit_16;
            if (leaf13.ebx_bit(17u)) result |= size_bit_17;
            if (leaf13.ebx_bit(18u)) result |= size_bit_18;
            if (leaf13.ebx_bit(19u)) result |= size_bit_19;
            if (leaf13.ebx_bit(20u)) result |= size_bit_20;
            if (leaf13.ebx_bit(21u)) result |= size_bit_21;
            if (leaf13.ebx_bit(22u)) result |= size_bit_22;
            if (leaf13.ebx_bit(23u)) result |= size_bit_23;
            if (leaf13.ebx_bit(24u)) result |= size_bit_24;
            if (leaf13.ebx_bit(25u)) result |= size_bit_25;
            if (leaf13.ebx_bit(26u)) result |= size_bit_26;
            if (leaf13.ebx_bit(27u)) result |= size_bit_27;
            if (leaf13.ebx_bit(28u)) result |= size_bit_28;
            if (leaf13.ebx_bit(29u)) result |= size_bit_29;
            if (leaf13.ebx_bit(30u)) result |= size_bit_30;
            if (leaf13.ebx_bit(31u)) result |= size_bit_31;
        }

        return result;
    }

    enum class cpu_simultaneous_max_xsave_save_area : std::uint8_t {
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
    }; // enum class cpu_simultaneous_max_xsave_save_area : std::uint8_t

    enum class cpu_simultaneous_max_xsave_save_area_mask : std::uint32_t {
        size = 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_0)
             | 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_1)
             | 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_2)
             | 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_3)
             | 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_4)
             | 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_5)
             | 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_6)
             | 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_7)
             | 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_8)
             | 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_9)
             | 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_10)
             | 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_11)
             | 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_12)
             | 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_13)
             | 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_14)
             | 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_15)
             | 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_16)
             | 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_17)
             | 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_18)
             | 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_19)
             | 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_20)
             | 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_21)
             | 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_22)
             | 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_23)
             | 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_24)
             | 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_25)
             | 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_26)
             | 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_27)
             | 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_28)
             | 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_29)
             | 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_30)
             | 1u << std::to_underlying(cpu_simultaneous_max_xsave_save_area::size_bit_31)
    }; // enum class cpu_simultaneous_max_xsave_save_area_mask : std::uint32_t

    [[nodiscard]]
    cpu_simultaneous_max_xsave_save_area_mask supported_cpu_simultaneous_max_save_save_area(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_simultaneous_max_xsave_save_area_mask{};

        if (max_leaf >= 0x0D) {
            using cpu_simultaneous_max_xsave_save_area;
            const auto leaf13 = cpu_id(0x0D, 0u);

            // ecx register
            if (leaf13.ebx_bit( 0u)) result |= size_bit_0;
            if (leaf13.ebx_bit( 1u)) result |= size_bit_1;
            if (leaf13.ebx_bit( 2u)) result |= size_bit_2;
            if (leaf13.ebx_bit( 3u)) result |= size_bit_3;
            if (leaf13.ebx_bit( 4u)) result |= size_bit_4;
            if (leaf13.ebx_bit( 5u)) result |= size_bit_5;
            if (leaf13.ebx_bit( 6u)) result |= size_bit_6;
            if (leaf13.ebx_bit( 7u)) result |= size_bit_7;
            if (leaf13.ebx_bit( 8u)) result |= size_bit_8;
            if (leaf13.ebx_bit( 9u)) result |= size_bit_9;
            if (leaf13.ebx_bit(10u)) result |= size_bit_10;
            if (leaf13.ebx_bit(11u)) result |= size_bit_11;
            if (leaf13.ebx_bit(12u)) result |= size_bit_12;
            if (leaf13.ebx_bit(13u)) result |= size_bit_13;
            if (leaf13.ebx_bit(14u)) result |= size_bit_14;
            if (leaf13.ebx_bit(15u)) result |= size_bit_15;
            if (leaf13.ebx_bit(16u)) result |= size_bit_16;
            if (leaf13.ebx_bit(17u)) result |= size_bit_17;
            if (leaf13.ebx_bit(18u)) result |= size_bit_18;
            if (leaf13.ebx_bit(19u)) result |= size_bit_19;
            if (leaf13.ebx_bit(20u)) result |= size_bit_20;
            if (leaf13.ebx_bit(21u)) result |= size_bit_21;
            if (leaf13.ebx_bit(22u)) result |= size_bit_22;
            if (leaf13.ebx_bit(23u)) result |= size_bit_23;
            if (leaf13.ebx_bit(24u)) result |= size_bit_24;
            if (leaf13.ebx_bit(25u)) result |= size_bit_25;
            if (leaf13.ebx_bit(26u)) result |= size_bit_26;
            if (leaf13.ebx_bit(27u)) result |= size_bit_27;
            if (leaf13.ebx_bit(28u)) result |= size_bit_28;
            if (leaf13.ebx_bit(29u)) result |= size_bit_29;
            if (leaf13.ebx_bit(30u)) result |= size_bit_30;
            if (leaf13.ebx_bit(31u)) result |= size_bit_31;
        }

        return result;
    }

    enum class cpu_state_component : std::uint16_t {
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
        size_bit_31,
        size_bit_32,
        size_bit_33,
        size_bit_34,
        size_bit_35,
        size_bit_36,
        size_bit_37,
        size_bit_38,
        size_bit_39,
        size_bit_40,
        size_bit_41,
        size_bit_42,
        size_bit_43,
        size_bit_44,
        size_bit_45,
        size_bit_46,
        size_bit_47,
        size_bit_48,
        size_bit_49,
        size_bit_50,
        size_bit_51,
        size_bit_52,
        size_bit_53,
        size_bit_54,
        size_bit_55,
        size_bit_56,
        size_bit_57,
        size_bit_58,
        size_bit_59,
        size_bit_60,
        size_bit_61,
        size_bit_62,
        size_bit_63
    }; // enum class cpu_state_component : std::uint16_t

    enum class cpu_state_component_mask : std::uint64_t {
        size = 1u << std::to_underlying(cpu_state_component::size_bit_0)
             | 1u << std::to_underlying(cpu_state_component::size_bit_1)
             | 1u << std::to_underlying(cpu_state_component::size_bit_2)
             | 1u << std::to_underlying(cpu_state_component::size_bit_3)
             | 1u << std::to_underlying(cpu_state_component::size_bit_4)
             | 1u << std::to_underlying(cpu_state_component::size_bit_5)
             | 1u << std::to_underlying(cpu_state_component::size_bit_6)
             | 1u << std::to_underlying(cpu_state_component::size_bit_7)
             | 1u << std::to_underlying(cpu_state_component::size_bit_8)
             | 1u << std::to_underlying(cpu_state_component::size_bit_9)
             | 1u << std::to_underlying(cpu_state_component::size_bit_10)
             | 1u << std::to_underlying(cpu_state_component::size_bit_11)
             | 1u << std::to_underlying(cpu_state_component::size_bit_12)
             | 1u << std::to_underlying(cpu_state_component::size_bit_13)
             | 1u << std::to_underlying(cpu_state_component::size_bit_14)
             | 1u << std::to_underlying(cpu_state_component::size_bit_15)
             | 1u << std::to_underlying(cpu_state_component::size_bit_16)
             | 1u << std::to_underlying(cpu_state_component::size_bit_17)
             | 1u << std::to_underlying(cpu_state_component::size_bit_18)
             | 1u << std::to_underlying(cpu_state_component::size_bit_19)
             | 1u << std::to_underlying(cpu_state_component::size_bit_20)
             | 1u << std::to_underlying(cpu_state_component::size_bit_21)
             | 1u << std::to_underlying(cpu_state_component::size_bit_22)
             | 1u << std::to_underlying(cpu_state_component::size_bit_23)
             | 1u << std::to_underlying(cpu_state_component::size_bit_24)
             | 1u << std::to_underlying(cpu_state_component::size_bit_25)
             | 1u << std::to_underlying(cpu_state_component::size_bit_26)
             | 1u << std::to_underlying(cpu_state_component::size_bit_27)
             | 1u << std::to_underlying(cpu_state_component::size_bit_28)
             | 1u << std::to_underlying(cpu_state_component::size_bit_29)
             | 1u << std::to_underlying(cpu_state_component::size_bit_30)
             | 1u << std::to_underlying(cpu_state_component::size_bit_31)
             | 1u << std::to_underlying(cpu_state_component::size_bit_32)
             | 1u << std::to_underlying(cpu_state_component::size_bit_33)
             | 1u << std::to_underlying(cpu_state_component::size_bit_34)
             | 1u << std::to_underlying(cpu_state_component::size_bit_35)
             | 1u << std::to_underlying(cpu_state_component::size_bit_36)
             | 1u << std::to_underlying(cpu_state_component::size_bit_37)
             | 1u << std::to_underlying(cpu_state_component::size_bit_38)
             | 1u << std::to_underlying(cpu_state_component::size_bit_39)
             | 1u << std::to_underlying(cpu_state_component::size_bit_40)
             | 1u << std::to_underlying(cpu_state_component::size_bit_41)
             | 1u << std::to_underlying(cpu_state_component::size_bit_42)
             | 1u << std::to_underlying(cpu_state_component::size_bit_43)
             | 1u << std::to_underlying(cpu_state_component::size_bit_44)
             | 1u << std::to_underlying(cpu_state_component::size_bit_45)
             | 1u << std::to_underlying(cpu_state_component::size_bit_46)
             | 1u << std::to_underlying(cpu_state_component::size_bit_47)
             | 1u << std::to_underlying(cpu_state_component::size_bit_48)
             | 1u << std::to_underlying(cpu_state_component::size_bit_49)
             | 1u << std::to_underlying(cpu_state_component::size_bit_50)
             | 1u << std::to_underlying(cpu_state_component::size_bit_51)
             | 1u << std::to_underlying(cpu_state_component::size_bit_52)
             | 1u << std::to_underlying(cpu_state_component::size_bit_53)
             | 1u << std::to_underlying(cpu_state_component::size_bit_54)
             | 1u << std::to_underlying(cpu_state_component::size_bit_55)
             | 1u << std::to_underlying(cpu_state_component::size_bit_56)
             | 1u << std::to_underlying(cpu_state_component::size_bit_57)
             | 1u << std::to_underlying(cpu_state_component::size_bit_58)
             | 1u << std::to_underlying(cpu_state_component::size_bit_59)
             | 1u << std::to_underlying(cpu_state_component::size_bit_60)
             | 1u << std::to_underlying(cpu_state_component::size_bit_61)
             | 1u << std::to_underlying(cpu_state_component::size_bit_62)
             | 1u << std::to_underlying(cpu_state_component::size_bit_63)
    }; // enum class cpu_state_component_mask : std::uint64_t

    [[nodiscard]]
    cpu_state_component_mask supported_cpu_state_components(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_state_component_mask{};

        if (max_leaf >= 0x0D) {
            using cpu_state_component_mask;
            const auto leaf13 = cpu_id(0x0D, 0u);

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

            // edx register
            if (leaf13.edx_bit( 0u)) result |= size_bit_32;
            if (leaf13.edx_bit( 1u)) result |= size_bit_33;
            if (leaf13.edx_bit( 2u)) result |= size_bit_34;
            if (leaf13.edx_bit( 3u)) result |= size_bit_35;
            if (leaf13.edx_bit( 4u)) result |= size_bit_36;
            if (leaf13.edx_bit( 5u)) result |= size_bit_37;
            if (leaf13.edx_bit( 6u)) result |= size_bit_38;
            if (leaf13.edx_bit( 7u)) result |= size_bit_39;
            if (leaf13.edx_bit( 8u)) result |= size_bit_40;
            if (leaf13.edx_bit( 9u)) result |= size_bit_41;
            if (leaf13.edx_bit(10u)) result |= size_bit_42;
            if (leaf13.edx_bit(11u)) result |= size_bit_43;
            if (leaf13.edx_bit(12u)) result |= size_bit_44;
            if (leaf13.edx_bit(13u)) result |= size_bit_45;
            if (leaf13.edx_bit(14u)) result |= size_bit_46;
            if (leaf13.edx_bit(15u)) result |= size_bit_47;
            if (leaf13.edx_bit(16u)) result |= size_bit_48;
            if (leaf13.edx_bit(17u)) result |= size_bit_49;
            if (leaf13.edx_bit(18u)) result |= size_bit_50;
            if (leaf13.edx_bit(19u)) result |= size_bit_51;
            if (leaf13.edx_bit(20u)) result |= size_bit_52;
            if (leaf13.edx_bit(21u)) result |= size_bit_53;
            if (leaf13.edx_bit(22u)) result |= size_bit_54;
            if (leaf13.edx_bit(23u)) result |= size_bit_55;
            if (leaf13.edx_bit(24u)) result |= size_bit_56;
            if (leaf13.edx_bit(25u)) result |= size_bit_57;
            if (leaf13.edx_bit(26u)) result |= size_bit_58;
            if (leaf13.edx_bit(27u)) result |= size_bit_59;
            if (leaf13.edx_bit(28u)) result |= size_bit_60;
            if (leaf13.edx_bit(29u)) result |= size_bit_61;
            if (leaf13.edx_bit(30u)) result |= size_bit_62;
            if (leaf13.edx_bit(31u)) result |= size_bit_63;
        }

        return result;
    }
} // namespace based::platform::x86::detail

