#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

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
        // bit 12 reserved
        prefetch_ctl_msr                     = 13u,
        // bits 16:14 reserved
        cpuid_user_dis                       = 17u,
        epsf,
        // bits 26:19 reserved
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
        prefetch_ctl_msr                     = 1u << std::to_underlying(cpu_extended_feature_identification::prefetch_ctl_msr),
        cpuid_user_dis                       = 1u << std::to_underlying(cpu_extended_feature_identification::cpuid_user_dis),
        epsf                                 = 1u << std::to_underlying(cpu_extended_feature_identification::epsf),
        sbpb                                 = 1u << std::to_underlying(cpu_extended_feature_identification::sbpb),
        ibpb_brtype                          = 1u << std::to_underlying(cpu_extended_feature_identification::ibpb_brtype),
        srso_no                              = 1u << std::to_underlying(cpu_extended_feature_identification::srso_no),
        srso_user_kernel_no                  = 1u << std::to_underlying(cpu_extended_feature_identification::srso_user_kernel_no),
        srso_msr_fix                         = 1u << std::to_underlying(cpu_extended_feature_identification::srso_msr_fix)
    }; // enum class cpu_extended_feature_identification_mask : std::uint32_t

    [[nodiscard]]
    cpu_extended_feature_identification_mask supported_cpu_extended_feature_identifications(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_extended_feature_identification_mask{};

        if (max_leaf >= 0x80000021) {
            using enum cpu_extended_feature_identification;
            const auto leaf8 = cpu_id(0x80000021, 0x00);

            // eax register
            if (leaf8.eax_bit( 0u)) result |= no_nested_data_bp;
            if (leaf8.eax_bit( 1u)) result |= fs_gs_kernel_gs_base_non_serializing;
            if (leaf8.eax_bit( 2u)) result |= lfence_always_serializing;
            if (leaf8.eax_bit( 3u)) result |= smm_pg_cfg_lock;
            if (leaf8.eax_bit( 6u)) result |= null_select_clears_base;
            if (leaf8.eax_bit( 7u)) result |= upper_address_ignore;
            if (leaf8.eax_bit( 8u)) result |= automatic_ibrs;
            if (leaf8.eax_bit( 9u)) result |= no_smm_ctl_msr;
            if (leaf8.eax_bit(10u)) result |= fsrs;
            if (leaf8.eax_bit(11u)) result |= fsrc;
            if (leaf8.eax_bit(13u)) result |= prefetch_ctl_msr;
            if (leaf8.eax_bit(17u)) result |= cpuid_user_dis;
            if (leaf8.eax_bit(18u)) result |= epsf;
            if (leaf8.eax_bit(27u)) result |= sbpb;
            if (leaf8.eax_bit(28u)) result |= ibpb_brtype;
            if (leaf8.eax_bit(29u)) result |= srso_no;
            if (leaf8.eax_bit(30u)) result |= srso_user_kernel_no;
            if (leaf8.eax_bit(31u)) result |= srso_msr_fix;
        }

        return result;
    }
} // namespace based::platform::x86::detail

