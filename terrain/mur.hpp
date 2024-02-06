#ifndef MUR_HPP
#define MUR_HPP
#include "SFML/Graphics.hpp"
#include "element.hpp"
#include "../Entity.hpp"

class Mur : public Element, public Entity
{
private:
    sf::Vector2i tail;
    sf::Vector2i posImage;
public:
    Mur();
    ~Mur();
    void update();
 
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
    int getPosImageX()
    {
        return posImage.x;
    }
    int getPosImageY()
    {
        return posImage.y;
    }
    sf::Sprite getSprite()
    {
        return sprite;
    }

    //set
    void setX(int X)
    {
        m_x = X;
    }
    void setY(int Y)
    {
        m_y = Y;
    }
    void setLargeur(int largeur)
    {
        tail.x = largeur;
    }
    void setHauteur(int hauteur)
    {
        tail.y = hauteur;
    }
    void setPosImageX(int X)
    {
        m_x = X;
    }
    void setPosImageY(int Y)
    {
        m_y = Y;
    }
};

#endif