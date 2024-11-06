#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"
#include "../../util.hpp"

// CPU Extended Intricate Features
// https://en.wikipedia.org/wiki/CPUID#EAX=7,_ECX=0:_Extended_Features

namespace based::platform::x86::detail {
    enum class cpu_extended_intricate_feature : std::uint8_t {
        sgx_tem,
        sgx_keys,
        avx512_4vnniw,
        avx512_4fmaps,
        fsrm,
        uintr,
        // bits 7:6 reserved
        avx512_vp2intersect = 8u,
        srbds_ctrl,
        md_clear,
        rtm_always_abort,
        // bit 12 reserved
        tsx_force_abort     = 13u,
        serialize,
        hybrid,
        tsxldtrk,
        // bit 17 reserved
        pconfig             = 18u,
        lbr,
        cet_ibt,
        // bit 21 reserved
        amx_bf16            = 22u,
        avx512_fp16,
        amx_tile,
        amx_int8,
        ibrs,
        stibp,
        l1d_flush,
        arch_capabilities,
        core_capabilities,
        ssbd
    }; // enum class cpu_extended_intricate_feature : std::uint8_t

    enum class cpu_extended_intricate_feature_mask : std::uint32_t {
        sgx_tem             = 1u << std::to_underlying(cpu_extended_intricate_feature::sgx_tem),
        sgx_keys            = 1u << std::to_underlying(cpu_extended_intricate_feature::sgx_keys),
        avx512_4vnniw       = 1u << std::to_underlying(cpu_extended_intricate_feature::avx512_4vnniw),
        avx512_4fmaps       = 1u << std::to_underlying(cpu_extended_intricate_feature::avx512_4fmaps),
        fsrm                = 1u << std::to_underlying(cpu_extended_intricate_feature::fsrm),
        uintr               = 1u << std::to_underlying(cpu_extended_intricate_feature::uintr),
        avx512_vp2intersect = 1u << std::to_underlying(cpu_extended_intricate_feature::avx512_vp2intersect),
        srbds_ctrl          = 1u << std::to_underlying(cpu_extended_intricate_feature::srbds_ctrl),
        md_clear            = 1u << std::to_underlying(cpu_extended_intricate_feature::md_clear),
        rtm_always_abort    = 1u << std::to_underlying(cpu_extended_intricate_feature::rtm_always_abort),
        tsx_force_abort     = 1u << std::to_underlying(cpu_extended_intricate_feature::tsx_force_abort),
        serialize           = 1u << std::to_underlying(cpu_extended_intricate_feature::serialize),
        hybrid              = 1u << std::to_underlying(cpu_extended_intricate_feature::hybrid),
        tsxldtrk            = 1u << std::to_underlying(cpu_extended_intricate_feature::tsxldtrk),
        pconfig             = 1u << std::to_underlying(cpu_extended_intricate_feature::pconfig),
        lbr                 = 1u << std::to_underlying(cpu_extended_intricate_feature::lbr),
        cet_ibt             = 1u << std::to_underlying(cpu_extended_intricate_feature::cet_ibt),
        amx_bf16            = 1u << std::to_underlying(cpu_extended_intricate_feature::amx_bf16),
        avx512_fp16         = 1u << std::to_underlying(cpu_extended_intricate_feature::avx512_fp16),
        amx_tile            = 1u << std::to_underlying(cpu_extended_intricate_feature::amx_tile),
        amx_int8            = 1u << std::to_underlying(cpu_extended_intricate_feature::amx_int8),
        ibrs                = 1u << std::to_underlying(cpu_extended_intricate_feature::ibrs),
        stibp               = 1u << std::to_underlying(cpu_extended_intricate_feature::stibp),
        l1d_flush           = 1u << std::to_underlying(cpu_extended_intricate_feature::l1d_flush),
        arch_capabilities   = 1u << std::to_underlying(cpu_extended_intricate_feature::arch_capabilities),
        core_capabilities   = 1u << std::to_underlying(cpu_extended_intricate_feature::core_capabilities),
        ssbd                = 1u << std::to_underlying(cpu_extended_intricate_feature::ssbd)
    }; // enum class cpu_extended_intricate_feature_mask : std::uint32_t

    [[nodiscard]]
    inline cpu_extended_intrcate_feature_mask supported_extended_intricate_features(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_extended_intricate_feature_mask{};

        if (max_leaf >= 0x07) {
            using enum cpu_extended_intricate_feature;
            const auto leaf_0x07 = cpu_id(0x07, 0x00);

            // edx register
            if (leaf_0x07.edx_bit( 0u)) result |= sgx_tem;
            if (leaf_0x07.edx_bit( 1u)) result |= sgx_keys;
            if (leaf_0x07.edx_bit( 2u)) result |= avx512_4vnniw;
            if (leaf_0x07.edx_bit( 3u)) result |= avx512_4fmaps;
            if (leaf_0x07.edx_bit( 4u)) result |= fsrm;
            if (leaf_0x07.edx_bit( 5u)) result |= uintr;
            if (leaf_0x07.edx_bit( 8u)) result |= avx512_vp2intersect;
            if (leaf_0x07.edx_bit( 9u)) result |= srbds_ctrl;
            if (leaf_0x07.edx_bit(10u)) result |= md_clear;
            if (leaf_0x07.edx_bit(11u)) result |= rtm_always_abort;
            if (leaf_0x07.edx_bit(13u)) result |= tsx_force_abort;
            if (leaf_0x07.edx_bit(14u)) result |= serialize;
            if (leaf_0x07.edx_bit(15u)) result |= hybrid;
            if (leaf_0x07.edx_bit(16u)) result |= tsxldtrk;
            if (leaf_0x07.edx_bit(18u)) result |= pconfig;
            if (leaf_0x07.edx_bit(19u)) result |= lbr;
            if (leaf_0x07.edx_bit(20u)) result |= cet_ibt;
            if (leaf_0x07.edx_bit(22u)) result |= amx_bf16;
            if (leaf_0x07.edx_bit(23u)) result |= avx512_fp16;
            if (leaf_0x07.edx_bit(24u)) result |= amx_tile;
            if (leaf_0x07.edx_bit(25u)) result |= amx_int8;
            if (leaf_0x07.edx_bit(26u)) result |= ibrs;
            if (leaf_0x07.edx_bit(27u)) result |= stibp;
            if (leaf_0x07.edx_bit(28u)) result |= l1d_flush;
            if (leaf_0x07.edx_bit(29u)) result |= arch_capabilities;
            if (leaf_0x07.edx_bit(30u)) result |= core_capabilities;
            if (leaf_0x07.edx_bit(31u)) result |= ssbd;
        }

        return result;
    }
} // namespace based::platform::x86::detail

