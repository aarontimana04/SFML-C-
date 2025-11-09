
#pragma once
#include <SFML/Graphics.hpp>
#include "Juego.h"

struct RendererSFML {
    // Definir primero dimensiones y hacerlas constexpr para usarlas al crear la ventana
    static constexpr unsigned W = 1100;
    static constexpr unsigned H = 700;
    static constexpr int rightPanelW = 280;

    sf::RenderWindow window;
    sf::Font font;

    RendererSFML()
    : window(sf::VideoMode({W, H}), "PoliDash (SFML - Automatico)"){
        window.setFramerateLimit(60);
    }

    bool loadFont(){
        if (font.openFromFile("assets/DejaVuSans.ttf")) return true;
        if (font.openFromFile("DejaVuSans.ttf")) return true;
        if (font.openFromFile("arial.ttf")) return true;
        return false;
    }

    static sf::Color colorOf(Color c){
        switch(c){
            case Color::Rojo: return sf::Color(220,70,70);
            case Color::Amarillo: return sf::Color(240,200,40);
            case Color::Azul: return sf::Color(60,100,210);
        }
        return sf::Color::White;
    }

    void drawPolygon(int n, float radius, sf::Vector2f center, sf::Color fill, sf::Color outline){
        sf::CircleShape poly(radius, std::max(3,n));
        poly.setFillColor(fill);
        poly.setOutlineColor(outline);
        poly.setOutlineThickness(3.f);
        poly.setOrigin({radius, radius});
        poly.setPosition(center);
        window.draw(poly);
    }

    void drawTrackFrame(float topY, const std::string& titulo){
        sf::RectangleShape r(sf::Vector2f(W - rightPanelW - 40, 180));
        r.setPosition({20.f, topY});
        r.setFillColor(sf::Color(210, 230, 250));
        r.setOutlineColor(sf::Color::Black);
        r.setOutlineThickness(2.f);
        window.draw(r);
        if (font.getInfo().family.size()){
            sf::Text t(font, titulo, 16);
            t.setFillColor(sf::Color::Black);
            t.setPosition({28.f, topY+8});
            window.draw(t);
        }
    }

    float xFromPos(int pos, int longitud){
        float left = 30.f;
        float right = (float)(W - rightPanelW - 50);
        return left + (right-left) * (pos / (float)longitud);
    }

    void drawRightPanel(const Jugador& j, const Tramo& t, int tramoIndex){
        sf::RectangleShape r(sf::Vector2f(rightPanelW-20, H-40));
        r.setPosition({(float)W-rightPanelW+10, 20.f});
        r.setFillColor(sf::Color(235,245,255));
        r.setOutlineColor(sf::Color::Black);
        r.setOutlineThickness(2.f);
        window.draw(r);
        if (!font.getInfo().family.size()) return;

        auto label = [&](std::string s, float y){
            sf::Text tx(font, s, 18);
            tx.setFillColor(sf::Color::Black);
            tx.setPosition({(float)W-rightPanelW+25, y});
            window.draw(tx);
        };
        label("Minimap", 30);
        label("Tramo: " + std::to_string(tramoIndex+1), 70);
        label("Lados: " + std::to_string(j.fig.lados), 120);
        label("Numero: " + std::to_string(j.fig.numeroCentral), 150);
        label("Sum.Ang: " + std::to_string(j.fig.sumaAngulos()), 180);
        label("Velocidad: " + std::to_string(t.velocidad), 210);
    }
};
