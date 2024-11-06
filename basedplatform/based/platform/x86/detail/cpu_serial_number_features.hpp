#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"
#include "../../util.hpp"

// Processor Serial Number
// https://en.wikipedia.org/wiki/CPUID#EAX=3:_Processor_Serial_Number

namespace based::platform::x86::detail {
    enum class cpu_serial_number : std::uint8_t {
        serial_number_bit_0,
        serial_number_bit_1,
        serial_number_bit_2,
        serial_number_bit_3,
        serial_number_bit_4,
        serial_number_bit_5,
        serial_number_bit_6,
        serial_number_bit_7,
        serial_number_bit_8,
        serial_number_bit_9,
        serial_number_bit_10,
        serial_number_bit_11,
        serial_number_bit_12,
        serial_number_bit_13,
        serial_number_bit_14,
        serial_number_bit_15,
        serial_number_bit_16,
        serial_number_bit_17,
        serial_number_bit_18,
        serial_number_bit_19,
        serial_number_bit_20,
        serial_number_bit_21,
        serial_number_bit_22,
        serial_number_bit_23,
        serial_number_bit_24,
        serial_number_bit_25,
        serial_number_bit_26,
        serial_number_bit_27,
        serial_number_bit_28,
        serial_number_bit_29,
        serial_number_bit_30,
        serial_number_bit_31,
        serial_number_bit_32,
        serial_number_bit_33,
        serial_number_bit_34,
        serial_number_bit_35,
        serial_number_bit_36,
        serial_number_bit_37,
        serial_number_bit_38,
        serial_number_bit_39,
        serial_number_bit_40,
        serial_number_bit_41,
        serial_number_bit_42,
        serial_number_bit_43,
        serial_number_bit_44,
        serial_number_bit_45,
        serial_number_bit_46,
        serial_number_bit_47,
        serial_number_bit_48,
        serial_number_bit_49,
        serial_number_bit_50,
        serial_number_bit_51,
        serial_number_bit_52,
        serial_number_bit_53,
        serial_number_bit_54,
        serial_number_bit_55,
        serial_number_bit_56,
        serial_number_bit_57,
        serial_number_bit_58,
        serial_number_bit_59,
        serial_number_bit_60,
        serial_number_bit_61,
        serial_number_bit_62,
        serial_number_bit_63
    }; // enum class cpu_serial_number : std::uint8_t

    enum class cpu_serial_number_mask : std::uint64_t {
        serial_number = 1u << std::to_underlying(cpu_serial_number::serial_number_bit_0)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_1)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_2)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_3)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_4)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_5)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_6)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_7)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_8)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_9)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_10)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_11)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_12)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_13)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_14)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_15)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_16)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_17)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_18)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_19)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_20)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_21)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_22)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_23)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_24)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_25)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_26)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_27)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_28)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_29)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_30)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_31)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_32)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_33)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_34)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_35)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_36)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_37)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_38)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_39)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_40)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_41)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_42)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_43)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_44)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_45)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_46)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_47)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_48)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_49)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_50)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_51)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_52)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_53)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_54)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_55)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_56)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_57)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_58)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_59)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_60)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_61)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_62)
                      |= 1u << std::to_underlying(cpu_serial_number::serial_number_bit_63)
    }; // enum class cpu_serial_number_mask : std::uint64_t

    [[nodiscard]]
    inline cpu_serial_number_mask intel_pentium_3_serial_number(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_serial_number_mask{};

        if (max_leaf >= 0x03) {
            using enum cpu_serial_number;
            const auto leaf_0x03 = cpu_id(0x03, 0x00);

            // ecx regisiter
            if (leaf_0x03.ecx_bit( 0u)) result |= serial_number_bit_0;
            if (leaf_0x03.ecx_bit( 1u)) result |= serial_number_bit_1;
            if (leaf_0x03.ecx_bit( 2u)) result |= serial_number_bit_2;
            if (leaf_0x03.ecx_bit( 3u)) result |= serial_number_bit_3;
            if (leaf_0x03.ecx_bit( 4u)) result |= serial_number_bit_4;
            if (leaf_0x03.ecx_bit( 5u)) result |= serial_number_bit_5;
            if (leaf_0x03.ecx_bit( 6u)) result |= serial_number_bit_6;
            if (leaf_0x03.ecx_bit( 7u)) result |= serial_number_bit_7;
            if (leaf_0x03.ecx_bit( 8u)) result |= serial_number_bit_8;
            if (leaf_0x03.ecx_bit( 9u)) result |= serial_number_bit_9;
            if (leaf_0x03.ecx_bit(10u)) result |= serial_number_bit_10;
            if (leaf_0x03.ecx_bit(11u)) result |= serial_number_bit_11;
            if (leaf_0x03.ecx_bit(12u)) result |= serial_number_bit_12;
            if (leaf_0x03.ecx_bit(13u)) result |= serial_number_bit_13;
            if (leaf_0x03.ecx_bit(14u)) result |= serial_number_bit_14;
            if (leaf_0x03.ecx_bit(15u)) result |= serial_number_bit_15;
            if (leaf_0x03.ecx_bit(16u)) result |= serial_number_bit_16;
            if (leaf_0x03.ecx_bit(17u)) result |= serial_number_bit_17;
            if (leaf_0x03.ecx_bit(18u)) result |= serial_number_bit_18;
            if (leaf_0x03.ecx_bit(19u)) result |= serial_number_bit_19;
            if (leaf_0x03.ecx_bit(20u)) result |= serial_number_bit_20;
            if (leaf_0x03.ecx_bit(21u)) result |= serial_number_bit_21;
            if (leaf_0x03.ecx_bit(22u)) result |= serial_number_bit_22;
            if (leaf_0x03.ecx_bit(23u)) result |= serial_number_bit_23;
            if (leaf_0x03.ecx_bit(24u)) result |= serial_number_bit_24;
            if (leaf_0x03.ecx_bit(25u)) result |= serial_number_bit_25;
            if (leaf_0x03.ecx_bit(26u)) result |= serial_number_bit_26;
            if (leaf_0x03.ecx_bit(27u)) result |= serial_number_bit_27;
            if (leaf_0x03.ecx_bit(28u)) result |= serial_number_bit_28;
            if (leaf_0x03.ecx_bit(29u)) result |= serial_number_bit_29;
            if (leaf_0x03.ecx_bit(30u)) result |= serial_number_bit_30;
            if (leaf_0x03.ecx_bit(31u)) result |= serial_number_bit_31;

            // edx regisiter
            if (leaf_0x03.edx_bit( 0u)) result |= serial_number_bit_32;
            if (leaf_0x03.edx_bit( 1u)) result |= serial_number_bit_33;
            if (leaf_0x03.edx_bit( 2u)) result |= serial_number_bit_34;
            if (leaf_0x03.edx_bit( 3u)) result |= serial_number_bit_35;
            if (leaf_0x03.edx_bit( 4u)) result |= serial_number_bit_36;
            if (leaf_0x03.edx_bit( 5u)) result |= serial_number_bit_37;
            if (leaf_0x03.edx_bit( 6u)) result |= serial_number_bit_38;
            if (leaf_0x03.edx_bit( 7u)) result |= serial_number_bit_39;
            if (leaf_0x03.edx_bit( 8u)) result |= serial_number_bit_40;
            if (leaf_0x03.edx_bit( 9u)) result |= serial_number_bit_41;
            if (leaf_0x03.edx_bit(10u)) result |= serial_number_bit_42;
            if (leaf_0x03.edx_bit(11u)) result |= serial_number_bit_43;
            if (leaf_0x03.edx_bit(12u)) result |= serial_number_bit_44;
            if (leaf_0x03.edx_bit(13u)) result |= serial_number_bit_45;
            if (leaf_0x03.edx_bit(14u)) result |= serial_number_bit_46;
            if (leaf_0x03.edx_bit(15u)) result |= serial_number_bit_47;
            if (leaf_0x03.edx_bit(16u)) result |= serial_number_bit_48;
            if (leaf_0x03.edx_bit(17u)) result |= serial_number_bit_49;
            if (leaf_0x03.edx_bit(18u)) result |= serial_number_bit_50;
            if (leaf_0x03.edx_bit(19u)) result |= serial_number_bit_51;
            if (leaf_0x03.edx_bit(20u)) result |= serial_number_bit_52;
            if (leaf_0x03.edx_bit(21u)) result |= serial_number_bit_53;
            if (leaf_0x03.edx_bit(22u)) result |= serial_number_bit_54;
            if (leaf_0x03.edx_bit(23u)) result |= serial_number_bit_55;
            if (leaf_0x03.edx_bit(24u)) result |= serial_number_bit_56;
            if (leaf_0x03.edx_bit(25u)) result |= serial_number_bit_57;
            if (leaf_0x03.edx_bit(26u)) result |= serial_number_bit_58;
            if (leaf_0x03.edx_bit(27u)) result |= serial_number_bit_59;
            if (leaf_0x03.edx_bit(28u)) result |= serial_number_bit_60;
            if (leaf_0x03.edx_bit(29u)) result |= serial_number_bit_61;
            if (leaf_0x03.edx_bit(30u)) result |= serial_number_bit_62;
            if (leaf_0x03.edx_bit(31u)) result |= serial_number_bit_63;
        }

        return result;
    }

    [[nodiscard]]
    inline cpu_serial_number_mask transmeta_efficeon_serial_number(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_serial_number_mask{};

        if (max_leaf >= 0x03) {
            using enum cpu_serial_number;
            const auto leaf_0x03 = cpu_id(0x03, 0x00);

            // eax regisiter
            if (leaf_0x03.eax_bit( 0u)) result |= serial_number_bit_0;
            if (leaf_0x03.eax_bit( 1u)) result |= serial_number_bit_1;
            if (leaf_0x03.eax_bit( 2u)) result |= serial_number_bit_2;
            if (leaf_0x03.eax_bit( 3u)) result |= serial_number_bit_3;
            if (leaf_0x03.eax_bit( 4u)) result |= serial_number_bit_4;
            if (leaf_0x03.eax_bit( 5u)) result |= serial_number_bit_5;
            if (leaf_0x03.eax_bit( 6u)) result |= serial_number_bit_6;
            if (leaf_0x03.eax_bit( 7u)) result |= serial_number_bit_7;
            if (leaf_0x03.eax_bit( 8u)) result |= serial_number_bit_8;
            if (leaf_0x03.eax_bit( 9u)) result |= serial_number_bit_9;
            if (leaf_0x03.eax_bit(10u)) result |= serial_number_bit_10;
            if (leaf_0x03.eax_bit(11u)) result |= serial_number_bit_11;
            if (leaf_0x03.eax_bit(12u)) result |= serial_number_bit_12;
            if (leaf_0x03.eax_bit(13u)) result |= serial_number_bit_13;
            if (leaf_0x03.eax_bit(14u)) result |= serial_number_bit_14;
            if (leaf_0x03.eax_bit(15u)) result |= serial_number_bit_15;
            if (leaf_0x03.eax_bit(16u)) result |= serial_number_bit_16;
            if (leaf_0x03.eax_bit(17u)) result |= serial_number_bit_17;
            if (leaf_0x03.eax_bit(18u)) result |= serial_number_bit_18;
            if (leaf_0x03.eax_bit(19u)) result |= serial_number_bit_19;
            if (leaf_0x03.eax_bit(20u)) result |= serial_number_bit_20;
            if (leaf_0x03.eax_bit(21u)) result |= serial_number_bit_21;
            if (leaf_0x03.eax_bit(22u)) result |= serial_number_bit_22;
            if (leaf_0x03.eax_bit(23u)) result |= serial_number_bit_23;
            if (leaf_0x03.eax_bit(24u)) result |= serial_number_bit_24;
            if (leaf_0x03.eax_bit(25u)) result |= serial_number_bit_25;
            if (leaf_0x03.eax_bit(26u)) result |= serial_number_bit_26;
            if (leaf_0x03.eax_bit(27u)) result |= serial_number_bit_27;
            if (leaf_0x03.eax_bit(28u)) result |= serial_number_bit_28;
            if (leaf_0x03.eax_bit(29u)) result |= serial_number_bit_29;
            if (leaf_0x03.eax_bit(30u)) result |= serial_number_bit_30;
            if (leaf_0x03.eax_bit(31u)) result |= serial_number_bit_31;

            // ebx regisiter
            if (leaf_0x03.ebx_bit( 0u)) result |= serial_number_bit_32;
            if (leaf_0x03.ebx_bit( 1u)) result |= serial_number_bit_33;
            if (leaf_0x03.ebx_bit( 2u)) result |= serial_number_bit_34;
            if (leaf_0x03.ebx_bit( 3u)) result |= serial_number_bit_35;
            if (leaf_0x03.ebx_bit( 4u)) result |= serial_number_bit_36;
            if (leaf_0x03.ebx_bit( 5u)) result |= serial_number_bit_37;
            if (leaf_0x03.ebx_bit( 6u)) result |= serial_number_bit_38;
            if (leaf_0x03.ebx_bit( 7u)) result |= serial_number_bit_39;
            if (leaf_0x03.ebx_bit( 8u)) result |= serial_number_bit_40;
            if (leaf_0x03.ebx_bit( 9u)) result |= serial_number_bit_41;
            if (leaf_0x03.ebx_bit(10u)) result |= serial_number_bit_42;
            if (leaf_0x03.ebx_bit(11u)) result |= serial_number_bit_43;
            if (leaf_0x03.ebx_bit(12u)) result |= serial_number_bit_44;
            if (leaf_0x03.ebx_bit(13u)) result |= serial_number_bit_45;
            if (leaf_0x03.ebx_bit(14u)) result |= serial_number_bit_46;
            if (leaf_0x03.ebx_bit(15u)) result |= serial_number_bit_47;
            if (leaf_0x03.ebx_bit(16u)) result |= serial_number_bit_48;
            if (leaf_0x03.ebx_bit(17u)) result |= serial_number_bit_49;
            if (leaf_0x03.ebx_bit(18u)) result |= serial_number_bit_50;
            if (leaf_0x03.ebx_bit(19u)) result |= serial_number_bit_51;
            if (leaf_0x03.ebx_bit(20u)) result |= serial_number_bit_52;
            if (leaf_0x03.ebx_bit(21u)) result |= serial_number_bit_53;
            if (leaf_0x03.ebx_bit(22u)) result |= serial_number_bit_54;
            if (leaf_0x03.ebx_bit(23u)) result |= serial_number_bit_55;
            if (leaf_0x03.ebx_bit(24u)) result |= serial_number_bit_56;
            if (leaf_0x03.ebx_bit(25u)) result |= serial_number_bit_57;
            if (leaf_0x03.ebx_bit(26u)) result |= serial_number_bit_58;
            if (leaf_0x03.ebx_bit(27u)) result |= serial_number_bit_59;
            if (leaf_0x03.ebx_bit(28u)) result |= serial_number_bit_60;
            if (leaf_0x03.ebx_bit(29u)) result |= serial_number_bit_61;
            if (leaf_0x03.ebx_bit(30u)) result |= serial_number_bit_62;
            if (leaf_0x03.ebx_bit(31u)) result |= serial_number_bit_63;
        }

        return result;
    }

    [[nodiscard]]
    inline cpu_serial_number_mask transmeta_crusoe_serial_number(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_serial_number_mask{};

        if (max_leaf >= 0x03) {
            using enum cpu_serial_number;
            const auto leaf_0x03 = cpu_id(0x03, 0x00);

            // ebx regisiter
            if (leaf_0x03.ebx_bit( 0u)) result |= serial_number_bit_0;
            if (leaf_0x03.ebx_bit( 1u)) result |= serial_number_bit_1;
            if (leaf_0x03.ebx_bit( 2u)) result |= serial_number_bit_2;
            if (leaf_0x03.ebx_bit( 3u)) result |= serial_number_bit_3;
            if (leaf_0x03.ebx_bit( 4u)) result |= serial_number_bit_4;
            if (leaf_0x03.ebx_bit( 5u)) result |= serial_number_bit_5;
            if (leaf_0x03.ebx_bit( 6u)) result |= serial_number_bit_6;
            if (leaf_0x03.ebx_bit( 7u)) result |= serial_number_bit_7;
            if (leaf_0x03.ebx_bit( 8u)) result |= serial_number_bit_8;
            if (leaf_0x03.ebx_bit( 9u)) result |= serial_number_bit_9;
            if (leaf_0x03.ebx_bit(10u)) result |= serial_number_bit_10;
            if (leaf_0x03.ebx_bit(11u)) result |= serial_number_bit_11;
            if (leaf_0x03.ebx_bit(12u)) result |= serial_number_bit_12;
            if (leaf_0x03.ebx_bit(13u)) result |= serial_number_bit_13;
            if (leaf_0x03.ebx_bit(14u)) result |= serial_number_bit_14;
            if (leaf_0x03.ebx_bit(15u)) result |= serial_number_bit_15;
            if (leaf_0x03.ebx_bit(16u)) result |= serial_number_bit_16;
            if (leaf_0x03.ebx_bit(17u)) result |= serial_number_bit_17;
            if (leaf_0x03.ebx_bit(18u)) result |= serial_number_bit_18;
            if (leaf_0x03.ebx_bit(19u)) result |= serial_number_bit_19;
            if (leaf_0x03.ebx_bit(20u)) result |= serial_number_bit_20;
            if (leaf_0x03.ebx_bit(21u)) result |= serial_number_bit_21;
            if (leaf_0x03.ebx_bit(22u)) result |= serial_number_bit_22;
            if (leaf_0x03.ebx_bit(23u)) result |= serial_number_bit_23;
            if (leaf_0x03.ebx_bit(24u)) result |= serial_number_bit_24;
            if (leaf_0x03.ebx_bit(25u)) result |= serial_number_bit_25;
            if (leaf_0x03.ebx_bit(26u)) result |= serial_number_bit_26;
            if (leaf_0x03.ebx_bit(27u)) result |= serial_number_bit_27;
            if (leaf_0x03.ebx_bit(28u)) result |= serial_number_bit_28;
            if (leaf_0x03.ebx_bit(29u)) result |= serial_number_bit_29;
            if (leaf_0x03.ebx_bit(30u)) result |= serial_number_bit_30;
            if (leaf_0x03.ebx_bit(31u)) result |= serial_number_bit_31;
        }

        return result;
    }
} // namespace based::platform::x86::detail

