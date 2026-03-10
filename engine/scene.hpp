#ifndef ENGINE_SCENE
#define ENGINE_SCENE

#include <SFML/Graphics.hpp>
#include <functional>
#include <map>
#include <memory>
#include <string>

struct GameContext;

class Scene;

class SceneManager {
private:
  std::unique_ptr<Scene> current_scene;
  GameContext *ctx;

public:
  SceneManager(GameContext *ctx) : ctx(ctx) {}

  GameContext &context() { return *ctx; }
  const GameContext &context() const { return *ctx; }

  void set_scene(std::unique_ptr<Scene> scene);
  void handle_event(const sf::Event &event);
  void update(sf::RenderWindow &window);
};

class Scene {
public:
  using SceneFactory = std::function<std::unique_ptr<Scene>()>;

  void add_edge(const std::string &key, SceneFactory factory);

  virtual void handle_event(SceneManager &, const sf::Event &) = 0;
  virtual void update(SceneManager &, sf::RenderWindow &) = 0;

  virtual ~Scene() = default;

protected:
  std::unique_ptr<Scene> navigate(const std::string &key);

private:
  std::map<std::string, SceneFactory> edges;
};

#endif // !ENGINE_SCENE
