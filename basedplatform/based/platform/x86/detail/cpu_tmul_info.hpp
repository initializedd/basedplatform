#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"
#include "../../util.hpp"

// TMUL Information
// https://en.wikipedia.org/wiki/CPUID#EAX=1Eh,_ECX=0:_TMUL_Information

namespace based::platform::x86::detail {
    enum class cpu_tmul_matrix_info : std::uint8_t {
        tmul_maxk_bit_0,
        tmul_maxk_bit_1,
        tmul_maxk_bit_2,
        tmul_maxk_bit_3,
        tmul_maxk_bit_4,
        tmul_maxk_bit_5,
        tmul_maxk_bit_6,
        tmul_maxk_bit_7,
        tmul_maxn_bit_0,
        tmul_maxn_bit_1,
        tmul_maxn_bit_2,
        tmul_maxn_bit_3,
        tmul_maxn_bit_4,
        tmul_maxn_bit_5,
        tmul_maxn_bit_6,
        tmul_maxn_bit_7
        // bits 31:23 reserved
    }; // enum class cpu_tmul_matrix_info : std::uint8_t

    enum class cpu_tmul_matrix_info_mask : std::uint32_t {
        tmul_maxk = 1u << std::to_underlying(cpu_tmul_matrix_info::tmul_maxk_bit_0)
                  | 1u << std::to_underlying(cpu_tmul_matrix_info::tmul_maxk_bit_1)
                  | 1u << std::to_underlying(cpu_tmul_matrix_info::tmul_maxk_bit_2)
                  | 1u << std::to_underlying(cpu_tmul_matrix_info::tmul_maxk_bit_3)
                  | 1u << std::to_underlying(cpu_tmul_matrix_info::tmul_maxk_bit_4)
                  | 1u << std::to_underlying(cpu_tmul_matrix_info::tmul_maxk_bit_5)
                  | 1u << std::to_underlying(cpu_tmul_matrix_info::tmul_maxk_bit_6)
                  | 1u << std::to_underlying(cpu_tmul_matrix_info::tmul_maxk_bit_7),
        tmul_maxn = 1u << std::to_underlying(cpu_tmul_matrix_info::tmul_maxn_bit_0)
                  | 1u << std::to_underlying(cpu_tmul_matrix_info::tmul_maxn_bit_1)
                  | 1u << std::to_underlying(cpu_tmul_matrix_info::tmul_maxn_bit_2)
                  | 1u << std::to_underlying(cpu_tmul_matrix_info::tmul_maxn_bit_3)
                  | 1u << std::to_underlying(cpu_tmul_matrix_info::tmul_maxn_bit_4)
                  | 1u << std::to_underlying(cpu_tmul_matrix_info::tmul_maxn_bit_5)
                  | 1u << std::to_underlying(cpu_tmul_matrix_info::tmul_maxn_bit_6)
                  | 1u << std::to_underlying(cpu_tmul_matrix_info::tmul_maxn_bit_7)
    }; // enum class cpu_tmul_matrix_info_mask : std::uint32_t

    [[nodiscard]]
    inline cpu_tmul_matrix_info_mask supported_cpu_tmul_matrix_info(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_tmul_matrix_info_mask{};

        if (max_leaf >= 0x1E) {
            using enum cpu_tmul_matrix_info;
            const auto leaf_0x1e = cpu_id(0x1E, 0x00);

            // ebx register
            if (leaf_0x1e.ebx_bit( 0u)) result |= tmul_maxk_bit_0;
            if (leaf_0x1e.ebx_bit( 1u)) result |= tmul_maxk_bit_1;
            if (leaf_0x1e.ebx_bit( 2u)) result |= tmul_maxk_bit_2;
            if (leaf_0x1e.ebx_bit( 3u)) result |= tmul_maxk_bit_3;
            if (leaf_0x1e.ebx_bit( 4u)) result |= tmul_maxk_bit_4;
            if (leaf_0x1e.ebx_bit( 5u)) result |= tmul_maxk_bit_5;
            if (leaf_0x1e.ebx_bit( 6u)) result |= tmul_maxk_bit_6;
            if (leaf_0x1e.ebx_bit( 7u)) result |= tmul_maxk_bit_7;
            if (leaf_0x1e.ebx_bit( 8u)) result |= tmul_maxn_bit_0;
            if (leaf_0x1e.ebx_bit( 9u)) result |= tmul_maxn_bit_1;
            if (leaf_0x1e.ebx_bit(10u)) result |= tmul_maxn_bit_2;
            if (leaf_0x1e.ebx_bit(11u)) result |= tmul_maxn_bit_3;
            if (leaf_0x1e.ebx_bit(12u)) result |= tmul_maxn_bit_4;
            if (leaf_0x1e.ebx_bit(13u)) result |= tmul_maxn_bit_5;
            if (leaf_0x1e.ebx_bit(14u)) result |= tmul_maxn_bit_6;
            if (leaf_0x1e.ebx_bit(15u)) result |= tmul_maxn_bit_7;

        }

        return result;
    }

    enum class cpu_tmul_number_info : std::uint8_t {
        amx_int8,
        amx_bf16,
        amx_complex,
        amx_fp16,
        amx_fp8,
        amx_transpose,
        amx_tf32,
        amx_avx512,
        amx_movrs
        // bits 31:9 reserved
    }; // enum class cpu_tmul_number_info : std::uint8_t

    enum class cpu_tmul_number_info_mask : std::uint8_t {
        amx_int8      = 1u << std::to_underlying(cpu_tmul_number_info::amx_int8),
        amx_bf16      = 1u << std::to_underlying(cpu_tmul_number_info::amx_bf16),
        amx_complex   = 1u << std::to_underlying(cpu_tmul_number_info::amx_complex),
        amx_fp16      = 1u << std::to_underlying(cpu_tmul_number_info::amx_fp16),
        amx_fp8       = 1u << std::to_underlying(cpu_tmul_number_info::amx_fp8),
        amx_transpose = 1u << std::to_underlying(cpu_tmul_number_info::amx_transpose),
        amx_tf32      = 1u << std::to_underlying(cpu_tmul_number_info::amx_tf32),
        amx_avx512    = 1u << std::to_underlying(cpu_tmul_number_info::amx_avx512),
        amx_movrs     = 1u << std::to_underlying(cpu_tmul_number_info::amx_movrs)
    }; // enum class cpu_tmul_number_info_mask : std::uint8_t

    [[nodiscard]]
    inline cpu_tmul_number_info_mask supported_cpu_tmul_number_info(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_tmul_number_info_mask{};

        if (max_leaf >= 0x1E) {
            using enum cpu_tmul_number_info;
            const auto leaf_0x1e = cpu_id(0x1E, 0x01);

            // eax register
            if (leaf_0x1e.eax_bit(0u)) result |= amx_int8;
            if (leaf_0x1e.eax_bit(1u)) result |= amx_bf16;
            if (leaf_0x1e.eax_bit(2u)) result |= amx_complex;
            if (leaf_0x1e.eax_bit(3u)) result |= amx_fp16;
            if (leaf_0x1e.eax_bit(4u)) result |= amx_fp8;
            if (leaf_0x1e.eax_bit(5u)) result |= amx_transpose;
            if (leaf_0x1e.eax_bit(6u)) result |= amx_tf32;
            if (leaf_0x1e.eax_bit(7u)) result |= amx_avx512;
            if (leaf_0x1e.eax_bit(8u)) result |= amx_movrs;
        }

        return result;
    }
} // namespace based::platform::x86::detail

