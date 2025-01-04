#pragma once
#include "../../header/Gameplay/Board/BoardService.h"

namespace Gameplay
{
	class GameplayController
	{
	private:
		Board::BoardService* board_service;

		float Max_Duration = 10.f;
		float remaining_time;

		void updateRemainingTime();
		
	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();

		float getRemainingTime();
		void restart();
	};
}