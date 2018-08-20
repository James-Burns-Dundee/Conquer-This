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
	int jumpState;
	int scale;
	bool faceRight;
	bool onGround;
	bool isColliding;
	sf::Sprite image;

	// Functions
	void update(bool r, bool l, bool u, bool d, Block level[5], float dt);
	void collision(float dx, float dy, Block level[5]);
};
