#include "scenes.hpp"

MainScene::MainScene() {
  add_edge("pause", []() { return std::make_unique<PauseScene>(); });
}

void MainScene::handle_event(SceneManager &manager, const sf::Event &event) {
  if (event.type == sf::Event::KeyPressed &&
      event.key.code == sf::Keyboard::Escape) {

    manager.set_scene(navigate("pause"));
  }
}

void MainScene::update(SceneManager &, sf::RenderWindow &window) {
  sf::CircleShape circle(100.f);
  circle.setFillColor(sf::Color::Red);

  circle.setPosition(window.getSize().x / 2 - circle.getRadius(),
                     window.getSize().y / 2 - circle.getRadius());

  window.clear();
  window.draw(circle);
  window.display();
}
