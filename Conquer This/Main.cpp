#include <SFML\Graphics.hpp>
#include "Player.h"
#include "Block.h"
#include "Entity.h"
#include "PlayerVertex.h"

int windowWidth = 1260;
int windowHeight = 720;

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Platformer");

	bool keyUp, keyDown, keyLeft, keyRight = false;

	sf::Texture platformSpriteSheet;
	platformSpriteSheet.loadFromFile("Assets/Images/PlatformSheet1.png");
	sf::Sprite earthSprite(platformSpriteSheet);
	earthSprite.setTextureRect(sf::IntRect(0, 0, 60, 60));

	sf::Texture playerTexture;
	playerTexture.loadFromFile("Assets/Images/Sprite.png");
	sf::Sprite playerSprite(playerTexture);
	//playerSprite.getTextureRect();

	Player playerObj(playerSprite);

	Block level[15] =
	{
		Block(100, 220, earthSprite),
		Block(160, 220, earthSprite),
		Block(220, 220, earthSprite),
		Block(280, 220, earthSprite),
		Block(340, 220, earthSprite),
		Block(400, 220, earthSprite),
		Block(400, 160, earthSprite),
		Block(400, 100, earthSprite),
		Block(460, 100, earthSprite),
		Block(520, 100, earthSprite),
		Block(520, 160, earthSprite),
		Block(520, 220, earthSprite),
		Block(580, 220, earthSprite),
		Block(640, 220, earthSprite),
		Block(700, 220, earthSprite)
	};

	PlayerVertex playerVertex("Assets/Images/Sprite.png", 200, 100, 42, 50);

	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(windowWidth, windowHeight));

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
		view.setCenter(sf::Vector2f(playerObj.image.getPosition().x + playerObj.image.getLocalBounds().width * playerObj.scale / 2.0f, playerObj.image.getPosition().y + playerObj.image.getLocalBounds().height * playerObj.scale / 2.0f));
		gameClock.restart().asSeconds();

		window.setView(view);

		// Clear screen
		window.clear(sf::Color(37, 155, 180));

		// Draw player, blocks, enemies etc to the screen
		window.draw(playerObj.image);
//		window.draw(playerVertex);     Unused part of tutorial video

		for (int i = 0; i < 15; i++)
		{
			window.draw(level[i].image);
		}

		// Update the window
		window.display();
	}
}
