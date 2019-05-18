cmake_minimum_required(VERSION 3.0)
project(Arta)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_COMPILER clang)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE lib_src "${CMAKE_CURRENT_SOURCE_DIR}" "src/*.c")
list(REMOVE_ITEM lib_src "${CMAKE_CURRENT_SOURCE_DIR}/src/main.c")
message("${lib_src}")
add_library(cscript ${lib_src})

add_executable(cscript.exe "${CMAKE_CURRENT_SOURCE_DIR}/src/main.c")
target_link_libraries(cscript.exe cscript)
target_link_libraries(cscript.exe edit)

IF (EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json")
  EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
    ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
    )
ENDIF()
