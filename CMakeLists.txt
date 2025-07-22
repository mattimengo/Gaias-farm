cmake_minimum_required(VERSION 3.16)

# Nome del progetto
project(Esame)

# Specifica la versione di C++ (ad esempio C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Imposta la variabile SFML_DIR al percorso corretto
set(SFML_DIR "C:/Users/matti/Desktop/SFML-2.6.2/lib/cmake/SFML")

# Trova SFML con i componenti system, window, graphics, audio
find_package(SFML 2.6.2 COMPONENTS system window graphics audio REQUIRED)


# Aggiungi i file sorgenti
set(SOURCES
    main.cpp
    avatar.cpp
    avatar.h
)

# Crea l'eseguibile
add_executable(${PROJECT_NAME} ${SOURCES})

# Collega le librerie SFML all'eseguibile
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)

# Se usi MSVC (Visual Studio), puoi aggiungere questa opzione per la console
if(MSVC)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:CONSOLE")
endif()
