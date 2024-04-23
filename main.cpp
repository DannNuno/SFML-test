#include <SFML/Graphics.hpp>
#include "rectangle.hpp"
#include <vector>
using namespace sf;
using namespace std;

vector<Rectangle> rectangulos;

int main()
{
    //setup
    RenderWindow window(VideoMode(800, 600), "SFML works!");
    window.setFramerateLimit(60);
    Rectangle rect(Vector2f(60.f,30.f),window);
    rectangulos.push_back(rect);

    //loop
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if(event.type == Event::MouseButtonPressed){
                if(event.mouseButton.button == Mouse::Left){
                    float x = float(rand()%100);
                    float y = float(rand()%100);
                    Rectangle r= Rectangle(Vector2f(x,y),window);
                    rectangulos.push_back(r);
                }

                if(event.mouseButton.button == Mouse::Right){
                    for(auto &r : rectangulos){
                    r.changeColorIfClick(Mouse::getPosition(window));
                }
                }

            }
        }

        window.clear();
        rect.update();
       
        rect.drawTo(window);

        for(auto &r : rectangulos){
            r.update();
            r.drawTo(window);
        }
        window.display();
    }

    return 0;
}