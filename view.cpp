#include "view.hpp"
#include <iostream>

View::View()
{
    posView.x = 0;
    posView.y = 0;
    tailView.x = 130;
    tailView.y = 100;
    view.setCenter(posView);
    view.setSize(tailView);
    m_zoom = false;
    m_deZoom = false;
    m_left = false;
    m_right = false;
    pos = true;
}

View::~View()
{
}

void View::update()
{
    // std::cout << "posView X/Y : " << posView.x << " ," << posView.y << std::endl;
    view.setCenter(posView);
    view.setSize(tailView);
}

void View::position(Ball *&ball)
{
    if (pos)
    {
        // std::cout << "position" << std::endl;
        posView.x = ball->getX();
        posView.y = ball->getY();
    }
    else
    {
    }
}

void View::input(sf::Keyboard::Key key, bool touche)
{
    if (touche)
    {
        if (key == sf::Keyboard::Up)
            m_zoom = true;
        else if (key == sf::Keyboard::Down)
            m_deZoom = true;
        else if (key == sf::Keyboard::Left)
            m_left = true;
        else if (key == sf::Keyboard::Right)
            m_right = true;
        else if (key == sf::Keyboard::P)
            pos = true;
    }
    else
    {
        m_zoom = false;
        m_deZoom = false;
        m_left = false;
        m_right = false;
    }
}

void View::chekInput()
{
    if (m_zoom)
    {
        pos = false;
        tailView.x -= 0.5;
        tailView.y -= 0.5;
    }
    else if (m_deZoom)
    {
        pos = false;
        tailView.x += 0.5;
        tailView.y += 0.5;
    }
    else if (m_left)
    {
        pos = false;
        posView.x -= 1;
    }
    else if (m_right)
    {
        pos = false;
        posView.x += 1;
    }
}