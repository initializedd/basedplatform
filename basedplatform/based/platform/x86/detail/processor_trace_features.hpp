#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// Intel Processor Trace Features
// https://en.wikipedia.org/wiki/CPUID#EAX=14h,_ECX=0:_Processor_Trace

namespace based::platform::x86::detail {
    enum class processor_trace_feature : std::uint8_t {
        cr3,
        psb_and_cyc,
        ip_and_tracestop_and_pt_msrs,
        mtc_and_cofi,
        ptwrite,
        power_event_trace,
        psb_and_pmi,
        event_trace_packet_generation,
        tnt,
        pttt
        // bits 31:10 reserved
    }; // enum class processor_trace_feature : std::uint8_t

    enum class processor_trace_feature_mask : std::uint32_t {
        cr3                           = 1u << std::to_underlying(processor_trace_feature::cr3),
        psb_and_cyc                   = 1u << std::to_underlying(processor_trace_feature::psb_and_cyc),
        ip_and_tracestop_and_pt_msrs  = 1u << std::to_underlying(processor_trace_feature::ip_and_tracestop_and_pt_msrs),
        mtc_and_cofi                  = 1u << std::to_underlying(processor_trace_feature::mtc_and_cofi),
        ptwrite                       = 1u << std::to_underlying(processor_trace_feature::ptwrite),
        power_event_trace             = 1u << std::to_underlying(processor_trace_feature::power_event_trace),
        psb_and_pmi                   = 1u << std::to_underlying(processor_trace_feature::psb_and_pmi),
        event_trace_packet_generation = 1u << std::to_underlying(processor_trace_feature::event_trace_packet_generation),
        tnt                           = 1u << std::to_underlying(processor_trace_feature::tnt),
        pttt                          = 1u << std::to_underlying(processor_trace_feature::pttt)
    }; // enum class processor_trace_feature_mask : std::uint32_t

    [[nodiscard]]
    processor_trace_feature_mask supported_processor_trace_features(const std::uint32_t max_leaf) noexcept {
        auto result = processor_trace_feature_mask{};

        if (max_leaf >= 0x14) {
            using processor_trace_feature;
            const auto leaf14 = cpu_id(0x14, 0u);

            // ebx register
            if (leaf14.ebx_bit(0u)) result |= cr3;
            if (leaf14.ebx_bit(1u)) result |= psb_and_cyc;
            if (leaf14.ebx_bit(2u)) result |= ip_and_tracestop_and_pt_msrs;
            if (leaf14.ebx_bit(3u)) result |= mtc_and_cofi;
            if (leaf14.ebx_bit(4u)) result |= ptwrite;
            if (leaf14.ebx_bit(5u)) result |= power_event_trace;
            if (leaf14.ebx_bit(6u)) result |= psb_and_pmi;
            if (leaf14.ebx_bit(7u)) result |= event_trace_packet_generation;
            if (leaf14.ebx_bit(8u)) result |= tnt;
            if (leaf14.ebx_bit(9u)) result |= pttt;
        }

        return result;
    }
} // namespace based::platform::x86::detail

