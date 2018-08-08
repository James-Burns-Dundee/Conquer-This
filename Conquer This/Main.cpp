#include <SFML\Graphics.hpp>
#include "Player.h"
#include "Block.h"

int windowWidth = 900;
int windowHeight = 600;

int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Platformer");

	bool playerUp, playerDown, playerLeft, playerRight = false;

	sf::Font consolasFont;
	consolasFont.loadFromFile("Assets/Fonts/consola.ttf");

	sf::Text helloText("Hello sprite", consolasFont, 12);

	sf::Texture platformSpriteSheet;

	platformSpriteSheet.loadFromFile("Assets/Images/PlatformSheet1.png");
	sf::Sprite earthSprite(platformSpriteSheet);
	earthSprite.setTextureRect(sf::IntRect(0, 0, 15, 15));

	sf::Texture playerTexture;
	playerTexture.loadFromFile("Assets/Images/Sprite.png");
	sf::Sprite playerSprite(playerTexture);
	playerSprite.getTextureRect();

	Player playerObj(playerSprite);

	Block platformObj(100, 100, earthSprite);

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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			playerRight = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			playerLeft = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			playerUp = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			playerDown = true;
		}
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			playerRight = false;
		}
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			playerLeft = false;
		}
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			playerUp = false;
		}
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			playerDown = false;
		}

		playerObj.update(playerUp, playerDown, playerLeft, playerRight, platformObj);

		// Clear screen
		window.clear();

		// Draw the sprite
		window.draw(platformObj.image);
		window.draw(playerObj.image);
		window.draw(helloText);

		// Update the window
		window.display();
	}
}
