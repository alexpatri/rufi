#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <map>
#include <string>

#include "scenes/scenes.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(1280, 720), "Titulo da Janela");

  Scene1 *scene1 = new Scene1();
  Scene2 *scene2 = new Scene2();

  scene1->add_edge("2", scene2);
  scene2->add_edge("1", scene1);

  Scene *scene = scene1;

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      Scene *next_scene = scene->handle_event(&event);
      if (next_scene) {
        scene = next_scene;
      }
    }

    Scene *next_scene = scene->process(&window);
    if (next_scene) {
      scene = next_scene;
    }
  }

  delete scene1;
  scene1 = nullptr;

  delete scene2;
  scene2 = nullptr;

  return EXIT_SUCCESS;
}
