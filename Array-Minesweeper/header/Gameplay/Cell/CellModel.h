#pragma once
#include <sfml/Graphics.hpp>

namespace Gameplay
{
	namespace Cell
	{
		enum class CellValue
		{
			EMPTY,
			ONE,
			TWO,
			THREE,
			FOUR,
			FIVE,
			SIX,
			SEVEN,
			EIGHT,
			MINE,
		};

		enum class CellState
		{
			HIDDEN,
			OPEN,
			FLAGGED
		};

		class CellModel
		{
		private:
			CellValue cell_value;
			CellState cell_state;

			sf::Vector2i position;
			int cell_index;

		public:
			CellModel(int index);
			~CellModel();

			CellValue getCellValue();
			CellState getCellState();

			void setCellValue(CellValue value);
			void setCellState(CellState state);


			int getCellIndex();
			sf::Vector2i getCellPosition();

			void reset();
		};

	}
}