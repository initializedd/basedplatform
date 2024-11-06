#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"
#include "../../util.hpp"

// Virtual and Physical Address Info
// https://en.wikipedia.org/wiki/CPUID#EAX=80000008h:_Virtual_and_Physical_address_Sizes

namespace based::platform::x86::detail {
    enum class cpu_address_info : std::uint8_t {
        num_of_physical_address_bit_0,
        num_of_physical_address_bit_1,
        num_of_physical_address_bit_2,
        num_of_physical_address_bit_3,
        num_of_physical_address_bit_4,
        num_of_physical_address_bit_5,
        num_of_physical_address_bit_6,
        num_of_physical_address_bit_7,
        num_of_linear_address_bit_0,
        num_of_linear_address_bit_1,
        num_of_linear_address_bit_2,
        num_of_linear_address_bit_3,
        num_of_linear_address_bit_4,
        num_of_linear_address_bit_5,
        num_of_linear_address_bit_6,
        num_of_linear_address_bit_7,
        guest_physical_address_size_bit_0,
        guest_physical_address_size_bit_1,
        guest_physical_address_size_bit_2,
        guest_physical_address_size_bit_3,
        guest_physical_address_size_bit_4,
        guest_physical_address_size_bit_5,
        guest_physical_address_size_bit_6,
        guest_physical_address_size_bit_7
        // bits 31:24 reserved
    }; // enum class cpu_address_info : std::uint8_t

    enum class cpu_address_info_mask : std::uint32_t {
        num_of_physical_address     = 1u << std::to_underlying(cpu_address_info::num_of_physical_address_bit_0)
                                    | 1u << std::to_underlying(cpu_address_info::num_of_physical_address_bit_1)
                                    | 1u << std::to_underlying(cpu_address_info::num_of_physical_address_bit_2)
                                    | 1u << std::to_underlying(cpu_address_info::num_of_physical_address_bit_3)
                                    | 1u << std::to_underlying(cpu_address_info::num_of_physical_address_bit_4)
                                    | 1u << std::to_underlying(cpu_address_info::num_of_physical_address_bit_5)
                                    | 1u << std::to_underlying(cpu_address_info::num_of_physical_address_bit_6)
                                    | 1u << std::to_underlying(cpu_address_info::num_of_physical_address_bit_7),
        num_of_linear_address       = 1u << std::to_underlying(cpu_address_info::num_of_linear_address_bit_0)
                                    | 1u << std::to_underlying(cpu_address_info::num_of_linear_address_bit_1)
                                    | 1u << std::to_underlying(cpu_address_info::num_of_linear_address_bit_2)
                                    | 1u << std::to_underlying(cpu_address_info::num_of_linear_address_bit_3)
                                    | 1u << std::to_underlying(cpu_address_info::num_of_linear_address_bit_4)
                                    | 1u << std::to_underlying(cpu_address_info::num_of_linear_address_bit_5)
                                    | 1u << std::to_underlying(cpu_address_info::num_of_linear_address_bit_6)
                                    | 1u << std::to_underlying(cpu_address_info::num_of_linear_address_bit_7),
        guest_physical_address_size = 1u << std::to_underlying(cpu_address_info::guest_physical_address_size_bit_0)
                                    | 1u << std::to_underlying(cpu_address_info::guest_physical_address_size_bit_1)
                                    | 1u << std::to_underlying(cpu_address_info::guest_physical_address_size_bit_2)
                                    | 1u << std::to_underlying(cpu_address_info::guest_physical_address_size_bit_3)
                                    | 1u << std::to_underlying(cpu_address_info::guest_physical_address_size_bit_4)
                                    | 1u << std::to_underlying(cpu_address_info::guest_physical_address_size_bit_5)
                                    | 1u << std::to_underlying(cpu_address_info::guest_physical_address_size_bit_6)
                                    | 1u << std::to_underlying(cpu_address_info::guest_physical_address_size_bit_7)
    }; // enum class cpu_address_info_mask : std::uint32_t

    [[nodiscard]]
    inline cpu_address_info_mask supported_cpu_address_info(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_address_info_mask{};

        if (max_leaf >= 0x80000008) {
            using enum cpu_address_info;
            const auto leaf_0x80000008 = cpu_id(0x80000008, 0x00);

            // eax register
            if (leaf_0x80000008.eax_bit( 0u)) result |= num_of_physical_address_bit_0;
            if (leaf_0x80000008.eax_bit( 1u)) result |= num_of_physical_address_bit_1;
            if (leaf_0x80000008.eax_bit( 2u)) result |= num_of_physical_address_bit_2;
            if (leaf_0x80000008.eax_bit( 3u)) result |= num_of_physical_address_bit_3;
            if (leaf_0x80000008.eax_bit( 4u)) result |= num_of_physical_address_bit_4;
            if (leaf_0x80000008.eax_bit( 5u)) result |= num_of_physical_address_bit_5;
            if (leaf_0x80000008.eax_bit( 6u)) result |= num_of_physical_address_bit_6;
            if (leaf_0x80000008.eax_bit( 7u)) result |= num_of_physical_address_bit_7;
            if (leaf_0x80000008.eax_bit( 8u)) result |= num_of_linear_address_bit_0;
            if (leaf_0x80000008.eax_bit( 9u)) result |= num_of_linear_address_bit_1;
            if (leaf_0x80000008.eax_bit(10u)) result |= num_of_linear_address_bit_2;
            if (leaf_0x80000008.eax_bit(11u)) result |= num_of_linear_address_bit_3;
            if (leaf_0x80000008.eax_bit(12u)) result |= num_of_linear_address_bit_4;
            if (leaf_0x80000008.eax_bit(13u)) result |= num_of_linear_address_bit_5;
            if (leaf_0x80000008.eax_bit(14u)) result |= num_of_linear_address_bit_6;
            if (leaf_0x80000008.eax_bit(15u)) result |= num_of_linear_address_bit_7;
            if (leaf_0x80000008.eax_bit(16u)) result |= guest_physical_address_size_bit_0;
            if (leaf_0x80000008.eax_bit(17u)) result |= guest_physical_address_size_bit_1;
            if (leaf_0x80000008.eax_bit(18u)) result |= guest_physical_address_size_bit_2;
            if (leaf_0x80000008.eax_bit(19u)) result |= guest_physical_address_size_bit_3;
            if (leaf_0x80000008.eax_bit(20u)) result |= guest_physical_address_size_bit_4;
            if (leaf_0x80000008.eax_bit(21u)) result |= guest_physical_address_size_bit_5;
            if (leaf_0x80000008.eax_bit(22u)) result |= guest_physical_address_size_bit_6;
            if (leaf_0x80000008.eax_bit(23u)) result |= guest_physical_address_size_bit_7;
        }

        return result;
    }
} // namespace based::platform::x86::detail

