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
			CellController();
			~CellController();

			CellState getCellState();
			CellValue getCellValue();

			void setCellState(CellState state);
			void setCellValue(CellValue value);

			void initialize(float width, float height);
			void update();
			void render();
		};
	}
}