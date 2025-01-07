#pragma once
#include <sfml/Graphics.hpp>
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/UI/UIElement/ButtonView.h"
#include <random>

namespace Gameplay
{
	namespace Board
	{
		enum class BoardState
		{
			FIRST_CELL,
			PLAYING,
			COMPLETED
		};

		class BoardView;

		class BoardController
		{	
		public:
			BoardController();
			~BoardController();

			static const int number_of_rows = 9;
			static const int number_of_colums = 9;
			static const int mines_count = 8;

			std::default_random_engine random_engine;
			std::random_device random_device;

			void initialize();
			void update();
			void render();
			void openCell(sf::Vector2i cell_position);
			void processCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType button_type);
			void flagCell(sf::Vector2i cell_position);
			void populateBoard(sf::Vector2i cell_position);
			void processValue(sf::Vector2i cell_position);
			int countMinesAround(sf::Vector2i cell_position);
			bool isValidCellPosition(sf::Vector2i cell_position);

			void openAllCells();
			void initializeCells();
			void populateCells();
			int getMineCount();
			BoardState getBoardState();
			void setBoardState(BoardState state);
			void reset();
			
		private:
			BoardState board_state;
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