#pragma once
#include "../../header/Gameplay/Board/BoardService.h"

namespace Gameplay
{
	enum class GameResult
	{
		NONE,
		WON,
		LOST
	};

	class GameplayController
	{
	private:
		Board::BoardService* board_service;
		GameResult game_result = GameResult::NONE;
		
		const float game_over_time = 11.f;

		float Max_Duration = 10.f;
		float remaining_time;

		void updateRemainingTime();
		
	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();

		void showCredits();
		void beginGameOverTime();
		void endGame(GameResult result);
		void gameWon();
		void gameLost();
		int getMineCount();

		float getRemainingTime();
		void restart();
	};
}