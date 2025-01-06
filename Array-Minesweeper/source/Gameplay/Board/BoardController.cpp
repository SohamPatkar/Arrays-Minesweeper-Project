#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/Gameplay/Board/BoardView.h"
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/Global/ServiceLocator.h"

namespace Gameplay
{
	namespace Board
	{
		BoardController::BoardController():random_engine(random_device())
		{
			board_view = new BoardView(this);
			createBoard();
		}

		BoardController::~BoardController(){}


		void BoardController::createBoard()
		{
			for (int a = 0; a < number_of_rows; a++)
			{
				for (int i = 0; i < number_of_colums; i++)
				{
					cells[a][i] = new Cell::CellController(sf::Vector2i(a,i)); //Passing Cell Index in Cell Controller's constructor
				}
			}
		}

		void BoardController::deleteBoard()
		{
			delete(cell_controller);
		}

		void BoardController::destroy()
		{
			deleteBoard();
			delete(board_view);
		}

		void BoardController::reset()
		{
			resetBoard();

			flagged_cells = 0;
			board_state = BoardState::FIRST_CELL;
		}

		void BoardController::resetBoard()
		{
			for (int a = 0; a < number_of_rows; a++)
			{
				for (int i = 0; i < number_of_colums; i++)
				{
					cells[a][i]->reset();
				}
			}
		}

		void BoardController::initialize()
		{
			board_view->initialize();
			initializeCells();
			reset();
		}

		void BoardController::update()
		{
			board_view->update();

			for (int a = 0; a < number_of_rows; a++)
			{
				for (int i = 0; i < number_of_colums; i++)
				{
					cells[a][i]->update();
				}
			}
		}

		void BoardController::render()
		{
			board_view->render();

			for (int a = 0; a < number_of_rows; a++)
			{
				for (int i = 0; i < number_of_colums; i++)
				{
					cells[a][i]->render();
				}
			}
		}

		void BoardController::initializeCells()
		{
			float cell_width = board_view->getCellWidth();
			float cell_height = board_view->getCellHeight();

			for (int a = 0; a < number_of_rows; a++)
			{
				for (int i = 0; i < number_of_colums; i++)
				{
					cells[a][i]->initialize(cell_width, cell_height);
				}
			}
		}

		void BoardController::openCell(sf::Vector2i cell_position)
		{
			if (cells[cell_position.x][cell_position.y]->canOpenCell())
			{
				if (board_state == BoardState::FIRST_CELL)
				{
					populateBoard(cell_position);
					board_state = BoardState::PLAYING;
				}

				cells[cell_position.x][cell_position.y]->openCell();
			}
		}

		void BoardController::populateBoard(sf::Vector2i cell_position)
		{
			std::uniform_int_distribution<int> x_distribution(0, number_of_colums - 1);
			std::uniform_int_distribution<int> y_distribution(0, number_of_rows - 1);

			for (int a = 0; a < mines_count; a++)
			{
				int i = static_cast<int>(x_distribution(random_engine));
				int j = static_cast<int>(y_distribution(random_engine));

				
				if (cells[i][j]->getCellValue() == Cell::CellValue::MINE || (cell_position.x == i && cell_position.y == j)) a--; 
				else cells[i][j]->setCellValue(Cell::CellValue::MINE);
			}

			populateCells();
		}

		int BoardController::countMinesAround(sf::Vector2i cell_position)
		{
			int mines_around = 0;

			for (int a = -1; a < 2; a++)
			{
				for (int b = -1; b < 2; b++)
				{
					//If its the current cell, or cell position is not valid, then the loop will skip once
					if ((a == 0 && b == 0) || !isValidCellPosition(sf::Vector2i(cell_position.x + a, cell_position.y + b))) continue;

					if (cells[a + cell_position.x][b + cell_position.y]->getCellValue() == Cell::CellValue::MINE) mines_around++;
				}
			}

			return mines_around;
		}

		void BoardController::populateCells()
		{
			for (int a = 0; a < number_of_rows; a++)
			{
				for (int b = 0; b < number_of_colums; b++)
				{
					if (cells[a][b]->getCellValue() != Cell::CellValue::MINE)
					{
						Cell::CellValue value = static_cast<Cell::CellValue>(countMinesAround(sf::Vector2i(a, b)));
						cells[a][b]->setCellValue(value);
					}
				}
			}
		}

		bool BoardController::isValidCellPosition(sf::Vector2i cell_position)
		{
			return (cell_position.x >= 0 && cell_position.y >= 0 && cell_position.x < number_of_colums && cell_position.y < number_of_rows);
		}

		int BoardController::getMineCount()
		{
			return mines_count - flagged_cells;
		}

		void BoardController::processCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType button_type)
		{
			switch (button_type)
			{
			case UI::UIElement::ButtonType::LEFT_MOUSE_BUTTON:
				openCell(cell_controller->getCellPosition());
				break;
			case UI::UIElement::ButtonType::RIGHT_MOUSE_BUTTON:
				flagCell(cell_controller->getCellPosition());
				break;
			}
		}

		void BoardController::flagCell(sf::Vector2i cell_position)
		{
			switch (cells[cell_position.x][cell_position.y]->getCellState())
			{
			case::Gameplay::Cell::CellState::FLAGGED:
				Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::FLAG);
				flagged_cells--; //Used to update Gameplay UI
				break;
			case::Gameplay::Cell::CellState::HIDDEN:
				Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::FLAG);
				flagged_cells++; //Used to update Gameplay UI
				break;
			}

			cells[cell_position.x][cell_position.y]->flagCell();
		}

		BoardState BoardController::getBoardState()
		{
			return board_state;
		}

		void BoardController::setBoardState(BoardState state)
		{
			board_state = state;
		}
	}
}