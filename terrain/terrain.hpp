#ifndef TERRAIN_HPP
#define TERRAIN_HPP
#include <vector>
#include <string>
#include "../ball/ball.hpp"
#include "SFML/Graphics.hpp"
#include "caseDeDepart.hpp"
#include "mur.hpp"
#include "sol.hpp"
#include "trou.hpp"
#include "element.hpp"

class Terrain
{
private :
    std::string line;
    int mapY;
    int mapX;
    bool vert = false;
    int i = 0;

    std::vector<Element*> elements;

public :
    Terrain();
    ~Terrain();
    void lire(const std::string& p_path = "golf/ressource/level.txt");
    void update(sf::RenderWindow &window, Ball *&ball);
};

#endif