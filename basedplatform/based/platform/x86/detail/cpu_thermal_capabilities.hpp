#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

// CPU Thermal Capabilities
// https://en.wikipedia.org/wiki/CPUID#EAX=6:_Thermal_and_power_management

namespace based::platform::x86::detail {
    enum class cpu_thermal_capability : std::uint8_t {
        dts,
        itbt,
        arat,
        // bit 3 reserved
        pln                               = 4u,
        ecmd,
        ptm,
        hwp,
        hwp_notification,
        hwp_activity_window,
        hwp_energy_performance_preference,
        hwp_package_level_request,
        // bit 12 reserved
        hdc                               = 13u,
        itbt3,
        hwp_interrupt,
        hwp_peci,
        hwp_flexible,
        hwp_fast_request,
        hw_feedback,
        hwp_ignore_request,
        // bit 21 reserved
        hwp_ctl                           = 22u,
        thread_director,
        therm_interrupt
        // bits 31:25 reserved
    }; // enum class cpu_thermal_capability : std::uint8_t

    enum class cpu_thermal_capability_mask : std::uint32_t {
        dts                               = 1u << std::to_underlying(cpu_thermal_capability::dts),
        itbt                              = 1u << std::to_underlying(cpu_thermal_capability::itbt),
        arat                              = 1u << std::to_underlying(cpu_thermal_capability::arat),
        pln                               = 1u << std::to_underlying(cpu_thermal_capability::pln),
        ecmd                              = 1u << std::to_underlying(cpu_thermal_capability::ecmd),
        ptm                               = 1u << std::to_underlying(cpu_thermal_capability::ptm),
        hwp                               = 1u << std::to_underlying(cpu_thermal_capability::hwp),
        hwp_notification                  = 1u << std::to_underlying(cpu_thermal_capability::hwp_notification),
        hwp_activity_window               = 1u << std::to_underlying(cpu_thermal_capability::hwp_activity_window),
        hwp_energy_performance_preference = 1u << std::to_underlying(cpu_thermal_capability::hwp_energy_performance_preference),
        hwp_package_level_request         = 1u << std::to_underlying(cpu_thermal_capability::hwp_package_level_request),
        hdc                               = 1u << std::to_underlying(cpu_thermal_capability::hdc),
        itbt3                             = 1u << std::to_underlying(cpu_thermal_capability::itbt3),
        hwp_interrupt                     = 1u << std::to_underlying(cpu_thermal_capability::hwp_interrupt),
        hwp_peci                          = 1u << std::to_underlying(cpu_thermal_capability::hwp_flexible),
        hwp_flexible                      = 1u << std::to_underlying(cpu_thermal_capability::hwp_flexible),
        hwp_fast_request                  = 1u << std::to_underlying(cpu_thermal_capability::hwp_fast_request),
        hw_feedback                       = 1u << std::to_underlying(cpu_thermal_capability::hw_feedback),
        hwp_ignore_request                = 1u << std::to_underlying(cpu_thermal_capability::hwp_ignore_request),
        hwp_ctl                           = 1u << std::to_underlying(cpu_thermal_capability::hwp_ctl),
        thread_director                   = 1u << std::to_underlying(cpu_thermal_capability::thread_director),
        therm_interrupt                   = 1u << std::to_underlying(cpu_thermal_capability::therm_interrupt)
    }; // enum class cpu_thermal_capability_mask : std::uint32_t

    [[nodiscard]]
    cpu_thermal_capability_mask supported_cpu_thermal_capabilities(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_thermal_capability_mask{};

        if (max_leaf >= 0x06) {
            using enum cpu_thermal_capability;
            const auto leaf_0x06 = cpu_id(0x06, 0x00);

            // eax register
            if (leaf_0x06.eax_bit( 0u)) result |= dts;
            if (leaf_0x06.eax_bit( 1u)) result |= itbt;
            if (leaf_0x06.eax_bit( 2u)) result |= arat;
            if (leaf_0x06.eax_bit( 4u)) result |= pln;
            if (leaf_0x06.eax_bit( 5u)) result |= ecmd;
            if (leaf_0x06.eax_bit( 6u)) result |= ptm;
            if (leaf_0x06.eax_bit( 7u)) result |= hwp;
            if (leaf_0x06.eax_bit( 8u)) result |= hwp_notification;
            if (leaf_0x06.eax_bit( 9u)) result |= hwp_activity_window;
            if (leaf_0x06.eax_bit(10u)) result |= hwp_energy_performance_preference;
            if (leaf_0x06.eax_bit(11u)) result |= hwp_package_level_request;
            if (leaf_0x06.eax_bit(13u)) result |= hdc;
            if (leaf_0x06.eax_bit(14u)) result |= itbt3;
            if (leaf_0x06.eax_bit(15u)) result |= hwp_interrupt;
            if (leaf_0x06.eax_bit(16u)) result |= hwp_peci;
            if (leaf_0x06.eax_bit(17u)) result |= hwp_flexible;
            if (leaf_0x06.eax_bit(18u)) result |= hwp_fast_request;
            if (leaf_0x06.eax_bit(19u)) result |= hw_feedback;
            if (leaf_0x06.eax_bit(20u)) result |= hwp_ignore_request;
            if (leaf_0x06.eax_bit(22u)) result |= hwp_ctl;
            if (leaf_0x06.eax_bit(23u)) result |= thread_director;
            if (leaf_0x06.eax_bit(24u)) result |= therm_interrupt;
        }

        return result;
    }
} // namespace based::platform::x86::detail

