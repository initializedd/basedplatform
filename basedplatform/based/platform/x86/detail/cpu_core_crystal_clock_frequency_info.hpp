#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// TSC and Core Crystal frequency information
// https://en.wikipedia.org/wiki/CPUID#EAX=15h_and_EAX=16h:_CPU,_TSC,_Bus_and_Core_Crystal_Clock_frequencies

namespace based::platform::x86::detail {
    enum class cpu_tsc_to_core_crystal_clock_frequency_denominator : std::uint8_t {
        ratio_bit_0,
        ratio_bit_1,
        ratio_bit_2,
        ratio_bit_3,
        ratio_bit_4,
        ratio_bit_5,
        ratio_bit_6,
        ratio_bit_7,
        ratio_bit_8,
        ratio_bit_9,
        ratio_bit_10,
        ratio_bit_11,
        ratio_bit_12,
        ratio_bit_13,
        ratio_bit_14,
        ratio_bit_15,
        ratio_bit_16,
        ratio_bit_17,
        ratio_bit_18,
        ratio_bit_19,
        ratio_bit_20,
        ratio_bit_21,
        ratio_bit_22,
        ratio_bit_23,
        ratio_bit_24,
        ratio_bit_25,
        ratio_bit_26,
        ratio_bit_27,
        ratio_bit_28,
        ratio_bit_29,
        ratio_bit_30,
        ratio_bit_31
    }; // enum class cpu_tsc_to_core_crystal_clock_frequency_denominator : std::uint8_t

    enum class cpu_tsc_to_core_crystal_clock_frequency_denominator_mask : std::uint32_t {
        ratio = 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_0)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_1)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_2)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_3)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_4)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_5)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_6)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_7)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_8)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_9)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_10)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_11)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_12)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_13)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_14)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_15)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_16)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_17)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_18)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_19)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_20)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_21)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_22)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_23)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_24)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_25)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_26)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_27)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_28)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_29)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_30)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_denominator::ratio_bit_31)
    }; // enum class cpu_tsc_to_core_crystal_clock_frequency_denominator_mask : std::uint32_t

    [[nodiscard]]
    cpu_tsc_to_core_crystal_clock_frequency_denominator_mask supported_cpu_tsc_to_crystal_clock_frequency_denominator(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_tsc_to_core_crystal_clock_frequency_denominator_mask{};

        if (max_leaf >= 0x15) {
            using cpu_tsc_to_core_crystal_clock_frequency_denominator;
            const auto leaf15 = cpu_id(0x15, 0u);

            // eax register
            if (leaf15.eax_bit( 0u)) result |= ratio_bit_0;
            if (leaf15.eax_bit( 1u)) result |= ratio_bit_1;
            if (leaf15.eax_bit( 2u)) result |= ratio_bit_2;
            if (leaf15.eax_bit( 3u)) result |= ratio_bit_3;
            if (leaf15.eax_bit( 4u)) result |= ratio_bit_4;
            if (leaf15.eax_bit( 5u)) result |= ratio_bit_5;
            if (leaf15.eax_bit( 6u)) result |= ratio_bit_6;
            if (leaf15.eax_bit( 7u)) result |= ratio_bit_7;
            if (leaf15.eax_bit( 8u)) result |= ratio_bit_8;
            if (leaf15.eax_bit( 9u)) result |= ratio_bit_9;
            if (leaf15.eax_bit(10u)) result |= ratio_bit_10;
            if (leaf15.eax_bit(11u)) result |= ratio_bit_11;
            if (leaf15.eax_bit(12u)) result |= ratio_bit_12;
            if (leaf15.eax_bit(13u)) result |= ratio_bit_13;
            if (leaf15.eax_bit(14u)) result |= ratio_bit_14;
            if (leaf15.eax_bit(15u)) result |= ratio_bit_15;
            if (leaf15.eax_bit(16u)) result |= ratio_bit_16;
            if (leaf15.eax_bit(17u)) result |= ratio_bit_17;
            if (leaf15.eax_bit(18u)) result |= ratio_bit_18;
            if (leaf15.eax_bit(19u)) result |= ratio_bit_19;
            if (leaf15.eax_bit(20u)) result |= ratio_bit_20;
            if (leaf15.eax_bit(21u)) result |= ratio_bit_21;
            if (leaf15.eax_bit(22u)) result |= ratio_bit_22;
            if (leaf15.eax_bit(23u)) result |= ratio_bit_23;
            if (leaf15.eax_bit(24u)) result |= ratio_bit_24;
            if (leaf15.eax_bit(25u)) result |= ratio_bit_25;
            if (leaf15.eax_bit(26u)) result |= ratio_bit_26;
            if (leaf15.eax_bit(27u)) result |= ratio_bit_27;
            if (leaf15.eax_bit(28u)) result |= ratio_bit_28;
            if (leaf15.eax_bit(29u)) result |= ratio_bit_29;
            if (leaf15.eax_bit(30u)) result |= ratio_bit_30;
            if (leaf15.eax_bit(31u)) result |= ratio_bit_31;
        }

        return result;
    }

    enum class cpu_tsc_to_core_crystal_clock_frequency_numerator : std::uint8_t {
        ratio_bit_0,
        ratio_bit_1,
        ratio_bit_2,
        ratio_bit_3,
        ratio_bit_4,
        ratio_bit_5,
        ratio_bit_6,
        ratio_bit_7,
        ratio_bit_8,
        ratio_bit_9,
        ratio_bit_10,
        ratio_bit_11,
        ratio_bit_12,
        ratio_bit_13,
        ratio_bit_14,
        ratio_bit_15,
        ratio_bit_16,
        ratio_bit_17,
        ratio_bit_18,
        ratio_bit_19,
        ratio_bit_20,
        ratio_bit_21,
        ratio_bit_22,
        ratio_bit_23,
        ratio_bit_24,
        ratio_bit_25,
        ratio_bit_26,
        ratio_bit_27,
        ratio_bit_28,
        ratio_bit_29,
        ratio_bit_30,
        ratio_bit_31
    }; // enum class cpu_tsc_to_core_crystal_clock_frequency_numerator : std::uint8_t

    enum class cpu_tsc_to_core_crystal_clock_frequency_numerator_mask : std::uint32_t {
        ratio = 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_0)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_1)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_2)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_3)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_4)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_5)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_6)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_7)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_8)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_9)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_10)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_11)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_12)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_13)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_14)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_15)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_16)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_17)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_18)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_19)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_20)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_21)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_22)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_23)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_24)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_25)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_26)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_27)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_28)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_29)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_30)
              | 1u << std::to_underlying(cpu_tsc_to_core_crystal_clock_frequency_numerator::ratio_bit_31)
    }; // enum class cpu_tsc_to_core_crystal_clock_frequency_numerator_mask : std::uint32_t

    [[nodiscard]]
    cpu_tsc_to_core_crystal_clock_frequency_numerator_mask supported_cpu_tsc_to_crystal_clock_frequency_numerator(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_tsc_to_core_crystal_clock_frequency_numerator_mask{};

        if (max_leaf >= 0x15) {
            using cpu_tsc_to_core_crystal_clock_frequency_numerator;
            const auto leaf15 = cpu_id(0x15, 0u);

            // ebx register
            if (leaf15.ebx_bit( 0u)) result |= ratio_bit_0;
            if (leaf15.ebx_bit( 1u)) result |= ratio_bit_1;
            if (leaf15.ebx_bit( 2u)) result |= ratio_bit_2;
            if (leaf15.ebx_bit( 3u)) result |= ratio_bit_3;
            if (leaf15.ebx_bit( 4u)) result |= ratio_bit_4;
            if (leaf15.ebx_bit( 5u)) result |= ratio_bit_5;
            if (leaf15.ebx_bit( 6u)) result |= ratio_bit_6;
            if (leaf15.ebx_bit( 7u)) result |= ratio_bit_7;
            if (leaf15.ebx_bit( 8u)) result |= ratio_bit_8;
            if (leaf15.ebx_bit( 9u)) result |= ratio_bit_9;
            if (leaf15.ebx_bit(10u)) result |= ratio_bit_10;
            if (leaf15.ebx_bit(11u)) result |= ratio_bit_11;
            if (leaf15.ebx_bit(12u)) result |= ratio_bit_12;
            if (leaf15.ebx_bit(13u)) result |= ratio_bit_13;
            if (leaf15.ebx_bit(14u)) result |= ratio_bit_14;
            if (leaf15.ebx_bit(15u)) result |= ratio_bit_15;
            if (leaf15.ebx_bit(16u)) result |= ratio_bit_16;
            if (leaf15.ebx_bit(17u)) result |= ratio_bit_17;
            if (leaf15.ebx_bit(18u)) result |= ratio_bit_18;
            if (leaf15.ebx_bit(19u)) result |= ratio_bit_19;
            if (leaf15.ebx_bit(20u)) result |= ratio_bit_20;
            if (leaf15.ebx_bit(21u)) result |= ratio_bit_21;
            if (leaf15.ebx_bit(22u)) result |= ratio_bit_22;
            if (leaf15.ebx_bit(23u)) result |= ratio_bit_23;
            if (leaf15.ebx_bit(24u)) result |= ratio_bit_24;
            if (leaf15.ebx_bit(25u)) result |= ratio_bit_25;
            if (leaf15.ebx_bit(26u)) result |= ratio_bit_26;
            if (leaf15.ebx_bit(27u)) result |= ratio_bit_27;
            if (leaf15.ebx_bit(28u)) result |= ratio_bit_28;
            if (leaf15.ebx_bit(29u)) result |= ratio_bit_29;
            if (leaf15.ebx_bit(30u)) result |= ratio_bit_30;
            if (leaf15.ebx_bit(31u)) result |= ratio_bit_31;
        }

        return result;
    }

    enum class cpu_core_crystal_clock_frequency : std::uint8_t {
        frequency_bit_0,
        frequency_bit_1,
        frequency_bit_2,
        frequency_bit_3,
        frequency_bit_4,
        frequency_bit_5,
        frequency_bit_6,
        frequency_bit_7,
        frequency_bit_8,
        frequency_bit_9,
        frequency_bit_10,
        frequency_bit_11,
        frequency_bit_12,
        frequency_bit_13,
        frequency_bit_14,
        frequency_bit_15,
        frequency_bit_16,
        frequency_bit_17,
        frequency_bit_18,
        frequency_bit_19,
        frequency_bit_20,
        frequency_bit_21,
        frequency_bit_22,
        frequency_bit_23,
        frequency_bit_24,
        frequency_bit_25,
        frequency_bit_26,
        frequency_bit_27,
        frequency_bit_28,
        frequency_bit_29,
        frequency_bit_30,
        frequency_bit_31
    }; // enum class cpu_core_crystal_clock_frequency : std::uint8_t

    enum class cpu_core_crystal_clock_frequency_mask : std::uint32_t {
        frequency = 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_0)
                  | 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_1)
                  | 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_2)
                  | 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_3)
                  | 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_4)
                  | 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_5)
                  | 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_6)
                  | 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_7)
                  | 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_8)
                  | 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_9)
                  | 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_10)
                  | 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_11)
                  | 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_12)
                  | 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_13)
                  | 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_14)
                  | 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_15)
                  | 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_16)
                  | 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_17)
                  | 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_18)
                  | 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_19)
                  | 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_20)
                  | 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_21)
                  | 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_22)
                  | 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_23)
                  | 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_24)
                  | 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_25)
                  | 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_26)
                  | 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_27)
                  | 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_28)
                  | 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_29)
                  | 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_30)
                  | 1u << std::to_underlying(cpu_core_crystal_clock_frequency::frequency_bit_31)
    }; // enum class cpu_core_crystal_clock_frequency_mask : std::uint32_t

    [[nodiscard]]
    cpu_core_crystal_clock_frequency_mask supported_cpu_core_crystal_clock_frequency(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_core_crystal_clock_frequency_mask{};

        if (max_leaf >= 0x15) {
            using cpu_core_crystal_clock_frequency;
            const auto leaf15 = cpu_id(0x15, 0u);

            // ecx register
            if (leaf15.ecx_bit( 0u)) result |= frequency_bit_0;
            if (leaf15.ecx_bit( 1u)) result |= frequency_bit_1;
            if (leaf15.ecx_bit( 2u)) result |= frequency_bit_2;
            if (leaf15.ecx_bit( 3u)) result |= frequency_bit_3;
            if (leaf15.ecx_bit( 4u)) result |= frequency_bit_4;
            if (leaf15.ecx_bit( 5u)) result |= frequency_bit_5;
            if (leaf15.ecx_bit( 6u)) result |= frequency_bit_6;
            if (leaf15.ecx_bit( 7u)) result |= frequency_bit_7;
            if (leaf15.ecx_bit( 8u)) result |= frequency_bit_8;
            if (leaf15.ecx_bit( 9u)) result |= frequency_bit_9;
            if (leaf15.ecx_bit(10u)) result |= frequency_bit_10;
            if (leaf15.ecx_bit(11u)) result |= frequency_bit_11;
            if (leaf15.ecx_bit(12u)) result |= frequency_bit_12;
            if (leaf15.ecx_bit(13u)) result |= frequency_bit_13;
            if (leaf15.ecx_bit(14u)) result |= frequency_bit_14;
            if (leaf15.ecx_bit(15u)) result |= frequency_bit_15;
            if (leaf15.ecx_bit(16u)) result |= frequency_bit_16;
            if (leaf15.ecx_bit(17u)) result |= frequency_bit_17;
            if (leaf15.ecx_bit(18u)) result |= frequency_bit_18;
            if (leaf15.ecx_bit(19u)) result |= frequency_bit_19;
            if (leaf15.ecx_bit(20u)) result |= frequency_bit_20;
            if (leaf15.ecx_bit(21u)) result |= frequency_bit_21;
            if (leaf15.ecx_bit(22u)) result |= frequency_bit_22;
            if (leaf15.ecx_bit(23u)) result |= frequency_bit_23;
            if (leaf15.ecx_bit(24u)) result |= frequency_bit_24;
            if (leaf15.ecx_bit(25u)) result |= frequency_bit_25;
            if (leaf15.ecx_bit(26u)) result |= frequency_bit_26;
            if (leaf15.ecx_bit(27u)) result |= frequency_bit_27;
            if (leaf15.ecx_bit(28u)) result |= frequency_bit_28;
            if (leaf15.ecx_bit(29u)) result |= frequency_bit_29;
            if (leaf15.ecx_bit(30u)) result |= frequency_bit_30;
            if (leaf15.ecx_bit(31u)) result |= frequency_bit_31;
        }

        return result;
    }
} // namespace based::platform::x86::detail

