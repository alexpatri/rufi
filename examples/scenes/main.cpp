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

  if (event.type == sf::Event::MouseButtonPressed &&
      event.mouseButton.button == sf::Mouse::Left) {

    auto &ctx = manager.context();

    sf::Vector2f mouse_pos(event.mouseButton.x, event.mouseButton.y);

    for (size_t i = 0; i < ctx.states.objects.size(); ++i) {
      if (ctx.states.objects[i].sprite.getGlobalBounds().contains(mouse_pos)) {
        ctx.states.score += 1;

        // marcar para remoção
        ctx.states.objects[i].remove = true;
      }
    }
  }
}

void MainScene::update(SceneManager &manager, sf::RenderWindow &window) {
  GameContext &ctx = manager.context();

  auto &objs = ctx.states.objects;

  // Spawn de novos objetos
  if (objs.size() < ctx.states.max_objects) {
    ctx.states.timer += 1.f;

    if (ctx.states.timer >= ctx.states.max_timer) {
      Object obj;
      obj.sprite = ctx.resources.object;

      float x = static_cast<float>(
          std::rand() % static_cast<int>(window.getSize().x -
                                         obj.sprite.getTexture()->getSize().x));

      obj.sprite.setPosition(x, 0.f);

      objs.push_back(obj);

      ctx.states.timer = 0.f;
    }
  }

  // Update dos objetos
  for (auto &obj : objs) {
    obj.sprite.move(0.f, obj.velocity);

    // saiu da tela
    if (obj.sprite.getPosition().y > window.getSize().y) {
      obj.remove = true;
    }
  }

  objs.erase(std::remove_if(objs.begin(), objs.end(),
                            [](const Object &o) { return o.remove; }),
             objs.end());

  // Render
  window.clear();

  for (const auto &obj : objs) {
    window.draw(obj.sprite);
  }

  window.display();
}
