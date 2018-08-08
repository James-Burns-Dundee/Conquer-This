#include <iostream>
#include <SFML\Graphics.hpp>
#include "Block.h"

#pragma once
class Player
{
public:
	Player(sf::Sprite sprite);
	~Player();

	// Variables
	float xVelocity;
	float yVelocity;
	float xPos;
	float yPos;
	int scale;
	float topSide;
	float bottomSide;
	float leftSide;
	float rightSide;
	bool faceRight;
	bool onGround;
	bool isColliding;
	sf::Sprite image;

	// Functions
	void update(bool u, bool d, bool l, bool r, Block plat);
	void collision(float dx, float dy, Block platform);
};
