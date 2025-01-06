#pragma once
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/UI/UIElement/ButtonView.h"

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

			void processCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType button_type);
			void resetBoard();
		};
	}
}