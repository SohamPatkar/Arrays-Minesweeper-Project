#include "../../header/Gameplay/Cell/CellView.h"
#include "../../header/UI/UIElement/ButtonView.h"
#include "../../header/Global/Config.h"

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
		}

		void CellView::initializeButtonImage(float width, float height)
		{
			cell_button->initialize("Cell",Global::Config::cells_texture_path, width, height,sf::Vector2f(0,0));
		}
	}
}