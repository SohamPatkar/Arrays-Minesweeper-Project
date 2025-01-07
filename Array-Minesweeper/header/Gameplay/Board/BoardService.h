#pragma once
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/UI/UIElement/ButtonView.h"
#include "../../header/Gameplay/Board/BoardController.h"

namespace Gameplay
{
	namespace Board
	{
		

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

			void showBoard();
			int getMineCount();
			void setBoardState(BoardState state);
			BoardState getBoardState();

			void processCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType button_type);
			void resetBoard();
		};
	}
}