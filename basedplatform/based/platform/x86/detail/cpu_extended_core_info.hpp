#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// CPU Extended Core Info
// https://en.wikipedia.org/wiki/CPUID#EAX=80000001h:_Extended_Processor_Info_and_Feature_Bits

namespace based::platform::x86::detail {
    enum class cpu_extended_core_info : std::uint8_t {
        fpu,
        vme,
        de,
        pse,
        tsc,
        msr,
        pae,
        mce,
        cx8,
        apic,
        syscall_k6,
        syscall,
        mtrr,
        pge,
        mca,
        cmov,
        pat,
        pse36,
        // bit 18 reserved
        ecc        = 19u,
        nx,
        // bit 21 reserved
        mmxext     = 22u,
        mmx,
        fxsr,
        fxsr_opt,
        pdpe1gb,
        rdtscp,
        // bit 28 reserved
        lm         = 29u,
        now3dext,
        now3d
    }; // enum class cpu_extended_core_info : std::uint8_t

    enum class cpu_extended_core_info_mask : std::uint32_t {
        fpu        = 1u << std::to_underlying(cpu_extended_core_info::fpu),
        vme        = 1u << std::to_underlying(cpu_extended_core_info::vme),
        de         = 1u << std::to_underlying(cpu_extended_core_info::de),
        pse        = 1u << std::to_underlying(cpu_extended_core_info::pse),
        tsc        = 1u << std::to_underlying(cpu_extended_core_info::tsc),
        msr        = 1u << std::to_underlying(cpu_extended_core_info::msr),
        pae        = 1u << std::to_underlying(cpu_extended_core_info::pae),
        mce        = 1u << std::to_underlying(cpu_extended_core_info::mce),
        cx8        = 1u << std::to_underlying(cpu_extended_core_info::cx8),
        apic       = 1u << std::to_underlying(cpu_extended_core_info::apic),
        syscall_k6 = 1u << std::to_underlying(cpu_extended_core_info::syscall_k6),
        syscall    = 1u << std::to_underlying(cpu_extended_core_info::syscall),
        mtrr       = 1u << std::to_underlying(cpu_extended_core_info::mtrr),
        pge        = 1u << std::to_underlying(cpu_extended_core_info::pge),
        mca        = 1u << std::to_underlying(cpu_extended_core_info::mca),
        cmov       = 1u << std::to_underlying(cpu_extended_core_info::cmov),
        pat        = 1u << std::to_underlying(cpu_extended_core_info::pat),
        pse36      = 1u << std::to_underlying(cpu_extended_core_info::pse36),
        ecc        = 1u << std::to_underlying(cpu_extended_core_info::ecc),
        nx         = 1u << std::to_underlying(cpu_extended_core_info::nx),
        mmxext     = 1u << std::to_underlying(cpu_extended_core_info::mmxext),
        mmx        = 1u << std::to_underlying(cpu_extended_core_info::mmx),
        fxsr       = 1u << std::to_underlying(cpu_extended_core_info::fxsr),
        fxsr_opt   = 1u << std::to_underlying(cpu_extended_core_info::fxsr_opt),
        pdpe1gb    = 1u << std::to_underlying(cpu_extended_core_info::pdpe1gb),
        rdtscp     = 1u << std::to_underlying(cpu_extended_core_info::rdtscp),
        lm         = 1u << std::to_underlying(cpu_extended_core_info::lm),
        now3dext   = 1u << std::to_underlying(cpu_extended_core_info::now3dext),
        now3d      = 1u << std::to_underlying(cpu_extended_core_info::now3d)
    }; // enum class cpu_extended_core_info_mask : std::uint32_t

    [[nodiscard]]
    cpu_extended_core_info_mask supported_extended_core_info(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_extended_core_info_mask{};

        if (max_leaf >= 0x80000001) {
            using enum cpu_extended_core_info;
            const auto leaf_0x80000001 = cpu_id(0x80000001, 0x00);

            // edx register
            if (leaf_0x80000001.edx_bit( 0u)) result |= fpu;
            if (leaf_0x80000001.edx_bit( 1u)) result |= vme;
            if (leaf_0x80000001.edx_bit( 2u)) result |= de;
            if (leaf_0x80000001.edx_bit( 3u)) result |= pse;
            if (leaf_0x80000001.edx_bit( 4u)) result |= tsc;
            if (leaf_0x80000001.edx_bit( 5u)) result |= msr;
            if (leaf_0x80000001.edx_bit( 6u)) result |= pae;
            if (leaf_0x80000001.edx_bit( 7u)) result |= mce;
            if (leaf_0x80000001.edx_bit( 8u)) result |= cx8;
            if (leaf_0x80000001.edx_bit( 9u)) result |= apic;
            if (leaf_0x80000001.edx_bit(10u)) result |= syscall_k6;
            if (leaf_0x80000001.edx_bit(11u)) result |= syscall;
            if (leaf_0x80000001.edx_bit(12u)) result |= mtrr;
            if (leaf_0x80000001.edx_bit(13u)) result |= pge;
            if (leaf_0x80000001.edx_bit(14u)) result |= mca;
            if (leaf_0x80000001.edx_bit(15u)) result |= cmov;
            if (leaf_0x80000001.edx_bit(16u)) result |= pat;
            if (leaf_0x80000001.edx_bit(17u)) result |= pse36;
            if (leaf_0x80000001.edx_bit(19u)) result |= ecc;
            if (leaf_0x80000001.edx_bit(20u)) result |= nx;
            if (leaf_0x80000001.edx_bit(22u)) result |= mmxext;
            if (leaf_0x80000001.edx_bit(23u)) result |= mmx;
            if (leaf_0x80000001.edx_bit(24u)) result |= fxsr;
            if (leaf_0x80000001.edx_bit(25u)) result |= fxsr_opt;
            if (leaf_0x80000001.edx_bit(26u)) result |= pdpe1gb;
            if (leaf_0x80000001.edx_bit(27u)) result |= rdtscp;
            if (leaf_0x80000001.edx_bit(29u)) result |= lm;
            if (leaf_0x80000001.edx_bit(30u)) result |= now3dext;
            if (leaf_0x80000001.edx_bit(31u)) result |= now3d;
        }

        return result;
    }
} // namespace based::platform::x86::detail

