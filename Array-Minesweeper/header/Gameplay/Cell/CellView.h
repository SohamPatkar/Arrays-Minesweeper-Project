#pragma once
#include "../../header/UI/UIElement/ButtonView.h"
#include <sfml/Graphics.hpp>


namespace Gameplay
{
	namespace Cell
	{
		class CellController;

		class CellView
		{
		private:
			UI::UIElement::ButtonView* cell_button;
			CellController* cell_controller;

			const int tile_size = 32;
			int slice_count = 12;

			void initializeButtonImage(float width, float height);

		public:
			CellView(CellController* controller);
			~CellView();

			void setCellTexture();

			void initialize();
			void update();
			void render();
		};
	}
}