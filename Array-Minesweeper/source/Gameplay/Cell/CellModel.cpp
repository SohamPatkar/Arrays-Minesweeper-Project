#include "../../header/Gameplay/Cell/CellModel.h"

namespace Gameplay
{
	namespace Cell
	{
		CellModel::CellModel()
		{

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
			return sf::Vector2i(0, 0);
		}

		void CellModel::reset()
		{
			cell_value = CellValue::EMPTY;
			cell_state = CellState::HIDDEN;
		}
	}
}
