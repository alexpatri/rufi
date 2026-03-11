#include <SFML/Graphics.hpp>
#include <memory>

#include "context.hpp"
#include "scenes/scenes.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(1280, 720), "Titulo");
  window.setFramerateLimit(60);

  GameContext ctx;

  sf::Texture object_texture;
  object_texture.loadFromFile("./examples/assets/img/block.png");
  ctx.resources.object.setTexture(object_texture);

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
