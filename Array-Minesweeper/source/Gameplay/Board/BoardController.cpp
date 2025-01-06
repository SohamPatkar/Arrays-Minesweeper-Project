#include "../../header/Gameplay/Board/BoardController.h"
#include "../../header/Gameplay/Board/BoardView.h"
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/Global/ServiceLocator.h"

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

			flagged_cells = 0;
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
				cells[cell_position.x][cell_position.y]->openCell();
			}
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
	}
}