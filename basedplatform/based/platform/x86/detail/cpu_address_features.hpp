#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// Virtual and Physical Address Features
// https://en.wikipedia.org/wiki/CPUID#EAX=80000008h:_Virtual_and_Physical_address_Sizes

namespace based::platform::x86::detail {
    enum class cpu_address_feature : std::uint8_t {
        clzero,
        retired_instr,
        xrstor_fp_err,
        invlpgb,
        rdpru,
        // bit 5 reserved
        mbe                       = 6u,
        // bit 7 reserved
        mcommit                   = 8u,
        wbnoinvd,
        // bits 11:10 reserved
        ibpb                      = 12u,
        wbinvd_int,
        ibrs,
        stibp,
        ibrs_always_on,
        stibp_always_on,
        ibrs_preferred,
        ibrs_same_mode_protection,
        no_efer_lmsle,
        invlpgb_nested,
        // bit 22 reserved
        ppin                      = 23u,
        ssbd,
        ssbd_legacy,
        ssbd_no,
        cppc,
        psfd,
        btc_no,
        ibpb_ret,
        branch_sampling
    }; // enum class cpu_address_feature : std::uint8_t

    enum class cpu_address_feature_mask : std::uint32_t {
        clzero                    = 1u << std::to_underlying(cpu_address_feature::clzero),
        retired_instr             = 1u << std::to_underlying(cpu_address_feature::retired_instr),
        xrstor_fp_err             = 1u << std::to_underlying(cpu_address_feature::xrstor_fp_err),
        invlpgb                   = 1u << std::to_underlying(cpu_address_feature::invlpgb),
        rdpru                     = 1u << std::to_underlying(cpu_address_feature::rdpru),
        mbe                       = 1u << std::to_underlying(cpu_address_feature::mbe),
        mcommit                   = 1u << std::to_underlying(cpu_address_feature::mcommit),
        wbnoinvd                  = 1u << std::to_underlying(cpu_address_feature::wbnoinvd),
        ibpb                      = 1u << std::to_underlying(cpu_address_feature::ibpb),
        wbinvd_int                = 1u << std::to_underlying(cpu_address_feature::wbinvd_int),
        ibrs                      = 1u << std::to_underlying(cpu_address_feature::ibrs),
        stibp                     = 1u << std::to_underlying(cpu_address_feature::stibp),
        ibrs_always_on            = 1u << std::to_underlying(cpu_address_feature::ibrs_always_on),
        stibp_always_on           = 1u << std::to_underlying(cpu_address_feature::stibp_always_on),
        ibrs_preferred            = 1u << std::to_underlying(cpu_address_feature::ibrs_preferred),
        ibrs_same_mode_protection = 1u << std::to_underlying(cpu_address_feature::ibrs_same_mode_protection),
        no_efer_lmsle             = 1u << std::to_underlying(cpu_address_feature::no_efer_lmsle),
        invlpgb_nested            = 1u << std::to_underlying(cpu_address_feature::invlpgb_nested),
        ppin                      = 1u << std::to_underlying(cpu_address_feature::ppin),
        ssbd                      = 1u << std::to_underlying(cpu_address_feature::ssbd),
        ssbd_legacy               = 1u << std::to_underlying(cpu_address_feature::ssbd_legacy),
        ssbd_no                   = 1u << std::to_underlying(cpu_address_feature::ssbd_no),
        cppc                      = 1u << std::to_underlying(cpu_address_feature::cppc),
        psfd                      = 1u << std::to_underlying(cpu_address_feature::psfd),
        btc_no                    = 1u << std::to_underlying(cpu_address_feature::btc_no),
        ibpb_ret                  = 1u << std::to_underlying(cpu_address_feature::ibpb_ret),
        branch_sampling           = 1u << std::to_underlying(cpu_address_feature::branch_sampling)
    }; // enum class cpu_address_feature_mask : std::uint32_t

    [[nodiscard]]
    cpu_address_feature_mask supported_cpu_address_features(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_address_feature_mask{};

        if (max_leaf >= 0x80000008) {
            using cpu_address_feature;
            const auto leaf8 = cpu_id(0x80000008, 0u);

            // ebx register
            if (leaf8.ebx_bit( 0u)) result |= clzero;
            if (leaf8.ebx_bit( 1u)) result |= retired_instr;
            if (leaf8.ebx_bit( 2u)) result |= xrstor_fp_err;
            if (leaf8.ebx_bit( 3u)) result |= invlpgb;
            if (leaf8.ebx_bit( 4u)) result |= rdpru;
            if (leaf8.ebx_bit( 6u)) result |= mbe;
            if (leaf8.ebx_bit( 8u)) result |= mcommit;
            if (leaf8.ebx_bit( 9u)) result |= wbnoinvd;
            if (leaf8.ebx_bit(12u)) result |= ibpb;
            if (leaf8.ebx_bit(13u)) result |= wbinvd_int;
            if (leaf8.ebx_bit(14u)) result |= ibrs;
            if (leaf8.ebx_bit(15u)) result |= stibp;
            if (leaf8.ebx_bit(16u)) result |= ibrs_always_on;
            if (leaf8.ebx_bit(17u)) result |= stibp_always_on;
            if (leaf8.ebx_bit(18u)) result |= ibrs_preferred;
            if (leaf8.ebx_bit(19u)) result |= ibrs_same_mode_protection;
            if (leaf8.ebx_bit(20u)) result |= no_efer_lmsle;
            if (leaf8.ebx_bit(21u)) result |= invlpgb_nested;
            if (leaf8.ebx_bit(23u)) result |= ppin;
            if (leaf8.ebx_bit(24u)) result |= ssbd;
            if (leaf8.ebx_bit(25u)) result |= ssbd_legacy;
            if (leaf8.ebx_bit(26u)) result |= ssbd_no;
            if (leaf8.ebx_bit(27u)) result |= cppc;
            if (leaf8.ebx_bit(28u)) result |= psfd;
            if (leaf8.ebx_bit(29u)) result |= btc_no;
            if (leaf8.ebx_bit(30u)) result |= ibpb_ret;
            if (leaf8.ebx_bit(31u)) result |= branch_sampling;
        }

        return result;
    }
} // namespace based::platform::x86::detail

