#include <SFML/Graphics.hpp>
#include <memory>

#include "scenes/scenes.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(1280, 720), "Titulo da Janela");

  SceneManager manager;
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
