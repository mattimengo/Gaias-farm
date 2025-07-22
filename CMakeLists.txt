cmake_minimum_required(VERSION 3.10)
project(Esame)

# Imposta lo standard C++ a 11.
set(CMAKE_CXX_STANDARD 11)

# --- Definizione dei file sorgente ---
set(SOURCES
    main.cpp
    avatar.cpp
)

# --- Creazione dell'eseguibile ---
add_executable(${PROJECT_NAME} ${SOURCES})


# Imposta il percorso degli header di SFML (se necessario)
include_directories(headers)

set(SFML_DIR "C:/Users/matti/Desktop/SFML-2.6.2/lib/cmake/SFML")
set(SFML_INCLUDE_DIR "C:/Users/matti/Desktop/SFML-2.6.2/include/SFML")
set(SFML_BIN_DIR "C:/Users/matti/Desktop/SFML-2.6.2/bin")

# Trova il pacchetto SFML.
find_package(SFML REQUIRED system window graphics)

# Controlla se SFML è stato trovato con successo e mostra un messaggio.
if(SFML_FOUND)
    message(STATUS "SFML trovato con successo. Versione: ${SFML_VERSION}")
    target_include_directories(Esame PRIVATE ${SFML_INCLUDE_DIR})

    # Linka librerie SFML
    target_link_libraries(${PROJECT_NAME}
       sfml-system
       sfml-window
       sfml-graphics
       sfml-audio
       sfml-network
)

else()
    message(FATAL_ERROR "SFML non trovato. Assicurati che SFML_DIR sia impostato correttamente.")
endif()






if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()



