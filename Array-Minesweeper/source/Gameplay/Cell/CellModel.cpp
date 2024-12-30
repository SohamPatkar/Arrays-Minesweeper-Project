#include "../../header/Gameplay/Cell/CellModel.h"
#include <sfml/Graphics.hpp>

namespace Gameplay
{
	namespace Cell
	{
		CellModel::CellModel()
		{
			reset();
		}

		CellModel::~CellModel()
		{

		}

		CellValue CellModel::getCellValue()
		{
			return cell_value;
		}

		CellState CellModel::getCellState()
		{
			return cell_state;
		}

		void CellModel::setCellValue(CellValue value)
		{
			cell_value = value;
		}

		void CellModel::setCellState(CellState state)
		{
			cell_state = state;
		}

		sf::Vector2i CellModel::getCellPosition()
		{
			return position;
		}

		void CellModel::reset()
		{
			cell_value = CellValue::EMPTY;
			cell_state = CellState::HIDDEN;
		}
	}
}
