#pragma once

// Operating System
// https://sourceforge.net/p/predef/wiki/OperatingSystems/

#if defined(_WIN32)
#    define BP_HAS_OS_WINDOWS 1
#elif defined(__APPLE__) && defined(__MACH__)
#    include "TargetConditionals.h"
#    if TARGET_OS_IPHONE || TARGET_OS_SIMULATOR
#        define BP_HAS_OS_IOS 1
#    elif TARGET_OS_MAC
#        define BP_HAS_OS_MACOS 1
#    endif
#elif defined(__ANDROID__)
#    define BP_HAS_OS_ANDROID 1
#elif defined(__linux__)
#    define BP_HAS_OS_LINUX 1
#elif defined(__unix__)
#    define BP_HAS_OS_UNIX 1
#else
#    define BP_HAS_OS_UNKNOWN 1
#endif

// Architecture
// https://sourceforge.net/p/predef/wiki/Architectures/

#if defined(__i386__) || defined(_M_IX86)
#    define BP_HAS_ARCH_X86 1
#elif defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64) || defined(_M_AMD64) || defined(_M_X64)
#    define BP_HAS_ARCH_X86_64 1
#elif defined(__arm__) || defined(_M_ARM)
#    define BP_HAS_ARCH_ARM 1
#elif defined(__aarch64__) || defined(_M_ARM64)
#    define BP_HAS_ARCH_ARM64 1
#else
#    define BP_HAS_ARCH_UNKNOWN 1
#endif

// Compiler
// https://sourceforge.net/p/predef/wiki/Compilers/

#if defined(_MSC_VER)
#    define BP_HAS_COMPILER_MSVC 1
#elif defined(__clang__)
#    define BP_HAS_COMPILER_CLANG 1
#elif defined(__GNUC__)
#    define BP_HAS_COMPILER_GCC 1
#else
#    define BP_HAS_COMPILER_UNKNOWN 1
#endif

// Features
// https://en.wikipedia.org/wiki/Streaming_SIMD_Extensions

#if BP_HAS_COMPILER_MSVC
#    if _M_IX86_FP >= 1 || BP_ARCHITECTURE == BP_ARCHITECTURE_X86_64
#        define BP_HAS_FEATURE_MMX 1
#        define BP_HAS_FEATURE_SSE 1
#    endif
#    if _M_IX86_FP >= 2 || BP_ARCHITECTURE == BP_ARCHITECTURE_X86_64
#        define BP_HAS_FEATURE_SSE2 1
#    endif
#    if defined(__AVX__)
#        define BP_HAS_FEATURE_SSE3 1
#        define BP_HAS_FEATURE_SSSE3 1
#        define BP_HAS_FEATURE_SSE4_1 1
#        define BP_HAS_FEATURE_SSE4_2 1
#        define BP_HAS_FEATURE_AVX 1
#    endif
#    if defined(__AVX2__)
#        define BP_HAS_FEATURE_AVX2 1
#    endif
#    if defined(__AVX512BW__) && defined(__AVX512CD__) && defined(__AVX512DQ__) && defined(__AVX512F__) && defined(__AVX512VL__)
#        define BP_HAS_FEATURE_AVX512BW 1
#        define BP_HAS_FEATURE_AVX512CD 1
#        define BP_HAS_FEATURE_AVX512DQ 1
#        define BP_HAS_FEATURE_AVX512F 1
#        define BP_HAS_FEATURE_AVX512VL 1
#    endif
#elif BP_HAS_COMPILER_CLANG || BP_HAS_COMPILER_GCC
#    if defined(__MMX__)
#        define BP_HAS_FEATURE_MMX 1
#    endif
#    if defined(__SSE__)
#        define BP_HAS_FEATURE_SSE 1
#    endif
#    if defined(__SSE2__)
#        define BP_HAS_FEATURE_SSE2 1
#    endif
#    if defined(__SSE3__)
#        define BP_HAS_FEATURE_SSE3 1
#    endif
#    if defined(__SSSE3__)
#        define BP_HAS_FEATURE_SSSE3 1
#    endif
#    if defined(__SSE4A__)
#        define BP_HAS_FEATURE_SSE4A 1
#    endif
#    if defined(__SSE4_1__)
#        define BP_HAS_FEATURE_SSE4_1 1
#    endif
#    if defined(__SSE4_2__)
#        define BP_HAS_FEATURE_SSE4_2 1
#    endif
#    if defined(__F16C__)
#        define BP_HAS_FEATURE_F16C 1
#    endif
#    if defined(__PCLMUL__)
#        define BP_HAS_FEATURE_PCLMUL 1
#    endif
#    if defined(__AVX__)
#        define BP_HAS_FEATURE_AVX 1
#    endif
#    if defined(__AVX2__)
#        define BP_HAS_FEATURE_AVX2 1
#    endif
#    if defined(__AVXVNNI__)
#        define BP_HAS_FEATURE_AVXVNNI 1
#    endif
#    if defined(__AVXIFMA__)
#        define BP_HAS_FEATURE_AVXIFMA 1
#    endif
#    if defined(__AVXVNNIINT8__)
#        define BP_HAS_FEATURE_AVXVNNIINT8 1
#    endif
#    if defined(__AVXVNNIINT16__)
#        define BP_HAS_FEATURE_AVXVNNIINT16 1
#    endif
#    if defined(__AVXNECONVERT__)
#        define BP_HAS_FEATURE_AVXNECONVERT 1
#    endif
#    if defined(__AVX10_1__)
#        define BP_HAS_FEATURE_AVX10_1 1
#    endif
#    if defined(__AVX10_1_256__)
#        define BP_HAS_FEATURE_AVX10_1_256 1
#    endif
#    if defined(__AVX10_1_512__)
#        define BP_HAS_FEATURE_AVX10_1_512 1
#    endif
#    if defined(__AVX512BF16__)
#        define BP_HAS_FEATURE_AVX512BF16 1
#    endif
#    if defined(__AVX512BW__)
#        define BP_HAS_FEATURE_AVX512BW 1
#    endif
#    if defined(__AVX512CD__)
#        define BP_HAS_FEATURE_AVX512CD 1
#    endif
#    if defined(__AVX512ER__)
#        define BP_HAS_FEATURE_AVX512ER 1
#    endif
#    if defined(__AVX512PF__)
#        define BP_HAS_FEATURE_AVX512PF 1
#    endif
#    if defined(__AVX512DQ__)
#        define BP_HAS_FEATURE_AVX512DQ 1
#    endif
#    if defined(__AVX512FP16__)
#        define BP_HAS_FEATURE_AVX512FP16 1
#    endif
#    if defined(__AVX512F__)
#        define BP_HAS_FEATURE_AVX512F 1
#    endif
#    if defined(__AVX512VL__)
#        define BP_HAS_FEATURE_AVX512VL 1
#    endif
#    if defined(__AVX512BITALG__)
#        define BP_HAS_FEATURE_AVX512BITALG 1
#    endif
#    if defined(__AVX512VBMI__)
#        define BP_HAS_FEATURE_AVX512VBMI 1
#    endif
#    if defined(__AVX512VBMI2__)
#        define BP_HAS_FEATURE_AVX512VBMI2 1
#    endif
#    if defined(__AVX512VNNI__)
#        define BP_HAS_FEATURE_AVX512VNNI 1
#    endif
#    if defined(__AVX512IFMA__)
#        define BP_HAS_FEATURE_AVX512IFMA 1
#    endif
#    if  defined(__AVX512VP2INTERSECT__)
#        define BP_HAS_FEATURE_AVX512VP2INTERSECT 1
#    endif
#    if defined(__AVX512VPOPCNTDQ__)
#        define BP_HAS_FEATURE_AVX512VPOPCNTDQ 1
#    endif
#    if defined(__CLDEMOTE__)
#        define BP_HAS_FEATURE_CLDEMOTE 1
#    endif
#    if defined(__BMI__)
#        define BP_HAS_FEATURE_BMI 1
#    endif
#    if defined(__BMI2__)
#        define BP_HAS_FEATURE_BMI2 1
#    endif
#    if defined(__POPCNT__)
#        define BP_HAS_FEATURE_POPCNT 1
#    endif
#    if defined(__RTM__)
#        define BP_HAS_FEATURE_RTM 1
#    endif
#    if defined(__FMA__)
#        define BP_HAS_FEATURE_FMA 1
#    endif
#    if defined(__FMA4__)
#        define BP_HAS_FEATURE_FMA4 1
#    endif
#    if defined(__FSGSBASE__)
#        define BP_HAS_FEATURE_FSGSBASE 1
#    endif
#    if defined(__FXSR__)
#        define BP_HAS_FEATURE_FXSR 1
#    endif
#    if defined(__INVPCID__)
#        define BP_HAS_FEATURE_INVPCID 1
#    endif
#    if defined(__LAHF_SAHF__)
#        define BP_HAS_FEATURE_LAHF_SAHF 1
#    endif
#    if defined(__LZCNT__)
#        define BP_HAS_FEATURE_LZCNT 1
#    endif
#    if defined(__MOVBE__)
#        define BP_HAS_FEATURE_MOVBE 1
#    endif
#    if defined(__MOVDIRI__)
#        define BP_HAS_FEATURE_MOVDIRI 1
#    endif
#    if defined(__MOVDIR64B__)
#        define BP_HAS_FEATURE_MOVDIR64B 1
#    endif
#    if defined(__AES__)
#        define BP_HAS_FEATURE_AES 1
#    endif
#    if defined(__VAES__)
#        define BP_HAS_FEATURE_VAES 1
#    endif
#    if defined(__GFNI__)
#        define BP_HAS_FEATURE_GFNI 1
#    endif
#    if defined(__SHA__)
#        define BP_HAS_FEATURE_SHA 1
#    endif
#    if defined(__SHA512__)
#        define BP_HAS_FEATURE_SHA512 1
#    endif
#    if defined(__ADX__)
#        define BP_HAS_FEATURE_ADX 1
#    endif
#    if defined(__SHSTK__)
#        define BP_HAS_FEATURE_SHSTK 1
#    endif
#    if defined(__RDSEED__)
#        define BP_HAS_FEATURE_RDSEED 1
#    endif
#    if defined(__SGX__)
#        define BP_HAS_FEATURE_SGX 1
#    endif
#    if defined(__XOP__)
#        define BP_HAS_FEATURE_XOP 1
#    endif
#    if defined(__XSAVE__)
#        define BP_HAS_FEATURE_XSAVE 1
#    endif
#    if defined(__XSAVEOPT__)
#        define BP_HAS_FEATURE_XSAVEOPT 1
#    endif
#    if defined(__XSAVEC__)
#        define BP_HAS_FEATURE_XSAVEC 1
#    endif
#    if defined(__XSAVES__)
#        define BP_HAS_FEATURE_XSAVES 1
#    endif
#    if defined(__CLFLUSHOPT__)
#        define BP_HAS_FEATURE_CLFLUSHOPT 1
#    endif
#    if defined(__CLWB__)
#        define BP_HAS_FEATURE_CLWB 1
#    endif
#    if defined(__CLZERO__)
#        define BP_HAS_FEATURE_CLZERO 1
#    endif
#    if defined(__PCLMUL__)
#        define BP_HAS_FEATURE_PCLMUL 1
#    endif
#    if defined(__PKU__)
#        define BP_HAS_FEATURE_PKU 1
#    endif
#    if defined(__PCONFIG__)
#        define BP_HAS_FEATURE_PCONFIG 1
#    endif
#    if defined(__VPCLMULQDQ__)
#        define BP_HAS_FEATURE_VPCLMULQDQ 1
#    endif
#    if defined(__LZCNT__)
#       define BP_HAS_FEATURE_LZCNT 1
#    endif
#    if defined(__WBNOINVD__)
#        define BP_HAS_FEATURE_WBNOINVD 1
#    endif
#    if defined(__RDRND__)
#        define BP_HAS_FEATURE_RDRND 1
#    endif
#    if defined(__LWP__)
#        define BP_HAS_FEATURE_LWP 1
#    endif
#    if defined(__LWP__)
#        define BP_HAS_FEATURE_LWP 1
#    endif
#    if defined(__MWAITX__)
#        define BP_HAS_FEATURE_MWAITX 1
#    endif
#    if defined(__TBM__)
#        define BP_HAS_FEATURE_TBM 1
#    endif
#    if defined(__GCC_HAVE_SYNC_COMPARE_AND_SWAP_1)
#        define BP_HAS_FEATURE_COMPARE_AND_SWAP_1 1
#    endif
#    if defined(__GCC_HAVE_SYNC_COMPARE_AND_SWAP_2)
#        define BP_HAS_FEATURE_COMPARE_AND_SWAP_2 1
#    endif
#    if defined(__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4)
#        define BP_HAS_FEATURE_COMPARE_AND_SWAP_4 1
#    endif
#    if defined(__GCC_HAVE_SYNC_COMPARE_AND_SWAP_8)
#        define BP_HAS_FEATURE_COMPARE_AND_SWAP_8 1
#    endif
#    if defined(__GCC_HAVE_SYNC_COMPARE_AND_SWAP_16)
#        define BP_HAS_FEATURE_COMPARE_AND_SWAP_16 1
#    endif
#    if defined(__PTWRITE__)
#        define BP_HAS_FEATURE_PTWRITE 1
#    endif
#    if defined(__PRFCHW__)
#        define BP_HAS_FEATURE_PRFCHW 1
#    endif
#    if defined(__PREFETCHWT1__)
#        define BP_HAS_FEATURE_PREFETCHWT1 1
#    endif
#    if defined(__3dNOW__)
#        define BP_HAS_FEATURE_3DNOW 1
#    endif
#    if defined(__3dNOW_A__)
#        define BP_HAS_FEATURE_3DNOW_A 1
#    endif
#    if defined(__ADX__)
#        define BP_HAS_FEATURE_ADX 1
#    endif
#    if defined(__SHSTK__)
#        define BP_HAS_FEATURE_SHSTK 1
#    endif
#    if defined(__RDSEED__)
#        define BP_HAS_FEATURE_RDSEED 1
#    endif
#    if defined(__RDPID__)
#        define BP_HAS_FEATURE_RDPID 1
#    endif
#    if defined(__EVEX256__)
#        define BP_HAS_FEATURE_EVEX256 1
#    endif
#    if defined(__EVEX512__)
#        define BP_HAS_FEATURE_EVEX512 1
#    endif
#    if defined(__ENQCMD__)
#        define BP_HAS_FEATURE_ENQCMD 1
#    endif
#    if defined(__SERIALIZE__)
#        define BP_HAS_FEATURE_SERIALIZE 1
#    endif
#    if defined(__TSXLDTRK__)
#        define BP_HAS_FEATURE_TSXLDTRK 1
#    endif
#    if defined(__HRESET__)
#        define BP_HAS_FEATURE_HRESET 1
#    endif
#    if defined(__UINTR__)
#        define BP_HAS_FEATURE_UINTR 1
#    endif
#    if defined(__RAOINT__)
#        define BP_HAS_FEATURE_RAOINT 1
#    endif
#    if defined(__WAITPKG__)
#        define BP_HAS_FEATURE_WAITPKG 1
#    endif
#    if defined(__KL__)
#        define BP_HAS_FEATURE_KL 1
#    endif
#    if defined(__WIDEKL__)
#        define BP_HAS_FEATURE_WIDEKL 1
#    endif
#    if defined(__AMX_FP16__)
#        define BP_HAS_FEATURE_AMX_FP16 1
#    endif
#    if defined(__AMX_BF16__)
#        define BP_HAS_FEATURE_AMX_BF16 1
#    endif
#    if defined(__AMX_INT8__)
#        define BP_HAS_FEATURE_AMX_INT8 1
#    endif
#    if defined(__AMX_TILE__)
#        define BP_HAS_FEATURE_AMX_TILE 1
#    endif
#    if defined(__AMX_COMPLEX__)
#        define BP_HAS_FEATURE_AMX_COMPLEX 1
#    endif
#    if defined(__CMPCCXADD__)
#        define BP_HAS_FEATURE_CMPCCXADD 1
#    endif
#    if defined(__SM3__)
#        define BP_HAS_FEATURE_SM3 1
#    endif
#    if defined(__SM4__)
#        define BP_HAS_FEATURE_SM4 1
#    endif
#    if defined(__USERMSR__)
#        define BP_HAS_FEATURE_USERMSR 1
#    endif
#    if defined(__CRC32__)
#        define BP_HAS_FEATURE_CRC32 1
#    endif
#    if defined(__RDPRU__)
#        define BP_HAS_FEATURE_RDPRU 1
#    endif
#    if defined(__APX_F__)
#        define BP_HAS_FEATURE_APX_F 1
#    endif
#    if defined(__APX_INLINE_ASM_USE_GPR32__)
#        define BP_HAS_FEATURE_APX_INLINE_ASM_USE_GPR32 1
#    endif
#    if defined(__CCMP__)
#        define BP_HAS_FEATURE_CCMP 1
#    endif
#    if defined(__CF__)
#        define BP_HAS_FEATURE_CF 1
#    endif
#    if defined(__EGPR__)
#        define BP_HAS_FEATURE_EGPR 1
#    endif
#    if defined(__NDD__)
#        define BP_HAS_FEATURE_NDD 1
#    endif
#    if defined(__NF__)
#        define BP_HAS_FEATURE_NF 1
#    endif
#    if defined(__PPX__)
#        define BP_HAS_FEATURE_PPX 1
#    endif
#    if defined(__PUSH2POP2__)
#        define BP_HAS_FEATURE_PUSH2POP2 1
#    endif
#    if defined(__POPCNT__)
#        define BP_HAS_FEATURE_POPCNT 1
#    endif
#    if  defined(__PREFETCHI__)
#        define BP_HAS_FEATURE_PREFETCHI 1
#    endif
#endif

