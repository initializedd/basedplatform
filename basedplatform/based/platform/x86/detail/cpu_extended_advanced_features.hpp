#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// CPU Extended Advanced Features
// https://en.wikipedia.org/wiki/CPUID#EAX=7,_ECX=0:_Extended_Features

namespace based::platform::x86::detail {
    enum class cpu_extended_advanced_feature : std::uint8_t {
        prefetchwt1,
        avx512vbmi,
        umip,
        pku,
        ospke,
        waitpkg,
        avx512vbmi2,
        cetss,
        gfni,
        vaes,
        vpclmulqdq,
        avx512vnni,
        avx512bitalg,
        tmeen,
        avx512vpopcntdq,
        fzm,
        la57,
        mawau_bit_0,
        mawau_bit_1,
        mawau_bit_2,
        mawau_bit_3,
        mawau_bit_4,
        rdpid,
        kl,
        bus_lock_detect,
        cldemote,
        mprr,
        movdiri,
        movdir64b,
        enqcmd,
        sgxlc,
        pks
    }; // enum class cpu_extended_advanced_feature : std::uint8_t

    enum class cpu_extended_advanced_feature_mask : std::uint32_t {
        prefetchwt1     = 1u << std::to_underlying(cpu_extended_advanced_feature::prefetchwt1),
        avx512vbmi      = 1u << std::to_underlying(cpu_extended_advanced_feature::avx512vbmi),
        umip            = 1u << std::to_underlying(cpu_extended_advanced_feature::umip),
        pku             = 1u << std::to_underlying(cpu_extended_advanced_feature::pku),
        ospke           = 1u << std::to_underlying(cpu_extended_advanced_feature::ospke),
        waitpkg         = 1u << std::to_underlying(cpu_extended_advanced_feature::waitpkg),
        avx512vbmi2     = 1u << std::to_underlying(cpu_extended_advanced_feature::avx512vbmi2),
        cetss           = 1u << std::to_underlying(cpu_extended_advanced_feature::cetss),
        gfni            = 1u << std::to_underlying(cpu_extended_advanced_feature::gfni),
        vaes            = 1u << std::to_underlying(cpu_extended_advanced_feature::vaes),
        vpclmulqdq      = 1u << std::to_underlying(cpu_extended_advanced_feature::vpclmulqdq),
        avx512vnni      = 1u << std::to_underlying(cpu_extended_advanced_feature::avx512vnni),
        avx512bitalg    = 1u << std::to_underlying(cpu_extended_advanced_feature::avx512bitalg),
        tmeen           = 1u << std::to_underlying(cpu_extended_advanced_feature::tmeen),
        avx512vpopcntdq = 1u << std::to_underlying(cpu_extended_advanced_feature::avx512vpopcntdq),
        fzm             = 1u << std::to_underlying(cpu_extended_advanced_feature::fzm),
        la57            = 1u << std::to_underlying(cpu_extended_advanced_feature::la57),
        mawau           = 1u << std::to_underlying(cpu_extended_advanced_feature::mawau_bit_0)
                        | 1u << std::to_underlying(cpu_extended_advanced_feature::mawau_bit_1)
                        | 1u << std::to_underlying(cpu_extended_advanced_feature::mawau_bit_2)
                        | 1u << std::to_underlying(cpu_extended_advanced_feature::mawau_bit_3)
                        | 1u << std::to_underlying(cpu_extended_advanced_feature::mawau_bit_4),
        rdpid           = 1u << std::to_underlying(cpu_extended_advanced_feature::rdpid),
        kl              = 1u << std::to_underlying(cpu_extended_advanced_feature::kl),
        bus_lock_detect = 1u << std::to_underlying(cpu_extended_advanced_feature::bus_lock_detect),
        cldemote        = 1u << std::to_underlying(cpu_extended_advanced_feature::cldemote),
        mprr            = 1u << std::to_underlying(cpu_extended_advanced_feature::mprr),
        movdiri         = 1u << std::to_underlying(cpu_extended_advanced_feature::movdiri),
        movdir64b       = 1u << std::to_underlying(cpu_extended_advanced_feature::movdir64b),
        enqcmd          = 1u << std::to_underlying(cpu_extended_advanced_feature::enqcmd),
        sgxlc           = 1u << std::to_underlying(cpu_extended_advanced_feature::sgxlc),
        pks             = 1u << std::to_underlying(cpu_extended_advanced_feature::pks)
    }; // enum class cpu_extended_advanced_feature : std::uint32_t

    [[nodiscard]]
    cpu_extended_advanced_feature_mask supported_extended_advanced_features(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_extended_advanced_feature_mask{};

        if (max_leaf >= 0x07) {
            using enum cpu_extended_advanced_feature;
            const auto leaf7 = cpu_id(0x07, 0x00);

            // ecx register
            if (leaf7.ecx_bit( 0u)) result |= prefetchwt1;
            if (leaf7.ecx_bit( 1u)) result |= avx512vbmi;
            if (leaf7.ecx_bit( 2u)) result |= umip;
            if (leaf7.ecx_bit( 3u)) result |= pku;
            if (leaf7.ecx_bit( 4u)) result |= ospke;
            if (leaf7.ecx_bit( 5u)) result |= waitpkg;
            if (leaf7.ecx_bit( 6u)) result |= avx512vbmi2;
            if (leaf7.ecx_bit( 7u)) result |= cetss;
            if (leaf7.ecx_bit( 8u)) result |= gfni;
            if (leaf7.ecx_bit( 9u)) result |= vaes;
            if (leaf7.ecx_bit(10u)) result |= vpclmulqdq;
            if (leaf7.ecx_bit(11u)) result |= avx512vnni;
            if (leaf7.ecx_bit(12u)) result |= avx512bitalg;
            if (leaf7.ecx_bit(13u)) result |= tmeen;
            if (leaf7.ecx_bit(14u)) result |= avx512vpopcntdq;
            if (leaf7.ecx_bit(15u)) result |= fzm;
            if (leaf7.ecx_bit(16u)) result |= la57;
            if (leaf7.ecx_bit(17u)) result |= mawau_bit_0;
            if (leaf7.ecx_bit(18u)) result |= mawau_bit_1;
            if (leaf7.ecx_bit(19u)) result |= mawau_bit_2;
            if (leaf7.ecx_bit(20u)) result |= mawau_bit_3;
            if (leaf7.ecx_bit(21u)) result |= mawau_bit_4;
            if (leaf7.ecx_bit(22u)) result |= rdpid;
            if (leaf7.ecx_bit(23u)) result |= kl;
            if (leaf7.ecx_bit(24u)) result |= bus_lock_detect;
            if (leaf7.ecx_bit(25u)) result |= cldemote;
            if (leaf7.ecx_bit(26u)) result |= mprr;
            if (leaf7.ecx_bit(27u)) result |= movdiri;
            if (leaf7.ecx_bit(28u)) result |= movdir64b;
            if (leaf7.ecx_bit(29u)) result |= enqcmd;
            if (leaf7.ecx_bit(30u)) result |= sgxlc;
            if (leaf7.ecx_bit(31u)) result |= pks;
        }

        return result;
    }
} // namespace based::platform::x86::detail

