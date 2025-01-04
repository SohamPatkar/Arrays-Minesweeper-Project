#pragma once
#include "../../header/UI/Interface/IUIController.h"
#include "../../header/UI/UIElement/TextView.h"
#include <sfml/Graphics.hpp>

namespace UI
{
	namespace Gameplay
	{
		class GameplayUIController : public Interface::IUIController
		{
		private:
			const int font_size = 110;
			const sf::Color text_color = sf::Color::Red;

			const float time_text_top_offset = 65.f;
			const float time_text_left_offset = 1090.f;

			UI::UIElement::TextView* time_text;

		public:
			GameplayUIController();
			~GameplayUIController();

			void createTexts();
			void initializeTimeText();
			void initializeTexts();
			void updateTimeText();
			
			void initialize();
			void update();
			void render();
			
			void show();
		};
	}
}