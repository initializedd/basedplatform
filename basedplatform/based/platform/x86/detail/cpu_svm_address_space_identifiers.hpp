#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"

namespace based::platform::x86::detail {
    enum class cpu_svm_address_space_identifier : std::uint8_t {
        num_of_available_asids_bit_0,
        num_of_available_asids_bit_1,
        num_of_available_asids_bit_2,
        num_of_available_asids_bit_3,
        num_of_available_asids_bit_4,
        num_of_available_asids_bit_5,
        num_of_available_asids_bit_6,
        num_of_available_asids_bit_7,
        num_of_available_asids_bit_8,
        num_of_available_asids_bit_9,
        num_of_available_asids_bit_10,
        num_of_available_asids_bit_11,
        num_of_available_asids_bit_12,
        num_of_available_asids_bit_13,
        num_of_available_asids_bit_14,
        num_of_available_asids_bit_15,
        num_of_available_asids_bit_16,
        num_of_available_asids_bit_17,
        num_of_available_asids_bit_18,
        num_of_available_asids_bit_19,
        num_of_available_asids_bit_20,
        num_of_available_asids_bit_21,
        num_of_available_asids_bit_22,
        num_of_available_asids_bit_23,
        num_of_available_asids_bit_24,
        num_of_available_asids_bit_25,
        num_of_available_asids_bit_26,
        num_of_available_asids_bit_27,
        num_of_available_asids_bit_28,
        num_of_available_asids_bit_29,
        num_of_available_asids_bit_30,
        num_of_available_asids_bit_31
    }; // enum class cpu_svm_address_space_identifier : std::uint8_t

    enum class cpu_svm_address_space_identifier_mask : std::uint32_t {
        num_of_available_asids = 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_0)
                               | 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_1)
                               | 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_2)
                               | 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_3)
                               | 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_4)
                               | 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_5)
                               | 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_6)
                               | 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_7)
                               | 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_8)
                               | 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_9)
                               | 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_10)
                               | 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_11)
                               | 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_12)
                               | 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_13)
                               | 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_14)
                               | 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_15)
                               | 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_16)
                               | 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_17)
                               | 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_18)
                               | 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_19)
                               | 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_20)
                               | 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_21)
                               | 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_22)
                               | 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_23)
                               | 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_24)
                               | 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_25)
                               | 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_26)
                               | 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_27)
                               | 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_28)
                               | 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_29)
                               | 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_30)
                               | 1u << std::to_underlying(cpu_svm_address_space_identifier::num_of_available_asids_bit_31)
    }; // enum class cpu_svm_address_space_identifier_mask : std::uint32_t

    [[nodiscard]]
    cpu_svm_address_space_identifier_mask supported_cpu_svm_address_space_identifiers(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_svm_address_space_identifier_mask{};

        if (max_leaf >= 0x8000000A) {
            using cpu_svm_address_space_identifier;
            const auto leaf8 = cpu_id(0x8000000A, 0u);

            // ebx register
            if (leaf8.ebx_bit( 0u)) result |= num_of_available_asids_bit_0;
            if (leaf8.ebx_bit( 1u)) result |= num_of_available_asids_bit_1;
            if (leaf8.ebx_bit( 2u)) result |= num_of_available_asids_bit_2;
            if (leaf8.ebx_bit( 3u)) result |= num_of_available_asids_bit_3;
            if (leaf8.ebx_bit( 4u)) result |= num_of_available_asids_bit_4;
            if (leaf8.ebx_bit( 5u)) result |= num_of_available_asids_bit_5;
            if (leaf8.ebx_bit( 6u)) result |= num_of_available_asids_bit_6;
            if (leaf8.ebx_bit( 7u)) result |= num_of_available_asids_bit_7;
            if (leaf8.ebx_bit( 8u)) result |= num_of_available_asids_bit_8;
            if (leaf8.ebx_bit( 9u)) result |= num_of_available_asids_bit_9;
            if (leaf8.ebx_bit(10u)) result |= num_of_available_asids_bit_10;
            if (leaf8.ebx_bit(11u)) result |= num_of_available_asids_bit_11;
            if (leaf8.ebx_bit(12u)) result |= num_of_available_asids_bit_12;
            if (leaf8.ebx_bit(13u)) result |= num_of_available_asids_bit_13;
            if (leaf8.ebx_bit(14u)) result |= num_of_available_asids_bit_14;
            if (leaf8.ebx_bit(15u)) result |= num_of_available_asids_bit_15;
            if (leaf8.ebx_bit(16u)) result |= num_of_available_asids_bit_16;
            if (leaf8.ebx_bit(17u)) result |= num_of_available_asids_bit_17;
            if (leaf8.ebx_bit(18u)) result |= num_of_available_asids_bit_18;
            if (leaf8.ebx_bit(19u)) result |= num_of_available_asids_bit_19;
            if (leaf8.ebx_bit(20u)) result |= num_of_available_asids_bit_20;
            if (leaf8.ebx_bit(21u)) result |= num_of_available_asids_bit_21;
            if (leaf8.ebx_bit(22u)) result |= num_of_available_asids_bit_22;
            if (leaf8.ebx_bit(23u)) result |= num_of_available_asids_bit_23;
            if (leaf8.ebx_bit(24u)) result |= num_of_available_asids_bit_24;
            if (leaf8.ebx_bit(25u)) result |= num_of_available_asids_bit_25;
            if (leaf8.ebx_bit(26u)) result |= num_of_available_asids_bit_26;
            if (leaf8.ebx_bit(27u)) result |= num_of_available_asids_bit_27;
            if (leaf8.ebx_bit(28u)) result |= num_of_available_asids_bit_28;
            if (leaf8.ebx_bit(29u)) result |= num_of_available_asids_bit_29;
            if (leaf8.ebx_bit(30u)) result |= num_of_available_asids_bit_30;
            if (leaf8.ebx_bit(31u)) result |= num_of_available_asids_bit_31;
        }

        return result;
    }
} // namespace based::platform::x86::detail

