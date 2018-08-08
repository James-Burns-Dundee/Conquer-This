#include <SFML\Graphics.hpp>

#pragma once
class Block
{
public:
	Block(float initXPos, float initYPos, sf::Sprite sprite);
	~Block();

	// Variables
	float xVelocity;
	float yVelocity;
	float xPos;
	float yPos;
	float topSide;
	float bottomSide;
	float leftSide;
	float rightSide;
	int scale;
	sf::Sprite image;
};
