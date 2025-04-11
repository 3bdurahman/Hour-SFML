#include <SFML/Graphics.hpp>
#include <ctime>
#include <cmath>

using namespace std;

class Circle {
  protected:
  sf::CircleShape circle;
  public:
  Circle();
  void setRadius(const float &radius);
  virtual void setColor(const sf::Color &color);
  virtual void setPosition(const sf::Vector2f &position);
  void setBorder(const sf::Color& color, const float &volume = 1);
  virtual sf::Vector2f getPosition() const;
  float getRadius() const;
};

class Text : virtual public Circle {
  protected:
  sf::Font font;
  sf::Text text[12];
  void format();
  public:
  Text();
  void setColor(const sf::Color &color) override;
};

class Second : virtual public Circle {
  protected:
  sf::RectangleShape second;
  void setPosition(const sf::Vector2f &position) override;
  public:
  Second();
  void setColor(const sf::Color &color) override;
  virtual void setSize(const sf::Vector2f &size);
};

class Minute : public Second {
  protected:
  sf::RectangleShape minute;
  void setPosition(const sf::Vector2f &position) override;
  public:
  Minute();
  void setColor(const sf::Color &color) override;
  void setSize(const sf::Vector2f &size) override;
  
};


class Hour : public Minute, public Text {
  protected:
  sf::RectangleShape hour;
  void setPosition(const sf::Vector2f &position) override;
  void now();
  public:
  Hour(const float &radius, const sf::Vector2f &pos, const sf::Color &color);
  void setColor(const sf::Color &color) override;
  void setSize(const sf::Vector2f &size) override;
  void draw(sf::RenderWindow &window);
};