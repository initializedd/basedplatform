#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// CPU Advanced Features
// https://en.wikipedia.org/wiki/CPUID#EAX=1:_Processor_Info_and_Feature_Bits

namespace based::platform::x86::detail {
    enum class cpu_advanced_feature : std::uint8_t {
        sse3,
        pclmulqdq,
        dtes64,
        monitor,
        ds_cpl,
        vmx,
        smx,
        est,
        tm2,
        ssse3,
        cnxt_id,
        sdbg,
        fma,
        cx16,
        xtpr,
        pdcm,
        // bit 16 reserved
        pcid         = 17u,
        dca,
        sse4_1,
        sse4_2,
        x2apic,
        movbe,
        popcnt,
        tsc_deadline,
        aes_ni,
        xsave,
        osxsave,
        avx,
        f16c,
        rdrnd,
        hypervisor
    }; // enum class cpu_advanced_feature : std::uint8_t

    enum class cpu_advanced_feature_mask : std::uint32_t {
        sse3         = 1u << std::to_underlying(cpu_advanced_feature::sse3),
        pclmulqdq    = 1u << std::to_underlying(cpu_advanced_feature::pclmulqdq),
        dtes64       = 1u << std::to_underlying(cpu_advanced_feature::dtes64),
        monitor      = 1u << std::to_underlying(cpu_advanced_feature::monitor),
        ds_cpl       = 1u << std::to_underlying(cpu_advanced_feature::ds_cpl),
        vmx          = 1u << std::to_underlying(cpu_advanced_feature::vmx),
        smx          = 1u << std::to_underlying(cpu_advanced_feature::smx),
        est          = 1u << std::to_underlying(cpu_advanced_feature::est),
        tm2          = 1u << std::to_underlying(cpu_advanced_feature::tm2),
        ssse3        = 1u << std::to_underlying(cpu_advanced_feature::ssse3),
        cnxt_id      = 1u << std::to_underlying(cpu_advanced_feature::cnxt_id),
        sdbg         = 1u << std::to_underlying(cpu_advanced_feature::sdbg),
        fma          = 1u << std::to_underlying(cpu_advanced_feature::fma),
        cx16         = 1u << std::to_underlying(cpu_advanced_feature::cx16),
        xtpr         = 1u << std::to_underlying(cpu_advanced_feature::xtpr),
        pdcm         = 1u << std::to_underlying(cpu_advanced_feature::pdcm),
        pcid         = 1u << std::to_underlying(cpu_advanced_feature::pcid),
        dca          = 1u << std::to_underlying(cpu_advanced_feature::dca),
        sse4_1       = 1u << std::to_underlying(cpu_advanced_feature::sse4_1),
        sse4_2       = 1u << std::to_underlying(cpu_advanced_feature::sse4_2),
        x2apic       = 1u << std::to_underlying(cpu_advanced_feature::x2apic),
        movbe        = 1u << std::to_underlying(cpu_advanced_feature::movbe),
        popcnt       = 1u << std::to_underlying(cpu_advanced_feature::popcnt),
        tsc_deadline = 1u << std::to_underlying(cpu_advanced_feature::tsc_deadline),
        aes_ni       = 1u << std::to_underlying(cpu_advanced_feature::aes_ni),
        xsave        = 1u << std::to_underlying(cpu_advanced_feature::xsave),
        osxsave      = 1u << std::to_underlying(cpu_advanced_feature::osxsave),
        avx          = 1u << std::to_underlying(cpu_advanced_feature::avx),
        f16c         = 1u << std::to_underlying(cpu_advanced_feature::f16c),
        rdrnd        = 1u << std::to_underlying(cpu_advanced_feature::rdrnd),
        hypervisor   = 1u << std::to_underlying(cpu_advanced_feature::hypervisor)
    }; // enum class cpu_advanced_feature_mask : std::uint32_t

    [[nodiscard]]
    cpu_advanced_feature_mask supported_cpu_advanced_features(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_advanced_feature_mask{};

        if (max_leaf >= 0x01) {
            using enum cpu_advanced_feature;
            const auto leaf_0x01 = cpu_id(0x01, 0x00);

            // ecx register
            if (leaf_0x01.ecx_bit( 0u)) result |= sse3;
            if (leaf_0x01.ecx_bit( 1u)) result |= pclmulqdq;
            if (leaf_0x01.ecx_bit( 2u)) result |= dtes64;
            if (leaf_0x01.ecx_bit( 3u)) result |= monitor;
            if (leaf_0x01.ecx_bit( 4u)) result |= ds_cpl;
            if (leaf_0x01.ecx_bit( 5u)) result |= vmx;
            if (leaf_0x01.ecx_bit( 6u)) result |= smx;
            if (leaf_0x01.ecx_bit( 7u)) result |= est;
            if (leaf_0x01.ecx_bit( 8u)) result |= tm2;
            if (leaf_0x01.ecx_bit( 9u)) result |= ssse3;
            if (leaf_0x01.ecx_bit(10u)) result |= cnxt_id;
            if (leaf_0x01.ecx_bit(11u)) result |= sdbg;
            if (leaf_0x01.ecx_bit(12u)) result |= fma;
            if (leaf_0x01.ecx_bit(13u)) result |= cx16;
            if (leaf_0x01.ecx_bit(14u)) result |= xtpr;
            if (leaf_0x01.ecx_bit(15u)) result |= pdcm;
            if (leaf_0x01.ecx_bit(17u)) result |= pcid;
            if (leaf_0x01.ecx_bit(18u)) result |= dca;
            if (leaf_0x01.ecx_bit(19u)) result |= sse4_1;
            if (leaf_0x01.ecx_bit(20u)) result |= sse4_2;
            if (leaf_0x01.ecx_bit(21u)) result |= x2apic;
            if (leaf_0x01.ecx_bit(22u)) result |= movbe;
            if (leaf_0x01.ecx_bit(23u)) result |= popcnt;
            if (leaf_0x01.ecx_bit(24u)) result |= tsc_deadline;
            if (leaf_0x01.ecx_bit(25u)) result |= aes_ni;
            if (leaf_0x01.ecx_bit(26u)) result |= xsave;
            if (leaf_0x01.ecx_bit(27u)) result |= osxsave;
            if (leaf_0x01.ecx_bit(28u)) result |= avx;
            if (leaf_0x01.ecx_bit(29u)) result |= f16c;
            if (leaf_0x01.ecx_bit(30u)) result |= rdrnd;
            if (leaf_0x01.ecx_bit(31u)) result |= hypervisor;
        }

        return result;
    }
} // namespace based::platform::x86::detail

