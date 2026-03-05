#include "scenes.hpp"

PauseScene::PauseScene() {
  add_edge("main", []() { return std::make_unique<MainScene>(); });
}

void PauseScene::handle_event(SceneManager &manager, const sf::Event &event) {
  if (event.type == sf::Event::KeyPressed &&
      event.key.code == sf::Keyboard::Escape) {

    manager.set_scene(navigate("main"));
  }
}

void PauseScene::update(SceneManager &, sf::RenderWindow &window) {
  sf::CircleShape circle(100.f);
  circle.setFillColor(sf::Color::Green);

  circle.setPosition(window.getSize().x / 2 - circle.getRadius(),
                     window.getSize().y / 2 - circle.getRadius());

  window.clear();
  window.draw(circle);
  window.display();
}
