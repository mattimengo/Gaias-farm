cmake_minimum_required(VERSION 3.14)
project(Esame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    main.cpp
    avatar.cpp
    avatar.h
)

add_executable(${PROJECT_NAME} ${SOURCES})

# Configura SFML (modifica il percorso se necessario)
set(SFML_DIR "C:/Users/matti/Desktop/Gioco C/SFML-2.6.2/lib/cmake/SFML")
find_package(SFML 2.6 COMPONENTS system window graphics audio REQUIRED)

if(NOT SFML_FOUND)
    message(FATAL_ERROR "SFML non trovato! Verifica il percorso.")
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE 
    sfml-graphics sfml-window sfml-system sfml-audio
)

# Solo per Visual Studio
if(MSVC)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:CONSOLE")
endif()
