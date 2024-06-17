#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// Centaur Feature Information
// https://en.wikipedia.org/wiki/CPUID#EAX=C0000001h:_Centaur_Feature_Information

namespace based::platform::x86::detail {
    enum class cpu_centaur_feature : std::uint8_t {
        sm2,
        sm2_en,
        rng,
        rng_en,
        ccs,
        ccs_en,
        xcrypt,
        xcrypt_en,
        ace2,
        ace2_en,
        phe,
        phe_en,
        pmm,
        pmm_en,
        // bit 14 reserved
        zx_fma        = 15u,
        parallax,
        parallax_en,
        overstress,
        overstress_en,
        tm3,
        tm3_en,
        rng2,
        rng2_en,
        sem,
        phe2,
        phe2_en,
        xmodx,
        xmodx_en,
        vex,
        vex_en,
        stk
    }; // enum class cpu_centaur_feature : std::uint8_t

    enum class cpu_centaur_feature_mask : std::uint32_t {
        sm2           = 1u << std::to_underlying(cpu_centaur_feature::sm2),
        sm2_en        = 1u << std::to_underlying(cpu_centaur_feature::sm2_en),
        rng           = 1u << std::to_underlying(cpu_centaur_feature::rng),
        rng_en        = 1u << std::to_underlying(cpu_centaur_feature::rng_en),
        ccs           = 1u << std::to_underlying(cpu_centaur_feature::ccs),
        ccs_en        = 1u << std::to_underlying(cpu_centaur_feature::ccs_en),
        xcrypt        = 1u << std::to_underlying(cpu_centaur_feature::xcrypt),
        xcrypt_en     = 1u << std::to_underlying(cpu_centaur_feature::xcrypt_en),
        ace2          = 1u << std::to_underlying(cpu_centaur_feature::ace2),
        ace2_en       = 1u << std::to_underlying(cpu_centaur_feature::ace2_en),
        phe           = 1u << std::to_underlying(cpu_centaur_feature::phe),
        phe_en        = 1u << std::to_underlying(cpu_centaur_feature::phe_en),
        pmm           = 1u << std::to_underlying(cpu_centaur_feature::pmm),
        pmm_en        = 1u << std::to_underlying(cpu_centaur_feature::pmm_en),
        zx_fma        = 1u << std::to_underlying(cpu_centaur_feature::zx_fma),
        parallax      = 1u << std::to_underlying(cpu_centaur_feature::parallax),
        parallax_en   = 1u << std::to_underlying(cpu_centaur_feature::parallax_en),
        overstress    = 1u << std::to_underlying(cpu_centaur_feature::overstress),
        overstress_en = 1u << std::to_underlying(cpu_centaur_feature::overstress_en),
        tm3           = 1u << std::to_underlying(cpu_centaur_feature::tm3),
        tm3_en        = 1u << std::to_underlying(cpu_centaur_feature::tm3_en),
        rng2          = 1u << std::to_underlying(cpu_centaur_feature::rng2),
        rng2_en       = 1u << std::to_underlying(cpu_centaur_feature::rng2_en),
        sem           = 1u << std::to_underlying(cpu_centaur_feature::sem),
        phe2          = 1u << std::to_underlying(cpu_centaur_feature::phe2),
        phe2_en       = 1u << std::to_underlying(cpu_centaur_feature::phe2_en),
        xmodx         = 1u << std::to_underlying(cpu_centaur_feature::xmodx),
        xmodx_en      = 1u << std::to_underlying(cpu_centaur_feature::xmodx_en),
        vex           = 1u << std::to_underlying(cpu_centaur_feature::vex),
        vex_en        = 1u << std::to_underlying(cpu_centaur_feature::vex_en),
        stk           = 1u << std::to_underlying(cpu_centaur_feature::stk)
    }; // enum class cpu_centaur_feature_mask : std::uint32_t

    [[nodiscard]]
    cpu_centaur_feature_mask supported_cpu_centaur_features(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_centaur_feature_mask{};

        if (max_leaf >= 0xC0000001) {
            using cpu_centaur_feature;
            const auto leaf8 = cpu_id(0xC0000001, 0u);

            // edx register
            if (leaf8.edx_bit( 0u)) result |= sm2;
            if (leaf8.edx_bit( 1u)) result |= sm2_en;
            if (leaf8.edx_bit( 2u)) result |= rng;
            if (leaf8.edx_bit( 3u)) result |= rng_en;
            if (leaf8.edx_bit( 4u)) result |= ccs;
            if (leaf8.edx_bit( 5u)) result |= ccs_en;
            if (leaf8.edx_bit( 6u)) result |= xcrypt;
            if (leaf8.edx_bit( 7u)) result |= xcrypt_en;
            if (leaf8.edx_bit( 8u)) result |= ace2;
            if (leaf8.edx_bit( 9u)) result |= ace2_en;
            if (leaf8.edx_bit(10u)) result |= phe;
            if (leaf8.edx_bit(11u)) result |= phe_en;
            if (leaf8.edx_bit(12u)) result |= pmm;
            if (leaf8.edx_bit(13u)) result |= pmm_en;
            if (leaf8.edx_bit(15u)) result |= zx_fma;
            if (leaf8.edx_bit(16u)) result |= parallax;
            if (leaf8.edx_bit(17u)) result |= parallax_en;
            if (leaf8.edx_bit(18u)) result |= overstress;
            if (leaf8.edx_bit(19u)) result |= overstress_en;
            if (leaf8.edx_bit(20u)) result |= tm3;
            if (leaf8.edx_bit(21u)) result |= tm3_en;
            if (leaf8.edx_bit(22u)) result |= rng2;
            if (leaf8.edx_bit(23u)) result |= rng2_en;
            if (leaf8.edx_bit(24u)) result |= sem;
            if (leaf8.edx_bit(25u)) result |= phe2;
            if (leaf8.edx_bit(26u)) result |= phe2_en;
            if (leaf8.edx_bit(27u)) result |= xmodx;
            if (leaf8.edx_bit(28u)) result |= xmodx_en;
            if (leaf8.edx_bit(29u)) result |= vex;
            if (leaf8.edx_bit(30u)) result |= vex_en;
            if (leaf8.edx_bit(31u)) result |= stk;
        }

        return result;
    }
} // namespace based::platform::x86::detail

