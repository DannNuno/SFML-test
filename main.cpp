#include <SFML/Graphics.hpp>
using namespace sf;

float speedX = 5.f;
float speedY = 5.f;

int main()
{
    RenderWindow window(VideoMode(800, 600), "SFML works!");
    RectangleShape rectangulo({100.f, 50.f});
    /*vector para el tamaño del rectangulo
    .f significa float
    */
    rectangulo.setFillColor(Color::Magenta);
    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();

        if(rectangulo.getPosition().x + rectangulo.getSize().x >= 800 || rectangulo.getPosition().x < 0){
            speedX *= -1;
            rectangulo.setFillColor({rand()%255,rand()%255,rand()%255});
        }

        if(Mouse::isButtonPressed(Mouse::Left)){
            rectangulo.rotate(15);
        }

        if(rectangulo.getPosition().y + rectangulo.getSize().y >= 600 || rectangulo.getPosition().y < 0){
            speedY *= -1;
            rectangulo.setFillColor({rand()%255,rand()%255,rand()%255});
        }

        if(Mouse::isButtonPressed(Mouse::Right)){
            rectangulo.rotate(-15);
        }

        rectangulo.move({speedX,speedY});
        //para mover la figura
        window.draw(rectangulo);
        window.display();
    }

    return 0;
}