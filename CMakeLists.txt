cmake_minimum_required(VERSION 3.15)

project(Esame LANGUAGES CXX)

# Imposta la directory di output in base al sistema operativo
if(WIN32)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/x64/Release)
elseif(APPLE)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/macos/Release)
elseif(UNIX)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/linux/Release)
endif()

# Crea la directory di output se non esiste
file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

# File sorgenti
set(SOURCES
    main.cpp
    avatar.cpp
)

add_executable(Esame ${SOURCES})

include_directories(${CMAKE_SOURCE_DIR}/include)

# Configurazione delle librerie SFML in base al sistema operativo
if(WIN32)
    # Windows: usa i file .lib
    target_link_libraries(Esame
        "${CMAKE_SOURCE_DIR}/library/sfml-graphics.lib"
        "${CMAKE_SOURCE_DIR}/library/sfml-audio.lib"
        "${CMAKE_SOURCE_DIR}/library/sfml-window.lib"
        "${CMAKE_SOURCE_DIR}/library/sfml-system.lib"
        "${CMAKE_SOURCE_DIR}/library/sfml-network.lib"
    )
elseif(APPLE)
    # macOS: usa i file .dylib o framework
    find_package(SFML REQUIRED COMPONENTS graphics audio window system network)
    target_link_libraries(Esame SFML::graphics SFML::audio SFML::window SFML::system SFML::network)
elseif(UNIX)
    # Linux: usa i file .so
    find_package(SFML REQUIRED COMPONENTS graphics audio window system network)
    target_link_libraries(Esame sfml-graphics sfml-audio sfml-window sfml-system sfml-network)
endif()

# Imposta lo standard C++ a 17
set_property(TARGET Esame PROPERTY CXX_STANDARD 17)
set_property(TARGET Esame PROPERTY CXX_STANDARD_REQUIRED ON)

if(CMAKE_CXX_STANDARD LESS 17)
    message(FATAL_ERROR "C++17 è richiesto per questo progetto.")
endif()

# Copia le risorse (assets e font) nella directory di output
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

add_custom_command(TARGET Esame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_SOURCE_DIR}/sfml-window-2.dll
    $<TARGET_FILE_DIR:Esame>/sfml-window-2.dll
)

add_custom_command(TARGET Esame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_SOURCE_DIR}/sfml-audio-2.dll
    $<TARGET_FILE_DIR:Esame>/sfml-audio-2.dll
)

add_custom_command(TARGET Esame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_SOURCE_DIR}/sfml-graphics-2.dll
    $<TARGET_FILE_DIR:Esame>/sfml-graphics-2.dll
)

add_custom_command(TARGET Esame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_SOURCE_DIR}/sfml-network-2.dll
    $<TARGET_FILE_DIR:Esame>/sfml-network-2.dll
)

add_custom_command(TARGET Esame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_SOURCE_DIR}/sfml-system-2.dll
    $<TARGET_FILE_DIR:Esame>/sfml-system-2.dll
)

# Messaggi di debug per verificare le configurazioni
message(STATUS "Sistema operativo rilevato: ${CMAKE_SYSTEM_NAME}")
message(STATUS "Percorso delle librerie SFML: ${CMAKE_SOURCE_DIR}/library")
message(STATUS "Directory di output: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
