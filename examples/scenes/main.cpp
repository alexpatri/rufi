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
  GameContext &ctx = manager.context();

  if (ctx.resources.objects.size() < ctx.states.max_objects) {
    if (ctx.states.object.timer >= ctx.states.object.max_timer) {
      float x = static_cast<float>(
          std::rand() %
          static_cast<int>(window.getSize().x -
                           ctx.resources.object.getTexture()->getSize().x));
      ctx.resources.object.setPosition(x, 0.f);
      ctx.resources.objects.push_back(ctx.resources.object);
      ctx.states.object.timer = 0.f;
    } else {
      ctx.states.object.timer += 1.f;
    }
  }

  for (size_t i = 0; i < ctx.resources.objects.size(); ++i) {
    ctx.resources.objects[i].move(0.f, ctx.states.object.velocity);

    if (ctx.resources.objects[i].getPosition().y > window.getSize().y) {
      ctx.resources.objects.erase(ctx.resources.objects.begin() + i);
      --i;
    }
  }

  window.clear();
  for (const auto &obj : ctx.resources.objects) {
    window.draw(obj);
  }
  window.display();
}
