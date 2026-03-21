#include <SFML/Graphics.hpp>
#include <memory>

#include "context.hpp"
#include "scenes/scenes.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(480, 854), "Titulo");
  window.setFramerateLimit(60);

  GameContext ctx;

  sf::Texture object_texture;
  object_texture.loadFromFile("./examples/assets/img/block.png");
  ctx.resources.object.setTexture(object_texture);

  ctx.resources.font.loadFromFile("./examples/assets/fonts/jetbrains.ttf");

  ctx.resources.score_text.setFont(ctx.resources.font);
  ctx.resources.score_text.setFillColor(sf::Color::White);
  ctx.resources.score_text.setPosition(5.f, 5.f);
  ctx.resources.score_text.setCharacterSize(20);

  SceneManager manager(&ctx);
  manager.set_scene(std::make_unique<MainScene>());

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();

      manager.handle_event(event);
    }

    manager.update(window);
  }

  return 0;
}
