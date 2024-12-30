#include "../../header/Gameplay/Cell/CellModel.h"
#include <sfml/Graphics.hpp>

namespace Gameplay
{
	namespace Cell
	{
		CellModel::CellModel(int index)
		{
			cell_index = index;
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

		int CellModel::getCellIndex()
		{
			return cell_index;
		}

		void CellModel::reset()
		{
			cell_value = CellValue::EMPTY;
			cell_state = CellState::HIDDEN;
		}
	}
}
