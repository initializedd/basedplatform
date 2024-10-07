#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// SGX settable bits in SECS.ATTRIBUTES
// https://en.wikipedia.org/wiki/CPUID#EAX=12h:_SGX_capabilities

namespace based::platform::x86::detail {
    enum class cpu_secs_attribute : std::uint8_t {
        init,
        debug,
        mode64bit,
        // bit 3 reserved
        provisionkey,
        einittoken_key,
        cet,
        kss,
        // bits 9:8 reserved
        aexnotify
        // bits 31:11 reserved
    }; // enum class cpu_secs_attribute : std::uint8_t

    enum class cpu_secs_attribute_mask : std::uint32_t {
        init           = 1u << std::to_underlying(cpu_secs_attribute::init),
        debug          = 1u << std::to_underlying(cpu_secs_attribute::debug),
        provisionkey   = 1u << std::to_underlying(cpu_secs_attribute::provisionkey),
        einittoken_key = 1u << std::to_underlying(cpu_secs_attribute::einittoken_key),
        cet            = 1u << std::to_underlying(cpu_secs_attribute::cet),
        kss            = 1u << std::to_underlying(cpu_secs_attribute::kss),
        aexnotify      = 1u << std::to_underlying(cpu_secs_attribute::aexnotify)
    }; // enum class cpu_secs_attribute_mask : std::uint32_t

    [[nodiscard]]
    cpu_secs_attribute_mask supported_cpu_secs_attributes(const std::uint32_t max_leaf) noexcept {
         auto result = cpu_secs_attribute_mask{};

        if (max_leaf >= 0x12) {
            using cpu_secs_attribute;
            const auto leaf18 = cpu_id(0x12, 1u);

            // eax register
            if (leaf18.eax_bit( 0u)) result |= init;
            if (leaf18.eax_bit( 1u)) result |= debug;
            if (leaf18.eax_bit( 2u)) result |= mode64bit;
            if (leaf18.eax_bit( 4u)) result |= provisionkey;
            if (leaf18.eax_bit( 5u)) result |= einittoken_key;
            if (leaf18.eax_bit( 6u)) result |= cet;
            if (leaf18.eax_bit( 7u)) result |= kss;
            if (leaf18.eax_bit(10u)) result |= aexnotify;
        }

        return result;
    }
} // namespace based::platform::x86::detail

