#pragma once
#include <sfml/Graphics.hpp>
#include "../../header/Gameplay/Cell/CellController.h"


namespace Gameplay
{
	namespace Board
	{
		class BoardController
		{
		private:
			static const int number_of_rows = 9;
			static const int number_of_colums = 9;
			static const int mines_count = 8;

			void createBoard();
			void deleteBoard();
			void destroy();
			

		public:
			BoardController();
			~BoardController();


			void initialize();
			void update();
			void render();

			void reset();
		};
	}
}