#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// CPU Extended Core Features
// https://en.wikipedia.org/wiki/CPUID#EAX=7,_ECX=0:_Extended_Features

namespace based::platform::x86::detail {
    enum class cpu_extended_core_feature : std::uint8_t {
        fsgsbase,
        ia32_tsc_adjust_msr,
        sgx,
        bmi1,
        hle,
        avx2,
        fdp_excptn_only,
        smep,
        bmi2,
        erms,
        invpcid,
        rtm,
        rdtm,
        // bit 13 deprecated
        mpx                 = 14u,
        rdta,
        avx512f,
        avx512dq,
        rdseed,
        adx,
        smap,
        avx512ifma,
        pcommit,
        clflushopt,
        clwb,
        pt,
        avx512pf,
        avx512er,
        avx512cd,
        sha,
        avx512bw,
        avx512vl
    }; // enum class cpu_extended_core_feature : std::uint8_t

    enum class cpu_extended_core_feature_mask : std::uint32_t {
        fsgsbase            = 1u << std::to_underlying(cpu_extended_core_feature::fsgsbase),
        ia32_tsc_adjust_msr = 1u << std::to_underlying(cpu_extended_core_feature::ia32_tsc_adjust_msr),
        sgx                 = 1u << std::to_underlying(cpu_extended_core_feature::sgx),
        bmi1                = 1u << std::to_underlying(cpu_extended_core_feature::bmi1),
        hle                 = 1u << std::to_underlying(cpu_extended_core_feature::hle),
        avx2                = 1u << std::to_underlying(cpu_extended_core_feature::avx2),
        fdp_excptn_only     = 1u << std::to_underlying(cpu_extended_core_feature::fdp_excptn_only),
        smep                = 1u << std::to_underlying(cpu_extended_core_feature::smep),
        bmi2                = 1u << std::to_underlying(cpu_extended_core_feature::bmi2),
        erms                = 1u << std::to_underlying(cpu_extended_core_feature::erms),
        invpcid             = 1u << std::to_underlying(cpu_extended_core_feature::invpcid),
        rtm                 = 1u << std::to_underlying(cpu_extended_core_feature::rtm),
        rdtm                = 1u << std::to_underlying(cpu_extended_core_feature::rdtm),
        mpx                 = 1u << std::to_underlying(cpu_extended_core_feature::mpx),
        rdta                = 1u << std::to_underlying(cpu_extended_core_feature::rdta),
        avx512f             = 1u << std::to_underlying(cpu_extended_core_feature::avx512f),
        avx512dq            = 1u << std::to_underlying(cpu_extended_core_feature::avx512dq),
        rdseed              = 1u << std::to_underlying(cpu_extended_core_feature::rdseed),
        adx                 = 1u << std::to_underlying(cpu_extended_core_feature::adx),
        smap                = 1u << std::to_underlying(cpu_extended_core_feature::smap),
        avx512ifma          = 1u << std::to_underlying(cpu_extended_core_feature::avx512ifma),
        pcommit             = 1u << std::to_underlying(cpu_extended_core_feature::pcommit),
        clflushopt          = 1u << std::to_underlying(cpu_extended_core_feature::clflushopt),
        clwb                = 1u << std::to_underlying(cpu_extended_core_feature::clwb),
        pt                  = 1u << std::to_underlying(cpu_extended_core_feature::pt),
        avx512pf            = 1u << std::to_underlying(cpu_extended_core_feature::avx512pf),
        avx512er            = 1u << std::to_underlying(cpu_extended_core_feature::avx512er),
        avx512cd            = 1u << std::to_underlying(cpu_extended_core_feature::avx512cd),
        sha                 = 1u << std::to_underlying(cpu_extended_core_feature::sha),
        avx512bw            = 1u << std::to_underlying(cpu_extended_core_feature::avx512bw),
        avx512vl            = 1u << std::to_underlying(cpu_extended_core_feature::avx512vl)
    }; // enum class cpu_extended_core_feature_mask : std::uint32_t

    [[nodiscard]]
    cpu_extended_core_feature_mask supported_extended_core_features(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_extended_core_feature_mask{};

        if (max_leaf >= 0x07) {
            using enum cpu_extended_core_feature;
            const auto leaf_0x07 = cpu_id(0x07, 0x00);

            // ebx register
            if (leaf_0x07.ebx_bit( 0u)) result |= fsgsbase;
            if (leaf_0x07.ebx_bit( 1u)) result |= ia32_tsc_adjust_msr;
            if (leaf_0x07.ebx_bit( 2u)) result |= sgx;
            if (leaf_0x07.ebx_bit( 3u)) result |= bmi1;
            if (leaf_0x07.ebx_bit( 4u)) result |= hle;
            if (leaf_0x07.ebx_bit( 5u)) result |= avx2;
            if (leaf_0x07.ebx_bit( 6u)) result |= fdp_excptn_only;
            if (leaf_0x07.ebx_bit( 7u)) result |= smep;
            if (leaf_0x07.ebx_bit( 8u)) result |= bmi2;
            if (leaf_0x07.ebx_bit( 9u)) result |= erms;
            if (leaf_0x07.ebx_bit(10u)) result |= invpcid;
            if (leaf_0x07.ebx_bit(11u)) result |= rtm;
            if (leaf_0x07.ebx_bit(12u)) result |= rdtm;
            if (leaf_0x07.ebx_bit(14u)) result |= mpx;
            if (leaf_0x07.ebx_bit(15u)) result |= rdta;
            if (leaf_0x07.ebx_bit(16u)) result |= avx512f;
            if (leaf_0x07.ebx_bit(17u)) result |= avx512dq;
            if (leaf_0x07.ebx_bit(18u)) result |= rdseed;
            if (leaf_0x07.ebx_bit(19u)) result |= adx;
            if (leaf_0x07.ebx_bit(20u)) result |= smap;
            if (leaf_0x07.ebx_bit(21u)) result |= avx512ifma;
            if (leaf_0x07.ebx_bit(22u)) result |= pcommit;
            if (leaf_0x07.ebx_bit(23u)) result |= clflushopt;
            if (leaf_0x07.ebx_bit(24u)) result |= clwb;
            if (leaf_0x07.ebx_bit(25u)) result |= pt;
            if (leaf_0x07.ebx_bit(26u)) result |= avx512pf;
            if (leaf_0x07.ebx_bit(27u)) result |= avx512er;
            if (leaf_0x07.ebx_bit(28u)) result |= avx512cd;
            if (leaf_0x07.ebx_bit(29u)) result |= sha;
            if (leaf_0x07.ebx_bit(30u)) result |= avx512bw;
            if (leaf_0x07.ebx_bit(31u)) result |= avx512vl;
        }

        return result;
    }
} // namespace based::platform::x86::detail

