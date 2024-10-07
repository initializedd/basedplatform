cmake_minimum_required(VERSION 3.25.1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(basedplatform)

add_library(basedplatform INTERFACE)
add_library(based::platform ALIAS basedplatform)

set_target_properties(
    basedplatform PROPERTIES
    LANGUAGES CXX
    DEBUG_POSTFIX d
    SOVERSION 1
    VERSION 1.0.0
)

target_sources(basedplatform INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/macros.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_id.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_info.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_core_features.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_advanced_features.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_descriptors.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_cache_info.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_cache_meta.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_cache_features.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_extended_protection_features.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_extended_timing_features.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_soc_vendor_identifiers.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_soc_project_identifiers.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_soc_stepping_identifiers.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_key_locker_features.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_tlb_identifiers.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_cache_identifiers.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_monitor_line_info.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_mwait_extensions.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_mwait_features.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_thermal_capabilities.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_thermal_info.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_thermal_meta.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_hardware_feedback.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_extended_core_features.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_extended_advanced_features.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_extended_intricate_features.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_extended_core_instructions.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_extended_compat_features.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_extended_advanced_instructions.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_extended_core_info.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_extended_advanced_info.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_state_components.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_state_component_info.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_xsave_features.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_xsave_extended_features.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_xsave_feature_flags.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_sgx_functions.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_sgx_miscselect_info.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_sgx_enclave_info.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_secs_attributes.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_sgx_epc_info.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/processor_trace_features.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/processor_trace_extended_features.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_core_crystal_clock_frequency_info.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/specification_frequency_info.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_avx10_features.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_ras_features.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_power_management_features.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_feedback_features.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_power_monitoring_interface_features.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_address_info.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_address_features.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_thread_info.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_address_limits.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_svm_revision_info.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_svm_address_space_identifiers.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_svm_features.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_encrypted_memory_features.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_encrypted_memory_info.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_encrypted_memory_asid_info.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_extended_feature_identifications.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_microcode_info.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/basedplatform/based/platform/x86/detail/cpu_centaur_features.hpp
)

target_include_directories(basedplatform INTERFACE basedplatform)
target_compile_features(basedplatform INTERFACE cxx_std_23)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    basedplatform-config-version.cmake
    VERSION 1.0.0
    COMPATIBILITY SameMajorVersion
)

include(GNUInstallDirs)
install(TARGETS basedplatform
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        COMPONENT basedplatform_runtime
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        COMPONENT basedplatform_runtime
        NAMELINK_COMPONENT basedplatform_development
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        COMPONENT basedplatform_development
)

