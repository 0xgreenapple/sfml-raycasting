//
//  Game.cpp
//  raycasting
//
//  Created by 0xgreenapple on 18/09/22.
//  Copyright © 2022 Apple. All rights reserved.
//


#include "Game.hpp"

game::game(){
    init();
};
void game::initwindow(){
    this->window = new sf::RenderWindow  \
    (sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT),GAMENAME,sf::Style::Default);
    this->window->setFramerateLimit(FPS);
}

void game::init(){
    initwindow();
    setup();
}
void game::setup(){
    srand(time(NULL));
    
    for(int i = 0; i< 5; i++){
        float x = rand() % 2000;
        float x2 = rand() % 2000;
        float y = rand() % 1000;
        float y2 = rand() % 1000;
        boundry boundtemp(sf::Vector2f(x,y),sf::Vector2f(x2,y2),window);
        bound.push_back(boundtemp);
    }
    
    this->particale = new particles(window);
    this->rays = new ray(sf::Vector2f(window->getSize().x /2, window->getSize().y/2),10,window);
};

game::~game(){
    delete this->window;
    delete this->particale;
    delete this->rays;
}

void game::updateEvents(){
    while (window->pollEvent(GameEvent))
    {
        // Close window: exit
        if (GameEvent.type == sf::Event::Closed) {
            window->close();
        }
        // Escape pressed: exit
        if (GameEvent.type == sf::Event::KeyPressed &&
            GameEvent.key.code == sf::Keyboard::Escape) {
            window->close();
        }
        //get the mouse postion
        if (GameEvent.type == sf::Event::MouseMoved)
       {
           particale->updatepos(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y);
       }
    }
};
void game::updateDt(){
    /// Get the Delta time from clock
    /// restart and store it as variable
    
    
    dt = Dt_clock.getElapsedTime().asSeconds();
    Dt_clock.restart();
};
void game::update(){
    /// handle Events For the game
    
    updateDt();
    updateEvents();
    rect.setSize(sf::Vector2f(100,100));
    rect.setFillColor(sf::Color::Red);
};
void game::render(){
    //clear the window and Draw
    window->clear();
    for (int i = 0; i < bound.size();i++){
        bound[i].show();
    }
    particale->look(bound);
    particale->show();
    window->display();
};

void game::run(){
    while (this->window->isOpen())
    {
        update();
        render();
    }
};
