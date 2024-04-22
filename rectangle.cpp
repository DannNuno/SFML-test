#include "rectangle.hpp"

Rectangle::Rectangle(Vector2f size){
    this->shape = RectangleShape(size);
    this->shape.setPosition({400.f,300.f});
    this->shape.setFillColor(Color(190,0,150));

    this->speed = Vector2f(5.f,5.f);
}

void Rectangle::update(){
     if(this->shape.getPosition().x + this->shape.getSize().x >= 800 || this->shape.getPosition().x < 0){
            this->speed.x *= -1;
            this->shape.setFillColor({rand()%255,rand()%255,rand()%255});
        }

        if(this->shape.getPosition().y + this->shape.getSize().y >= 600 || this->shape.getPosition().y < 0){
            this->speed.y *= -1;
            this->shape.setFillColor({rand()%255,rand()%255,rand()%255});
        }

        this->shape.move(this->speed);
}

void Rectangle::drawTo(RenderWindow &window){
    window.draw(this->shape);
}