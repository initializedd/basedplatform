#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// CPU Extended Advanced Info
// https://en.wikipedia.org/wiki/CPUID#EAX=80000001h:_Extended_Processor_Info_and_Feature_Bits

namespace based::platform::x86::detail {
    enum class cpu_extended_advanced_info : std::uint8_t {
        lahf_lm,
        cmp_legacy,
        svm,
        extapic,
        cr8_legacy,
        abm,
        sse4a,
        misalignsse,
        now3dprefetch, // 3dnowprefetch
        osvw,
        ibs,
        xop,
        skinit,
        wdt,
        // bit 14 reserved
        lwp             = 15u,
        fma4,
        tce,
        // bit 18 reserved
        nodeid_msr      = 19u,
        // bit 20 reserved
        tbm             = 21u,
        topoext,
        perfctr_core,
        perfctr_nb,
        stream_perf_mon,
        dbx,
        perftsc,
        pcx_l2i,
        monitorx,
        addr_mask_ext
        // bit 31 reserved
    }; // enum class cpu_extended_advanced_info : std::uint8_t

    enum class cpu_extended_advanced_info_mask : std::uint32_t {
        lahf_lm         = 1u << std::to_underlying(cpu_extended_advanced_info::lahf_lm),
        cmp_legacy      = 1u << std::to_underlying(cpu_extended_advanced_info::cmp_legacy),
        svm             = 1u << std::to_underlying(cpu_extended_advanced_info::svm),
        extapic         = 1u << std::to_underlying(cpu_extended_advanced_info::extapic),
        cr8_legacy      = 1u << std::to_underlying(cpu_extended_advanced_info::cr8_legacy),
        abm             = 1u << std::to_underlying(cpu_extended_advanced_info::abm),
        sse4a           = 1u << std::to_underlying(cpu_extended_advanced_info::sse4a),
        misalignsse     = 1u << std::to_underlying(cpu_extended_advanced_info::misalignsse),
        now3dprefetch   = 1u << std::to_underlying(cpu_extended_advanced_info::now3dprefetch), // 3dnowprefetch
        osvw            = 1u << std::to_underlying(cpu_extended_advanced_info::osvw),
        ibs             = 1u << std::to_underlying(cpu_extended_advanced_info::ibs),
        xop             = 1u << std::to_underlying(cpu_extended_advanced_info::xop),
        skinit          = 1u << std::to_underlying(cpu_extended_advanced_info::skinit),
        wdt             = 1u << std::to_underlying(cpu_extended_advanced_info::wdt),
        lwp             = 1u << std::to_underlying(cpu_extended_advanced_info::lwp),
        fma4            = 1u << std::to_underlying(cpu_extended_advanced_info::fma4),
        tce             = 1u << std::to_underlying(cpu_extended_advanced_info::tce),
        nodeid_msr      = 1u << std::to_underlying(cpu_extended_advanced_info::nodeid_msr),
        tbm             = 1u << std::to_underlying(cpu_extended_advanced_info::tbm),
        topoext         = 1u << std::to_underlying(cpu_extended_advanced_info::topoext),
        perfctr_core    = 1u << std::to_underlying(cpu_extended_advanced_info::perfctr_core),
        perfctr_nb      = 1u << std::to_underlying(cpu_extended_advanced_info::perfctr_nb),
        stream_perf_mon = 1u << std::to_underlying(cpu_extended_advanced_info::stream_perf_mon),
        dbx             = 1u << std::to_underlying(cpu_extended_advanced_info::dbx),
        perftsc         = 1u << std::to_underlying(cpu_extended_advanced_info::perftsc),
        pcx_l2i         = 1u << std::to_underlying(cpu_extended_advanced_info::pcx_l2i),
        monitorx        = 1u << std::to_underlying(cpu_extended_advanced_info::monitorx),
        addr_mask_ext   = 1u << std::to_underlying(cpu_extended_advanced_info::addr_mask_ext)
    }; // enum class cpu_extended_advanced_info_mask : std::uint32_t

    [[nodiscard]]
    cpu_extended_advanced_info_mask supported_extended_advanced_info(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_extended_advanced_info_mask{};

        if (max_leaf >= 0x80000001) {
            using cpu_extended_advanced_info;
            const auto leaf8 = cpu_id(0x80000001, 0u);

            // ecx register
            if (leaf8.ecx_bit( 0u)) result |= lahf_lm;
            if (leaf8.ecx_bit( 1u)) result |= cmp_legacy;
            if (leaf8.ecx_bit( 2u)) result |= svm;
            if (leaf8.ecx_bit( 3u)) result |= extrapic;
            if (leaf8.ecx_bit( 4u)) result |= cr8_legacy;
            if (leaf8.ecx_bit( 5u)) result |= abm;
            if (leaf8.ecx_bit( 6u)) result |= sse4a;
            if (leaf8.ecx_bit( 7u)) result |= misalignsse;
            if (leaf8.ecx_bit( 8u)) result |= now3dprefetch;
            if (leaf8.ecx_bit( 9u)) result |= osvw;
            if (leaf8.ecx_bit(10u)) result |= ibs;
            if (leaf8.ecx_bit(11u)) result |= xop;
            if (leaf8.ecx_bit(12u)) result |= skinit;
            if (leaf8.ecx_bit(13u)) result |= wdt;
            if (leaf8.ecx_bit(15u)) result |= lwp;
            if (leaf8.ecx_bit(16u)) result |= fma4;
            if (leaf8.ecx_bit(17u)) result |= tce;
            if (leaf8.ecx_bit(19u)) result |= nodeid_msr;
            if (leaf8.ecx_bit(21u)) result |= tbm;
            if (leaf8.ecx_bit(22u)) result |= topoext;
            if (leaf8.ecx_bit(23u)) result |= perfctr_core;
            if (leaf8.ecx_bit(24u)) result |= perfctr_nb;
            if (leaf8.ecx_bit(25u)) result |= stream_perf_mon;
            if (leaf8.ecx_bit(26u)) result |= dbx;
            if (leaf8.ecx_bit(27u)) result |= perftsc;
            if (leaf8.ecx_bit(28u)) result |= pcx_l2i;
            if (leaf8.ecx_bit(29u)) result |= monitorx;
            if (leaf8.ecx_bit(30u)) result |= addr_mask_ext;
        }

        return result;
    }
} // namespace based::platform::x86::detail

