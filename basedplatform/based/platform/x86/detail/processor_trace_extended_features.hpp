#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// Intel Processor Trace Extended Features
// https://en.wikipedia.org/wiki/CPUID#EAX=14h,_ECX=0:_Processor_Trace

namespace based::platform::x86::detail {
    enum class processor_trace_extended_feature : std::uint8_t {
        topaout,
        mentry,
        snglrngout,
        output_trace_transport,
        // bits 30:4 reserved
        instruction_pointer_format
    }; // enum class processor_trace_extended_feature : std::uint8_t

    enum class processor_trace_extended_feature_mask : std::uint32_t {
        topaout                    = 1u << std::to_underlying(processor_trace_extended_feature::topaout),
        mentry                     = 1u << std::to_underlying(processor_trace_extended_feature::mentry),
        snglrngout                 = 1u << std::to_underlying(processor_trace_extended_feature::snglrngout),
        output_trace_transport     = 1u << std::to_underlying(processor_trace_extended_feature::output_trace_transport),
        instruction_pointer_format = 1u << std::to_underlying(processor_trace_extended_feature::instruction_pointer_format)
    }; // enum class processor_trace_extended_feature_mask : std::uint32_t

    [[nodiscard]]
    processor_trace_extended_feature_mask supported_processor_trace_extended_features(const std::uint32_t max_leaf) noexcept {
        auto result = processor_trace_extended_feature_mask{};

        if (max_leaf >= 0x14) {
            using enum processor_trace_extended_feature;
            const auto leaf14 = cpu_id(0x14, 0x00);

            // ecx register
            if (leaf14.ecx_bit( 0u)) result |= topaout;
            if (leaf14.ecx_bit( 1u)) result |= mentry;
            if (leaf14.ecx_bit( 2u)) result |= snglrngout;
            if (leaf14.ecx_bit( 3u)) result |= output_trace_transport;
            if (leaf14.ecx_bit(31u)) result |= instruction_pointer_format;
        }

        return result;
    }
} // namespace based::platform::x86::detail

