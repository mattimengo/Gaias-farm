cmake_minimum_required(VERSION 3.15)
project(Esame)

# Imposta la cartella di output per l'eseguibile
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build/x64/Release)

# Specifica il percorso di SFML (mettilo prima di find_package)
set(SFML_DIR "C:/Users/matti/Desktop/Gioco C/SFML-2.6.2/lib/cmake/SFML")

# Trova le librerie SFML
find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

# Aggiungi il percorso di CSFML manualmente
set(CSFML_INCLUDE_DIR "C:/Users/matti/Desktop/Gioco C/CSFML/include")
set(CSFML_LIBRARY_DIR "C:/Users/matti/Desktop/Gioco C/CSFML/lib")

# Includi la directory di CSFML per i file header
include_directories(${CSFML_INCLUDE_DIR})

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
target_link_libraries(Esame
    sfml-system
    sfml-window
    sfml-graphics
    sfml-audio
    ${CSFML_LIBRARY_DIR}/csfml-system.lib
    ${CSFML_LIBRARY_DIR}/csfml-window.lib
    ${CSFML_LIBRARY_DIR}/csfml-graphics.lib
    ${CSFML_LIBRARY_DIR}/csfml-audio.lib
)
