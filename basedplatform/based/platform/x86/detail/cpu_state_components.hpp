#pragma once

#include <cstdint>
#include <utility>

// XSAVE State-components
// https://en.wikipedia.org/wiki/CPUID#EAX=0Dh:_XSAVE_features_and_state-components

namespace based::platform::x86::detail {
    enum class cpu_state_component : std::uint16_t {
        x87_state,
        sse_state,
        avx_state,
        mpx_bnd0_bnd3_state,
        mpx_bndcfgu_bndstatus_state,
        avx512_k0_k7_state,
        avx512_zmm_hi256_state,
        avx512_hi16_zmm_state,
        processor_trace_state,
        pkru,
        pasid,
        cet_u_state,
        cet_s_state,
        hdc,
        uintr,
        lbr,
        hwp,
        amx_tile_config_state,
        amx_tile_data,
        apx,
        // bits 61:20 reserved
        lwp                         = 62u
        // bit 63 reserved
    }; // enum class cpu_state_component : std::uint16_t

    enum class cpu_state_component_mask : std::uint64_t {
        x87_state                   = 1u << std::to_underlying(cpu_state_component::x87_state),
        sse_state                   = 1u << std::to_underlying(cpu_state_component::sse_state),
        avx_state                   = 1u << std::to_underlying(cpu_state_component::avx_state),
        mpx_bnd0_bnd3_state         = 1u << std::to_underlying(cpu_state_component::mpx_bnd0_bnd3_state),
        mpx_bndcfgu_bndstatus_state = 1u << std::to_underlying(cpu_state_component::mpx_bndcfgu_bndstatus_state),
        avx512_k0_k7_state          = 1u << std::to_underlying(cpu_state_component::avx512_k0_k7_state),
        avx512_zmm_hi256_state      = 1u << std::to_underlying(cpu_state_component::avx512_zmm_hi256_state),
        avx512_hi16_zmm_state       = 1u << std::to_underlying(cpu_state_component::avx512_hi16_zmm_state),
        processor_trace_state       = 1u << std::to_underlying(cpu_state_component::processor_trace_state),
        pkru                        = 1u << std::to_underlying(cpu_state_component::pkru),
        pasid                       = 1u << std::to_underlying(cpu_state_component::pasid),
        cet_u_state                 = 1u << std::to_underlying(cpu_state_component::cet_u_state),
        cet_s_state                 = 1u << std::to_underlying(cpu_state_component::cet_s_state),
        hdc                         = 1u << std::to_underlying(cpu_state_component::hdc),
        uintr                       = 1u << std::to_underlying(cpu_state_component::uintr),
        lbr                         = 1u << std::to_underlying(cpu_state_component::lbr),
        hwp                         = 1u << std::to_underlying(cpu_state_component::hwp),
        amx_tile_config_state       = 1u << std::to_underlying(cpu_state_component::amx_tile_config_state),
        amx_tile_data               = 1u << std::to_underlying(cpu_state_component::amx_tile_data),
        apx                         = 1u << std::to_underlying(cpu_state_component::apx),
        lwp                         = 1u << std::to_underlying(cpu_state_component::lwp)
    }; // enum class cpu_state_component_mask : std::uint64_t
} // namespace based::platform::x86::detail

