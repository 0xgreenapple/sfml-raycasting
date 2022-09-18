//
//  boundry.hpp
//  raycasting
//
//  Created by 0xgreenapple on 18/09/22.
//  Copyright © 2022 Apple. All rights reserved.
//
#pragma once
#include <math.h>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class boundry
{
protected:
    sf::RenderWindow * window;

public:
    sf::Vector2f pos1;
    sf::Vector2f pos2;
    boundry(sf::Vector2f pos1 ,sf::Vector2f pos2, sf::RenderWindow * window);
    void show ();
};

