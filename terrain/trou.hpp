#ifndef TROU_HPP
#define TROU_HPP
#include "SFML/Graphics.hpp"
#include "../Entity.hpp"
#include "element.hpp"
#include "../ball/ball.hpp"

class Trou : private Entity, public Element
{
private :
    sf::Vector2i tail;
    sf::Vector2i posImage;

public :
    Trou();
    ~Trou();
    void update();
    void dedant(Ball *&ball);

    // get 
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
    int getPosImageX()
    {
        return posImage.x;
    }
    int getPosImageY()
    {
        return posImage.y;
    }
    
    // set 
    void setX(int X)
    {
        m_x = X;
    }
    void setY(int Y)
    {
        m_y = Y;
    }
    void setHauteur(int H)
    {
        tail.y = H;
    }
    void setLargeur(int L)
    {
        tail.x = L;
    }
    void setPosImageX(int X)
    {
        posImage.x = X;
    }
    void setPosImageY(int Y)
    {
        posImage.y = Y;
    }
};
#endif