
#pragma once
#include <string>
enum class Color { Rojo=0, Amarillo=1, Azul=2 };
inline std::string to_string(Color c){
    switch(c){
        case Color::Rojo: return "Rojo";
        case Color::Amarillo: return "Amarillo";
        case Color::Azul: return "Azul";
    }
    return "Desconocido";
}
