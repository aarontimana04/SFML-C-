
#pragma once
#include <vector>
#include <memory>
#include <random>
#include <string>
#include <sstream>
#include "Power.h"

enum class Orientacion { H_Derecha, V_Arriba, H_Izquierda };

struct Tramo {
    int id;
    int longitud;
    int velocidad;
    Orientacion orient;
    std::vector<std::unique_ptr<Power>> powers;

    Tramo(int id_, int L, int v, Orientacion o) : id(id_), longitud(L), velocidad(v), orient(o) {}

    static int randInt(int a, int b){
        static std::mt19937 rng{std::random_device{}()};
        std::uniform_int_distribution<int> d(a,b);
        return d(rng);
    }

    void poblar(int N){
        powers.clear();
        for(int i=0;i<N;i++){
            int valor = randInt(1,5);
            Color col = static_cast<Color>(randInt(0,2));
            int pos = randInt(5, longitud-5);
            bool esUp = randInt(0,1)==1;
            if (esUp){
                auto p = std::make_unique<PowerUp>();
                p->valor = valor; p->color = col; p->pos = pos;
                powers.push_back(std::move(p));
            }else{
                auto p = std::make_unique<PowerDown>();
                p->valor = valor; p->color = col; p->pos = pos;
                powers.push_back(std::move(p));
            }
        }
    }
};
