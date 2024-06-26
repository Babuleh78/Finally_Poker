
#pragma once
#include <SFML/Graphics.hpp>

namespace game {

	class GameMenu
	{
		float menu_X;                                    
		float menu_Y;				                    
		int menu_Step;                                    
		int max_menu;                                     
		int size_font;                                    
		int mainMenuSelected;                             
		sf::Font font;                                    
		sf::Text* mainMenu;                               

		sf::Color menu_text_color = sf::Color::White;      
		sf::Color chose_text_color = sf::Color::Black;    
		sf::Color border_color = sf::Color::Black;         

		void SetTextOpt(sf::Text& text,  sf::String& str, float xpos, float ypos);

		sf::RenderWindow& mywindow;                       
	public:

		GameMenu(sf::RenderWindow& window, float menux, float menuy, sf::String name[], int sizeFont = 60, int step = 80);

		~GameMenu() {
			delete[] mainMenu;
		}
		void draw();                                     

		void MoveUp();                                   

		void MoveDown();                                 

		void setColorTextMenu(sf::Color menColor, sf::Color ChoColor, sf::Color BordColor);

		void AlignMenu(int posx);       

		int getSelectedMenuNumber()
		{
			return mainMenuSelected;
		}


	};

}
