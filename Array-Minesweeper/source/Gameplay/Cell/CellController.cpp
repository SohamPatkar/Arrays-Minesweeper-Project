#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/Gameplay/Cell/CellView.h"


namespace Gameplay
{
	namespace Cell
	{
		CellController::CellController(int cell_index)
		{
			cell_view = new CellView(this);
			cell_model = new CellModel(cell_index);
		}

		CellController::~CellController()
		{
			destroy();
		}

		void CellController::initialize(float width, float height)
		{
			cell_view->initialize(width,height);
		}

		void CellController::update()
		{
			cell_view->update();
		}

		void CellController::render()
		{
			cell_view->render();
		}

		void CellController::destroy()
		{
			delete(cell_view);
			delete(cell_model);
		}

		void CellController::setCellState(CellState state)
		{
			cell_model->setCellState(state);
		}

		void CellController::setCellValue(CellValue value)
		{
			cell_model->setCellValue(value);
		}

		CellState CellController::getCellState()
		{
			return cell_model->getCellState();
		}

		int CellController::getCellIndex()
		{
			return cell_model->getCellIndex();
		}

		CellValue CellController::getCellValue()
		{
			return cell_model->getCellValue();
		}
	}
}
