#include "ball.hpp"
#include "../Entity.hpp"
#include <cmath>
#include <iostream>

Ball::Ball()
{
    m_hauteur = 15;
    m_largeur = 15;
    m_x;
    m_y;
    texBall.loadFromFile("golf/ressource/Ball.png");
    texBall.setSmooth(true);
    ball.setTexture(texBall);
    position = sf::Mouse::getPosition(window);
    worldPos = window.mapPixelToCoords(position);
    toucheBall = false;
    envoieBall = false;
    m_vitesse.y = 0;
    m_vitesse.x = 0;
    timeMesure = 0.10;
    timeMove = sf::seconds(timeMesure);
}

Ball::~Ball()
{
}

void Ball::update(sf::RenderWindow& window)
{
    // std::cout << "worldPos X/Y : " << worldPos.x << " ," << worldPos.y << std::endl;
    // std::cout << "X/Y : " << m_x << ", " << m_y << std::endl;
    //std::cout << "largeur/hauteur : " << m_largeur << ", " << m_hauteur << std::endl;
    //std::cout << "X/Y (mouse) : " << position.x << ", " << position.y << std::endl;
    // std::cout << "toucheBall : " << toucheBall << std::endl;
    ball.setPosition(sf::Vector2f(m_x, m_y));
    position = sf::Mouse::getPosition(window);
    worldPos = window.mapPixelToCoords(position);
}

void Ball::input(sf::Event ev, bool chekPressed)
{
    if (chekPressed)
    {
        if (ev.mouseButton.button == sf::Mouse::Left && worldPos.x > m_x - 10 && worldPos.x < m_x + m_largeur && worldPos.y > m_y - 10 && worldPos.y < m_y + m_hauteur && !toucheBall)
        {
            toucheBall = true;
        }
        else if (ev.mouseButton.button == sf::Mouse::Left && toucheBall)
        {
            envoieBall = true; 
        }
    }
    else
    {
    }
}

void Ball::chekInput()
{
    if (envoieBall && toucheBall)
    {
        vitesse();
        toucheBall = false;
        envoieBall = false;
    }
    else if (toucheBall && !envoieBall)
    {
        // std::cout << "touché \n";
        m_vitesse.x = 0;
        m_vitesse.y = 0;
    }
}

void Ball::vitesse()
{
    m_vitesse.y = m_y - worldPos.y;
    m_vitesse.x = m_x - worldPos.x;
}

void Ball::avancer(sf::Clock& clock)
{
    // std::cout << "vitesse.X/Y : " << m_vitesse.x << " ," << m_vitesse.y << std::endl;

    // std::cout << "test" << std::endl;
    // std::cout << debeg.asSeconds() << std::endl;
    // std::cout << time.asSeconds() << std::endl;
    if (clock.getElapsedTime() > timeMove)
    {
        // std::cout << "test : ok" << std::endl;
        setY(m_y + m_vitesse.y);
        setX(m_x + m_vitesse.x);

        m_vitesse.x *= 0.85;
        m_vitesse.y *= 0.85;

        timeMove += timeMoveConst;
    }
}

void Ball::rebond(Mur *&mur)
{
    int X = 0;
    int Y = 0;

    if (m_vitesse.x > 0 && m_vitesse.y > 0)
    {
        if (m_x > mur->getX() && m_y > mur->getY() && m_y < mur->getY() + mur->getLargeur())
        {
            X = m_x - mur->getX();
            Y = m_y - (X * m_vitesse.y / m_vitesse.x);
            m_x = m_x - (m_vitesse.x * 2);
            m_y = m_y - (m_vitesse.y * 2);
            m_x += X;
            m_y += Y;

            m_vitesse.y *= -1;
        }
        else if (m_y > mur->getY() && m_x > mur->getX() && m_x < mur->getX() + mur->getLargeur())
        {
            Y = m_y - mur->getY();
            X = m_x - (Y * m_vitesse.x / m_vitesse.y);
            m_x = m_x - (m_vitesse.x * 2);
            m_y = m_y - (m_vitesse.y * 2);
            m_x += X;
            m_y += Y;

            m_vitesse.x *= -1;
        }
    }
    else if (m_vitesse.x < 0 && m_vitesse.y < 0)
    {
        if (m_x < mur->getX() && m_y > mur->getY() && m_y < mur->getY() + mur->getLargeur())
        {
            X = m_x - mur->getX();
            Y = m_y - (X * m_vitesse.y / m_vitesse.x);
            m_x -= m_vitesse.x * 2;
            m_y -= m_vitesse.y * 2;
            m_x += X;
            m_y += Y;

            m_vitesse.y *= -1;
        }
        else if (m_y <= mur->getY() && m_x > mur->getX() && m_x < mur->getX() + mur->getHauteur())
        {
            Y = m_y - mur->getY();
            X = m_x - (Y * m_vitesse.y / m_vitesse.x);
            m_x = m_x - (m_vitesse.x * 2);
            m_y = m_y - (m_vitesse.y * 2);
            m_x += X;
            m_y += Y;

            m_vitesse.x *= -1;
        }
    }
    else if (m_vitesse.x < 0 && m_vitesse.y > 0)
    {
        if (m_x < mur->getX() && m_y > mur->getY() && m_y < mur->getY() + mur->getLargeur())
        {
            X = m_x - mur->getX();
            Y = m_y - (X * m_vitesse.y / m_vitesse.x);
            m_x -= m_vitesse.x * 2;
            m_y -= m_vitesse.y * 2;
            m_x += X;
            m_y += Y;

            m_vitesse.y *= -1;
        }
        
        else if (m_y > mur->getY() && m_x > mur->getX() && m_x < mur->getX() + mur->getLargeur())
        {
            Y = m_y - mur->getY();
            X = m_x - (Y * m_vitesse.x / m_vitesse.y);
            m_x = m_x - (m_vitesse.x * 2);
            m_y = m_y - (m_vitesse.y * 2);
            m_x += X;
            m_y += Y;

            m_vitesse.x *= -1;
        }
    }
    else if (m_vitesse.x > 0 && m_vitesse.y < 0)
    {
        if (m_x > mur->getX() && m_y > mur->getY() && m_y < mur->getY() + mur->getLargeur())
        {
            X = m_x - mur->getX();
            Y = m_y - (X * m_vitesse.y / m_vitesse.x);
            m_x = m_x - (m_vitesse.x * 2);
            m_y = m_y - (m_vitesse.y * 2);
            m_x += X;
            m_y += Y;

            m_vitesse.y *= -1;
        }
        else if (m_y <= mur->getY() && m_x > mur->getX() && m_x < mur->getX() + mur->getHauteur())
        {
            Y = m_y - mur->getY();
            X = m_x - (Y * m_vitesse.y / m_vitesse.x);
            m_x = m_x - (m_vitesse.x * 2);
            m_y = m_y - (m_vitesse.y * 2);
            m_x += X;
            m_y += Y;

            m_vitesse.x *= -1;
        }
    }
}