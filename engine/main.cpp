#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class Scene {
public:
  Scene *process(sf::Event);
  void add_edge(std::string, Scene *);

private:
  std::map<std::string, Scene *> edges;

  // void init();
  Scene *navigate(std::string);
};

int main() {
  sf::RenderWindow window(sf::VideoMode(1280, 720), "Titulo da Janela");

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    window.clear();
    // window.draw();
    window.display();
  }

  return EXIT_SUCCESS;
}
