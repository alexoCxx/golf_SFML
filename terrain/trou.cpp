#include "trou.hpp"
#include <iostream>

Trou::Trou()
{
    m_x;
    m_y;
    tail.x = 15;
    tail.y = 15;
    posImage.x = 0;
    posImage.y = 0;
    texture.loadFromFile("golf/ressource/trou.png");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    type = ElementType::Hole;
}

Trou::~Trou()
{

}

void Trou::update()
{
    sprite.setPosition(sf::Vector2f(m_x,m_y));
    sprite.setTextureRect(sf::IntRect(posImage,tail));
}

void Trou::dedant(Ball *&ball)
{
    std::cout << "test\n";

    // if (mur.getY() > m_y && mur.getY() < m_y + m_hauteur && mur.getX() < m_x + (m_largeur / 2) && mur.getX() + mur.getLargeur() > m_x + (m_largeur / 2)
    //  || mur.getY() < m_y && mur.getY() > m_y + m_hauteur && mur.getX() < m_x + (m_largeur / 2) && mur.getX())
    // if (mur.getX() > m_x && mur.getX() < m_x + m_largeur && mur.getY() < m_y + (m_hauteur / 2) && mur.getY() + mur.getHauteur() > m_y + (m_hauteur / 2)
    //  || mur.getX() < m_x && mur.getX() > m_x + m_largeur && mur.getY() < m_y + (m_hauteur / 2) && mur.getY())
    if (m_y > ball->getY() && m_y < ball->getY() + ball->getHauteur() &&
    m_x > ball->getX() && m_x < ball->getX() + ball->getLargeur())
    {
        delete ball;
    }
}