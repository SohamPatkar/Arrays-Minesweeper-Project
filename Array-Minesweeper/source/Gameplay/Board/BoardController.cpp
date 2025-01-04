#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/Gameplay/Board/BoardView.h"
#include "../../header/Gameplay/Cell/CellController.h"

namespace Gameplay
{
	namespace Board
	{
		BoardController::BoardController()
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

		int BoardController::getMineCount()
		{
			return mines_count;
		}

	}
}