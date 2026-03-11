#include "../context.hpp"
#include "scenes.hpp"

MainScene::MainScene() {
  add_edge("pause", []() { return std::make_unique<PauseScene>(); });
  add_edge("game_over", []() { return std::make_unique<GameOverScene>(); });
}

void MainScene::handle_event(SceneManager &manager, const sf::Event &event) {
  if (event.type == sf::Event::KeyPressed &&
      event.key.code == sf::Keyboard::Escape) {

    manager.set_scene(navigate("pause"));
  }
}

void MainScene::update(SceneManager &manager, sf::RenderWindow &window) {
  GameContext ctx = manager.context();

  if (ctx.states.lives <= 0) {
    manager.set_scene(navigate("game_over"));
  }

  sf::Sprite *object = &ctx.resources.object;
  object->setPosition(
      (window.getSize().x - object->getTexture()->getSize().x) / 2,
      (window.getSize().y - object->getTexture()->getSize().y) / 2);

  window.clear();
  window.draw(*object);
  window.display();
}
