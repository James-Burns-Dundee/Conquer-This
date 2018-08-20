#include <SFML\Graphics.hpp>
#include "Player.h"
#include "Block.h"

int windowWidth = 900;
int windowHeight = 600;

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Platformer");

	bool keyUp, keyDown, keyLeft, keyRight = false;

	sf::Texture platformSpriteSheet;

	platformSpriteSheet.loadFromFile("Assets/Images/PlatformSheet1.png");
	sf::Sprite earthSprite(platformSpriteSheet);
	earthSprite.setTextureRect(sf::IntRect(15, 15, 15, 15));

	sf::Texture playerTexture;
	playerTexture.loadFromFile("Assets/Images/Sprite.png");
	sf::Sprite playerSprite(playerTexture);
	playerSprite.getTextureRect();

	Player playerObj(playerSprite);

	Block level[5] =
	{
		Block(100, 200, earthSprite),
		Block(145, 200, earthSprite),
		Block(190, 200, earthSprite),
		Block(235, 200, earthSprite),
		Block(280, 200, earthSprite)
	};

	sf::Clock gameClock;
	// Start the game loop
	while (window.isOpen())
	{
		// Progress events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window : exit
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		keyRight = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
		keyLeft = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
		keyUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
		keyDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);

		float deltaTime = gameClock.getElapsedTime().asSeconds();

		playerObj.update(keyRight, keyLeft, keyUp, keyDown, level, deltaTime);

		gameClock.restart().asSeconds();

		// Clear screen
		window.clear();

		window.draw(playerObj.image);

		for (int i = 0; i < 5; i++)
		{
			window.draw(level[i].image);
		}

		// Update the window
		window.display();
	}
}
