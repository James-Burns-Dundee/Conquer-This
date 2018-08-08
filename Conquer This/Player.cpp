#include "Player.h"

Player::Player(sf::Sprite sprite)
{
	xVelocity = 0;
	yVelocity = 0;
	xPos = 0;
	yPos = 0;
	scale = 1;
	leftSide = image.getPosition().x;
	rightSide = image.getPosition().x + (image.getLocalBounds().width* scale);
	topSide = image.getPosition().y;
	bottomSide = image.getPosition().y + (image.getLocalBounds().height * scale);
	faceRight = true;
	onGround = false;
	isColliding = false;
	image = sprite;
}

Player::~Player()
{
}

void Player::update(bool plUp, bool plDwn, bool plLft, bool plRgt, Block platforms)
{
	if (plRgt)
	{
		faceRight = true;
		xVelocity = 1;
	}
	if (plLft)
	{
		faceRight = false;
		xVelocity = -1;
	}
	if (plUp)
	{
		yVelocity = -1;
	}
	if (plDwn)
	{
		yVelocity = 1;
	}
	if (!(plRgt || plLft))
	{
		xVelocity = 0;
	}
	if (onGround)
	{
		yVelocity = 0;
	}
	image.move(sf::Vector2f(xVelocity, 0));
	image.move(sf::Vector2f(0, yVelocity));
	collision(xVelocity, 0, platforms);
	collision(0, yVelocity, platforms);
}

void Player::collision(float dx, float dy, Block platforms)
{
	if (rightSide > platforms.leftSide && leftSide < platforms.rightSide &&
	    topSide < platforms.bottomSide && bottomSide > platforms.topSide)
	{
		isColliding = true;
	}
	else
	{
		isColliding = false;
	}

	if (dx > 0)
	{
		image.setPosition(sf::Vector2f(platforms.leftSide - image.getLocalBounds().width * scale, image.getPosition().y));
	}
	if (dx < 0)
	{
		image.setPosition(sf::Vector2f(platforms.rightSide, image.getPosition().y));
	}
	if (dy > 0)
	{
		image.setPosition(sf::Vector2f(image.getPosition().x, platforms.topSide + image.getLocalBounds().height * scale));
	}
	if (dy < 0)
	{
		image.setPosition(sf::Vector2f(image.getPosition().x, platforms.bottomSide));
	}
}
