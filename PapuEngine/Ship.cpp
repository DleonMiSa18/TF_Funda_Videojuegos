#include "Ship.h"
#include "ResourceManager.h"
#include <SDL\SDL.h>
#include"Enemie.h"
#include"Food.h"
#include<iostream>

using namespace std;

Ship::Ship(float _speed, std::string texture, InputManager* _inputManager)
{
	puntaje = 100;
	speed = _speed;
	position = glm::vec2(350, 50);
	textureID = ResourceManager::getTexture(texture).id;
	inputManager = _inputManager;
}
int Ship::getPuntaje() {
	return puntaje;
}
void Ship::draw(SpriteBacth & spriteBatch)
{
	const glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
	ColorRGBA color;
	color.set(255, 255, 255, 255);
	glm::vec4 desctRect(position.x, position.y, 50, 50);
	spriteBatch.draw(desctRect, uvRect, textureID, 0.0f, color);
}

void Ship::setColor(ColorRGBA color)
{
}

void Ship::update(std::vector<Enemie*>& enemies, std::vector<Food*>& food)
{
	for (size_t i = 0; i < enemies.size();i++) {
		
		if (collideWithEnemie(enemies[i])) {
			cout << "d";
			puntaje -= 1;
		}
	}

	for (size_t i = 0; i < food.size();i++) {

		if (collideWithFood(food[i])) {
			cout << "d";
			puntaje += 1;
		}
	}
	if (inputManager->isKeyPressed(SDLK_w)) {
		position.y += speed;
	}
	if (inputManager->isKeyPressed(SDLK_s)) {
		position.y -= speed;
	}
	if (inputManager->isKeyPressed(SDLK_a)) {
		position.x -= speed;
	}
	if (inputManager->isKeyPressed(SDLK_d)) {
		position.x += speed;
	}

}

bool Ship::collideWithEnemie(Enemie* enemie) {
	int _agent_radius = 25;
	const float MIN_DISTANCE = _agent_radius * 2.0f;

	glm::vec2 centerPosA = position + glm::vec2(_agent_radius);

	glm::vec2 centerPosB =
		enemie->getPosition() + glm::vec2(_agent_radius);

	glm::vec2 distVec = centerPosA - centerPosB;
	float distance = glm::length(distVec);

	float collisionDepth = MIN_DISTANCE - distance;
	if (collisionDepth > 0) {
		return true;
	}

	return false;
}

bool Ship::collideWithFood(Food* enemie) {
	int _agent_radius = 25;
	const float MIN_DISTANCE = _agent_radius * 2.0f;

	glm::vec2 centerPosA = position + glm::vec2(_agent_radius);

	glm::vec2 centerPosB =
		enemie->getPosition() + glm::vec2(_agent_radius);

	glm::vec2 distVec = centerPosA - centerPosB;
	float distance = glm::length(distVec);

	float collisionDepth = MIN_DISTANCE - distance;
	if (collisionDepth > 0) {
		return true;
	}

	return false;
}

Ship::~Ship()
{

}

