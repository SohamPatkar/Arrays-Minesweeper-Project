#include "../../header/Gameplay/Board/BoardService.h"
#include "../../header/Gameplay/Board/BoardController.h"

namespace Gameplay
{
	namespace Board
	{
		BoardService::BoardService()
		{
			board_controller = nullptr;
		}

		BoardService::~BoardService()
		{
			
		}

		void BoardService::initialize()
		{
			board_controller = new BoardController();
			board_controller->initialize();
		}

		void BoardService::update()
		{
			board_controller->update();
		}

		void BoardService::render()
		{
			board_controller->render();
		}

		void BoardService::resetBoard()
		{
			board_controller->reset();
		}

		void BoardService::processCellInput(Cell::CellController* cell_controller, UI::UIElement::ButtonType button_type)
		{
			board_controller->processCellInput(cell_controller, button_type);
		}

		int BoardService::getMineCount()
		{
			return board_controller->getMineCount();
		}
	}
}