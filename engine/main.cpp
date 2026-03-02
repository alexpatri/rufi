#include <SFML/Graphics.hpp>
#include <map>
#include <string>

#include "scene.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(1280, 720), "Titulo da Janela");

  Scene *game = new GameScene();

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    game->process(&event, &window);
  }

  delete game;

  return EXIT_SUCCESS;
}
