cmake_minimum_required(VERSION 3.15)

project(Esame LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/x64/Release)

set(SOURCES
    main.cpp
    avatar.cpp
)

add_executable(Esame ${SOURCES})

include_directories(${CMAKE_SOURCE_DIR}/include)


target_link_libraries(Esame
    "${CMAKE_SOURCE_DIR}/library/sfml-graphics.lib"
    "${CMAKE_SOURCE_DIR}/library/sfml-audio.lib"
    "${CMAKE_SOURCE_DIR}/library/sfml-window.lib"
    "${CMAKE_SOURCE_DIR}/library/sfml-system.lib"
    "${CMAKE_SOURCE_DIR}/library/sfml-network.lib"
)


set_property(TARGET Esame PROPERTY CXX_STANDARD 17)
set_property(TARGET Esame PROPERTY CXX_STANDARD_REQUIRED ON)

add_custom_command(TARGET Esame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets
    $<TARGET_FILE_DIR:Esame>/assets
)

add_custom_command(TARGET Esame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/font
    $<TARGET_FILE_DIR:Esame>/font
)