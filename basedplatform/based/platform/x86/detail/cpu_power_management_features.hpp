#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// Processor Power Management Information
// https://en.wikipedia.org/wiki/CPUID#EAX=80000007h:_Processor_Power_Management_Information_and_RAS_Capabilities

namespace based::platform::x86::detail {
    enum class cpu_power_management_feature : std::uint8_t {
        ts,
        fid,
        vid,
        ttp,
        tm,
        stc,
        steps100mhz,
        hw_pstate,
        tsc_invariant,
        cpb,
        eff_freq_ro,
        proc_feedback_interface,
        proc_power_reporting,
        connected_standby,
        rapl,
        fast_cppc
        // bits 31:16 reserved
    }; // enum class cpu_power_management_feature : std::uint8_t

    enum class cpu_power_management_feature_mask : std::uint32_t {
        ts                      = 1u << std::to_underlying(cpu_power_management_feature::ts),
        fid                     = 1u << std::to_underlying(cpu_power_management_feature::fid),
        vid                     = 1u << std::to_underlying(cpu_power_management_feature::vid),
        ttp                     = 1u << std::to_underlying(cpu_power_management_feature::ttp),
        tm                      = 1u << std::to_underlying(cpu_power_management_feature::tm),
        stc                     = 1u << std::to_underlying(cpu_power_management_feature::stc),
        steps100mhz             = 1u << std::to_underlying(cpu_power_management_feature::steps100mhz), // 100mhzsteps
        hw_pstate               = 1u << std::to_underlying(cpu_power_management_feature::hw_pstate),
        tsc_invariant           = 1u << std::to_underlying(cpu_power_management_feature::tsc_invariant),
        cpb                     = 1u << std::to_underlying(cpu_power_management_feature::cpb),
        eff_freq_ro             = 1u << std::to_underlying(cpu_power_management_feature::eff_freq_ro),
        proc_feedback_interface = 1u << std::to_underlying(cpu_power_management_feature::proc_feedback_interface),
        proc_power_reporting    = 1u << std::to_underlying(cpu_power_management_feature::proc_power_reporting),
        connected_standby       = 1u << std::to_underlying(cpu_power_management_feature::connected_standby),
        rapl                    = 1u << std::to_underlying(cpu_power_management_feature::rapl),
        fast_cppc               = 1u << std::to_underlying(cpu_power_management_feature::fast_cppc)
    }; // enum class cpu_power_management_feature_mask : std::uint32_t

    [[nodiscard]]
    cpu_power_management_feature_mask supported_cpu_power_management_features(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_power_management_feature_mask{};

        if (max_leaf >= 0x80000007) {
            using cpu_power_management_feature;
            const auto leaf8 = cpu_id(0x80000007, 0u);

            // edx register
            if (leaf8.edx_bit( 0u)) result |= ts;
            if (leaf8.edx_bit( 1u)) result |= fid;
            if (leaf8.edx_bit( 2u)) result |= vid;
            if (leaf8.edx_bit( 3u)) result |= ttp;
            if (leaf8.edx_bit( 4u)) result |= tm;
            if (leaf8.edx_bit( 5u)) result |= stc;
            if (leaf8.edx_bit( 6u)) result |= steps100mhz;
            if (leaf8.edx_bit( 7u)) result |= hw_pstate;
            if (leaf8.edx_bit( 8u)) result |= tsc_invariant;
            if (leaf8.edx_bit( 9u)) result |= cpb;
            if (leaf8.edx_bit(10u)) result |= eff_freq_ro;
            if (leaf8.edx_bit(11u)) result |= proc_feedback_interface;
            if (leaf8.edx_bit(12u)) result |= proc_power_reporting;
            if (leaf8.edx_bit(13u)) result |= connected_standby;
            if (leaf8.edx_bit(14u)) result |= rapl;
            if (leaf8.edx_bit(15u)) result |= fast_cppc;
        }

        return result;
    }
} // namespace based::platform::x86::detail

