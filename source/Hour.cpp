#include "Hour.hpp"

void Hour::setColor(const sf::Color &color) {
  hour.setFillColor(color);
}

void Hour::setPosition(const sf::Vector2f &position) {
  hour.setPosition(position);
}

void Hour::setSize(const sf::Vector2f &size) {
  hour.setSize(size);
}

void Hour::now() {
  time_t now(time(0));
  tm* local_time = localtime(&now);
  int hours = local_time->tm_hour % 12;
  int minutes = local_time->tm_min;
  int seconds =local_time->tm_sec;
  float hourAngle = (hours * 30) + (minutes * 0.5) - 180;
  float minuteAngle = (minutes * 6)  - 180;
  float secondAngle = (seconds * 6) - 180;
  hour.setRotation(hourAngle);
  minute.setRotation(minuteAngle);
  second.setRotation(secondAngle);
}

void Text::format() {
  float centerX = Circle::getPosition().x + Circle::getRadius();
  float centerY = Circle::getPosition().y + Circle::getRadius();
  float radius = Circle::getRadius() - 20;

  for (int i = 0; i < 12; ++i) {
    float angle = (i * 30 - 90) * (3.14159265f / 180.0f);
    float x = centerX + radius * cos(angle) - 15;
    float y = centerY + radius * sin(angle) - 15;

    text[i].setString(std::to_string(i == 0 ? 12 : i));
    text[i].setCharacterSize(24);
    text[i].setFont(font);
    text[i].setPosition(x, y);
  }
}

void Text::setColor(const sf::Color &color) {
  for (int i = 0; i < 12; ++i) text[i].setFillColor(color);
}

Text::Text() {
  font.loadFromFile("arial.ttf");
}


Hour::Hour(const float &radius, const sf::Vector2f &pos, const sf::Color &color) {
  Circle::setRadius(radius);
  Circle::setPosition(pos);
  Circle::setColor(color);

  Second::setPosition(sf::Vector2f(Circle::getPosition().x + radius, Circle::getPosition().y + radius));
  Second::setSize(sf::Vector2f(4, radius));

  Minute::setPosition(sf::Vector2f(Circle::getPosition().x + radius, Circle::getPosition().y + radius));
  Minute::setSize(sf::Vector2f(4, radius));

  setPosition(sf::Vector2f(Circle::getPosition().x + radius, Circle::getPosition().y + radius));
  setSize(sf::Vector2f(4, radius));

  Text::format();
}

Minute::Minute() {}

void Minute::setColor(const sf::Color &color) {
  minute.setFillColor(color);
}

void Minute::setPosition(const sf::Vector2f &position) {
  minute.setPosition(position);
}

void Minute::setSize(const sf::Vector2f &size) {
  minute.setSize(size);
}

Circle::Circle() {}

void Circle::setColor(const sf::Color &color) {
  circle.setFillColor(color);
}

void Circle::setPosition(const sf::Vector2f &position) {
  circle.setPosition(position);
}

void Circle::setBorder(const sf::Color & color, const float &volume) {
  circle.setOutlineColor(color);
  circle.setOutlineThickness(volume);
}

sf::Vector2f Circle::getPosition() const {
  return circle.getPosition();
}

float Circle::getRadius() const {
  return circle.getRadius();
}

void Circle::setRadius(const float& radius) {
  circle.setRadius(radius);
}

void Hour::draw(sf::RenderWindow &window) {
  window.draw(Circle::circle);
  window.draw(Second::second);
  window.draw(Minute::minute);
  window.draw(hour);
  now();
  for(int i = 0; i < 12; ++i) window.draw(text[i]);
}

void Second::setPosition(const sf::Vector2f & position) {
  second.setPosition(position);
}

Second::Second() {}

void Second::setColor(const sf::Color & color) {
  second.setFillColor(color);
}

void Second::setSize(const sf::Vector2f & size) {
  second.setSize(size);
}