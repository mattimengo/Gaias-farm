cmake_minimum_required(VERSION 3.15)
project(Esame)

# Imposta lo standard C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Cartella output eseguibile
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/x64/Release)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/x64/Release)

# Percorso SFML (librerie .d per debug)
set(SFML_DIR "C:/Users/matti/Desktop/Gioco C/SFML-2.6.2/lib/cmake/SFML")

# Trova SFML
find_package(SFML 2.6.2 COMPONENTS system window graphics audio REQUIRED)

# Includi header SFML e CSFML
include_directories(
    "C:/Users/matti/Desktop/Gioco C/SFML-2.6.2/include"
     ${CMAKE_CURRENT_SOURCE_DIR}
)

# Aggiungi directory librerie SFML e CSFML
link_directories(
    "C:/Users/matti/Desktop/Gioco C/SFML-2.6.2/lib"
    
)

# File sorgenti
set(SOURCES
   
    main.cpp
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
    sfml-audio-d)

# Configurazione aggiuntiva per MSVC (pausa console)
if(MSVC)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:CONSOLE")
endif()
