#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"
#include "../../util.hpp"

// CPU Extended Compat Features
// https://en.wikipedia.org/wiki/CPUID#EAX=7,_ECX=1:_Extended_Features

namespace based::platform::x86::detail {
    enum class cpu_extended_compat_feature : std::uint8_t {
        // bits 1:0 reserved
        legacy_reduced_isa = 2u,
        // bit 3 reserved
        sipi64             = 4u,
        msr_imm
        // bits 31:6 reserved
    }; // enum class cpu_extended_compat_feature : std::uint8_t

    enum class cpu_extended_compat_feature_mask : std::uint32_t {
        legacy_reduced_isa = 1u << std::to_underlying(cpu_extended_compat_feature::legacy_reduced_isa),
        sipi64             = 1u << std::to_underlying(cpu_extended_compat_feature::sipi64),
        msr_imm            = 1u << std::to_underlying(cpu_extended_compat_feature::msr_imm)
    }; // enum class cpu_extended_compat_feature_mask : std::uint32_t

    [[nodiscard]]
    inline cpu_extended_compat_feature_mask supported_extended_compat_features(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_extended_compat_feature_mask{};

        if (max_leaf >= 0x07) {
            using enum cpu_extended_compat_feature;
            const auto leaf_0x07 = cpu_id(0x07, 0x01);

            // ecx register
            if (leaf_0x07.ecx_bit(2u)) result |= legacy_reduced_isa;
            if (leaf_0x07.ecx_bit(4u)) result |= sipi64;
            if (leaf_0x07.ecx_bit(5u)) result |= msr_imm;
        }

        return result;
    }
} // namespace based::platform::x86::detail

