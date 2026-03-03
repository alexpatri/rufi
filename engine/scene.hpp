#ifndef ENGINE_SCENE
#define ENGINE_SCENE

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Window.hpp>
#include <string>

class Scene {
public:
  virtual Scene *process(sf::Event *, sf::RenderWindow *) = 0;
  void add_edge(std::string, Scene *);
  virtual ~Scene() = default;

private:
  std::map<std::string, Scene *> edges;

  Scene *navigate(std::string);
};

#endif // !ENGINE_SCENE
