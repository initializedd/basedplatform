#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"
#include "cpu_state_components.hpp"
#include "../../util.hpp"

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
    inline cpu_distinct_max_xsave_save_area_mask supported_cpu_distinct_max_save_save_area(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_distinct_max_xsave_save_area_mask{};

        if (max_leaf >= 0x0D) {
            using enum cpu_distinct_max_xsave_save_area;
            const auto leaf_0x0d = cpu_id(0x0D, 0x00);

            // ebx register
            if (leaf_0x0d.ebx_bit( 0u)) result |= size_bit_0;
            if (leaf_0x0d.ebx_bit( 1u)) result |= size_bit_1;
            if (leaf_0x0d.ebx_bit( 2u)) result |= size_bit_2;
            if (leaf_0x0d.ebx_bit( 3u)) result |= size_bit_3;
            if (leaf_0x0d.ebx_bit( 4u)) result |= size_bit_4;
            if (leaf_0x0d.ebx_bit( 5u)) result |= size_bit_5;
            if (leaf_0x0d.ebx_bit( 6u)) result |= size_bit_6;
            if (leaf_0x0d.ebx_bit( 7u)) result |= size_bit_7;
            if (leaf_0x0d.ebx_bit( 8u)) result |= size_bit_8;
            if (leaf_0x0d.ebx_bit( 9u)) result |= size_bit_9;
            if (leaf_0x0d.ebx_bit(10u)) result |= size_bit_10;
            if (leaf_0x0d.ebx_bit(11u)) result |= size_bit_11;
            if (leaf_0x0d.ebx_bit(12u)) result |= size_bit_12;
            if (leaf_0x0d.ebx_bit(13u)) result |= size_bit_13;
            if (leaf_0x0d.ebx_bit(14u)) result |= size_bit_14;
            if (leaf_0x0d.ebx_bit(15u)) result |= size_bit_15;
            if (leaf_0x0d.ebx_bit(16u)) result |= size_bit_16;
            if (leaf_0x0d.ebx_bit(17u)) result |= size_bit_17;
            if (leaf_0x0d.ebx_bit(18u)) result |= size_bit_18;
            if (leaf_0x0d.ebx_bit(19u)) result |= size_bit_19;
            if (leaf_0x0d.ebx_bit(20u)) result |= size_bit_20;
            if (leaf_0x0d.ebx_bit(21u)) result |= size_bit_21;
            if (leaf_0x0d.ebx_bit(22u)) result |= size_bit_22;
            if (leaf_0x0d.ebx_bit(23u)) result |= size_bit_23;
            if (leaf_0x0d.ebx_bit(24u)) result |= size_bit_24;
            if (leaf_0x0d.ebx_bit(25u)) result |= size_bit_25;
            if (leaf_0x0d.ebx_bit(26u)) result |= size_bit_26;
            if (leaf_0x0d.ebx_bit(27u)) result |= size_bit_27;
            if (leaf_0x0d.ebx_bit(28u)) result |= size_bit_28;
            if (leaf_0x0d.ebx_bit(29u)) result |= size_bit_29;
            if (leaf_0x0d.ebx_bit(30u)) result |= size_bit_30;
            if (leaf_0x0d.ebx_bit(31u)) result |= size_bit_31;
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
    inline cpu_simultaneous_max_xsave_save_area_mask supported_cpu_simultaneous_max_save_save_area(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_simultaneous_max_xsave_save_area_mask{};

        if (max_leaf >= 0x0D) {
            using enum cpu_simultaneous_max_xsave_save_area;
            const auto leaf_0x0d = cpu_id(0x0D, 0x00);

            // ecx register
            if (leaf_0x0d.ebx_bit( 0u)) result |= size_bit_0;
            if (leaf_0x0d.ebx_bit( 1u)) result |= size_bit_1;
            if (leaf_0x0d.ebx_bit( 2u)) result |= size_bit_2;
            if (leaf_0x0d.ebx_bit( 3u)) result |= size_bit_3;
            if (leaf_0x0d.ebx_bit( 4u)) result |= size_bit_4;
            if (leaf_0x0d.ebx_bit( 5u)) result |= size_bit_5;
            if (leaf_0x0d.ebx_bit( 6u)) result |= size_bit_6;
            if (leaf_0x0d.ebx_bit( 7u)) result |= size_bit_7;
            if (leaf_0x0d.ebx_bit( 8u)) result |= size_bit_8;
            if (leaf_0x0d.ebx_bit( 9u)) result |= size_bit_9;
            if (leaf_0x0d.ebx_bit(10u)) result |= size_bit_10;
            if (leaf_0x0d.ebx_bit(11u)) result |= size_bit_11;
            if (leaf_0x0d.ebx_bit(12u)) result |= size_bit_12;
            if (leaf_0x0d.ebx_bit(13u)) result |= size_bit_13;
            if (leaf_0x0d.ebx_bit(14u)) result |= size_bit_14;
            if (leaf_0x0d.ebx_bit(15u)) result |= size_bit_15;
            if (leaf_0x0d.ebx_bit(16u)) result |= size_bit_16;
            if (leaf_0x0d.ebx_bit(17u)) result |= size_bit_17;
            if (leaf_0x0d.ebx_bit(18u)) result |= size_bit_18;
            if (leaf_0x0d.ebx_bit(19u)) result |= size_bit_19;
            if (leaf_0x0d.ebx_bit(20u)) result |= size_bit_20;
            if (leaf_0x0d.ebx_bit(21u)) result |= size_bit_21;
            if (leaf_0x0d.ebx_bit(22u)) result |= size_bit_22;
            if (leaf_0x0d.ebx_bit(23u)) result |= size_bit_23;
            if (leaf_0x0d.ebx_bit(24u)) result |= size_bit_24;
            if (leaf_0x0d.ebx_bit(25u)) result |= size_bit_25;
            if (leaf_0x0d.ebx_bit(26u)) result |= size_bit_26;
            if (leaf_0x0d.ebx_bit(27u)) result |= size_bit_27;
            if (leaf_0x0d.ebx_bit(28u)) result |= size_bit_28;
            if (leaf_0x0d.ebx_bit(29u)) result |= size_bit_29;
            if (leaf_0x0d.ebx_bit(30u)) result |= size_bit_30;
            if (leaf_0x0d.ebx_bit(31u)) result |= size_bit_31;
        }

        return result;
    }

    [[nodiscard]]
    inline cpu_state_component_mask supported_cpu_xcr0_state_components(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_state_component_mask{};

        if (max_leaf >= 0x0D) {
            using enum cpu_state_component_mask;
            const auto leaf_0x0d = cpu_id(0x0D, 0x00);

            // eax register
            if (leaf_0x0d.eax_bit( 0u)) result |= x87_state;
            if (leaf_0x0d.eax_bit( 1u)) result |= sse_state;
            if (leaf_0x0d.eax_bit( 2u)) result |= avx_state;
            if (leaf_0x0d.eax_bit( 3u)) result |= mpx_bnd0_bnd3_state;
            if (leaf_0x0d.eax_bit( 4u)) result |= mpx_bndcfgu_bndstatus_state;
            if (leaf_0x0d.eax_bit( 5u)) result |= avx512_k0_k7_state;
            if (leaf_0x0d.eax_bit( 6u)) result |= avx512_zmm_hi256_state;
            if (leaf_0x0d.eax_bit( 7u)) result |= avx512_hi16_zmm_state;
            if (leaf_0x0d.eax_bit( 9u)) result |= pkru;
            if (leaf_0x0d.eax_bit(17u)) result |= amx_tile_config_state;
            if (leaf_0x0d.eax_bit(18u)) result |= amx_tile_data;
            if (leaf_0x0d.eax_bit(19u)) result |= apx;

            // edx register
            if (leaf_0x0d.edx_bit(62u)) result |= lwp;
        }

        return result;
    }
} // namespace based::platform::x86::detail

