#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// Encrypted Memory Capabilities
// https://en.wikipedia.org/wiki/CPUID#EAX=8000001Fh:_Encrypted_Memory_Capabilities

namespace based::platform::x86::detail {
    enum class cpu_encrypted_memory_feature : std::uint8_t {
        sme,
        sev,
        page_flush_msr,
        sev_es,
        sev_snp,
        vmpl,
        rmpquery,
        vmpl_sss,
        secure_tsc,
        tsc_aux_virtualization,
        hw_enf_cache_coh,
        host_64_bit,
        restricted_injection,
        alternate_injection,
        debug_virt,
        prevent_host_ibs,
        vte,
        vmgexit_parameter,
        virtual_tom_msr,
        ibs_virt_guest_ctl,
        pmc_virt_guest_ctl,
        rmpread,
        guest_intercept_control,
        segmented_rmp,
        vmsa_reg_prot,
        smt_protection,
        secure_avic,
        allowed_sev_features,
        svsm_comm_page_msr,
        nested_virt_snp_msr,
        hv_in_use_wr_allowed,
        ibpb_on_entry
    }; // enum class cpu_encrypted_memory_feature : std::uint8_t

    enum class cpu_encrypted_memory_feature_mask : std::uint32_t {
        sme                     = 1u << std::to_underlying(cpu_encrypted_memory_feature::sme),
        sev                     = 1u << std::to_underlying(cpu_encrypted_memory_feature::sev),
        page_flush_msr          = 1u << std::to_underlying(cpu_encrypted_memory_feature::page_flush_msr),
        sev_es                  = 1u << std::to_underlying(cpu_encrypted_memory_feature::sev_es),
        sev_snp                 = 1u << std::to_underlying(cpu_encrypted_memory_feature::sev_snp),
        vmpl                    = 1u << std::to_underlying(cpu_encrypted_memory_feature::vmpl),
        rmpquery                = 1u << std::to_underlying(cpu_encrypted_memory_feature::rmpquery),
        vmpl_sss                = 1u << std::to_underlying(cpu_encrypted_memory_feature::vmpl_sss),
        secure_tsc              = 1u << std::to_underlying(cpu_encrypted_memory_feature::secure_tsc),
        tsc_aux_virtualization  = 1u << std::to_underlying(cpu_encrypted_memory_feature::tsc_aux_virtualization),
        hw_enf_cache_coh        = 1u << std::to_underlying(cpu_encrypted_memory_feature::hw_enf_cache_coh),
        host_64_bit             = 1u << std::to_underlying(cpu_encrypted_memory_feature::host_64_bit),
        restricted_injection    = 1u << std::to_underlying(cpu_encrypted_memory_feature::restricted_injection),
        alternate_injection     = 1u << std::to_underlying(cpu_encrypted_memory_feature::alternate_injection),
        debug_virt              = 1u << std::to_underlying(cpu_encrypted_memory_feature::debug_virt),
        prevent_host_ibs        = 1u << std::to_underlying(cpu_encrypted_memory_feature::prevent_host_ibs),
        vte                     = 1u << std::to_underlying(cpu_encrypted_memory_feature::vte),
        vmgexit_parameter       = 1u << std::to_underlying(cpu_encrypted_memory_feature::vmgexit_parameter),
        virtual_tom_msr         = 1u << std::to_underlying(cpu_encrypted_memory_feature::virtual_tom_msr),
        ibs_virt_guest_ctl      = 1u << std::to_underlying(cpu_encrypted_memory_feature::ibs_virt_guest_ctl),
        pmc_virt_guest_ctl      = 1u << std::to_underlying(cpu_encrypted_memory_feature::pmc_virt_guest_ctl),
        rmpread                 = 1u << std::to_underlying(cpu_encrypted_memory_feature::rmpread),
        guest_intercept_control = 1u << std::to_underlying(cpu_encrypted_memory_feature::guest_intercept_control),
        segmented_rmp           = 1u << std::to_underlying(cpu_encrypted_memory_feature::segmented_rmp),
        vmsa_reg_prot           = 1u << std::to_underlying(cpu_encrypted_memory_feature::vmsa_reg_prot),
        smt_protection          = 1u << std::to_underlying(cpu_encrypted_memory_feature::smt_protection),
        secure_avic             = 1u << std::to_underlying(cpu_encrypted_memory_feature::secure_avic),
        allowed_sev_features    = 1u << std::to_underlying(cpu_encrypted_memory_feature::allowed_sev_features),
        svsm_comm_page_msr      = 1u << std::to_underlying(cpu_encrypted_memory_feature::svsm_comm_page_msr),
        nested_virt_snp_msr     = 1u << std::to_underlying(cpu_encrypted_memory_feature::nested_virt_snp_msr),
        hv_in_use_wr_allowed    = 1u << std::to_underlying(cpu_encrypted_memory_feature::hv_in_use_wr_allowed),
        ibpb_on_entry           = 1u << std::to_underlying(cpu_encrypted_memory_feature::ibpb_on_entry)
    }; // enum class cpu_encrypted_memory_feature_mask : std::uint32_t

    [[nodiscard]]
    cpu_encrypted_memory_feature_mask supported_cpu_encrypted_memory_features(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_encrypted_memory_feature_mask{};

        if (max_leaf >= 0x8000001F) {
            using enum cpu_encrypted_memory_feature;
            const auto leaf_0x8000001f = cpu_id(0x8000001F, 0x00);

            // eax register
            if (leaf_0x8000001f.eax_bit( 0u)) result |= sme;
            if (leaf_0x8000001f.eax_bit( 1u)) result |= sev;
            if (leaf_0x8000001f.eax_bit( 2u)) result |= page_flush_msr;
            if (leaf_0x8000001f.eax_bit( 3u)) result |= sev_es;
            if (leaf_0x8000001f.eax_bit( 4u)) result |= sev_snp;
            if (leaf_0x8000001f.eax_bit( 5u)) result |= vmpl;
            if (leaf_0x8000001f.eax_bit( 6u)) result |= rmpquery;
            if (leaf_0x8000001f.eax_bit( 7u)) result |= vmpl_sss;
            if (leaf_0x8000001f.eax_bit( 8u)) result |= secure_tsc;
            if (leaf_0x8000001f.eax_bit( 9u)) result |= tsc_aux_virtualization;
            if (leaf_0x8000001f.eax_bit(10u)) result |= hw_enf_cache_coh;
            if (leaf_0x8000001f.eax_bit(11u)) result |= host_64_bit;
            if (leaf_0x8000001f.eax_bit(12u)) result |= restricted_injection;
            if (leaf_0x8000001f.eax_bit(13u)) result |= alternate_injection;
            if (leaf_0x8000001f.eax_bit(14u)) result |= debug_virt;
            if (leaf_0x8000001f.eax_bit(15u)) result |= prevent_host_ibs;
            if (leaf_0x8000001f.eax_bit(16u)) result |= vte;
            if (leaf_0x8000001f.eax_bit(17u)) result |= vmgexit_parameter;
            if (leaf_0x8000001f.eax_bit(18u)) result |= virtual_tom_msr;
            if (leaf_0x8000001f.eax_bit(19u)) result |= ibs_virt_guest_ctl;
            if (leaf_0x8000001f.eax_bit(20u)) result |= pmc_virt_guest_ctl;
            if (leaf_0x8000001f.eax_bit(21u)) result |= rmpread;
            if (leaf_0x8000001f.eax_bit(22u)) result |= guest_intercept_control;
            if (leaf_0x8000001f.eax_bit(23u)) result |= segmented_rmp;
            if (leaf_0x8000001f.eax_bit(24u)) result |= vmsa_reg_prot;
            if (leaf_0x8000001f.eax_bit(25u)) result |= smt_protection;
            if (leaf_0x8000001f.eax_bit(26u)) result |= secure_avic;
            if (leaf_0x8000001f.eax_bit(27u)) result |= allowed_sev_features;
            if (leaf_0x8000001f.eax_bit(28u)) result |= svsm_comm_page_msr;
            if (leaf_0x8000001f.eax_bit(29u)) result |= nested_virt_snp_msr;
            if (leaf_0x8000001f.eax_bit(30u)) result |= hv_in_use_wr_allowed;
            if (leaf_0x8000001f.eax_bit(31u)) result |= ibpb_on_entry;
        }

        return result;
    }
} // namespace based::platform::x86::detail

