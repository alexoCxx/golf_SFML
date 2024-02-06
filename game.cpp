#include "game.hpp"

Game::Game() : m_ball(nullptr), m_terrain(), m_view()
{
    largeur;
    hauteur;
    event;
    window;

    View &view = m_view;
    Terrain &terrain = m_terrain;
    m_ball = new Ball();
}

Game::~Game()
{
    delete m_ball;
}

void Game::game()
{
    window.create(sf::VideoMode(largeur, hauteur), "golf");
    m_terrain.lire();
    clock.restart();

    gameLoop();
}

void Game::gameLoop()
{
    m_ball->setX(500);
    m_ball->setY(400);
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                delete m_ball;
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                m_ball->input(event, true);
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                m_ball->input(event, false);
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                m_view.input(event.key.code, true);
            }
            else if (event.type == sf::Event::KeyReleased)
            {
                m_view.input(event.key.code, false);
            }
        }
        m_ball->chekInput();
        m_ball->avancer(clock);
        m_ball->update(window);
        
        m_view.update();
        m_view.position(m_ball);
 
        gameAffichage();
    }
}

void Game::gameAffichage()
{
    m_view.chekInput();
    window.setView(m_view.getView());
    
    window.clear(sf::Color::White);

    m_terrain.update(window,m_ball);
    window.draw(m_ball->getBall());

    window.display();
}