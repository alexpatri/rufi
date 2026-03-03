#include "scene.hpp"
#include <SFML/Graphics/CircleShape.hpp>

void Scene::add_edge(std::string key, Scene *scene) {
  this->edges[key] = scene;
}

Scene *Scene::navigate(std::string key) { return this->edges[key]; }
