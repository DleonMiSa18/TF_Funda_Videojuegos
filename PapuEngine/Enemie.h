#pragma once
#include "Agent.h"
#include <string>
#include <glm/glm.hpp>
#include "InputManager.h"

class Enemie
{
private:
	int typeEnemie;
	float speed;
	std::string texture;
	int textureID;
	glm::vec2 position;

public:
	Enemie(float _speed, std::string texture, int _type);
	void draw(SpriteBacth& spriteBatch);
	void setColor(ColorRGBA color);
	glm::vec2 getPosition()const {
		return position;
	}
	void update();
	glm::vec2 getPosition();
	~Enemie();

};

