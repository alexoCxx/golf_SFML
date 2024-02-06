#ifndef SOL_HPP
#define SOL_HPP
#include "SFML/Graphics.hpp"
#include "../Entity.hpp"
#include "element.hpp"

class Sol : private Entity, public Element
{
private:
    sf::Vector2i tail;
    sf::Vector2i posImage;
    int ChiffreAléatoires;
    bool VertFoncer;

public:
    Sol();
    ~Sol();
    void costume();
    void update();
    int chiffreAl();

    //get
    float getX()
    {
        return m_x;
    }
    float getY()
    {
        return m_y;
    }
    int getLargeur()
    {
        return tail.x;
    }
    int getHauteur()
    {
        return tail.y;
    }
    int getChiffreAléatoires()
    {
        return ChiffreAléatoires;
    }
    bool getVertFoncer()
    {
        return VertFoncer;
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
    void setChiffreAléatoires(int aléatoires)
    {
        ChiffreAléatoires = aléatoires;
    }
    void setVertFoncer(bool vert)
    {
        VertFoncer = vert;
    }
};

#endif