#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// CPU Core Features
// https://en.wikipedia.org/wiki/CPUID#EAX=1:_Processor_Info_and_Feature_Bits

namespace based::platform::x86::detail {
    enum class cpu_core_feature : std::uint8_t {
        fpu,
        vme,
        de,
        pse,
        tsc,
        msr,
        pae,
        mce,
        cx8,
        apic,
        // bit 10 reserved
        sep    = 11u,
        mtrr,
        pge,
        mca,
        cmov,
        pat,
        pse_36,
        psn,
        clfsh,
        nx,
        ds,
        acpi,
        mmx,
        fxsr,
        sse,
        sse2,
        ss,
        htt,
        tm,
        ia64,
        pbe
    }; // enum class cpu_core_feature : std::uint8_t

    enum class cpu_core_feature_mask : std::uint32_t {
        fpu    = 1u << std::to_underlying(cpu_core_feature::fpu),
        vme    = 1u << std::to_underlying(cpu_core_feature::vme),
        de     = 1u << std::to_underlying(cpu_core_feature::de),
        pse    = 1u << std::to_underlying(cpu_core_feature::pse),
        tsc    = 1u << std::to_underlying(cpu_core_feature::tsc),
        msr    = 1u << std::to_underlying(cpu_core_feature::msr),
        pae    = 1u << std::to_underlying(cpu_core_feature::pae),
        mce    = 1u << std::to_underlying(cpu_core_feature::mce),
        cx8    = 1u << std::to_underlying(cpu_core_feature::cx8),
        apic   = 1u << std::to_underlying(cpu_core_feature::apic),
        sep    = 1u << std::to_underlying(cpu_core_feature::sep),
        mtrr   = 1u << std::to_underlying(cpu_core_feature::mtrr),
        pge    = 1u << std::to_underlying(cpu_core_feature::pge),
        mca    = 1u << std::to_underlying(cpu_core_feature::mca),
        cmov   = 1u << std::to_underlying(cpu_core_feature::cmov),
        pat    = 1u << std::to_underlying(cpu_core_feature::pat),
        pse_36 = 1u << std::to_underlying(cpu_core_feature::pse_36),
        psn    = 1u << std::to_underlying(cpu_core_feature::psn),
        clfsh  = 1u << std::to_underlying(cpu_core_feature::clfsh),
        nx     = 1u << std::to_underlying(cpu_core_feature::nx),
        ds     = 1u << std::to_underlying(cpu_core_feature::ds),
        acpi   = 1u << std::to_underlying(cpu_core_feature::acpi),
        mmx    = 1u << std::to_underlying(cpu_core_feature::mmx),
        fxsr   = 1u << std::to_underlying(cpu_core_feature::fxsr),
        sse    = 1u << std::to_underlying(cpu_core_feature::sse),
        sse2   = 1u << std::to_underlying(cpu_core_feature::sse2),
        ss     = 1u << std::to_underlying(cpu_core_feature::ss),
        htt    = 1u << std::to_underlying(cpu_core_feature::htt),
        tm     = 1u << std::to_underlying(cpu_core_feature::tm),
        ia64   = 1u << std::to_underlying(cpu_core_feature::ia64),
        pbe    = 1u << std::to_underlying(cpu_core_feature::pbe)
    }; // enum class cpu_core_feature_mask : std::uint32_t

    [[nodiscard]]
    cpu_core_feature_mask supported_cpu_core_features(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_core_feature_mask{};

        if (max_leaf >= 0x01) {
            using enum cpu_core_feature;
            const auto leaf_0x01 = cpu_id(0x01, 0x00);

            // edx register
            if (leaf_0x01.edx_bit( 0u)) result |= fpu;
            if (leaf_0x01.edx_bit( 1u)) result |= vme;
            if (leaf_0x01.edx_bit( 2u)) result |= de;
            if (leaf_0x01.edx_bit( 3u)) result |= pse;
            if (leaf_0x01.edx_bit( 4u)) result |= tsc;
            if (leaf_0x01.edx_bit( 5u)) result |= msr;
            if (leaf_0x01.edx_bit( 6u)) result |= pae;
            if (leaf_0x01.edx_bit( 7u)) result |= mce;
            if (leaf_0x01.edx_bit( 8u)) result |= cx8;
            if (leaf_0x01.edx_bit( 9u)) result |= apic;
            if (leaf_0x01.edx_bit(11u)) result |= sep;
            if (leaf_0x01.edx_bit(12u)) result |= mtrr;
            if (leaf_0x01.edx_bit(13u)) result |= pge;
            if (leaf_0x01.edx_bit(14u)) result |= mca;
            if (leaf_0x01.edx_bit(15u)) result |= cmov;
            if (leaf_0x01.edx_bit(16u)) result |= pat;
            if (leaf_0x01.edx_bit(17u)) result |= pse_36;
            if (leaf_0x01.edx_bit(18u)) result |= psn;
            if (leaf_0x01.edx_bit(19u)) result |= clfsh;
            if (leaf_0x01.edx_bit(20u)) result |= nx;
            if (leaf_0x01.edx_bit(21u)) result |= ds;
            if (leaf_0x01.edx_bit(22u)) result |= acpi;
            if (leaf_0x01.edx_bit(23u)) result |= mmx;
            if (leaf_0x01.edx_bit(24u)) result |= fxsr;
            if (leaf_0x01.edx_bit(25u)) result |= sse;
            if (leaf_0x01.edx_bit(26u)) result |= sse2;
            if (leaf_0x01.edx_bit(27u)) result |= ss;
            if (leaf_0x01.edx_bit(28u)) result |= htt;
            if (leaf_0x01.edx_bit(29u)) result |= tm;
            if (leaf_0x01.edx_bit(30u)) result |= ia64;
            if (leaf_0x01.edx_bit(31u)) result |= pbe;
        }

        return result;
    }
} // namespace based::platform::x86::detail

