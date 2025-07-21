cmake_minimum_required(VERSION 3.15)
project(Esame)

# Imposta la cartella di output per l'eseguibile
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/x64/Release)

# Trova le librerie SFML e CSFML
find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

# Aggiungi la subdirectory TEST
add_subdirectory(TEST)

# Specifica i file sorgenti principali (fuori dalla subdirectory TEST)
set(SOURCES
    avatar.cpp
    main2.cpp
)

# Includi la directory corrente per i file header
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Crea l'eseguibile principale
add_executable(Esame ${SOURCES})

# Linka SFML e CSFML all'eseguibile principale
target_link_libraries(Esame sfml-system sfml-window sfml-graphics sfml-audio)

# Se TEST produce una libreria, linkarla (commentato, da abilitare se serve)
# target_link_libraries(Esame TESTLib)
