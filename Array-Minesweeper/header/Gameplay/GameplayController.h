#pragma once
#include "../../header/Gameplay/Board/BoardService.h"

namespace Gameplay
{
	class GameplayController
	{
	private:
		Board::BoardService* board_service;

	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();

		void reset();
	};
}