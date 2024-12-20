#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"
#include "../../util.hpp"

// CPU Extended Core Instructions
// https://en.wikipedia.org/wiki/CPUID#EAX=7,_ECX=1:_Extended_Features

namespace based::platform::x86::detail {
    enum class cpu_extended_core_instruction : std::uint8_t {
        sha512,
        sm3,
        smm4,
        rao_int,
        avx_vnni,
        avx512_bf16,
        lass,
        cmpccxadd,
        archperfmonext,
        dedup,
        fzrm,
        fsrs,
        rsrcs,
        // bits 16:13 reserved
        fred                        = 17u,
        lkgs,
        wrmsrns,
        nmi_src,
        amx_fp16,
        hreset,
        avx_ifma,
        // bits 25:24 reserved
        lam                         = 26u,
        msrlist,
        // bits 29:28 reserved
        invd_disable_post_bios_done = 30u,
        movrs
    }; // enum class cpu_extended_core_instruction : std::uint8_t

    enum class cpu_extended_core_instruction_mask : std::uint32_t {
        sha512                      = 1u << std::to_underlying(cpu_extended_core_instruction::sha512),
        sm3                         = 1u << std::to_underlying(cpu_extended_core_instruction::sm3),
        smm4                        = 1u << std::to_underlying(cpu_extended_core_instruction::smm4),
        rao_int                     = 1u << std::to_underlying(cpu_extended_core_instruction::rao_int),
        avx_vnni                    = 1u << std::to_underlying(cpu_extended_core_instruction::avx_vnni),
        avx512_bf16                 = 1u << std::to_underlying(cpu_extended_core_instruction::avx512_bf16),
        lass                        = 1u << std::to_underlying(cpu_extended_core_instruction::lass),
        cmpccxadd                   = 1u << std::to_underlying(cpu_extended_core_instruction::cmpccxadd),
        archperfmonext              = 1u << std::to_underlying(cpu_extended_core_instruction::archperfmonext),
        dedup                       = 1u << std::to_underlying(cpu_extended_core_instruction::dedup),
        fzrm                        = 1u << std::to_underlying(cpu_extended_core_instruction::fzrm),
        fsrs                        = 1u << std::to_underlying(cpu_extended_core_instruction::fsrs),
        rsrcs                       = 1u << std::to_underlying(cpu_extended_core_instruction::rsrcs),
        fred                        = 1u << std::to_underlying(cpu_extended_core_instruction::fred),
        lkgs                        = 1u << std::to_underlying(cpu_extended_core_instruction::lkgs),
        wrmsrns                     = 1u << std::to_underlying(cpu_extended_core_instruction::wrmsrns),
        nmi_src                     = 1u << std::to_underlying(cpu_extended_core_instruction::nmi_src),
        amx_fp16                    = 1u << std::to_underlying(cpu_extended_core_instruction::amx_fp16),
        hreset                      = 1u << std::to_underlying(cpu_extended_core_instruction::hreset),
        avx_ifma                    = 1u << std::to_underlying(cpu_extended_core_instruction::avx_ifma),
        lam                         = 1u << std::to_underlying(cpu_extended_core_instruction::lam),
        msrlist                     = 1u << std::to_underlying(cpu_extended_core_instruction::msrlist),
        invd_disable_post_bios_done = 1u << std::to_underlying(cpu_extended_core_instruction::invd_disable_post_bios_done),
        movrs                       = 1u << std::to_underlying(cpu_extended_core_instruction::movrs)
    }; // enum class cpu_extended_core_instruction_mask : std::uint32_t

    [[nodiscard]]
    inline cpu_extended_core_instruction_mask supported_extended_core_instructions(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_extended_core_instruction_mask{};

        if (max_leaf >= 0x07) {
            using enum cpu_extended_core_instruction;
            const auto leaf_0x07 = cpu_id(0x07, 0x01);

            // eax register
            if (leaf_0x07.eax_bit( 0u)) result |= sha512;
            if (leaf_0x07.eax_bit( 1u)) result |= sm3;
            if (leaf_0x07.eax_bit( 2u)) result |= smm4;
            if (leaf_0x07.eax_bit( 3u)) result |= rao_int;
            if (leaf_0x07.eax_bit( 4u)) result |= avx_vnni;
            if (leaf_0x07.eax_bit( 5u)) result |= avx512_bf16;
            if (leaf_0x07.eax_bit( 6u)) result |= lass;
            if (leaf_0x07.eax_bit( 7u)) result |= cmpccxadd;
            if (leaf_0x07.eax_bit( 8u)) result |= archperfmonext;
            if (leaf_0x07.eax_bit( 9u)) result |= dedup;
            if (leaf_0x07.eax_bit(10u)) result |= fzrm;
            if (leaf_0x07.eax_bit(11u)) result |= fsrs;
            if (leaf_0x07.eax_bit(12u)) result |= rsrcs;
            if (leaf_0x07.eax_bit(17u)) result |= fred;
            if (leaf_0x07.eax_bit(18u)) result |= lkgs;
            if (leaf_0x07.eax_bit(19u)) result |= wrmsrns;
            if (leaf_0x07.eax_bit(20u)) result |= nmi_src;
            if (leaf_0x07.eax_bit(21u)) result |= amx_fp16;
            if (leaf_0x07.eax_bit(22u)) result |= hreset;
            if (leaf_0x07.eax_bit(23u)) result |= avx_ifma;
            if (leaf_0x07.eax_bit(26u)) result |= lam;
            if (leaf_0x07.eax_bit(27u)) result |= msrlist;
            if (leaf_0x07.eax_bit(30u)) result |= invd_disable_post_bios_done;
            if (leaf_0x07.eax_bit(31u)) result |= movrs;
        }

        return result;
    }
} // namespace based::platform::x86::detail

