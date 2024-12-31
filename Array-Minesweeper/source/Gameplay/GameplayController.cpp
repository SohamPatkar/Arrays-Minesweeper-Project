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

	}

	void GameplayController::render()
	{

	}

	void GameplayController::reset()
	{
		Global::ServiceLocator::getInstance()->getBoardService()->resetBoard();
	}

}