#include "Player.h"

Player::Player(sf::Sprite sprite)
{
	xVelocity = 0;
	yVelocity = 0;
	xPos = 0;
	yPos = 0;
	jumpState = 0;
	scale = 1;
	faceRight = true;
	onGround = false;
	isColliding = false;
	image = sprite;
}

Player::~Player()
{
}

void Player::update(bool keyRight, bool keyLeft, bool keyUp, bool keyDown, Block level[5], float dt)
{
	if (keyRight)
	{
		faceRight = true;
		xVelocity = 200;
	}
	if (keyLeft)
	{
		faceRight = false;
		xVelocity = -200;
	}
	if (keyUp)
	{
		yVelocity = -200;
	}
	if (keyDown)
	{
		yVelocity = 200;
	}
	if (!(keyRight || keyLeft))
	{
		xVelocity = 0;
	}
	if (onGround)
	{
		yVelocity = 0;
	}
	image.move(sf::Vector2f(xVelocity * dt, 0));
	collision(xVelocity, 0, level);
	image.move(sf::Vector2f(0, yVelocity * dt));
	collision(0, yVelocity, level);
}

void Player::collision(float dx, float dy, Block level[5])
{
	for (int i = 0; i < 5; i++)
	{
		if (image.getPosition().x + (image.getLocalBounds().width* scale) > level[i].leftSide && image.getPosition().x < level[i].rightSide &&
			image.getPosition().y < level[i].bottomSide && image.getPosition().y + (image.getLocalBounds().height * scale) > level[i].topSide)
		{
			isColliding = true;
		}
		else
		{
			isColliding = false;
		}
		if (isColliding)
		{
			if (dx > 0)
			{
				image.setPosition(sf::Vector2f(level[i].leftSide - image.getLocalBounds().width * scale, image.getPosition().y));
			}
			if (dx < 0)
			{
				image.setPosition(sf::Vector2f(level[i].rightSide, image.getPosition().y));
			}
			if (dy > 0)
			{
				image.setPosition(sf::Vector2f(image.getPosition().x, level[i].topSide - image.getLocalBounds().height * scale));
			}
			if (dy < 0)
			{
				image.setPosition(sf::Vector2f(image.getPosition().x, level[i].bottomSide));
			}
		}
	}
}
