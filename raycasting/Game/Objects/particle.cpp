//
//  particle.cpp
//  raycasting
//
//  Created by 0xgreenapple on 18/09/22.
//  Copyright © 2022 Apple. All rights reserved.
//

#include "particle.hpp"
#include "../settings.h"
particles::particles(sf::RenderWindow * window ){
    this->window  = window;
    this->pos = sf::Vector2f(window->getSize().x /2, window->getSize().y/2);

    for (int i = 0 ; i < 360 ;  i +=1){
        ray ray1(sf::Vector2f(pos.x , pos.y),i,window);
        rays.push_back(ray1);
    }
}

void particles::updatearray(){
    rays.clear();
    int ray_den = 1;
    
    if(RAY_DENSITY < 1){
        ray_den = 1;
    }else if (RAY_DENSITY > 360){
        ray_den = 360-1;
    }else{
        ray_den = RAY_DENSITY;
    };
    for (int i = 0 ; i < 360 ;  i +=ray_den){
        ray ray1(sf::Vector2f(pos.x , pos.y),i,window);
        rays.push_back(ray1);
    }
}
void particles::look(std::vector<boundry> &wall){
    //stop the rays to go other rays
    
    for (int i = 0;  i < rays.size();i++){
        sf::Vector2f closest (NULL,NULL);
        float record = INFINITY;
        for (int j = 0;  j < wall.size();j++){
            sf::Vector2f p = rays[i].cast(wall[j]);
            if (p.x != NULL && p.y != NULL ){
                float dis = sqrt((pow((pos.x - p.x),2)+pow((pos.y - p.y),2)));

                if (dis < record){
                    record  = dis;
                    closest = p;
                }
            }

        }
        if (closest.x != NULL && closest.y != NULL){
            sf::Vertex line[] =
            {
                sf::Vertex(pos,sf::Color::Red),
                sf::Vertex(closest , sf::Color::Yellow),
            };
            
        
            sf::CircleShape pt;
            pt.setRadius(BOUND_REFLECTION);
            pt.setFillColor(sf::Color::White);
            pt.setPosition(closest.x - BOUND_REFLECTION , closest.y - BOUND_REFLECTION);
            window->draw(pt);
            window->draw(line,2,sf::Lines);


        }
    }
}
void particles::updatepos(float pos_X,float pos_Y){
    updatearray();
    this->pos.x = pos_X;
    this->pos.y = pos_Y;
}
void particles::show(){
    for (int i = 0;  i < rays.size();i++){
        rays[i].show();
    }
};
