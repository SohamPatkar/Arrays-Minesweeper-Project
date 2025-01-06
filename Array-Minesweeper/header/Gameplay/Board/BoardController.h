#pragma once
#include <sfml/Graphics.hpp>
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/UI/UIElement/ButtonView.h"


namespace Gameplay
{
	namespace Board
	{
		class BoardView;

		class BoardController
		{	
		public:
			BoardController();
			~BoardController();

			static const int number_of_rows = 9;
			static const int number_of_colums = 9;
			static const int mines_count = 8;

			void initialize();
			void update();
			void render();
			void openCell(sf::Vector2i cell_position);
			void processCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType button_type);
			void flagCell(sf::Vector2i cell_position);

			void initializeCells();
			int getMineCount();
			void reset();

		private:
			BoardView* board_view;
			Gameplay::Cell::CellController* cell_controller;
			Gameplay::Cell::CellController* cells[number_of_rows][number_of_colums];
			int flagged_cells;
			

			void resetBoard();
			void createBoard();
			void deleteBoard();
			void destroy();
		};
	}
}