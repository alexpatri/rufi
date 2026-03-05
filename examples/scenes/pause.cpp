#include "scenes.hpp"

Scene *PauseScene::handle_event(const sf::Event *event) {
  if (event->type == sf::Event::KeyPressed &&
      event->key.code == sf::Keyboard::Escape) {
    return this->navigate("main");
  }

  return nullptr;
}

Scene *PauseScene::process(sf::RenderWindow *window) {
  sf::CircleShape circle = sf::CircleShape(100.f);
  circle.setFillColor(sf::Color::Green);
  circle.setPosition(
      sf::Vector2f(window->getSize().x / 2 - circle.getRadius(),
                   window->getSize().y / 2 - circle.getRadius()));

  window->clear();
  window->draw(circle);
  window->display();

  return nullptr;
}
