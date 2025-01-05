#pragma once

namespace Gameplay
{
	namespace Board
	{
		class BoardController;

		class BoardService 
		{
		private:
				BoardController* board_controller;

		public:
			BoardService();
			~BoardService();

			void initialize();
			void update();
			void render();

			int getMineCount();

			void resetBoard();
		};
	}
}