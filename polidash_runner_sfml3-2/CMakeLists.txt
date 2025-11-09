
cmake_minimum_required(VERSION 3.16)
project(polidash_sfml CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Try SFML 3 first (Homebrew default), fallback to SFML 2.5
set(SFML_FIND_VERSION 3)
find_package(SFML ${SFML_FIND_VERSION} QUIET CONFIG COMPONENTS Graphics Window System)
if(NOT SFML_FOUND)
    set(SFML_FIND_VERSION 2.5)
    find_package(SFML ${SFML_FIND_VERSION} REQUIRED COMPONENTS graphics window system)
endif()

add_executable(polidash_sfml
    src/main.cpp
    src/Color.h
    src/Figura.h
    src/Power.h
    src/Tramo.h
    src/Jugador.h
    src/ArregloTramo.h
    src/Juego.h
    src/RendererSFML.h
)

if(SFML_VERSION VERSION_GREATER_EQUAL "3.0.0")
    target_link_libraries(polidash_sfml PRIVATE SFML::Graphics SFML::Window SFML::System)
else()
    target_link_libraries(polidash_sfml PRIVATE sfml-graphics sfml-window sfml-system)
endif()

if(APPLE)
    target_link_libraries(polidash_sfml PRIVATE "-framework AppKit" "-framework IOKit")
endif()
