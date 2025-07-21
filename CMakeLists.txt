cmake_minimum_required(VERSION 3.15)
project(Esame)

# Imposta lo standard C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Cartella output eseguibile
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/x64/Release)

# Percorso SFML (librerie .d per debug)
set(SFML_DIR "C:/Users/matti/Desktop/Gioco C/SFML-2.6.2/lib/cmake/SFML")

# Trova SFML
find_package(SFML 2.6.2 COMPONENTS system window graphics audio REQUIRED)

# Percorsi CSFML aggiornati (con sottocartella msvc)
set(CSFML_INCLUDE_DIR "C:/Users/matti/Desktop/Gioco C/CSFML/include")
set(CSFML_LIBRARY_DIR "C:/Users/matti/Desktop/Gioco C/CSFML/lib/msvc")

# Includi header SFML e CSFML
include_directories(
    "C:/Users/matti/Desktop/Gioco C/SFML-2.6.2/include"
    ${CSFML_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Aggiungi directory librerie SFML e CSFML
link_directories(
    "C:/Users/matti/Desktop/Gioco C/SFML-2.6.2/lib"
    "${CSFML_LIBRARY_DIR}"
)

# File sorgenti
set(SOURCES
    main.c
    main2.cpp
    avatar.cpp
    avatar.h
)

# Crea eseguibile
add_executable(Esame ${SOURCES})

# Linka librerie SFML e CSFML
target_link_libraries(Esame
    sfml-system-d
    sfml-window-d
    sfml-graphics-d
    sfml-audio-d
    csfml-system
    csfml-window
    csfml-graphics
    csfml-audio
)

# Configurazione aggiuntiva per MSVC (pausa console)
if(MSVC)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:CONSOLE")
endif()
