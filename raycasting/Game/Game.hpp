// game class
#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <vector>
#include <math.h>
#include "settings.h"
#include "Objects/boundry.hpp"
#include "Objects/ray.hpp"
#include "Objects/particle.hpp"


class game
{
protected:
    sf::RenderWindow* window;
    sf::Clock Dt_clock;
    sf::Event GameEvent;
    sf::RectangleShape rect;
    
    std:: vector <boundry> bound;
    particles *particale;
    ray *rays;

private:
    int dt;
    void init();
    void initwindow();
    void setup();
public:
    game();
    virtual ~game();
    
public:
    void run();
    void updateEvents();
    void updateDt();
    void update();
    void render();
};
