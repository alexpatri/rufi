#include <SFML/Graphics.hpp>
#include <map>
#include <string>

#include "../engine/scene.hpp"

class GameScene : public Scene {
public:
  Scene *process(sf::Event *, sf::RenderWindow *) override;
};

Scene *GameScene::process(sf::Event *event, sf::RenderWindow *window) {
  sf::CircleShape circle = sf::CircleShape(100.f);
  circle.setFillColor(sf::Color::Red);
  circle.setPosition(
      sf::Vector2f(window->getSize().x / 2 - circle.getRadius(),
                   window->getSize().y / 2 - circle.getRadius()));

  window->clear();
  window->draw(circle);
  window->display();

  return nullptr;
}

int main() {
  sf::RenderWindow window(sf::VideoMode(1280, 720), "Titulo da Janela");

  Scene *scene = new GameScene();

  while (window.isOpen()) {
    sf::Event event;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    Scene *new_scene = scene->process(&event, &window);
    if (new_scene) {
      scene = new_scene;
    }
  }

  delete scene;

  return EXIT_SUCCESS;
}
