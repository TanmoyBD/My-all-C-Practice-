#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const int PLAYER_SIZE = 50;
const int PLAYER_SPEED = 10;

const int OBSTACLE_SIZE = 30;
const int OBSTACLE_SPEED = 5;

const int POINT_SIZE = 20;

int main() {
  srand(time(0)); // seed the random number generator with the current time

  sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "2D Game Example");

  // create the player sprite
  sf::RectangleShape player(sf::Vector2f(PLAYER_SIZE, PLAYER_SIZE));
  player.setFillColor(sf::Color::Green);
  player.setPosition(WINDOW_WIDTH / 2 - PLAYER_SIZE / 2, WINDOW_HEIGHT - PLAYER_SIZE);

  // create the obstacle sprites
  std::vector<sf::RectangleShape> obstacles;
  for (int i = 0; i < 10; i++) {
    sf::RectangleShape obstacle(sf::Vector2f(OBSTACLE_SIZE, OBSTACLE_SIZE));
    obstacle.setFillColor(sf::Color::Red);
    obstacle.setPosition(rand() % (WINDOW_WIDTH - OBSTACLE_SIZE), -OBSTACLE_SIZE);
    obstacles.push_back(obstacle);
  }

  // create the point sprite
  sf::CircleShape point(POINT_SIZE);
  point.setFillColor(sf::Color::Yellow);
  point.setPosition(rand() % (WINDOW_WIDTH - POINT_SIZE), -POINT_SIZE);

  // set up the game loop
  sf::Clock clock;
  while (window.isOpen()) {
    sf::Time elapsed = clock.restart();
    float dt = elapsed.asSeconds();

    // handle window events
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    // handle player movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player.getPosition().x > 0) {
      player.move(-PLAYER_SPEED * dt, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player.getPosition().x + PLAYER_SIZE < WINDOW_WIDTH) {
      player.move(PLAYER_SPEED * dt, 0);
    }

    // handle obstacle movement and collision
    for (auto& obstacle : obstacles) {
      obstacle.move(0, OBSTACLE_SPEED * dt);
      if (obstacle.getGlobalBounds().intersects(player.getGlobalBounds())) {
        std::cout << "Game over!" << std::endl;
        return 0;
      }
      if (obstacle.getPosition().y > WINDOW_HEIGHT) {
        obstacle.setPosition(rand() % (WINDOW_WIDTH - OBSTACLE_SIZE), -OBSTACLE_SIZE);
      }
    }

    // handle point movement and collection
    point.move(0, OBSTACLE_SPEED * dt);
    if (point.getGlobalBounds().intersects(player.getGlobalBounds())) {
      std::cout << "Point collected!" << std::endl;
      point.setPosition(rand() % (WINDOW_WIDTH - POINT_SIZE), -POINT_SIZE);
    }
    if (point.getPosition().y > WINDOW_HEIGHT) {
      point.setPosition(rand() % (WINDOW_WIDTH - POINT_SIZE), -POINT_SIZE);
    }

    // draw everything to the window
    window.clear(sf::Color::Black);


