#ifndef GAME_HPP
#define GAME_HPP
#include <SFML/Graphics.hpp>
#include "ball/ball.hpp"
#include "terrain/terrain.hpp"
#include "view.hpp"

class Game
{
private :
    sf::RenderWindow window;
    sf::Event event;
    sf::Mouse::Button button;
    sf::Clock clock;

    float largeur = 1300;
    float hauteur = 1000;

    Terrain m_terrain;
    View m_view;
    Ball *m_ball;

public :
    Game();
    ~Game();
    void game();
    void gameLoop();
    void gameAffichage();

};
#endif