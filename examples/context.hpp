#ifndef GAME_CONTEXT_HPP
#define GAME_CONTEXT_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>

struct Object {
  sf::Sprite sprite;

  float velocity{5.f};
  float max_velocity{10.f};
  bool remove{false};
};

struct States {
  int score{};
  int lives{10};

  float timer{};
  float max_timer{30.f};

  size_t max_objects{8};
  std::vector<Object> objects;
};

struct Resources {
  sf::Sprite object, background;
  sf::Font font;

  sf::Text score_text;
};

struct GameContext {
  States states;
  Resources resources;
};

#endif // GAME_CONTEXT_HPP
