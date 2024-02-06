#ifndef VIEW_HPP
#define VIEW_HPP
#include "SFML/Graphics.hpp"
#include "ball/ball.hpp"

class View
{
private :
    sf::View view;
    sf::Vector2f posView;
    sf::Vector2f tailView;
    int rotation;

    bool m_zoom;
    bool m_deZoom;
    bool m_right;
    bool m_left;

    bool pos;

public :
    View();
    ~View();
    void update();
    void position(Ball *&ball);
    void input(sf::Keyboard::Key key, bool touche);
    void chekInput();

    // get
    sf::View getView()
    {
        return view;
    }
    float getX()
    {
        return posView.x;
    }
    float getY()
    {
        return posView.y;
    }
    float getLargeur()
    {
        return tailView.x;
    }
    float getHauteur()
    {
        return tailView.y;
    }
    int getRotation()
    {
        return rotation;
    }

    // set 
    void setX(float p_X)
    {
        posView.x = p_X;
    }
    void setY(float p_Y)
    {
        posView.y = p_Y;
    }
    void setLargeur(float p_largeur)
    {
        tailView.x = p_largeur;
    }
    void setHauteur(float p_hauteur)
    {
        tailView.y = p_hauteur;
    }
    void setRotation(int p_rotation)
    {
        rotation = p_rotation;
    }
};

#endif