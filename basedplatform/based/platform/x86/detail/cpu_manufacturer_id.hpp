#pragma once

#include <cstdint>
#include <string>

#include "cpu_id.hpp"

// Manufacturer ID
// https://en.wikipedia.org/wiki/CPUID#EAX=0:_Highest_Function_Parameter_and_Manufacturer_ID

namespace based::platform::x86::detail {
    [[nodiscard]]
    inline std::string cpu_manufacturer_id(const std::uint32_t max_leaf) noexcept {
        std::string result = "";

        if (max_leaf >= 0x00) {
            result.reserve(12u);
            const auto leaf_0x00 = cpu_id(0x00, 0x00);

            result += static_cast<char>((leaf_0x00.ebx >>  0u) & 0xff); // ebx byte 0
            result += static_cast<char>((leaf_0x00.ebx >>  8u) & 0xff); // ebx byte 1
            result += static_cast<char>((leaf_0x00.ebx >> 16u) & 0xff); // ebx byte 2
            result += static_cast<char>((leaf_0x00.ebx >> 24u) & 0xff); // ebx byte 3

            result += static_cast<char>((leaf_0x00.edx >>  0u) & 0xff); // edx byte 0
            result += static_cast<char>((leaf_0x00.edx >>  8u) & 0xff); // edx byte 1
            result += static_cast<char>((leaf_0x00.edx >> 16u) & 0xff); // edx byte 2
            result += static_cast<char>((leaf_0x00.edx >> 24u) & 0xff); // edx byte 3

            result += static_cast<char>((leaf_0x00.ecx >>  0u) & 0xff); // ecx byte 0
            result += static_cast<char>((leaf_0x00.ecx >>  8u) & 0xff); // ecx byte 1
            result += static_cast<char>((leaf_0x00.ecx >> 16u) & 0xff); // ecx byte 2
            result += static_cast<char>((leaf_0x00.ecx >> 24u) & 0xff); // ecx byte 3
        }

        return result;
    }
} // namespace based::platform::x86::detail

