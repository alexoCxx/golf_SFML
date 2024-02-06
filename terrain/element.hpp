#ifndef ELEMENT_HPP
#define ELEMENT_HPP
#include "SFML/Graphics.hpp"

enum class ElementType {
    Wall,
    Ground,
    Hole,
    Start
}; 

class Element
{
protected:
    sf::Sprite sprite;
    sf::Texture texture;
    ElementType type;

public:
    Element();
    virtual ~Element() = default;

    sf::Sprite getSprite() const
    {
        return sprite;
    }
    ElementType getType() const
    {
        return type;
    }
};

#endif