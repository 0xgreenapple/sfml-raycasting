//  Created by 0xgreenapple on 18/09/22.

#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>
#include "boundry.hpp"
#include <vector>

class ray
{
protected:
    sf::RenderWindow * window;
    
public:
    sf::Vector2f pos1;
    sf::Vector2f dir;
    float angle = 50;
    
public:
    ray(sf::Vector2f pos1 ,float angle, sf::RenderWindow * window);
    void show ();
    sf::Vector2f cast(boundry wall);
};
