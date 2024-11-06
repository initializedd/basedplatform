#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"
#include "../../util.hpp"

// SGX Supported Enclave Sizes
// https://en.wikipedia.org/wiki/CPUID#EAX=12h:_SGX_capabilities

namespace based::platform::x86::detail {
    enum class cpu_sgx_enclave_info : std::uint8_t {
        max_enclave_size_not_64_bit_0,
        max_enclave_size_not_64_bit_1,
        max_enclave_size_not_64_bit_2,
        max_enclave_size_not_64_bit_3,
        max_enclave_size_not_64_bit_4,
        max_enclave_size_not_64_bit_5,
        max_enclave_size_not_64_bit_6,
        max_enclave_size_not_64_bit_7,
        max_enclave_size_64_bit_0,
        max_enclave_size_64_bit_1,
        max_enclave_size_64_bit_2,
        max_enclave_size_64_bit_3,
        max_enclave_size_64_bit_4,
        max_enclave_size_64_bit_5,
        max_enclave_size_64_bit_6,
        max_enclave_size_64_bit_7
        // bits 31:16 reserved
    }; // enum class cpu_sgx_enclave_info : std::uint8_t

    enum class cpu_sgx_enclave_info_mask : std::uint32_t {
        max_enclave_size_not_64 = 1u << std::to_underlying(cpu_sgx_enclave_info::max_enclave_size_not_64_bit_0)
                                | 1u << std::to_underlying(cpu_sgx_enclave_info::max_enclave_size_not_64_bit_1)
                                | 1u << std::to_underlying(cpu_sgx_enclave_info::max_enclave_size_not_64_bit_2)
                                | 1u << std::to_underlying(cpu_sgx_enclave_info::max_enclave_size_not_64_bit_3)
                                | 1u << std::to_underlying(cpu_sgx_enclave_info::max_enclave_size_not_64_bit_4)
                                | 1u << std::to_underlying(cpu_sgx_enclave_info::max_enclave_size_not_64_bit_5)
                                | 1u << std::to_underlying(cpu_sgx_enclave_info::max_enclave_size_not_64_bit_6)
                                | 1u << std::to_underlying(cpu_sgx_enclave_info::max_enclave_size_not_64_bit_7),
        max_enclave_Size_64     = 1u << std::to_underlying(cpu_sgx_enclave_info::max_enclave_size_64_bit_0)
                                | 1u << std::to_underlying(cpu_sgx_enclave_info::max_enclave_size_64_bit_1)
                                | 1u << std::to_underlying(cpu_sgx_enclave_info::max_enclave_size_64_bit_2)
                                | 1u << std::to_underlying(cpu_sgx_enclave_info::max_enclave_size_64_bit_3)
                                | 1u << std::to_underlying(cpu_sgx_enclave_info::max_enclave_size_64_bit_4)
                                | 1u << std::to_underlying(cpu_sgx_enclave_info::max_enclave_size_64_bit_5)
                                | 1u << std::to_underlying(cpu_sgx_enclave_info::max_enclave_size_64_bit_6)
                                | 1u << std::to_underlying(cpu_sgx_enclave_info::max_enclave_size_64_bit_7)
    }; // enum class cpu_sgx_enclave_info_mask : std::uint32_t

    [[nodiscard]]
    inline cpu_sgx_enclave_info_mask supported_cpu_sgx_enclave_info(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_sgx_enclave_info_mask{};

        if (max_leaf >= 0x12) {
            using enum cpu_sgx_enclave_info;
            const auto leaf_0x12 = cpu_id(0x12, 0x00);

            // edx register
            if (leaf_0x12.edx_bit( 0u)) result |= max_enclave_size_not_64_bit_0;
            if (leaf_0x12.edx_bit( 1u)) result |= max_enclave_size_not_64_bit_1;
            if (leaf_0x12.edx_bit( 2u)) result |= max_enclave_size_not_64_bit_2;
            if (leaf_0x12.edx_bit( 3u)) result |= max_enclave_size_not_64_bit_3;
            if (leaf_0x12.edx_bit( 4u)) result |= max_enclave_size_not_64_bit_4;
            if (leaf_0x12.edx_bit( 5u)) result |= max_enclave_size_not_64_bit_5;
            if (leaf_0x12.edx_bit( 6u)) result |= max_enclave_size_not_64_bit_6;
            if (leaf_0x12.edx_bit( 7u)) result |= max_enclave_size_not_64_bit_7;
            if (leaf_0x12.edx_bit( 8u)) result |= max_enclave_size_64_bit_0;
            if (leaf_0x12.edx_bit( 9u)) result |= max_enclave_size_64_bit_1;
            if (leaf_0x12.edx_bit(10u)) result |= max_enclave_size_64_bit_2;
            if (leaf_0x12.edx_bit(11u)) result |= max_enclave_size_64_bit_3;
            if (leaf_0x12.edx_bit(12u)) result |= max_enclave_size_64_bit_4;
            if (leaf_0x12.edx_bit(13u)) result |= max_enclave_size_64_bit_5;
            if (leaf_0x12.edx_bit(14u)) result |= max_enclave_size_64_bit_6;
            if (leaf_0x12.edx_bit(15u)) result |= max_enclave_size_64_bit_7;
        }

        return result;
    }
} // namespace based::platform::x86::detail

