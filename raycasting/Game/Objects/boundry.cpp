//
//  boundry.cpp
//  raycasting
//
//  Created by 0xgreenapple on 18/09/22.
//  Copyright © 2022 Apple. All rights reserved.
//

#include "boundry.hpp"

boundry::boundry(sf::Vector2f pos1 ,sf::Vector2f pos2, sf::RenderWindow * window){
    this -> pos1 = pos1;
    this -> pos2 = pos2;
    this->window = window;
};
void boundry::show(){
    sf::Vertex line[] =
    {
        sf::Vertex(pos1),
        sf::Vertex(pos2)
    };
    window->draw(line,2,sf::Lines);
}
