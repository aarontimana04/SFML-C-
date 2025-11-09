
#pragma once
#include "Figura.h"
#include "Tramo.h"
#include <string>

struct Jugador {
    Figura fig;
    int pos = 0;
    Jugador(Color c): fig(c) {}
    std::string step(Tramo& t){
        pos += t.velocidad;
        if (pos>t.longitud) pos = t.longitud;
        for (auto& uptr : t.powers){
            if (uptr->pos == pos){
                if (uptr->tipo()=="PowerUp" && uptr->color==fig.color){ fig.powerUp(uptr->valor); return "UP"; }
                else if (uptr->tipo()=="PowerDown" && uptr->color!=fig.color){ fig.powerDown(uptr->valor); return "DOWN"; }
                else return "NONE";
            }
        }
        return "";
    }
    bool llegoFin(const Tramo& t) const { return pos >= t.longitud; }
};
