#pragma once
#include <algorithm>
#include "Game.h"
#include "MenuScreen.h"
#include "PlayScreen.h"
#include "MembersScreen.h"
#include "TurorialScreen.h"
#include "EndScreen.h"
#include "VictoryScreen.h"

class App : public Game
{
public:
	App();
	~App();
	virtual void setScreen(int index) override;
	virtual void onInit() override;
	virtual void addScreens() override;
	virtual void onExit() override;
private:
	std::unique_ptr<MenuScreen> _menuScreen;
	std::unique_ptr<PlayScreen> _playScreen;
	std::unique_ptr<MembersScreen> _membersScreen;
	std::unique_ptr<TurorialScreen> _tutorialScreen;
	std::unique_ptr<EndScreen> _endScreen;
	std::unique_ptr<VictoryScreen> _victoryScreen;
};

