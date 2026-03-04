#ifndef ENGINE_SCENE
#define ENGINE_SCENE

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Window.hpp>
#include <string>

class Scene {
public:
  void add_edge(std::string, Scene *);
  virtual Scene *handle_event(const sf::Event *) = 0;
  virtual Scene *process(sf::RenderWindow *) = 0;
  virtual ~Scene() = default;

protected:
  std::map<std::string, Scene *> edges;

  Scene *navigate(std::string);
};

#endif // !ENGINE_SCENE
