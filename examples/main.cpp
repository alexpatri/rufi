#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <map>
#include <string>

#include "scenes/scenes.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(1280, 720), "Titulo da Janela");

  Scene *main_scene = new MainScene();
  Scene *pause_scene = new PauseScene();

  main_scene->add_edge("pause", pause_scene);
  pause_scene->add_edge("main", main_scene);

  Scene *scene = main_scene;

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

  delete main_scene;
  main_scene = nullptr;

  delete pause_scene;
  pause_scene = nullptr;

  return EXIT_SUCCESS;
}
