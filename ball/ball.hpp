#ifndef BALL_HPP
#define BALL_HPP
#include "../terrain/mur.hpp"
#include "../Entity.hpp"
#include "SFML/Graphics.hpp"

class Ball : private Entity
{
private :
    sf::Texture texBall;
    sf::Sprite ball;
    sf::Vector2i m_vitesse;
    
    sf::Vector2i position;
    bool toucheBall;
    bool envoieBall;
    sf::RenderWindow window;
    sf::Vector2f worldPos;

    sf::Time timeMove;
    const sf::Time timeMoveConst = sf::seconds(0.10);
    float timeMesure; 

public :
    Ball();
    ~Ball();
    void update(sf::RenderWindow &window);
    void input(sf::Event ev, bool chekPressed);
    void chekInput();
    void vitesse();
    void avancer(sf::Clock& clock);
    void rebond(Mur *&mur);

    //get
    sf::Sprite getBall()
    {
        return ball;
    }
    float getX()
    {
        return m_x;
    }
    float getY()
    {
        return m_y;
    }
    int getHauteur()
    {
        return m_hauteur;
    }
    int getLargeur()
    {
        return m_largeur;
    }

    //set
    void setX(float X)
    {
        m_x = X;
    }
    void setY(float Y)
    {
        m_y = Y;
    }
};

#endif