#include <SFML/Graphics.hpp>

#define WIDE 800
#define HIGH 600



//Game Loop
int main()
{
  sf::RenderWindow window(sf::VideoMode(WIDE,HIGH),"Wilson was Bored");

  sf::CircleShape circle(25);
  circle.setFillColor(sf::Color::Red);
  circle.setPosition(100,100);
  int circleDirection = 0;


  while(window.isOpen())
  {
    //Handles Events
    sf::Event event;
    while(window.pollEvent(event))
    {
      //Close Event
      if(event.type == sf::Event::Closed)
      {
        window.close();
      }
    }
    window.clear(sf::Color::Black);

    //update
    if(circleDirection == 0)
    {
      circle.move(1,0);
    }
    if(circleDirection == 1)
    {
      circle.move(-1,0);
    }

    if(circle.getPosition().x > 750)
    {
      circleDirection = 1;
    }
    if(circle.getPosition().x < 0)
    {
      circleDirection = 0;
    }


    //render fender bender sender
    window.draw(circle);
    window.display();

  }
}
