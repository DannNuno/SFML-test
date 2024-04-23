#include "rectangle.hpp"

Rectangle::Rectangle(Vector2f size, RenderWindow &window){
    this->shape = RectangleShape(size);
    this->shape.setPosition({Mouse::getPosition(window).x,Mouse::getPosition(window).y});
    this->shape.setFillColor(Color::Red);
    this->shape.setOutlineThickness(10.f);
    this->shape.setOutlineColor(Color::Green);

    this->speed = Vector2f(5.f,5.f);
    this->acc = Vector2f(0.f,1.f);
}

void Rectangle::update(){

        if(this->shape.getPosition().y + this->shape.getSize().y <= 600){
            this->speed += this->acc;
            this->shape.move(this->speed);
        }

        if(this->shape.getPosition().x + this->shape.getSize().x >= (800-10) || this->shape.getPosition().x < 0+10){
            this->speed.x *= -1;
        }

        if(this->shape.getPosition().y + this->shape.getSize().y >= (590) || this->shape.getPosition().y < 0+10){
            this->speed.y *= -1;
            this->shape.setPosition(this->shape.getPosition().x, 590-this->shape.getSize().y);
        }

}

void Rectangle::changeColorIfClick(Vector2i position){
    float x = this->shape.getPosition().x;
    float y = this->shape.getPosition().y;

    float w = this->shape.getSize().x;
    float h = this->shape.getSize().y;

    int mouseX = position.x;
    int mouseY = position.y;

    if((mouseX >= x && mouseX <= x+w && mouseY >= y && mouseY <= y+h)){
            this->shape.setFillColor(Color::Green);
            this->shape.setOutlineColor(Color::Red);
    }

};

void Rectangle::drawTo(RenderWindow &window){
    window.draw(this->shape);
}