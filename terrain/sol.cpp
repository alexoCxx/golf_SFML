#include "sol.hpp"
#include <random>

Sol::Sol()
{
    VertFoncer = false;
    posImage.x = 0;
    posImage.y = 0;
    tail.x = 15;
    tail.y = 15;
    m_x;
    m_y;
    ChiffreAléatoires;
    texture.loadFromFile("golf/ressource/Terrain.png");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    type = ElementType::Ground;

    srand(time(nullptr));
}

Sol::~Sol()
{

}

void Sol::update()
{
    sprite.setPosition(sf::Vector2f(m_x,m_y));
    sprite.setTextureRect(sf::IntRect(posImage,tail));
}

void Sol::costume()
{
    // chiffreAl();

    if (ChiffreAléatoires == 2 || ChiffreAléatoires == 3)
    {
        posImage.x = 30;
        posImage.y = 0;
    }
    else if (ChiffreAléatoires == 1)
    {
        posImage.x = 60;
        posImage.y = 0;
    }
    else
    {
        posImage.x = 0;
        posImage.y = 0;
    }

    if (!VertFoncer)
    {
        VertFoncer = true;
    }
    else
    {
        VertFoncer = false;
        posImage.x += 15;
    }
    sprite.setTextureRect(sf::IntRect(posImage.x, posImage.y, tail.x, tail.y));
}

int Sol::chiffreAl()
{
    ChiffreAléatoires = rand() % 10 + 1;
    return ChiffreAléatoires;
}