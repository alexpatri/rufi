#include "scene.hpp"

void Scene::add_edge(std::string key, Scene *scene) {
  this->edges[key] = scene;
}

Scene *Scene::navigate(std::string key) { return this->edges[key]; }

Scene *GameScene::process(sf::Event *event, sf::RenderWindow *window) {
  window->clear();
  // window->draw();
  window->display();

  return nullptr;
}
