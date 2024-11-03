#pragma once

#include <cstdint>
#include <utility>
#include <bitset>

#include "cpu_id.hpp"

// Cache and TLB Descriptor information
// https://en.wikipedia.org/wiki/CPUID#EAX=2:_Cache_and_TLB_Descriptor_information

namespace based::platform::x86::detail {
    enum class cpu_descriptor : std::uint8_t {
        null_descriptor,
        itlb_32e_4kp_4a,
        itlb_2e_4mp_fa,
        dtlb_64e_4kp_fa,
        dtlb_8e_4mp_4a,
        dtlb_32e_4mp_4a,
        l1i_8k_4a_32l,
        l1i_16k_4a_32l_0                           = 8u,
        l1i_32k_4a_64l,
        l1d_8k_2a_32l,
        itlb_4e_4mp_fa,
        l1d_16k_4a_32l_0,
        l1d_16k_4a_64l_0,
        l1d_24k_6a_64l,
        l1d_16k_4a_32l_1                           = 16u,
        l1i_16k_4a_32l_1                           = 21u,
        l2c_96k_6a_64l                             = 26u,
        l2c_128k_2a_64l                            = 29u,
        l2c_256k_8a_64l                            = 33u,
        l3c_512k_4a_64l_2s,
        l3c_1m_8a_64l_2s,
        l2c_1m_16a_64l,
        l3c_2m_8a_64l_2s,
        prefetch_128_byte_0,
        prefetch_128_byte_1,
        prefetch_128_byte_2,
        l3c_4m_8a_64l_2s,
        l1d_32k_8a_64l                             = 44u,
        l1i_32k_8a_64l                             = 48u,
        l2c_128k_4a_64l_2s                         = 57u,
        l2c_192k_6a_64l_2s,
        l2c_128k_2a_64l_2s,
        l2c_256k_4a_64l_2s,
        l2c_384k_6a_64l_2s,
        l2c_512k_4a_64l_2s,
        no_l3_cache_present                        = 64u,
        l2c_128k_4a_32l,
        l2c_256k_4a_32l,
        l2c_512k_4a_32l,
        l2c_1m_4a_32l,
        l2c_2m_4a_32l,
        l3c_4m_4a_64l_0,
        l3c_8m_8a_64l,
        l2c_3m_12a_64l,
        l2c_l3c_4m_16a_64l,
        l3c_6m_12a_64l_0,
        l3c_8m_16a_64l_0,
        l3c_12m_12a_64l,
        l3c_16m_16a_64l,
        l2c_6m_24a_64l,
        itlb_32e_4kp,
        itlb_64e_fa_4k_2m_4mp,
        itlb_128e_fa_4k_2m_4mp,
        itlb_256e_fa_4k_2m_4mp,
        itlb_7e_2m_4mp_fa                          = 85u,
        dtlb_16e_4mp_4a,
        dtlb_16e_4kp_4a,
        dtlb_16e_4kp_fa                            = 89u,
        dtlb_32e_2m_4mp_4a_0,
        dtlb_64e_4k_4mp_fa,
        dtlb_128e_4k_4mp_fa,
        dtlb_256e_4k_4mp_fa,
        l1d_16k_8a_64l                             = 96u,
        itlb_48e_4kp_fa,
        dtlb_32e_2m_4mp_4a_dtlb_4e_1gp_fa,
        dtlb_512e_4kp_4a,
        l1d_8k_4a_64l                              = 102u,
        l1d_16k_4a_64l_1,
        l1d_32k_4a_64l,
        dtlb_64e_4kp_8a                            = 106u,
        dtlb_256e_4kp_8a,
        dtlb_128e_2m_4mp_8a,
        dtlb_16e_1gp_fa,
        trace_cache_12k_micro_op_8a                = 112u,
        trace_cache_16k_micro_op_8a,
        trace_cache_32k_micro_op_8a,
        trace_cache_64k_micro_op_8a,
        itlb_8e_2m_4mp_fa                          = 118u,
        l1i_16k_4a_64l,
        l2c_1m_4a_64l,
        l2c_128k_8a_64l_2s,
        l2c_256k_8a_64l_2s,
        l2c_512k_8a_64l_2s,
        l2c_1m_8a_64l_2s,
        l2c_2m_8a_64l,
        l2c_256k_8a_128l,
        l2c_512k_2a_64l,
        l2c_512k_8a_64l,
        l2c_128k_8a_32l,
        l2c_256k_8a_32l,
        l2c_512k_8a_32l,
        l2c_1m_8a_32l,
        l2c_2m_8a_32l,
        l2c_512k_4a_64l,
        l2c_1m_8a_64l,
        l3c_2m_4a_64l_0,
        l3c_4m_4a_64l_1,
        l3c_8m_4a_64l,
        l3c_3m_128_128l                            = 141u,
        itlb_64e_fa_4k_256mp                       = 144u,
        dtlb_32e_fa_4k_256mp                       = 150u,
        dtlb_96e_fa_4k_256mp                       = 155u,
        dtlb_32e_4kp_fa                            = 160u,
        itlb_128e_4kp_4a                           = 176u,
        itlb_8e_2m_4mp_4a,
        itlb_64e_4kp_4a,
        dtlb_128e_4kp_4a,
        dtlb_256e_4kp_4a,
        itlb_64e_4kp_8a,
        itlb_128e_4kp_8a,
        dtlb_64e_4kp_4a                            = 186u,
        dtlb_8e_4k_4mp_4a                          = 192u,
        l2tlb_1024e_4k_2mp_8a,
        dtlb_16e_2m_4mp_4a,
        l2_stlb_1536e_4k_2mp_6a_l2_stlb_16e_1gp_4a,
        dtlb_32e_2m_4mp_4a_1,
        l2tlb_512e_4kp_4a                          = 202u,
        l3c_512k_4a_64l                            = 208u,
        l3c_1m_4a_64l,
        l3c_2m_4a_64l_1,
        l3c_1m_8a_64l                              = 214u,
        l3c_2m_8a_64l,
        l3c_4m_8a_64l,
        l3c_1_5m_12a_64l                           = 220u,
        l3c_3m_12a_64l,
        l3c_6m_12a_64l_1,
        l3c_2m_16a_64l                             = 226u,
        l3c_4m_16a_64l,
        l3c_8m_16a_64l_1,
        l3c_12m_24a_64l                            = 234u,
        l3c_18m_24a_64l,
        l3c_24m_24a_64l,
        prefetch_64_byte                           = 240u,
        prefetch_128_byte,
        no_tlb_info                                = 254u,
        no_cache_info
    }; // enum class cpu_descriptor : std::uint8_t

    [[nodiscard]]
    inline std::bitset<256> supported_cpu_descriptors(const std::uint32_t max_leaf) noexcept {
        auto result = std::bitset<256>{};

        if (max_leaf >= 0x02) {
            const auto leaf_0x02 = cpu_id(0x02, 0x00);

            result.set((leaf_0x02.eax >>  0u) & 0xff); // eax byte 0
            result.set((leaf_0x02.eax >>  8u) & 0xff); // eax byte 1
            result.set((leaf_0x02.eax >> 16u) & 0xff); // eax byte 2
            result.set((leaf_0x02.eax >> 24u) & 0xff); // eax byte 3

            result.set((leaf_0x02.ebx >>  0u) & 0xff); // ebx byte 0
            result.set((leaf_0x02.ebx >>  8u) & 0xff); // ebx byte 1
            result.set((leaf_0x02.ebx >> 16u) & 0xff); // ebx byte 2
            result.set((leaf_0x02.ebx >> 24u) & 0xff); // ebx byte 3

            result.set((leaf_0x02.ecx >>  0u) & 0xff); // ecx byte 0
            result.set((leaf_0x02.ecx >>  8u) & 0xff); // ecx byte 1
            result.set((leaf_0x02.ecx >> 16u) & 0xff); // ecx byte 2
            result.set((leaf_0x02.ecx >> 24u) & 0xff); // ecx byte 3

            result.set((leaf_0x02.edx >>  0u) & 0xff); // edx byte 0
            result.set((leaf_0x02.edx >>  8u) & 0xff); // edx byte 1
            result.set((leaf_0x02.edx >> 16u) & 0xff); // edx byte 2
            result.set((leaf_0x02.edx >> 24u) & 0xff); // edx byte 3
        }

        return result;
    }
} // namespace based::platform::x86::detail

