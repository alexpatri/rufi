#include "scene.hpp"

void Scene::add_edge(const std::string &key, SceneFactory factory) {
  edges[key] = std::move(factory);
}

std::unique_ptr<Scene> Scene::navigate(const std::string &key) {
  auto it = edges.find(key);

  if (it == edges.end())
    return nullptr;

  return it->second();
}
