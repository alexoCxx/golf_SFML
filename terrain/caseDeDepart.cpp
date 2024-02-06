#include "caseDeDepart.hpp"

CaseDeDepart::CaseDeDepart()
{
    m_x;
    m_y;
    posImage.x = 0;
    posImage.y = 0;
    tail.y = 15;
    tail.x = 15;
    texture.loadFromFile("golf/ressource/caseDeDepart.png");
    texture.setSmooth(true);
    sprite.setTexture(texture);
    type = ElementType::Start;
}

CaseDeDepart::~CaseDeDepart()
{
}

void CaseDeDepart::update()
{
    sprite.setTextureRect(sf::IntRect(posImage,tail));
    sprite.setPosition(sf::Vector2f(m_x, m_y));
}