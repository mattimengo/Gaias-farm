cmake_minimum_required(VERSION 3.14)
project(Esame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# File sorgenti
set(SOURCES
    main.cpp
    avatar.cpp
    avatar.h
)

# Aggiungi eseguibile
add_executable(${PROJECT_NAME} ${SOURCES})

# Include SFML
set(SFML_DIR "C:/Users/matti/Desktop/Gioco C/SFML-2.6.2/lib/cmake/SFML")
find_package(SFML 2.6 COMPONENTS system window graphics audio REQUIRED)

target_include_directories(${PROJECT_NAME} PRIVATE
    "C:/Users/matti/Desktop/Gioco C/SFML-2.6.2/include"
)

# Collega le librerie SFML
target_link_libraries(${PROJECT_NAME}
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
)

# Visual Studio console
if (MSVC)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:CONSOLE")
endif()
