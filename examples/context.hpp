#ifndef GAME_CONTEXT_HPP
#define GAME_CONTEXT_HPP

#include <SFML/Graphics.hpp>

struct Object {
  float velocity{5.f};
  sf::Vector2f position{sf::Vector2f(0.f, 10.f)};
  const float max_velocity{10.f};
};

struct States {
  int score{};
  int lives{10};
  Object object;

  std::vector<sf::Sprite> objects;
  size_t max_objects{5};
};

struct Resources {
  sf::Texture object_texture, background_texture;
  sf::Sprite object, background;
};

struct GameContext {
  States states;
  Resources resources;
};

#endif // GAME_CONTEXT_HPP
