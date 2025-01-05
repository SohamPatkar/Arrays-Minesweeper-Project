#include "../../header/Gameplay/Cell/CellController.h"
#include "../../header/Gameplay/Cell/CellView.h"
#include "../../header/Global/ServiceLocator.h"

namespace Gameplay
{
	namespace Cell
	{
		CellController::CellController(sf::Vector2i position)
		{
			cell_view = new CellView(this);
			cell_model = new CellModel(position);
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

		sf::Vector2i CellController::getCellPosition()
		{
			return cell_model->getCellPosition();
		}

		void CellController::reset()
		{
			cell_model->reset();
		}

		void CellController::openCell()
		{
			if (cell_model->getCellState() != CellState::FLAGGED)
			{
				cell_model->setCellState(CellState::OPEN);
				Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
			}
		}

		void CellController::flagCell()
		{
			switch (cell_model->getCellState())
			{
			case::Gameplay::Cell::CellState::FLAGGED:
				cell_model->setCellState(CellState::HIDDEN);
				break;
			case::Gameplay::Cell::CellState::HIDDEN:
				cell_model->setCellState(CellState::FLAGGED);
				break;
			}
		}

		CellValue CellController::getCellValue()
		{
			return cell_model->getCellValue();
		}
	}
}
