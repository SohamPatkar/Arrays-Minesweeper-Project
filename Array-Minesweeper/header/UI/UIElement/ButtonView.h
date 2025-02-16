#pragma once
#include "../../header/UI/UIElement/ImageView.h"
#include <sfml/Graphics.hpp>
#include <functional>

namespace UI
{
	namespace UIElement
	{
		enum class ButtonType
		{
			LEFT_MOUSE_BUTTON,
			RIGHT_MOUSE_BUTTON,
			PRESSEDPLAY
		};

		class ButtonView : public ImageView
		{
		private:
			// Define a function pointer type for the callback function
			using CallbackFunction = std::function<void(ButtonType)>;

			// Store the callback function
			CallbackFunction callback_function = nullptr;

			void printButtonClicked();
			int counter_button;

		protected:
			sf::String button_title;

			virtual void handleButtonInteraction();

		public:
			ButtonView();
			virtual ~ButtonView();

			virtual void initialize(sf::String title, sf::String texture_path, float button_width, float button_height, sf::Vector2f position);
			virtual void update() override;
			virtual void render() override;

			bool clickedLeftMouseButton(sf::Sprite* button_sprite, sf::Vector2f mouse_position);
			bool clickedRightMouseButton(sf::Sprite* button_sprite, sf::Vector2f mouse_position);
			
			void registerCallbackFuntion(CallbackFunction button_callback);
		};
	}
}