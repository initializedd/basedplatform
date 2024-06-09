#pragma once

#include <cstdint>

#if defined(_MSC_VER)
#    include <intrin.h>
#endif
#if defined(__clang__) || defined(__GNUC__)
#    include <cpuid.h>
#endif

namespace based::platform::x86::detail {
    struct cpu_id {
        std::uint32_t eax;
        std::uint32_t ebx;
        std::uint32_t ecx;
        std::uint32_t edx;

        cpu_id() = delete;
        cpu_id(const std::uint32_t leaf, const std::uint32_t subleaf) noexcept {
#           if defined(_MSC_VER)
                int tmp[4];
                __cpuidex(tmp, static_cast<int>(leaf), static_cast<int>(subleaf));
                eax = tmp[0];
                ebx = tmp[1];
                ecx = tmp[2];
                edx = tmp[3];
#           endif
#           if defined(__clang__) || defined(__GNUC__)
                __cpuid_count(leaf, subleaf, eax, ebx, ecx, edx);
#           endif
        }

        [[nodiscard]]
        constexpr inline bool eax_bit(const std::uint8_t bit) const noexcept {
            return (eax & (1u << bit)) != 0;
        }

        [[nodiscard]]
        constexpr inline bool ebx_bit(const std::uint8_t bit) const noexcept {
            return (ebx & (1u << bit)) != 0;
        }

        [[nodiscard]]
        constexpr inline bool ecx_bit(const std::uint8_t bit) const noexcept {
            return (ecx & (1u << bit)) != 0;
        }

        [[nodiscard]]
        constexpr inline bool edx_bit(const std::uint8_t bit) const noexcept {
            return (edx & (1u << bit)) != 0;
        }
    }; // struct cpu_id
} // namespace based::platform::x86::detail

