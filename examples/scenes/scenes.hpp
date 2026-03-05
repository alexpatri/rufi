#ifndef SCENES
#define SCENES

#include "../../engine/scene.hpp"

class MainScene : public Scene {
public:
  MainScene();
  void handle_event(SceneManager &, const sf::Event &) override;
  void update(SceneManager &, sf::RenderWindow &) override;
};

class PauseScene : public Scene {
public:
  PauseScene();
  void handle_event(SceneManager &, const sf::Event &) override;
  void update(SceneManager &, sf::RenderWindow &) override;
};

class GameOverScene : public Scene {
public:
  void handle_event(SceneManager &, const sf::Event &) override;
  void update(SceneManager &, sf::RenderWindow &) override;
};

#endif // !SCENES
