#pragma once

namespace Gameplay
{
	class GameplayController;
	enum class GameResult;

	class GameplayService
	{
	private:
		GameplayController* gameplay_controller;

	public:
		GameplayService();
		~GameplayService();

		void initialize();
		void update();
		void render();

		float getRemainingTime();
		int getMineCount();

		void endGame(GameResult result);
		void startGame();
		void reset();
	};
}