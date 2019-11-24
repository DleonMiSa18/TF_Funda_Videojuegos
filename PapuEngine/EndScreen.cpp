#include "EndScreen.h"



#include "PlayScreen.h"
#include "Game.h"
#include "MyScreens.h"
#include <iostream>


EndScreen::EndScreen(Window* window) :_window(window)
{
}


EndScreen::~EndScreen()
{
}

void EndScreen::initGUI() {

}

void EndScreen::initSystem() {
	_program.compileShaders("Shaders/colorShaderVert.txt",
		"Shaders/colorShaderFrag.txt");
	_program.addAtribute("vertexPosition");
	_program.addAtribute("vertexColor");
	_program.addAtribute("vertexUV");
	_program.linkShader();
}

void EndScreen::destroy() {

}

void EndScreen::onExit() {}

void EndScreen::onEntry() {
	_camera2D.init(_window->getScreenWidth(), _window->getScreenHeight());
	_camera2D.setPosition(
		glm::vec2(
			_window->getScreenWidth() / 2.0f,
			_window->getScreenHeight() / 2.0f)
	);
	initSystem();
	initGUI();
	backGround = new Background("Textures/parque1.png");
	spriteFont = new SpriteFont("Fonts/ShakaPowHollow.ttf", 64);
	_spriteBatch.init();

}



void EndScreen::update() {

	_camera2D.update();


}

void EndScreen::checkInput() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		_game->onSDLEvent(event);
		switch (event.type)
		{
		case SDL_MOUSEMOTION:
			_inputManager.setMouseCoords(event.motion.x, event.motion.y);
			break;
		case  SDL_KEYUP:
			_inputManager.releaseKey(event.key.keysym.sym);
			break;
		case  SDL_KEYDOWN:
			_inputManager.pressKey(event.key.keysym.sym);
			break;
		case SDL_MOUSEBUTTONDOWN:
			_inputManager.pressKey(event.button.button);
			break;
		case SDL_MOUSEBUTTONUP:
			_inputManager.releaseKey(event.button.button);
			break;
		}
	}
}

void EndScreen::draw() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_program.use();
	glBindTexture(GL_TEXTURE_2D, 0);

	GLuint pLocation = _program.getUniformLocation("P");
	glm::mat4 cameraMatrix = _camera2D.getCameraMatrix();
	glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));

	GLuint imageLocation = _program.getUniformLocation("myImage");
	glUniform1i(imageLocation, 0);
	_spriteBatch.begin();


	backGround->draw(_spriteBatch);



	_spriteBatch.end();
	_spriteBatch.renderBatch();
	//
	char buffer[256];
	_spriteBatch.begin();
	sprintf(
		buffer, "Game Over"
	);


	spriteFont->draw(_spriteBatch, buffer,
		glm::vec2(300, 260), glm::vec2(0.5), 0.0f,
		ColorRGBA(255, 0, 0, 255)
	);



	_spriteBatch.end();
	_spriteBatch.renderBatch();

	glBindTexture(GL_TEXTURE_2D, 0);
	_program.unuse();

}

void EndScreen::drawHUD() {

}

void EndScreen::build() {}

int EndScreen::getPreviousScreen() const {
	return SCREEN_INDEX_MENU;
}

int EndScreen::getNextScreen() const {
	return SCREEN_INDEX_OVER;
}