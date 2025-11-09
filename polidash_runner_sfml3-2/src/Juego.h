
#pragma once
#include "ArregloTramo.h"
#include "Jugador.h"

struct Juego {
    ArregloTramo arr;
    Jugador jugador;
    bool victoria = false;

    Juego(): jugador(static_cast<Color>(Tramo::randInt(0,2))) {
        arr.tramos.emplace_back(1, 120, 2, Orientacion::H_Derecha);
        arr.tramos.emplace_back(2, 120, 3, Orientacion::V_Arriba);
        arr.tramos.emplace_back(3, 160, 4, Orientacion::H_Izquierda);
        for(auto& t: arr.tramos) t.poblar(10);
    }
};
