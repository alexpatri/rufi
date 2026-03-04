#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <map>
#include <string>

#include "../engine/scene.hpp"

class Scene1 : public Scene {
public:
  Scene *handle_event(const sf::Event *) override;
  Scene *process(sf::RenderWindow *) override;
};

Scene *Scene1::handle_event(const sf::Event *event) {
  if (event->type == sf::Event::KeyPressed &&
      event->key.code == sf::Keyboard::Space) {
    return this->navigate("2");
  }

  return nullptr;
}

Scene *Scene1::process(sf::RenderWindow *window) {
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

class Scene2 : public Scene {
public:
  Scene *handle_event(const sf::Event *) override;
  Scene *process(sf::RenderWindow *) override;
};

Scene *Scene2::handle_event(const sf::Event *event) {
  if (event->type == sf::Event::KeyPressed &&
      event->key.code == sf::Keyboard::Space) {
    return this->navigate("1");
  }

  return nullptr;
}

Scene *Scene2::process(sf::RenderWindow *window) {
  sf::CircleShape circle = sf::CircleShape(100.f);
  circle.setFillColor(sf::Color::Green);
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
