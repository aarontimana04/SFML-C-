
#pragma once
#include "Color.h"
#include <algorithm>

struct Figura {
    int lados = 3;
    int numeroCentral = 0;
    Color color;
    Figura(Color c): color(c) {}
    int sumaAngulos() const { return (lados - 2) * 180; }
    void powerUp(int v){ lados = std::min(10, lados + 1); numeroCentral += v; }
    void powerDown(int v){ lados = std::max(3, lados - 1); numeroCentral = std::max(0, numeroCentral - v); }
};
