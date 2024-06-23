#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// Secure Virtual Machine features
// https://en.wikipedia.org/wiki/CPUID#EAX=8000000Ah:_Secure_Virtual_Machine_features

namespace based::platform::x86::detail {
    enum class cpu_svm_feature : std::uint8_t {
        np,
        lbr_virt,
        svml,
        nrips,
        tsc_rate_msr,
        vmcb_clean,
        flush_by_asid,
        decode_assist,
        pmc_virt,
        // bit 9 reserved
        pause_filter             = 10u,
        // bit 11 reserved
        pause_filter_threshold   = 12u,
        avic,
        // bit 14 reserved
        vmsave_virt              = 15u,
        vgif,
        gmet,
        x2avic,
        sss_check,
        spec_ctrl,
        rogpt,
        // bit 22 reserved
        host_mce_override        = 23u,
        tlbi_ctl,
        vnmi,
        ibs_virt,
        ext_lvt_offset_fault_chg,
        vmcb_addr_chk_chg,
        bus_lock_threshold,
        idle_hlt_intercept
        // bit 31 reserved
    }; // enum class cpu_svm_feature : std::uint8_t

    enum class cpu_svm_feature_mask : std::uint32_t {
        np                       = 1u << std::to_underlying(cpu_svm_feature::np),
        lbr_virt                 = 1u << std::to_underlying(cpu_svm_feature::lbr_virt),
        svml                     = 1u << std::to_underlying(cpu_svm_feature::svml),
        nrips                    = 1u << std::to_underlying(cpu_svm_feature::nrips),
        tsc_rate_msr             = 1u << std::to_underlying(cpu_svm_feature::tsc_rate_msr),
        vmcb_clean               = 1u << std::to_underlying(cpu_svm_feature::vmcb_clean),
        flush_by_asid            = 1u << std::to_underlying(cpu_svm_feature::flush_by_asid),
        decode_assist            = 1u << std::to_underlying(cpu_svm_feature::decode_assist),
        pmc_virt                 = 1u << std::to_underlying(cpu_svm_feature::pmc_virt),
        pause_filter             = 1u << std::to_underlying(cpu_svm_feature::pause_filter),
        pause_filter_threshold   = 1u << std::to_underlying(cpu_svm_feature::pause_filter_threshold),
        avic                     = 1u << std::to_underlying(cpu_svm_feature::avic),
        vmsave_virt              = 1u << std::to_underlying(cpu_svm_feature::vmsave_virt),
        vgif                     = 1u << std::to_underlying(cpu_svm_feature::vgif),
        gmet                     = 1u << std::to_underlying(cpu_svm_feature::gmet),
        x2avic                   = 1u << std::to_underlying(cpu_svm_feature::x2avic),
        sss_check                = 1u << std::to_underlying(cpu_svm_feature::sss_check),
        spec_ctrl                = 1u << std::to_underlying(cpu_svm_feature::spec_ctrl),
        rogpt                    = 1u << std::to_underlying(cpu_svm_feature::rogpt),
        host_mce_override        = 1u << std::to_underlying(cpu_svm_feature::host_mce_override),
        tlbi_ctl                 = 1u << std::to_underlying(cpu_svm_feature::tlbi_ctl),
        vnmi                     = 1u << std::to_underlying(cpu_svm_feature::vnmi),
        ibs_virt                 = 1u << std::to_underlying(cpu_svm_feature::ibs_virt),
        ext_lvt_offset_fault_chg = 1u << std::to_underlying(cpu_svm_feature::ext_lvt_offset_fault_chg),
        vmcb_addr_chk_chg        = 1u << std::to_underlying(cpu_svm_feature::vmcb_addr_chk_chg),
        bus_lock_threshold       = 1u << std::to_underlying(cpu_svm_feature::bus_lock_threshold),
        idle_hlt_intercept       = 1u << std::to_underlying(cpu_svm_feature::idle_hlt_intercept)
    }; // enum class cpu_svm_feature_mask : std::uint32_t

    [[nodiscard]]
    cpu_svm_feature_mask supported_cpu_svm_features(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_svm_feature_mask{};

        if (max_leaf >= 0x8000000A) {
            using cpu_svm_feature;
            const auto leaf8 = cpu_id(0x8000000A, 0u);

            // edx register
            if (leaf8.edx_bit( 0u)) result |= dp;
            if (leaf8.edx_bit( 1u)) result |= lbr_virt;
            if (leaf8.edx_bit( 2u)) result |= svml;
            if (leaf8.edx_bit( 3u)) result |= nrips;
            if (leaf8.edx_bit( 4u)) result |= tsc_rate_msr;
            if (leaf8.edx_bit( 5u)) result |= vmcb_clean;
            if (leaf8.edx_bit( 6u)) result |= flush_by_asid;
            if (leaf8.edx_bit( 7u)) result |= decode_assist;
            if (leaf8.edx_bit( 8u)) result |= pmc_virt;
            if (leaf8.edx_bit(10u)) result |= pause_filter;
            if (leaf8.edx_bit(12u)) result |= pause_filter_threshold;
            if (leaf8.edx_bit(13u)) result |= avic;
            if (leaf8.edx_bit(15u)) result |= vmsave_virt;
            if (leaf8.edx_bit(16u)) result |= vgif;
            if (leaf8.edx_bit(17u)) result |= gmet;
            if (leaf8.edx_bit(18u)) result |= x2avic;
            if (leaf8.edx_bit(19u)) result |= sss_check;
            if (leaf8.edx_bit(20u)) result |= spec_ctrl;
            if (leaf8.edx_bit(21u)) result |= rogpt;
            if (leaf8.edx_bit(23u)) result |= host_mce_override;
            if (leaf8.edx_bit(24u)) result |= tlbi_ctl;
            if (leaf8.edx_bit(25u)) result |= vnmi;
            if (leaf8.edx_bit(26u)) result |= ibs_virt;
            if (leaf8.edx_bit(27u)) result |= ext_lvt_offset_fault_chg;
            if (leaf8.edx_bit(28u)) result |= vmcb_addr_chk_chg;
            if (leaf8.edx_bit(29u)) result |= bus_lock_threshold;
            if (leaf8.edx_bit(30u)) result |= idle_hlt_intercept;
        }

        return result;
    }
} // namespace based::platform::x86::detail

