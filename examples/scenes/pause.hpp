#ifndef PAUSE_SCENE
#define PAUSE_SCENE

class Scene2 : public Scene {
public:
  Scene *handle_event(const sf::Event *) override;
  Scene *process(sf::RenderWindow *) override;
};

#endif // !PAUSE_SCENE

