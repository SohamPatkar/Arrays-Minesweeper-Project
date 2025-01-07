#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GameService.h"
#include "../../header/Gameplay/Board/BoardController.h"

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
		if (isTimeOver())
		{
			endGame(GameResult::LOST);
		}
	}

	void GameplayController::render()
	{

	}

	void GameplayController::beginGameOverTime()
	{
		remaining_time = game_over_time;
	}

	void GameplayController::endGame(GameResult result)
	{
		switch (result)
		{
			
		case GameResult::WON:
			gameWon();
			break;
		
		case GameResult::LOST:
			gameLost();
			break;
			
		default:
			
			break;
		}
	}

	void GameplayController::gameWon()
	{

	}

	void GameplayController::gameLost()
	{
		if (game_result == GameResult::NONE)
		{
			game_result = GameResult::LOST;
			beginGameOverTime();
			board_service->showBoard();
			board_service->setBoardState(Board::BoardState::COMPLETED);
		}
		else
		{
			showCredits();
		}
	}

	bool GameplayController::isTimeOver()
	{
		return remaining_time <= 1;
	}

	void GameplayController::restart()
	{
		remaining_time = Max_Duration;
		Global::ServiceLocator::getInstance()->getBoardService()->resetBoard();
	}

	int GameplayController::getMineCount()
	{
		return board_service->getMineCount();
	}

	void GameplayController::updateRemainingTime()
	{
		remaining_time -= Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
	}

	float GameplayController::getRemainingTime()
	{
		return remaining_time;
	}

	void GameplayController::showCredits()
	{
		Main::GameService::setGameState(Main::GameState::CREDITS);
	}
}