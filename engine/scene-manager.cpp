#include "scene.hpp"

void SceneManager::set_scene(std::unique_ptr<Scene> scene) {
  current_scene = std::move(scene);
}

void SceneManager::handle_event(const sf::Event &event) {
  if (current_scene)
    current_scene->handle_event(*this, event);
}

void SceneManager::update(sf::RenderWindow &window) {
  if (current_scene)
    current_scene->update(*this, window);
}
