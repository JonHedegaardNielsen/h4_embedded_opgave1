include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(opgave1_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(opgave1_default_default_XC8_FILE_TYPE_assemble)
add_library(opgave1_default_default_XC8_assemble OBJECT ${opgave1_default_default_XC8_FILE_TYPE_assemble})
    opgave1_default_default_XC8_assemble_rule(opgave1_default_default_XC8_assemble)
    list(APPEND opgave1_default_library_list "$<TARGET_OBJECTS:opgave1_default_default_XC8_assemble>")

endif()

# Handle files with suffix S, for group default-XC8
if(opgave1_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(opgave1_default_default_XC8_assemblePreprocess OBJECT ${opgave1_default_default_XC8_FILE_TYPE_assemblePreprocess})
    opgave1_default_default_XC8_assemblePreprocess_rule(opgave1_default_default_XC8_assemblePreprocess)
    list(APPEND opgave1_default_library_list "$<TARGET_OBJECTS:opgave1_default_default_XC8_assemblePreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC8
if(opgave1_default_default_XC8_FILE_TYPE_compile)
add_library(opgave1_default_default_XC8_compile OBJECT ${opgave1_default_default_XC8_FILE_TYPE_compile})
    opgave1_default_default_XC8_compile_rule(opgave1_default_default_XC8_compile)
    list(APPEND opgave1_default_library_list "$<TARGET_OBJECTS:opgave1_default_default_XC8_compile>")

endif()

# Handle files with suffix elf, for group default-XC8
if(opgave1_default_default_XC8_FILE_TYPE_objcopy_avr)
add_library(opgave1_default_default_XC8_objcopy_avr OBJECT ${opgave1_default_default_XC8_FILE_TYPE_objcopy_avr})
    opgave1_default_default_XC8_objcopy_avr_rule(opgave1_default_default_XC8_objcopy_avr)
    list(APPEND opgave1_default_library_list "$<TARGET_OBJECTS:opgave1_default_default_XC8_objcopy_avr>")

endif()


# Main target for this project
add_executable(opgave1_default_image_2u960kMZ ${opgave1_default_library_list})

set_target_properties(opgave1_default_image_2u960kMZ PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf"
    ADDITIONAL_CLEAN_FILES "${output_extensions}"
    RUNTIME_OUTPUT_DIRECTORY "${opgave1_default_output_dir}")
target_link_libraries(opgave1_default_image_2u960kMZ PRIVATE ${opgave1_default_default_XC8_FILE_TYPE_link})
# Add the link options from the rule file.
opgave1_default_link_rule( opgave1_default_image_2u960kMZ)


#Add objcopy steps
opgave1_default_objcopy_avr_rule(opgave1_default_image_2u960kMZ)
add_custom_target(
    merge_loadable_files ALL
    COMMAND hexmate  /home/jon/Projects/Programming/Embedded/opgave1/main.hex ${CMAKE_CURRENT_SOURCE_DIR}/../../../out/opgave1/default.hex  -O${CMAKE_CURRENT_SOURCE_DIR}/../../../out/opgave1/default-unified.hex
    BYPRODUCTS ${CMAKE_CURRENT_SOURCE_DIR}/../../../out/opgave1/default-unified.hex
    COMMENT "Merging loadable hex files into unified image")
add_dependencies(merge_loadable_files opgave1_default_image_2u960kMZ)

