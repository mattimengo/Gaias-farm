cmake_minimum_required(VERSION 3.16)

project(Esame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_DIR "C:/Users/matti/Desktop/SFML-2.6.2/lib/cmake/SFML")
find_package(SFML 2.6 COMPONENTS system window graphics audio REQUIRED)

set(SOURCES
    main.cpp
    avatar.cpp
    avatar.h
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)

if(MSVC)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:CONSOLE")
endif()

