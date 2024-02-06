#include "mur.hpp"
#include "SFML/Graphics.hpp"

Mur::Mur() : Element()
{
    m_x;
    m_y;
    tail.x = 15;
    tail.y = 15;
    posImage.x = 0;
    posImage.y = 0;
    texture.loadFromFile("golf/ressource/Mur.png");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    type = ElementType::Wall;
}

Mur::~Mur()
{
    
}

void Mur::update()
{
    sprite.setTextureRect(sf::IntRect(posImage,tail));
    sprite.setPosition(sf::Vector2f(m_x, m_y));
}