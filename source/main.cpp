#include "Hour.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(1280, 720), "Hour");

  const sf::Vector2f pos(window.getSize().x / 2 - 200.f, window.getSize().y / 2 - 200.f);
  const float radius = 200.f;
  Hour circle(radius, pos, sf::Color::Black);
  circle.Second::setColor(sf::Color::Red);
  circle.Minute::setColor(sf::Color::Green);
  circle.Hour::setColor(sf::Color::White);
  circle.Text::setColor(sf::Color::White);
  circle.Circle::setBorder(sf::Color::White, 5);

  while(window.isOpen()) {
    sf::Event event;
    while(window.pollEvent(event))
      if (event.type == event.Closed) window.close();
    window.clear();
    circle.draw(window);
    window.display();
  }
}