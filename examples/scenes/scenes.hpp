#ifndef SCENES
#define SCENES

#include "../../engine/scene.hpp"

class MainScene : public Scene {
public:
  Scene *handle_event(const sf::Event *) override;
  Scene *process(sf::RenderWindow *) override;
};

class PauseScene : public Scene {
public:
  Scene *handle_event(const sf::Event *) override;
  Scene *process(sf::RenderWindow *) override;
};

class GameOverScene : public Scene {
public:
  Scene *handle_event(const sf::Event *) override;
  Scene *process(sf::RenderWindow *) override;
};

#endif // !SCENES
