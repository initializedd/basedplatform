#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"
#include "../../util.hpp"

// CPU Cache Features
// https://en.wikipedia.org/wiki/CPUID#EAX=4_and_EAX=8000001Dh:_Cache_hierarchy_and_topology

namespace based::platform::x86::detail {
    enum class cpu_cache_feature : std::uint8_t {
        wbinvd_cache_invalidation_execution_scope,
        cache_inclusiveness,
        complex_cache_indexing
        // bits 31:3 reserved
    }; // enum class cpu_cache_feature : std::uint8_t

    enum class cpu_cache_feature_mask : std::uint32_t {
        wbinvd_cache_invalidation_execution_scope = 1u << std::to_underlying(cpu_cache_feature::wbinvd_cache_invalidation_execution_scope),
        cache_inclusiveness                       = 1u << std::to_underlying(cpu_cache_feature::cache_inclusiveness),
        complex_cache_indexing                    = 1u << std::to_underlying(cpu_cache_feature::complex_cache_indexing)
    }; // enum class cpu_cache_feature_mask : std::uint32_t

    [[nodiscard]]
    inline cpu_cache_feature_mask supported_cpu_cache_features(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_cache_feature_mask{};

        if (max_leaf >= 0x04) {
            using enum cpu_cache_feature;
            const auto leaf_0x04 = cpu_id(0x04, 0x00);

            // edx register
            if (leaf_0x04.edx_bit(0u)) result |= wbinvd_cache_invalidation_execution_scope;
            if (leaf_0x04.edx_bit(1u)) result |= cache_inclusiveness;
            if (leaf_0x04.edx_bit(2u)) result |= complex_cache_indexing;
        }

        return result;
    }
} // namespace based::platform::x86::detail

