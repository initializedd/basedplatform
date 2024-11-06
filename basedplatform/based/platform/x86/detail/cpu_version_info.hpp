#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"
#include "../../util.hpp"

// Processor Version Information in EAX
// https://en.wikipedia.org/wiki/CPUID#EAX=1:_Processor_Info_and_Feature_Bits

namespace based::platform::x86::detail {
    enum class cpu_version_info : std::uint8_t {
        stepping_id_bit_0,
        stepping_id_bit_1,
        stepping_id_bit_2,
        stepping_id_bit_3,
        model_bit_0,
        model_bit_1,
        model_bit_2,
        model_bit_3,
        family_id_bit_0,
        family_id_bit_1,
        family_id_bit_2,
        family_id_bit_3,
        processor_type_bit_0,
        processor_type_bit_1,
        // bits 15:14 reserved
        extended_model_id_bit_0  = 16u,
        extended_model_id_bit_1,
        extended_model_id_bit_2,
        extended_model_id_bit_3,
        extended_family_id_bit_0,
        extended_family_id_bit_1,
        extended_family_id_bit_2,
        extended_family_id_bit_3,
        extended_family_id_bit_4,
        extended_family_id_bit_5,
        extended_family_id_bit_6,
        extended_family_id_bit_7
        // bits 31:28 reserved
    }; // enum class cpu_version_info : std::uint8_t

    enum class cpu_version_info_mask : std::uint32_t {
        stepping_id        = 1u << std::to_underlying(cpu_version_info::stepping_id_bit_0)
                           | 1u << std::to_underlying(cpu_version_info::stepping_id_bit_1)
                           | 1u << std::to_underlying(cpu_version_info::stepping_id_bit_2)
                           | 1u << std::to_underlying(cpu_version_info::stepping_id_bit_3),
        model              = 1u << std::to_underlying(cpu_version_info::model_bit_0)
                           | 1u << std::to_underlying(cpu_version_info::model_bit_1)
                           | 1u << std::to_underlying(cpu_version_info::model_bit_2)
                           | 1u << std::to_underlying(cpu_version_info::model_bit_3),
        family_id          = 1u << std::to_underlying(cpu_version_info::family_id_bit_0)
                           | 1u << std::to_underlying(cpu_version_info::family_id_bit_1)
                           | 1u << std::to_underlying(cpu_version_info::family_id_bit_2)
                           | 1u << std::to_underlying(cpu_version_info::family_id_bit_3),
        processor_type     = 1u << std::to_underlying(cpu_version_info::processor_type_bit_0)
                           | 1u << std::to_underlying(cpu_version_info::processor_type_bit_1),
        extended_model_id  = 1u << std::to_underlying(cpu_version_info::extended_model_id_bit_0)
                           | 1u << std::to_underlying(cpu_version_info::extended_model_id_bit_1)
                           | 1u << std::to_underlying(cpu_version_info::extended_model_id_bit_2)
                           | 1u << std::to_underlying(cpu_version_info::extended_model_id_bit_3),
        extended_family_id = 1u << std::to_underlying(cpu_version_info::extended_family_id_bit_0)
                           | 1u << std::to_underlying(cpu_version_info::extended_family_id_bit_1)
                           | 1u << std::to_underlying(cpu_version_info::extended_family_id_bit_2)
                           | 1u << std::to_underlying(cpu_version_info::extended_family_id_bit_3)
                           | 1u << std::to_underlying(cpu_version_info::extended_family_id_bit_4)
                           | 1u << std::to_underlying(cpu_version_info::extended_family_id_bit_5)
                           | 1u << std::to_underlying(cpu_version_info::extended_family_id_bit_6)
                           | 1u << std::to_underlying(cpu_version_info::extended_family_id_bit_7)
    }; // enum class cpu_version_info_mask : std::uint32_t

    [[nodiscard]]
    inline cpu_version_info_mask supported_cpu_version_info(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_version_info_mask{};

        if (max_leaf >= 0x01) {
            using enum cpu_version_info;
            const auto leaf_0x01 = cpu_id(0x01, 0x00);

            if (leaf_0x01.eax_bit( 0u)) result |= stepping_id_bit_0;
            if (leaf_0x01.eax_bit( 1u)) result |= stepping_id_bit_1;
            if (leaf_0x01.eax_bit( 2u)) result |= stepping_id_bit_2;
            if (leaf_0x01.eax_bit( 3u)) result |= stepping_id_bit_3;
            if (leaf_0x01.eax_bit( 4u)) result |= model_bit_0;
            if (leaf_0x01.eax_bit( 5u)) result |= model_bit_1;
            if (leaf_0x01.eax_bit( 6u)) result |= model_bit_2;
            if (leaf_0x01.eax_bit( 7u)) result |= model_bit_3;
            if (leaf_0x01.eax_bit( 8u)) result |= family_id_bit_0;
            if (leaf_0x01.eax_bit( 9u)) result |= family_id_bit_1;
            if (leaf_0x01.eax_bit(10u)) result |= family_id_bit_2;
            if (leaf_0x01.eax_bit(11u)) result |= family_id_bit_3;
            if (leaf_0x01.eax_bit(12u)) result |= processor_type_bit_0;
            if (leaf_0x01.eax_bit(13u)) result |= processor_type_bit_1;
            if (leaf_0x01.eax_bit(16u)) result |= extended_model_id_bit_0;
            if (leaf_0x01.eax_bit(17u)) result |= extended_model_id_bit_1;
            if (leaf_0x01.eax_bit(18u)) result |= extended_model_id_bit_2;
            if (leaf_0x01.eax_bit(19u)) result |= extended_model_id_bit_3;
            if (leaf_0x01.eax_bit(20u)) result |= extended_family_id_bit_0;
            if (leaf_0x01.eax_bit(21u)) result |= extended_family_id_bit_1;
            if (leaf_0x01.eax_bit(22u)) result |= extended_family_id_bit_2;
            if (leaf_0x01.eax_bit(23u)) result |= extended_family_id_bit_3;
            if (leaf_0x01.eax_bit(24u)) result |= extended_family_id_bit_4;
            if (leaf_0x01.eax_bit(25u)) result |= extended_family_id_bit_5;
            if (leaf_0x01.eax_bit(26u)) result |= extended_family_id_bit_6;
            if (leaf_0x01.eax_bit(27u)) result |= extended_family_id_bit_7;
        }

        return result;
    }
} // namespace based::platform::x86::detail

