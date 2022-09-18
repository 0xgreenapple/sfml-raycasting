//
//  particle.hpp
//  raycasting
//
//  Created by 0xgreenapple on 18/09/22.
//  Copyright © 2022 Apple. All rights reserved.
//

#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <math.h>
#include "ray.hpp"


class particles
{
private:
    sf::RenderWindow* window;
    
public:

    sf::Vector2f pos;
    std::vector <ray> rays;

    particles(sf::RenderWindow * window );
    
    void updatearray();
    void look(std::vector<boundry> &wall);
    void updatepos(float pos_X,float pos_Y);
    void show();
};
