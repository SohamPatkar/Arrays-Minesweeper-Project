#include "../../header/Gameplay/Cell/CellView.h"
#include "../../header/UI/UIElement/ButtonView.h"
#include "../../header/Global/Config.h"
#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/Global/ServiceLocator.h"
#include <iostream>

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

		void CellView::initialize(float cell_width, float cell_height)
		{
			initializeButtonImage(cell_width, cell_height);
		}

		void CellView::update()
		{
			cell_button->update();
		}

		void CellView::render()
		{
			setCellTexture();
			cell_button->render();	
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

		sf::Vector2f CellView::getCellScreenPosition(float width, float height)
		{
			sf::Vector2i cell_index = cell_controller->getCellPosition();

			float x_screen_position = cell_left_offset + cell_index.x * width;
			float y_screen_position = cell_top_offset + cell_index.y * height;

			return sf::Vector2f(x_screen_position, y_screen_position);
		}

		void CellView::registerButtonCallback()
		{
			cell_button->registerCallbackFuntion(std::bind(&CellView::cellButtonCallback, this, std::placeholders::_1));
		}

		void CellView::cellButtonCallback(UI::UIElement::ButtonType button_type)
		{
			Global::ServiceLocator::getInstance()->getBoardService()->processCellInput(cell_controller, button_type);
		}

		void CellView::initializeButtonImage(float width, float height)
		{
			sf::Vector2f cell_screen_position = getCellScreenPosition(width, height);

			cell_button->initialize("Cell",Global::Config::cells_texture_path, width*slice_count, height, cell_screen_position);
			registerButtonCallback();
		}
	}
}