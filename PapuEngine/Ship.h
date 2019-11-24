#pragma once
#include "Agent.h"
#include <string>
#include <glm/glm.hpp>
#include "InputManager.h"
#include"Enemie.h"
#include"Food.h"

class Ship
{

private:
	float speed;
	int puntaje;
	std::string texture;
	int textureID;
	glm::vec2 position;
	InputManager* inputManager;

public:
	Ship(float _speed,std::string texture, InputManager* _inputManager );
	void draw(SpriteBacth& spriteBatch);
	void setColor(ColorRGBA color);
	glm::vec2 getPosition()const {
		return position;
	}
	int getPuntaje();
	void update(std::vector<Enemie*>& enemies, std::vector<Food*>& food);
	bool collideWithEnemie(Enemie* enemie);
	bool collideWithFood(Food* food);
	~Ship();

};

