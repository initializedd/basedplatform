#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// CPU Core Features
// https://en.wikipedia.org/wiki/CPUID#EAX=1:_Processor_Info_and_Feature_Bits

namespace based::platform::x86::detail {
    enum class cpu_core_feature : std::uint8_t {
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
    }; // enum class cpu_core_feature : std::uint8_t

    enum class cpu_core_feature_mask : std::uint32_t {
        sse3         = 1u << std::to_underlying(cpu_core_feature::sse3),
        pclmulqdq    = 1u << std::to_underlying(cpu_core_feature::pclmulqdq),
        dtes64       = 1u << std::to_underlying(cpu_core_feature::dtes64),
        monitor      = 1u << std::to_underlying(cpu_core_feature::monitor),
        ds_cpl       = 1u << std::to_underlying(cpu_core_feature::ds_cpl),
        vmx          = 1u << std::to_underlying(cpu_core_feature::vmx),
        smx          = 1u << std::to_underlying(cpu_core_feature::smx),
        est          = 1u << std::to_underlying(cpu_core_feature::est),
        tm2          = 1u << std::to_underlying(cpu_core_feature::tm2),
        ssse3        = 1u << std::to_underlying(cpu_core_feature::ssse3),
        cnxt_id      = 1u << std::to_underlying(cpu_core_feature::cnxt_id),
        sdbg         = 1u << std::to_underlying(cpu_core_feature::sdbg),
        fma          = 1u << std::to_underlying(cpu_core_feature::fma),
        cx16         = 1u << std::to_underlying(cpu_core_feature::cx16),
        xtpr         = 1u << std::to_underlying(cpu_core_feature::xtpr),
        pdcm         = 1u << std::to_underlying(cpu_core_feature::pdcm),
        pcid         = 1u << std::to_underlying(cpu_core_feature::pcid),
        dca          = 1u << std::to_underlying(cpu_core_feature::dca),
        sse4_1       = 1u << std::to_underlying(cpu_core_feature::sse4_1),
        sse4_2       = 1u << std::to_underlying(cpu_core_feature::sse4_2),
        x2apic       = 1u << std::to_underlying(cpu_core_feature::x2apic),
        movbe        = 1u << std::to_underlying(cpu_core_feature::movbe),
        popcnt       = 1u << std::to_underlying(cpu_core_feature::popcnt),
        tsc_deadline = 1u << std::to_underlying(cpu_core_feature::tsc_deadline),
        aes_ni       = 1u << std::to_underlying(cpu_core_feature::aes_ni),
        xsave        = 1u << std::to_underlying(cpu_core_feature::xsave),
        osxsave      = 1u << std::to_underlying(cpu_core_feature::osxsave),
        avx          = 1u << std::to_underlying(cpu_core_feature::avx),
        f16c         = 1u << std::to_underlying(cpu_core_feature::f16c),
        rdrnd        = 1u << std::to_underlying(cpu_core_feature::rdrnd),
        hypervisor   = 1u << std::to_underlying(cpu_core_feature::hypervisor)
    }; // enum class cpu_core_feature_mask : std::uint32_t

    [[nodiscard]]
    cpu_core_feature_mask supported_cpu_core_features(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_core_feature_mask{};

        if (max_leaf >= 1u) {
            using cpu_core_feature;
            const auto leaf1 = cpu_id(0x01, 0u);

            // ecx register
            if (leaf1.ecx_bit( 0u)) result |= sse3;
            if (leaf1.ecx_bit( 1u)) result |= pclmulqdq;
            if (leaf1.ecx_bit( 2u)) result |= dtes64;
            if (leaf1.ecx_bit( 3u)) result |= monitor;
            if (leaf1.ecx_bit( 4u)) result |= ds_cpl;
            if (leaf1.ecx_bit( 5u)) result |= vmx;
            if (leaf1.ecx_bit( 6u)) result |= smx;
            if (leaf1.ecx_bit( 7u)) result |= est;
            if (leaf1.ecx_bit( 8u)) result |= tm2;
            if (leaf1.ecx_bit( 9u)) result |= ssse3;
            if (leaf1.ecx_bit(10u)) result |= cnxt_id;
            if (leaf1.ecx_bit(11u)) result |= sdbg;
            if (leaf1.ecx_bit(12u)) result |= fma;
            if (leaf1.ecx_bit(13u)) result |= cx16;
            if (leaf1.ecx_bit(14u)) result |= xtpr;
            if (leaf1.ecx_bit(15u)) result |= pdcm;
            if (leaf1.ecx_bit(17u)) result |= pcid;
            if (leaf1.ecx_bit(18u)) result |= dca;
            if (leaf1.ecx_bit(19u)) result |= sse4_1;
            if (leaf1.ecx_bit(20u)) result |= sse4_2;
            if (leaf1.ecx_bit(21u)) result |= x2apic;
            if (leaf1.ecx_bit(22u)) result |= movbe;
            if (leaf1.ecx_bit(23u)) result |= popcnt;
            if (leaf1.ecx_bit(24u)) result |= tsc_deadline;
            if (leaf1.ecx_bit(25u)) result |= aes_ni;
            if (leaf1.ecx_bit(26u)) result |= xsave;
            if (leaf1.ecx_bit(27u)) result |= osxsave;
            if (leaf1.ecx_bit(28u)) result |= avx;
            if (leaf1.ecx_bit(29u)) result |= f16c;
            if (leaf1.ecx_bit(30u)) result |= rdrnd;
            if (leaf1.ecx_bit(31u)) result |= hypervisor;
        }

        return result;
    }
} // namespace based::platform::x86::detail

