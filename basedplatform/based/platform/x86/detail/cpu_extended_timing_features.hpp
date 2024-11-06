#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"
#include "../../util.hpp"

// CPU Extended Timing Features
// https://en.wikipedia.org/wiki/CPUID#EAX=7,_ECX=2:_Extended_Features

namespace based::platform::x86::detail {
    enum class cpu_extended_timing_feature : std::uint8_t {
        psfd,
        ipred_ctrl,
        rrsba_ctrl,
        ddpd_u,
        bhi_ctrl,
        mcdt_no,
        uc_lock
        // bits 31:7 reserved
    }; // enum class cpu_extended_timing_feature : std::uint8_t

    enum class cpu_extended_timing_feature_mask : std::uint32_t {
        psfd       = 1u << std::to_underlying(cpu_extended_timing_feature::psfd),
        ipred_ctrl = 1u << std::to_underlying(cpu_extended_timing_feature::ipred_ctrl),
        rrsba_ctrl = 1u << std::to_underlying(cpu_extended_timing_feature::rrsba_ctrl),
        ddpd_u     = 1u << std::to_underlying(cpu_extended_timing_feature::ddpd_u),
        bhi_ctrl   = 1u << std::to_underlying(cpu_extended_timing_feature::bhi_ctrl),
        mcdt_no    = 1u << std::to_underlying(cpu_extended_timing_feature::mcdt_no),
        uc_lock    = 1u << std::to_underlying(cpu_extended_timing_feature::uc_lock)
    }; // enum class cpu_extended_timing_feature_mask : std::uint32_t

    [[nodiscard]]
    inline cpu_extended_timing_feature_mask supported_cpu_extended_timing_features(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_extended_timing_feature_mask{};

        if (max_leaf >= 0x07) {
            using enum cpu_extended_timing_feature;
            const auto leaf_0x07 = cpu_id(0x07, 0x02);

            // edx register
            if (leaf_0x07.edx_bit(0u)) result |= psfd;
            if (leaf_0x07.edx_bit(1u)) result |= ipred_ctrl;
            if (leaf_0x07.edx_bit(2u)) result |= rrsba_ctrl;
            if (leaf_0x07.edx_bit(3u)) result |= ddpd_u;
            if (leaf_0x07.edx_bit(4u)) result |= bhi_ctrl;
            if (leaf_0x07.edx_bit(5u)) result |= mcdt_no;
            if (leaf_0x07.edx_bit(6u)) result |= uc_lock;
        }

        return result;
    }
} // namespace based::platform::x86::detail

