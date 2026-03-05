#include "scenes.hpp"

Scene *GameOverScene::handle_event(const sf::Event *event) { return nullptr; }

Scene *GameOverScene::process(sf::RenderWindow *window) {
  window->clear();
  window->display();

  return nullptr;
}
