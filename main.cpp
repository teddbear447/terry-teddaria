#include <SFML/Graphics.hpp>

#define WIDE 800
#define HIGH 600



//Game Loop
int main()
{
  sf::RenderWindow window(sf::VideoMode(WIDE,HIGH),"Once there was a Square named Timothy");

  sf::CircleShape circle(15);
  circle.setFillColor(sf::Color::Red);
  circle.setPosition(100,100);

  sf::RectangleShape hero(sf::Vector2f(20,20));
  hero.setFillColor(sf::Color::Green);
  hero.setPosition(400,300);

  int circleDirection = 0;

  double heroSpeed = 0.5;


  while(window.isOpen())
  {
    //Handle Only Certain Events
    sf::Event event;
    while(window.pollEvent(event))
    {
      //Close Event
      if(event.type == sf::Event::Closed)
      {
        window.close();
      }

    }
    //Handle Input NOW!!!
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && hero.getPosition().y > 0)
    {
      hero.move(0,-heroSpeed);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && hero.getPosition().y < HIGH-hero.getSize().y)
    {
      hero.move(0,heroSpeed);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && hero.getPosition().x > 0)
    {
      hero.move(-heroSpeed,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && hero.getPosition().x < WIDE-hero.getSize().x)
    {
      hero.move(heroSpeed,0);
    }


    window.clear(sf::Color::Black);

    //UPDATE the WORLD!!!

    if(circleDirection == 0)
    {
      circle.move(0.5,0);
    }
    if(circleDirection == 1)
    {
      circle.move(-0.5,0);
    }

    if(circle.getPosition().x > 770)
    {
      circleDirection = 1;
    }
    if(circle.getPosition().x < 0)
    {
      circleDirection = 0;
    }



    //RENDER ALL THE THINGS
    window.draw(circle);
    window.draw(hero);
    window.display();

  }
}
