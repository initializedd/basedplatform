#pragma once

#include <cstdint>
#include <utility>

#include "cpu_id.hpp"
#include "../../util.hpp"

// SVM Revision Number
// https://en.wikipedia.org/wiki/CPUID#EAX=8000000Ah:_Secure_Virtual_Machine_features

namespace based::platform::x86::detail {
    enum class cpu_svm_revision_info : std::uint8_t {
        svm_revision_num_bit_0,
        svm_revision_num_bit_1,
        svm_revision_num_bit_2,
        svm_revision_num_bit_3,
        svm_revision_num_bit_4,
        svm_revision_num_bit_5,
        svm_revision_num_bit_6,
        svm_revision_num_bit_7
        // bits 31:8 reserved
    }; // enum class cpu_svm_revision_info : std::uint8_t

    enum class cpu_svm_revision_info_mask : std::uint32_t {
        svm_revision_num = 1u << std::to_underlying(cpu_svm_revision_info::svm_revision_num_bit_0)
                         | 1u << std::to_underlying(cpu_svm_revision_info::svm_revision_num_bit_1)
                         | 1u << std::to_underlying(cpu_svm_revision_info::svm_revision_num_bit_2)
                         | 1u << std::to_underlying(cpu_svm_revision_info::svm_revision_num_bit_3)
                         | 1u << std::to_underlying(cpu_svm_revision_info::svm_revision_num_bit_4)
                         | 1u << std::to_underlying(cpu_svm_revision_info::svm_revision_num_bit_5)
                         | 1u << std::to_underlying(cpu_svm_revision_info::svm_revision_num_bit_6)
                         | 1u << std::to_underlying(cpu_svm_revision_info::svm_revision_num_bit_7)
    }; // enum class cpu_svm_revision_info_mask : std::uint32_t

    [[nodiscard]]
    inline cpu_svm_revision_info_mask supported_cpu_svm_revision_info(const std::uint32_t max_leaf) noexcept {
        auto result = cpu_svm_revision_info_mask{};

        if (max_leaf >= 0x8000000A) {
            using enum cpu_svm_revision_info;
            const auto leaf_0x8000000a = cpu_id(0x8000000A, 0x00);

            // eax register
            if (leaf_0x8000000a.eax_bit(0u)) result |= svm_revision_num_bit_0;
            if (leaf_0x8000000a.eax_bit(1u)) result |= svm_revision_num_bit_1;
            if (leaf_0x8000000a.eax_bit(2u)) result |= svm_revision_num_bit_2;
            if (leaf_0x8000000a.eax_bit(3u)) result |= svm_revision_num_bit_3;
            if (leaf_0x8000000a.eax_bit(4u)) result |= svm_revision_num_bit_4;
            if (leaf_0x8000000a.eax_bit(5u)) result |= svm_revision_num_bit_5;
            if (leaf_0x8000000a.eax_bit(6u)) result |= svm_revision_num_bit_6;
            if (leaf_0x8000000a.eax_bit(7u)) result |= svm_revision_num_bit_7;
        }

        return result;
    }
} // namespace based::platform::x86::detail

