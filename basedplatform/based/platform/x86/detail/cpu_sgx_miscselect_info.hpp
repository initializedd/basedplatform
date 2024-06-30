#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// SGX MISCSELECT
// https://en.wikipedia.org/wiki/CPUID#EAX=12h:_SGX_capabilities

namespace based::platform::x86::detail {
    enum class cpu_sgx_miscselect_info : std::uint8_t {
        exinfo,
        cpinfo
        // bits 31:2 reserved
    }; // enum class cpu_sgx_miscselect_info : std::uint8_t

    enum class cpu_sgx_miscselect_info_mask : std::uint32_t {
        exinfo = 1u << std::to_underlying(cpu_sgx_miscselect_info::exinfo),
        cpinfo = 1u << std::to_underlying(cpu_sgx_miscselect_info::cpinfo)
    }; // enum class cpu_sgx_miscselect_info_mask : std::uint32_t

    [[nodiscard]]
    cpu_sgx_miscselect_info_mask supported_cpu_sgx_miscselect_info(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_sgx_miscselect_info_mask{};

        if (max_leaf >= 0x12) {
            using enum cpu_sgx_miscselect_info;
            const auto leaf12 = cpu_id(0x12, 0x00);

            // ebx
            if (leaf12.ebx_bit(0u)) result |= exinfo;
            if (leaf12.ebx_bit(1u)) result |= cpinfo;
        }
    }
} // namespace based::platform::x86::detail

