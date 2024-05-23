#pragma once
#include <SFML/Graphics.hpp>
#include "GameProcess.h"
class Graphics {
public:
	static void draw_win_card(sf::RenderWindow& window, int opencard, GameProcess::card draw[52], int podsvet[7], int WhoWin);
	static void BetWindow(int& playcap, int& playbet, int botbet);
	static void VashShash(sf::RenderWindow& window, int a, int opencard);
	static void Win_Window(sf::RenderWindow& window, int a, int combination_number);
	static void Opred_cards(int mas[7], int combination_number, GameProcess::card* hand, GameProcess::card* table);
	static void Bet_display(int botbet, int playbet, int botcap, int playcap, sf::RenderWindow& window);
	static void Buttons_display(sf::RenderWindow& window, int& opencard);
	static void draw_card(sf::RenderWindow& window, int opencard, GameProcess::card draw[52]);
	static void Texture_Card(sf::RenderWindow& window, int& what_deck);
	static void Developers(sf::RenderWindow& window);
	static void draw_all(sf::RenderWindow& window, sf::RectangleShape Back, sf::CircleShape button_fold, sf::CircleShape button_bet, sf::CircleShape button_call,
		int opencard, GameProcess::card deck[52], int botbet, int playbet, int botcap, int playcap, int a);
	static void draw_all_Win(sf::RenderWindow& window, sf::RectangleShape Back, sf::CircleShape button_fold, sf::CircleShape button_bet, sf::CircleShape button_call,
		int opencard, GameProcess::card deck[52], int botbet, int playbet, int botcap, int playcap, int a, int WhoWin, int podsvet[7], int combination_number);
};
