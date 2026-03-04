#ifndef MAIN_SCENE
#define MAIN_SCENE

class Scene1 : public Scene {
public:
  Scene *handle_event(const sf::Event *) override;
  Scene *process(sf::RenderWindow *) override;
};

#endif // !MAIN_SCENE
