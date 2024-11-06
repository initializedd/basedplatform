#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"
#include "../../util.hpp"

// Extended Feature Identification 2
// https://en.wikipedia.org/wiki/CPUID#EAX=80000021h:_Extended_Feature_Identification_2

namespace based::platform::x86::detail {
    enum class cpu_extended_feature_identification : std::uint8_t {
        no_nested_data_bp,
        fs_gs_kernel_gs_base_non_serializing,
        lfence_always_serializing,
        smm_pg_cfg_lock,
        // bits 5:4 reserved
        null_select_clears_base              = 6u,
        upper_address_ignore,
        automatic_ibrs,
        no_smm_ctl_msr,
        fsrs,
        fsrc,
        pmc2_precise_retire,
        prefetch_ctl_msr,
        l2_tlb_size_x32,
        amd_ermsb,
        opcode_0f017_reclaim,
        cpuid_user_dis,
        epsf,
        fast_rep_scasb,
        prefetchi,
        fp512_downgrade,
        wl_class_support,
        // bit 23 reserved
        eraps                                = 24u,
        // bits 26:25 reserved
        sbpb                                 = 27u,
        ibpb_brtype,
        srso_no,
        srso_user_kernel_no,
        srso_msr_fix
    }; // enum class cpu_extended_feature_identification : std::uint8_t

    enum class cpu_extended_feature_identification_mask : std::uint32_t {
        no_nested_data_bp                    = 1u << std::to_underlying(cpu_extended_feature_identification::no_nested_data_bp),
        fs_gs_kernel_gs_base_non_serializing = 1u << std::to_underlying(cpu_extended_feature_identification::fs_gs_kernel_gs_base_non_serializing),
        lfence_always_serializing            = 1u << std::to_underlying(cpu_extended_feature_identification::lfence_always_serializing),
        smm_pg_cfg_lock                      = 1u << std::to_underlying(cpu_extended_feature_identification::smm_pg_cfg_lock),
        null_select_clears_base              = 1u << std::to_underlying(cpu_extended_feature_identification::null_select_clears_base),
        upper_address_ignore                 = 1u << std::to_underlying(cpu_extended_feature_identification::upper_address_ignore),
        automatic_ibrs                       = 1u << std::to_underlying(cpu_extended_feature_identification::automatic_ibrs),
        no_smm_ctl_msr                       = 1u << std::to_underlying(cpu_extended_feature_identification::no_smm_ctl_msr),
        fsrs                                 = 1u << std::to_underlying(cpu_extended_feature_identification::fsrs),
        fsrc                                 = 1u << std::to_underlying(cpu_extended_feature_identification::fsrc),
        pmc2_precise_retire                  = 1u << std::to_underlying(cpu_extended_feature_identification::pmc2_precise_retire),
        prefetch_ctl_msr                     = 1u << std::to_underlying(cpu_extended_feature_identification::prefetch_ctl_msr),
        l2_tlb_size_x32                      = 1u << std::to_underlying(cpu_extended_feature_identification::l2_tlb_size_x32),
        amd_ermsb                            = 1u << std::to_underlying(cpu_extended_feature_identification::amd_ermsb),
        opcode_0f017_reclaim                 = 1u << std::to_underlying(cpu_extended_feature_identification::opcode_0f017_reclaim),
        cpuid_user_dis                       = 1u << std::to_underlying(cpu_extended_feature_identification::cpuid_user_dis),
        epsf                                 = 1u << std::to_underlying(cpu_extended_feature_identification::epsf),
        fast_rep_scasb                       = 1u << std::to_underlying(cpu_extended_feature_identification::fast_rep_scasb),
        prefetchi                            = 1u << std::to_underlying(cpu_extended_feature_identification::prefetchi),
        fp512_downgrade                      = 1u << std::to_underlying(cpu_extended_feature_identification::fp512_downgrade),
        wl_class_support                     = 1u << std::to_underlying(cpu_extended_feature_identification::wl_class_support),
        eraps                                = 1u << std::to_underlying(cpu_extended_feature_identification::eraps),
        sbpb                                 = 1u << std::to_underlying(cpu_extended_feature_identification::sbpb),
        ibpb_brtype                          = 1u << std::to_underlying(cpu_extended_feature_identification::ibpb_brtype),
        srso_no                              = 1u << std::to_underlying(cpu_extended_feature_identification::srso_no),
        srso_user_kernel_no                  = 1u << std::to_underlying(cpu_extended_feature_identification::srso_user_kernel_no),
        srso_msr_fix                         = 1u << std::to_underlying(cpu_extended_feature_identification::srso_msr_fix)
    }; // enum class cpu_extended_feature_identification_mask : std::uint32_t

    [[nodiscard]]
    inline cpu_extended_feature_identification_mask supported_cpu_extended_feature_identifications(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_extended_feature_identification_mask{};

        if (max_leaf >= 0x80000021) {
            using enum cpu_extended_feature_identification;
            const auto leaf_0x80000021 = cpu_id(0x80000021, 0x00);

            // eax register
            if (leaf_0x80000021.eax_bit( 0u)) result |= no_nested_data_bp;
            if (leaf_0x80000021.eax_bit( 1u)) result |= fs_gs_kernel_gs_base_non_serializing;
            if (leaf_0x80000021.eax_bit( 2u)) result |= lfence_always_serializing;
            if (leaf_0x80000021.eax_bit( 3u)) result |= smm_pg_cfg_lock;
            if (leaf_0x80000021.eax_bit( 6u)) result |= null_select_clears_base;
            if (leaf_0x80000021.eax_bit( 7u)) result |= upper_address_ignore;
            if (leaf_0x80000021.eax_bit( 8u)) result |= automatic_ibrs;
            if (leaf_0x80000021.eax_bit( 9u)) result |= no_smm_ctl_msr;
            if (leaf_0x80000021.eax_bit(10u)) result |= fsrs;
            if (leaf_0x80000021.eax_bit(11u)) result |= fsrc;
            if (leaf_0x80000021.eax_bit(12u)) result |= pmc2_precise_retire;
            if (leaf_0x80000021.eax_bit(13u)) result |= prefetch_ctl_msr;
            if (leaf_0x80000021.eax_bit(14u)) result |= l2_tlb_size_x32;
            if (leaf_0x80000021.eax_bit(15u)) result |= amd_ermsb;
            if (leaf_0x80000021.eax_bit(16u)) result |= opcode_0f017_reclaim;
            if (leaf_0x80000021.eax_bit(17u)) result |= cpuid_user_dis;
            if (leaf_0x80000021.eax_bit(18u)) result |= epsf;
            if (leaf_0x80000021.eax_bit(19u)) result |= fast_rep_scasb;
            if (leaf_0x80000021.eax_bit(20u)) result |= prefetchi;
            if (leaf_0x80000021.eax_bit(21u)) result |= fp512_downgrade;
            if (leaf_0x80000021.eax_bit(22u)) result |= wl_class_support;
            if (leaf_0x80000021.eax_bit(24u)) result |= eraps;
            if (leaf_0x80000021.eax_bit(27u)) result |= sbpb;
            if (leaf_0x80000021.eax_bit(28u)) result |= ibpb_brtype;
            if (leaf_0x80000021.eax_bit(29u)) result |= srso_no;
            if (leaf_0x80000021.eax_bit(30u)) result |= srso_user_kernel_no;
            if (leaf_0x80000021.eax_bit(31u)) result |= srso_msr_fix;
        }

        return result;
    }
} // namespace based::platform::x86::detail

