#include "terrain.hpp"
#include <fstream>
#include <string>
#include <iostream>

Terrain::Terrain() :
    line(),
    mapX(0),
    mapY(0),
    vert(false),
    i(0),
    elements()
{
}

Terrain::~Terrain()
{
    for(auto element : elements)
    {
        delete element;
    }
} 
void Terrain::lire(const std::string& p_path)
{
    std::ifstream sol(p_path, std::ios::in);
    if (sol)
    {
        int y = 0;
        vert = true;
        while (std::getline(sol, line))
        {
            for (int x = 0; x < line.size(); x++)
            {
                if (line.at(x) == '1')
                {
                    Sol* sol = new Sol();
                    sol->setX(x * sol->getLargeur());
                    sol->setY(y * sol->getHauteur());
                    if (vert)
                    {
                        sol->setVertFoncer(false);
                        vert = false;
                    }
                    else if (!vert)
                    {
                        sol->setVertFoncer(true);
                        vert = true;
                    }
                    sol->costume();
                    elements.push_back(sol);
                }
                else if (line.at(x) == '2')
                {
                    Mur* mur = new Mur();
                    mur->setX(x * mur->getLargeur());
                    mur->setY(y * mur->getHauteur());
                    elements.push_back(mur);
                }
                else if (line.at(x) == '3')
                {
                    Trou* trou = new Trou();
                    trou->setX(x * trou->getLargeur());
                    trou->setY(y * trou->getHauteur());
                    elements.push_back(trou);
                }
                else if (line.at(x) == '4')
                {
                    CaseDeDepart* Cball = new CaseDeDepart();
                    Cball->setX(x * Cball->getLargeur());
                    Cball->setY(y * Cball->getHauteur());
                    elements.push_back(Cball);
                }
                else
                {
                    std::cerr << "Error unknown ground type : " << line.at(x) << " at location x: " << x << "; y: " << y << std::endl;
                }
            }
            y++;
        }
        sol.close();
    }
    else
    {
        std::cout << "ERREUR du fichier sol\n";
    }
}

void Terrain::update(sf::RenderWindow &window, Ball *&ball)
{
    for(auto element : elements)
    {
        if (element->getType() == ElementType::Ground)
        {
            Sol *sol = dynamic_cast<Sol*>(element);
            sol->update();
            window.draw(sol->getSprite());
        }
        else if (element->getType() == ElementType::Wall)
        {
            Mur *mur = dynamic_cast<Mur*>(element);
            ball->rebond(mur);
            mur->update();
            window.draw(mur->getSprite());
        }
        else if (element->getType() == ElementType::Hole)
        {
            Trou *trou = dynamic_cast<Trou*>(element);
            trou->update();
            trou->dedant(ball);
            window.draw(trou->getSprite());
        }
        else if (element->getType() == ElementType::Start)
        {
            CaseDeDepart *Cball = dynamic_cast<CaseDeDepart*>(element);
            Cball->update();
            while (i == 0)
            {
                ball->setX(Cball->getX());
                ball->setY(Cball->getY());
                i++;
            }
            window.draw(Cball->getSprite());
        }
        else
        {
        }
    }
}