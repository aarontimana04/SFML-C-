
#pragma once
#include "Color.h"
#include <string>

struct Power {
    int pos = 0;
    int valor = 1;
    Color color = Color::Rojo;
    virtual ~Power() = default;
    virtual std::string tipo() const = 0;
};
struct PowerUp : public Power { std::string tipo() const override { return "PowerUp"; } };
struct PowerDown : public Power { std::string tipo() const override { return "PowerDown"; } };
