#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"

namespace Gameplay
{
	GameplayController::GameplayController()
	{
		board_service = nullptr;
	}

	GameplayController::~GameplayController()
	{

	}

	void GameplayController::initialize()
	{
		board_service = Global::ServiceLocator::getInstance()->getBoardService();
	}

	void GameplayController::update()
	{
		updateRemainingTime();
	}

	void GameplayController::render()
	{

	}

	void GameplayController::restart()
	{
		remaining_time = Max_Duration;
		Global::ServiceLocator::getInstance()->getBoardService()->resetBoard();
	}

	void GameplayController::updateRemainingTime()
	{
		remaining_time -= Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}

	float GameplayController::getRemainingTime()
	{
		return remaining_time;
	}
}