
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Juego.h"
#include "RendererSFML.h"
#include <thread>
#include <optional>

int main(){
    Juego game;
    RendererSFML r;
    r.loadFont();

    int current = 0;
    bool victoria = false;
    int baseY[3] = {80, 300, 520};

    while (r.window.isOpen()){
        while (auto event = r.window.pollEvent()){
            if (event->is<sf::Event::Closed>()) r.window.close();
        }

        r.window.clear(sf::Color(245,245,245));

        for(int i=0;i<3;i++) r.drawTrackFrame(baseY[i]-70, "Tramo " + std::to_string(i+1));

        Tramo& t = game.arr.tramos[current];
        (void)game.jugador.step(t);
        if (game.jugador.llegoFin(t)){
            if (current==2 && game.jugador.fig.lados==10){ victoria = true; }
            if (current<2){ current++; game.jugador.pos = 0; }
            else { r.window.close(); }
        }

        float x = r.xFromPos(game.jugador.pos, t.longitud);
        r.drawPolygon(game.jugador.fig.lados, 28.f, sf::Vector2f(x, (float)baseY[current]), RendererSFML::colorOf(game.jugador.fig.color), sf::Color::Black);

        for (auto& uptr : t.powers){
            float px = r.xFromPos(uptr->pos, t.longitud);
            sf::CircleShape c(12);
            c.setOrigin({12,12});
            c.setPosition({px, (float)baseY[current]});
            c.setFillColor(RendererSFML::colorOf(uptr->color));
            c.setOutlineColor(sf::Color::Black);
            c.setOutlineThickness(2.f);
            r.window.draw(c);
        }

        r.drawRightPanel(game.jugador, t, current);
        r.window.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(70));
    }

    if (victoria) printf("DECAGONO PERFECTO! YOU WIN!\n");
    else printf("YOU LOST (no alcanzaste 10 lados en el tramo 3)\n");
    return 0;
}
