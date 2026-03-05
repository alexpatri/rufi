#include "scenes.hpp"

Scene *MainScene::handle_event(const sf::Event *event) {
  if (event->type == sf::Event::KeyPressed &&
      event->key.code == sf::Keyboard::Escape) {
    return this->navigate("pause");
  }

  return nullptr;
}

Scene *MainScene::process(sf::RenderWindow *window) {
  sf::CircleShape circle = sf::CircleShape(100.f);
  circle.setFillColor(sf::Color::Red);
  circle.setPosition(
      sf::Vector2f(window->getSize().x / 2 - circle.getRadius(),
                   window->getSize().y / 2 - circle.getRadius()));

  window->clear();
  window->draw(circle);
  window->display();

  return nullptr;
}
