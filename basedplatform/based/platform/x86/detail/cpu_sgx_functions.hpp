#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"
#include "../../util.hpp"

// SGX Functions
// https://en.wikipedia.org/wiki/CPUID#EAX=12h:_SGX_capabilities

namespace based::platform::x86::detail {
    enum class cpu_sgx_function : std::uint8_t {
        sgx1,
        sgx2,
        // bits 4:2 reserved
        oss            = 5u,
        encls,
        everifyreport2,
        // bits 9:8 reserved
        eupdatesvn     = 10u,
        edecssa
        // bits 31:12 reserved
    }; // enum class cpu_sgx_function : std::uint8_t

    enum class cpu_sgx_function_mask : std::uint32_t {
        sgx1           = 1u << std::to_underlying(cpu_sgx_function::sgx1),
        sgx2           = 1u << std::to_underlying(cpu_sgx_function::sgx2),
        oss            = 1u << std::to_underlying(cpu_sgx_function::oss),
        encls          = 1u << std::to_underlying(cpu_sgx_function::encls),
        everifyreport2 = 1u << std::to_underlying(cpu_sgx_function::everifyreport2),
        eupdatesvn     = 1u << std::to_underlying(cpu_sgx_function::eupdatesvn),
        edecssa        = 1u << std::to_underlying(cpu_sgx_function::edecssa)
    }; // enum class cpu_sgx_function_mask : std::uint32_t

    [[nodiscard]]
    inline cpu_sgx_function_mask supported_cpu_sgx_functions(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_sgx_function_mask{};

        if (max_leaf >= 0x12) {
            using enum cpu_sgx_function;
            const auto leaf_0x12 = cpu_id(0x12, 0x00);

            // eax register
            if (leaf_0x12.eax_bit( 0u)) result |= sgx1;
            if (leaf_0x12.eax_bit( 1u)) result |= sgx2;
            if (leaf_0x12.eax_bit( 5u)) result |= oss;
            if (leaf_0x12.eax_bit( 6u)) result |= encls;
            if (leaf_0x12.eax_bit( 7u)) result |= everifyreport2;
            if (leaf_0x12.eax_bit(10u)) result |= eupdatesvn;
            if (leaf_0x12.eax_bit(11u)) result |= edecssa;
        }

        return result;
    }
} // namespace based::platform::x86::detail

