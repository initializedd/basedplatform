#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// Extended advanced instructions
// https://en.wikipedia.org/wiki/CPUID#EAX=7,_ECX=1:_Extended_Features

namespace based::platform::x86::detail {
    enum class cpu_extended_advanced_instruction : std::uint8_t {
        // bits 3:0 reserved
        avx_vnni_int8         = 4u,
        avx_ne_convert,
        // bits 7:6 reserved
        amx_complex           = 8u,
        // bit 9 reserved
        avx_vnni_int16        = 10u,
        // bits 12:11 reserved
        utmr                  = 13u,
        prefetchi,
        user_msr,
        // bit 16 reserved
        uiret_uif_from_rflags = 17u,
        cet_sss,
        avx10,
        // bit 20 reserved
        apx_f                 = 21u,
        // bit 22 reserved
        mwait                 = 23u
        // bits 31:24 reserved
    }; // enum class cpu_extended_advanced_instruction : std::uint8_t

    enum class cpu_extended_advanced_instruction_mask : std::uint32_t {
        avx_vnni_int8         = 1u << std::to_underlying(cpu_extended_advanced_instruction::avx_vnni_int8),
        avx_ne_convert        = 1u << std::to_underlying(cpu_extended_advanced_instruction::avx_ne_convert),
        amx_complex           = 1u << std::to_underlying(cpu_extended_advanced_instruction::amx_complex),
        avx_vnni_int16        = 1u << std::to_underlying(cpu_extended_advanced_instruction::avx_vnni_int16),
        utmr                  = 1u << std::to_underlying(cpu_extended_advanced_instruction::utmr),
        prefetchi             = 1u << std::to_underlying(cpu_extended_advanced_instruction::prefetchi),
        user_msr              = 1u << std::to_underlying(cpu_extended_advanced_instruction::user_msr),
        uiret_uif_from_rflags = 1u << std::to_underlying(cpu_extended_advanced_instruction::uiret_uif_from_rflags),
        cet_sss               = 1u << std::to_underlying(cpu_extended_advanced_instruction::cet_sss),
        avx10                 = 1u << std::to_underlying(cpu_extended_advanced_instruction::avx10),
        apx_f                 = 1u << std::to_underlying(cpu_extended_advanced_instruction::apx_f),
        mwait                 = 1u << std::to_underlying(cpu_extended_advanced_instruction::mwait)
    }; // enum class cpu_extended_advanced_instruction_mask : std::uint32_t

    [[nodiscard]]
    cpu_extended_advanced_instruction_mask supported_extended_advanced_instructions(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_extended_advanced_instruction_mask{};

        if (max_leaf >= 0x07) {
            using enum cpu_extended_advanced_instruction;
            const auto leaf_0x07 = cpu_id(0x07, 0x01);

            // edx register
            if (leaf_0x07.edx_bit( 4u)) result |= avx_vnni_int8;
            if (leaf_0x07.edx_bit( 5u)) result |= avx_ne_convert;
            if (leaf_0x07.edx_bit( 8u)) result |= amx_complex;
            if (leaf_0x07.edx_bit(10u)) result |= avx_vnni_int16;
            if (leaf_0x07.edx_bit(13u)) result |= utmr;
            if (leaf_0x07.edx_bit(14u)) result |= prefetchi;
            if (leaf_0x07.edx_bit(15u)) result |= user_msr;
            if (leaf_0x07.edx_bit(17u)) result |= uiret_uif_from_rflags;
            if (leaf_0x07.edx_bit(18u)) result |= cet_sss;
            if (leaf_0x07.edx_bit(19u)) result |= avx10;
            if (leaf_0x07.edx_bit(21u)) result |= apx_f;
            if (leaf_0x07.edx_bit(23u)) result |= mwait;
        }

        return result;
    }
} // namespace based::platform::x86::detail

