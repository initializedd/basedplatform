#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// Intel Key Locker features
// https://en.wikipedia.org/wiki/CPUID#EAX=19h:_Intel_Key_Locker_features

namespace based::platform::x86::detail {
    enum class cpu_key_locker_restriction : std::uint8_t {
        cpl0,
        no_encrypt,
        no_decrypt,
        process_restriction
        // bits 31:4 reserved
    }; // enum class cpu_key_locker_restriction : std::uint8_t

    enum class cpu_key_locker_restriction_mask : std::uint32_t {
        cpl0                = 1u << std::to_underlying(cpu_key_locker_restriction::cpl0),
        no_encrypt          = 1u << std::to_underlying(cpu_key_locker_restriction::no_encrypt),
        no_decrypt          = 1u << std::to_underlying(cpu_key_locker_restriction::no_decrypt),
        process_restriction = 1u << std::to_underlying(cpu_key_locker_restriction::process_restriction)
    }; // enum class cpu_key_locker_restriction_mask : std::uint32_t

    [[nodiscard]]
    cpu_key_locker_restriction_mask supported_cpu_key_locker_restrictions(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_key_locker_restriction_mask{};

        if (max_leaf >= 0x19) {
            using enum cpu_key_locker_restriction;
            const auto leaf19 = cpu_id(0x19, 0x00);

            // eax register
            if (leaf19.eax_bit(0u)) result |= cpl0;
            if (leaf19.eax_bit(1u)) result |= no_encrypt;
            if (leaf19.eax_bit(2u)) result |= no_decrypt;
            if (leaf19.eax_bit(3u)) result |= process_restriction;
        }

        return result;
    }

    enum class cpu_key_locker_security : std::uint8_t {
        aes_kle,
        // bit 1 reserved
        aes_wide_kl = 2u,
        // bit 3 reserved
        kl_msrs     = 4u
        // bits 31:5 reserved
    }; // enum class cpu_key_locker_security : std::uint8_t

    enum class cpu_key_locker_security_mask : std::uint32_t {
        aes_kle     = 1u << std::to_underlying(cpu_key_locker_security::aes_kle),
        aes_wide_kl = 1u << std::to_underlying(cpu_key_locker_security::aes_wide_kl),
        kl_msrs     = 1u << std::to_underlying(cpu_key_locker_security::kl_msrs)
    }; // enum class cpu_key_locker_security_mask : std::uint32_t

    [[nodiscard]]
    cpu_key_locker_security_mask supported_cpu_key_locker_security(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_key_locker_security_mask{};

        if (max_leaf >= 0x19) {
            using enum cpu_key_locker_security;
            const auto leaf_0x19 = cpu_id(0x19, 0x00);

            // ebx register
            if (leaf_0x19.eax_bit(0u)) result |= aes_kle;
            if (leaf_0x19.eax_bit(2u)) result |= aes_wide_kl;
            if (leaf_0x19.eax_bit(4u)) result |= kl_msrs;
        }

        return result;
    }

    enum class cpu_key_locker_meta : std::uint8_t {
        loadiwkey_no_backup_parameter,
        key_source_encoding_of_1
        // bits 31:2 reserved
    }; // enum class cpu_key_locker_meta : std::uint8_t

    enum class cpu_key_locker_meta_mask : std::uint32_t {
        loadiwkey_no_backup_parameter = 1u << std::to_underlying(cpu_key_locker_meta::loadiwkey_no_backup_parameter),
        key_source_encoding_of_1      = 1u << std::to_underlying(cpu_key_locker_meta::key_source_encoding_of_1)
    }; // enum class cpu_key_locker_meta_mask : std::uint32_t

    [[nodiscard]]
    cpu_key_locker_meta_mask supported_cpu_key_locker_meta(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_key_locker_meta_mask{};

        if (max_leaf >= 0x19) {
            using enum cpu_key_locker_meta;
            const auto leaf_0x19 = cpu_id(0x19, 0x00);

            // ecx register
            if (leaf_0x19.eax_bit(0u)) result |= loadiwkey_no_backup_parameter;
            if (leaf_0x19.eax_bit(1u)) result |= key_source_encoding_of_1;
        }

        return result;
    }
} // namespace based::platform::x86::detail

