#pragma once
#include "../../header/Gameplay/Cell/CellModel.h"

namespace Gameplay
{
	namespace Cell
	{
		class CellView;
		class CellModel;

		class CellController
		{
		private:
			CellView* cell_view;
			CellModel* cell_model;

			void destroy();

		public:
			CellController(sf::Vector2i position);
			~CellController();

			CellState getCellState();
			CellValue getCellValue();

			void setCellState(CellState state);
			void setCellValue(CellValue value);
			void openCell();
			void flagCell();

			void initialize(float width, float height);
			void update();
			void render();

			void reset();

			sf::Vector2i getCellPosition();
			bool canOpenCell();
		};
	}
}