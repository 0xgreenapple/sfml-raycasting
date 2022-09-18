//  Created by 0xgreenapple on 18/09/22.


#include "ray.hpp"

ray::ray(sf::Vector2f pos1 ,float angle, sf::RenderWindow * window){
    this -> pos1 = pos1;
    this->window = window;
    this-> angle = angle;
    this->dir = sf::Vector2f(cos(angle),sin(angle));
};

void ray::show(){
    sf::Vertex line[] =
    {
        sf::Vertex(pos1),
        sf::Vertex(sf::Vector2f( pos1.x + dir.x*30,pos1.y + dir.y*30))
    };
    window->draw(line,2,sf::Lines);
};

sf::Vector2f ray::cast(boundry wall){
    float x1  = wall.pos1.x;
    float y1  = wall.pos1.y;
    float x2  = wall.pos2.x;
    float y2  = wall.pos2.y;

    float x3 = pos1.x;
    float y3 = pos1.y;
    float x4 = pos1.x + dir.x*20;
    float y4 = pos1.y + dir.y*20;


    float den = (x1 - x2)*(y3-y4) - (y1-y2)*(x3-x4);
    
    if (den == 0){
        sf::Vector2f(NULL, NULL);
    }
    float t = ((x1-x3)*(y3-y4) - (y1-y3)*(x3-x4))/den;
    float u = -((x1-x2)*(y1-y3) - (y1-y2)*(x1-x3))/den;

    if(t>0 && t < 1 && u>0){

        sf::Vector2f position(x1+t*(x2-x1),y1+t*(y2-y1));

        return position;
    } else{
        return sf::Vector2f(NULL, NULL);
    };


}
