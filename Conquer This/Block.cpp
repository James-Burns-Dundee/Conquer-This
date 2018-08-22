#include "Block.h"

Block::Block(float initXPos, float initYPos, sf::Sprite sprite)
{
	scale = 1;
	image = sprite;
	image.setPosition(initXPos, initYPos);
	image.setScale(scale, scale);
	leftSide = image.getPosition().x;
	rightSide = image.getPosition().x + (image.getLocalBounds().width * scale);
	topSide = image.getPosition().y;
	bottomSide = image.getPosition().y + (image.getLocalBounds().height * scale);
}

Block::~Block()
{
}
