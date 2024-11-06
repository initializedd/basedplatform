#pragma once

#include <cstdint>
#include <string>

#include "cpu_id.hpp"
#include "../../util.hpp"

// Processor Brand String
// https://en.wikipedia.org/wiki/CPUID#EAX=80000002h,80000003h,80000004h:_Processor_Brand_String

namespace based::platform::x86::detail {
    [[nodiscard]]
    inline std::string cpu_vendor(const std::uint32_t max_leaf) noexcept {
        std::string result = "";

        if (max_leaf >= 0x80000004) {
            result.reserve(48u);
            const auto leaf_0x80000002 = cpu_id(0x80000002, 0x00);

            result += static_cast<char>((leaf_0x80000002.eax >>  0u) & 0xff); // eax byte 0
            result += static_cast<char>((leaf_0x80000002.eax >>  8u) & 0xff); // eax byte 1
            result += static_cast<char>((leaf_0x80000002.eax >> 16u) & 0xff); // eax byte 2
            result += static_cast<char>((leaf_0x80000002.eax >> 24u) & 0xff); // eax byte 3

            result += static_cast<char>((leaf_0x80000002.ebx >>  0u) & 0xff); // ebx byte 0
            result += static_cast<char>((leaf_0x80000002.ebx >>  8u) & 0xff); // ebx byte 1
            result += static_cast<char>((leaf_0x80000002.ebx >> 16u) & 0xff); // ebx byte 2
            result += static_cast<char>((leaf_0x80000002.ebx >> 24u) & 0xff); // ebx byte 3

            result += static_cast<char>((leaf_0x80000002.ecx >>  0u) & 0xff); // ecx byte 0
            result += static_cast<char>((leaf_0x80000002.ecx >>  8u) & 0xff); // ecx byte 1
            result += static_cast<char>((leaf_0x80000002.ecx >> 16u) & 0xff); // ecx byte 2
            result += static_cast<char>((leaf_0x80000002.ecx >> 24u) & 0xff); // ecx byte 3

            result += static_cast<char>((leaf_0x80000002.edx >>  0u) & 0xff); // edx byte 0
            result += static_cast<char>((leaf_0x80000002.edx >>  8u) & 0xff); // edx byte 1
            result += static_cast<char>((leaf_0x80000002.edx >> 16u) & 0xff); // edx byte 2
            result += static_cast<char>((leaf_0x80000002.edx >> 24u) & 0xff); // edx byte 3

            const auto leaf_0x80000003 = cpu_id(0x80000003, 0x00);

            result += static_cast<char>((leaf_0x80000003.eax >>  0u) & 0xff); // eax byte 0
            result += static_cast<char>((leaf_0x80000003.eax >>  8u) & 0xff); // eax byte 1
            result += static_cast<char>((leaf_0x80000003.eax >> 16u) & 0xff); // eax byte 2
            result += static_cast<char>((leaf_0x80000003.eax >> 24u) & 0xff); // eax byte 3

            result += static_cast<char>((leaf_0x80000003.ebx >>  0u) & 0xff); // ebx byte 0
            result += static_cast<char>((leaf_0x80000003.ebx >>  8u) & 0xff); // ebx byte 1
            result += static_cast<char>((leaf_0x80000003.ebx >> 16u) & 0xff); // ebx byte 2
            result += static_cast<char>((leaf_0x80000003.ebx >> 24u) & 0xff); // ebx byte 3

            result += static_cast<char>((leaf_0x80000003.ecx >>  0u) & 0xff); // ecx byte 0
            result += static_cast<char>((leaf_0x80000003.ecx >>  8u) & 0xff); // ecx byte 1
            result += static_cast<char>((leaf_0x80000003.ecx >> 16u) & 0xff); // ecx byte 2
            result += static_cast<char>((leaf_0x80000003.ecx >> 24u) & 0xff); // ecx byte 3

            result += static_cast<char>((leaf_0x80000003.edx >>  0u) & 0xff); // edx byte 0
            result += static_cast<char>((leaf_0x80000003.edx >>  8u) & 0xff); // edx byte 1
            result += static_cast<char>((leaf_0x80000003.edx >> 16u) & 0xff); // edx byte 2
            result += static_cast<char>((leaf_0x80000003.edx >> 24u) & 0xff); // edx byte 3

            const auto leaf_0x80000004 = cpu_id(0x80000004, 0x00);

            result += static_cast<char>((leaf_0x80000004.eax >>  0u) & 0xff); // eax byte 0
            result += static_cast<char>((leaf_0x80000004.eax >>  8u) & 0xff); // eax byte 1
            result += static_cast<char>((leaf_0x80000004.eax >> 16u) & 0xff); // eax byte 2
            result += static_cast<char>((leaf_0x80000004.eax >> 24u) & 0xff); // eax byte 3

            result += static_cast<char>((leaf_0x80000004.ebx >>  0u) & 0xff); // ebx byte 0
            result += static_cast<char>((leaf_0x80000004.ebx >>  8u) & 0xff); // ebx byte 1
            result += static_cast<char>((leaf_0x80000004.ebx >> 16u) & 0xff); // ebx byte 2
            result += static_cast<char>((leaf_0x80000004.ebx >> 24u) & 0xff); // ebx byte 3

            result += static_cast<char>((leaf_0x80000004.ecx >>  0u) & 0xff); // ecx byte 0
            result += static_cast<char>((leaf_0x80000004.ecx >>  8u) & 0xff); // ecx byte 1
            result += static_cast<char>((leaf_0x80000004.ecx >> 16u) & 0xff); // ecx byte 2
            result += static_cast<char>((leaf_0x80000004.ecx >> 24u) & 0xff); // ecx byte 3

            result += static_cast<char>((leaf_0x80000004.edx >>  0u) & 0xff); // edx byte 0
            result += static_cast<char>((leaf_0x80000004.edx >>  8u) & 0xff); // edx byte 1
            result += static_cast<char>((leaf_0x80000004.edx >> 16u) & 0xff); // edx byte 2
            result += static_cast<char>((leaf_0x80000004.edx >> 24u) & 0xff); // edx byte 3
        }

        return result;
    }
} // namespace based::platform::x86::detail

