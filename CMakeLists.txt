cmake_minimum_required(VERSION 3.15)
project(Esame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Cartella output eseguibile
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/x64/Release/Debug)

# Percorso SFML
set(SFML_DIR "C:/Users/matti/Desktop/Gioco C/SFML-2.6.2/lib/cmake/SFML")

# Trova SFML
find_package(SFML 2.6.2 COMPONENTS system window graphics audio REQUIRED)

# Percorsi CSFML aggiornati (con sottocartella msvc)
set(CSFML_INCLUDE_DIR "C:/Users/matti/Desktop/Gioco C/CSFML/include")
set(CSFML_LIBRARY_DIR "C:/Users/matti/Desktop/Gioco C/CSFML/lib/msvc")

# Includi header CSFML
include_directories(${CSFML_INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Aggiungi directory librerie CSFML
link_directories("${CSFML_LIBRARY_DIR}")

# File sorgenti
set(SOURCES
    main.c
    main2.cpp
    avatar.cpp
    avatar.h)

# Crea eseguibile
add_executable(Esame ${SOURCES})

# Linka librerie SFML e CSFML
target_link_libraries(Esame
    sfml-system
    sfml-window
    sfml-graphics
    sfml-audio
    csfml-system
    csfml-window
    csfml-graphics
    csfml-audio
)

#pausa?
if(MSVC)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:CONSOLE")
endif()

