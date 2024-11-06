#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"
#include "../../util.hpp"

// MONITOR/MWAIT Extension Enumeration
// https://en.wikipedia.org/wiki/CPUID#EAX=5:_MONITOR/MWAIT_Features

namespace based::platform::x86::detail {
    enum class cpu_mwait_extension : std::uint8_t {
        emx,
        ibe,
        // bit 2 reserved
        monitorless_mwait = 3u
        // bits 31:4 reserved
    }; // enum class cpu_mwait_extension : std::uint8_t

    enum class cpu_mwait_extension_mask : std::uint32_t {
        emx               = 1u << std::to_underlying(cpu_mwait_extension::emx),
        ibe               = 1u << std::to_underlying(cpu_mwait_extension::ibe),
        monitorless_mwait = 1u << std::to_underlying(cpu_mwait_extension::monitorless_mwait)
    }; // enum class cpu_mwait_extension_mask : std::uint32_t

    [[nodiscard]]
    inline cpu_mwait_extension_mask supported_cpu_mwait_extensions(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_mwait_extension_mask{};

        if (max_leaf >= 0x05) {
            using enum cpu_mwait_extension;
            const auto leaf_0x05 = cpu_id(0x05, 0x00);

            // ecx register
            if (leaf_0x05.ecx_bit(0u)) result |= emx;
            if (leaf_0x05.ecx_bit(1u)) result |= ibe;
            if (leaf_0x05.ecx_bit(3u)) result |= monitorless_mwait;
        }

        return result;
    }
} // namespace based::platform::x86::detail

