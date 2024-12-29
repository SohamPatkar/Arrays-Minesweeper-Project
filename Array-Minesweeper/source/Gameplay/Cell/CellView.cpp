#include "../../header/Gameplay/Cell/CellView.h"
#include "../../header/UI/UIElement/ButtonView.h"
#include "../../header/Global/Config.h"
#include "../../header/Gameplay/Cell/CellController.h"

namespace Gameplay
{
	namespace Cell
	{
		CellView::CellView(CellController* controller)
		{
			cell_controller = controller;
			cell_button = new UI::UIElement::ButtonView();
		}

		CellView::~CellView()
		{
			delete(cell_button);
		}

		void CellView::initialize()
		{
			initializeButtonImage(tile_size*3, tile_size*3);
		}

		void CellView::update()
		{
			cell_button->update();
		}

		void CellView::render()
		{
			cell_button->render();
			setCellTexture();
		}

		void CellView::setCellTexture()
		{
			int index = static_cast<int>(cell_controller->getCellValue());

			switch (cell_controller->getCellState())
			{
			case::Gameplay::Cell::CellState::HIDDEN:
				cell_button->setTextureRect(sf::IntRect(10 * tile_size, 0, tile_size, tile_size));
				break;

			case::Gameplay::Cell::CellState::OPEN:
				cell_button->setTextureRect(sf::IntRect(index * tile_size, 0, tile_size, tile_size));
				break;

			case::Gameplay::Cell::CellState::FLAGGED:
				cell_button->setTextureRect(sf::IntRect(11 * tile_size, 0, tile_size, tile_size));
				break;
			}
		}

		void CellView::initializeButtonImage(float width, float height)
		{
			cell_button->initialize("Cell",Global::Config::cells_texture_path, width*slice_count, height,sf::Vector2f(0,0));
		}
	}
}