#ifndef rectangle_h
#define rectangle_h

#include <SFML/Graphics.hpp>
using namespace sf;

class Rectangle{
private:
Vector2f speed;
Vector2f acc;
RectangleShape shape;

public:
Rectangle(Vector2f size, RenderWindow &window);

void changeColorIfClick(Vector2i position);
void update();
void drawTo(RenderWindow &window);
};

/*La clase Rectangle deberá tener las siguientes propiedades privadas:
variable speed de tipo Vector 2f
variable shape de tipo RectangleShape

constructor:
Constructor que recibe un Vector2f llamado size

métodos:
update de tipo void
drawTo de tipo void que recibe un objeto de tipo RenderWindow por referencia.*/

#endif