#include "Enemie.h"
#include "ResourceManager.h"
#include <random>
#include <ctime>
Enemie::Enemie(float _speed, std::string texture, int _type)
{
	typeEnemie = _type;
	speed = _speed;
	std::mt19937 randomEngine(time(nullptr));
	std::uniform_int_distribution<int>randPos(1, 500);
	if(typeEnemie == 0)position = glm::vec2(randPos(randomEngine), 500);
	if (typeEnemie == 1)position = glm::vec2(randPos(randomEngine), -50 );
	if (typeEnemie == 2)position = glm::vec2(600, randPos(randomEngine));
	if (typeEnemie == 3)position = glm::vec2(-50, randPos(randomEngine));
	textureID = ResourceManager::getTexture(texture).id;
}


void Enemie::draw(SpriteBacth& spriteBatch)
{
	const glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
	ColorRGBA color;
	color.set(255, 255, 255, 255);
	glm::vec4 desctRect(position.x, position.y, 50, 50);
	spriteBatch.draw(desctRect, uvRect, textureID, 0.0f, color);
}

void Enemie::setColor(ColorRGBA color)
{
}

void Enemie::update()
{
	if (typeEnemie == 0)position.y -= speed;
	if (typeEnemie == 1)position.y += speed;
	if (typeEnemie == 2)position.x -= speed;
	if (typeEnemie == 3)position.x += speed;
}

glm::vec2 Enemie::getPosition() {
	return position;
}

Enemie::~Enemie()
{
}
