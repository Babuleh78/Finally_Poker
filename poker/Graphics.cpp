#include "Graphics.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include<thread>
#include <iostream>
#include <string>
#include <iterator>
#include <conio.h>
void Graphics::Developers(sf::RenderWindow& window) {
	sf::RectangleShape background(sf::Vector2f(1920, 1080));
	sf::Texture texture_window;
	if (!texture_window.loadFromFile("image/kptch.jpg")) return;
	background.setTexture(&texture_window);
	sf::Font font;
	if (!font.loadFromFile("font/Inky-Thin-Pixels_0.ttf")) return;
	sf::Text titul; titul.setFont(font);
	titul.setString("Developers:");
	sf::Text dev1; dev1.setFont(font);
	dev1.setString("Denis Markin - Graphic component and logic ");
	sf::Text dev2; dev2.setFont(font);
	dev2.setString("Dmitry Nagdasev - Bot and gameplay");
	titul.setCharacterSize(150); dev1.setCharacterSize(75); dev2.setCharacterSize(75);
	titul.setPosition(100, 100); dev1.setPosition(100, 300); dev2.setPosition(100, 600);
	titul.setFillColor(sf::Color::White);
	dev1.setFillColor(sf::Color::Cyan);
	dev2.setFillColor(sf::Color::Green);
	sf::CircleShape button(75);
	sf::Texture texture1;
	if (!texture1.loadFromFile("image/button.png")) return;
	button.setTexture(&texture1);
	button.setPosition(150, 800);
	while (window.isOpen()) {
		sf::Event event_play;
		sf::Vector2i mousePoz = sf::Mouse::getPosition(window);
		while (window.pollEvent(event_play)) {
			if (event_play.type == sf::Event::MouseButtonPressed) {
				if (event_play.key.code == sf::Mouse::Left) {
					if (button.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
						return;
					}
				}
			

			}
			window.clear();
			window.draw(background);
			window.draw(titul);
			window.draw(dev1);
			window.draw(dev2);
			window.draw(button);
			window.display();
		}
	}
}
void Graphics::draw_card(sf::RenderWindow& window, int opencard, GameProcess::card deck[52]) {
	std::string names[5] = { "image/card.jpg", "image/card.jpg" , "image/card.jpg", "image/card.jpg" , "image/card.jpg" };
	GameProcess::card mycard;
	mycard.card_X = 350; mycard.card_Y = 350; mycard.card_Step = 250;
	for (int i = 0; i < 5; i++) {
		sf::RectangleShape Card(sf::Vector2f(150, 250));
		sf::Texture texture;
		Card.setPosition(mycard.card_X, mycard.card_Y);
		mycard.card_X += mycard.card_Step;
		if (!texture.loadFromFile("image/card.jpg")) exit(1);
		Card.setTexture(&texture);
		window.draw(Card);
	}
	deck[0].card_X = 750; deck[0].card_Y = 50; //Карты бота, всегда закрытые, кроме финала
	deck[1].card_X = 950; deck[1].card_Y = 50;
	for (int i = 0; i < 2; i++) {
		sf::RectangleShape Card(sf::Vector2f(150, 250));
		sf::Texture texture;
		Card.setPosition(deck[i].card_X, deck[i].card_Y);
		deck[i].card_X += deck[i].card_Step;
		if (opencard < 6) {
			if (!texture.loadFromFile(names[i])) exit(1);
		}
		else {
			if (!texture.loadFromFile(deck[i].texture_name)) exit(1);
		}
		Card.setTexture(&texture);
		window.draw(Card);
	}
	deck[2].card_X = 750; deck[2].card_Y = 650;
	deck[3].card_X = 950; deck[3].card_Y = 650;
	for (int i = 2; i < 4; i++) {
		sf::RectangleShape Card(sf::Vector2f(150, 250));
		sf::Texture texture;
		Card.setPosition(deck[i].card_X, deck[i].card_Y);
		deck[i].card_X += deck[i].card_Step;
		if (!texture.loadFromFile(deck[i].texture_name)) exit(1);
		Card.setTexture(&texture);
		window.draw(Card);
	}
	if (opencard == 6) {
		opencard -= 1;
	}
	else if (opencard == 7) {
		opencard -= 2;
	}
	for (int i = 4; i < 4 + opencard; i++) {
		deck[i].card_X = 350 + (i - 4) * 250; deck[i].card_Y = 350;
		sf::RectangleShape Card(sf::Vector2f(150, 250));
		sf::Texture texture;
		Card.setPosition(deck[i].card_X, deck[i].card_Y);
		deck[i].card_X += deck[i].card_Step;
		if (!texture.loadFromFile(deck[i].texture_name)) exit(1);
		Card.setTexture(&texture);
		window.draw(Card);
	}


}
void Graphics::Bet_display(int botbet, int playbet, int botcap, int playcap, sf::RenderWindow& window) {
	sf::Font font;
	if (!font.loadFromFile("font/Rus1.otf")) return;
	sf::Text play_info;
	play_info.setFont(font);
	play_info.setCharacterSize(45);
	play_info.setString("Your money is " + std::to_string(playcap));
	window.draw(play_info);
	play_info.setPosition(0, 80);
	
	play_info.setString("Your bet is " + std::to_string(playbet));
	window.draw(play_info);
	sf::Text bot_info;
	bot_info.setFont(font);
	bot_info.setCharacterSize(45);
	bot_info.setPosition(1520, 0);	
	bot_info.setString("Bot money is " + std::to_string(botcap));
	window.draw(bot_info);
	bot_info.setPosition(1620, 80);
	bot_info.setString("Bot bet is " + std::to_string(botbet));
	window.draw(bot_info);
}
void Graphics::Buttons_display(sf::RenderWindow& window, int& opencard) {

	sf::CircleShape button_call(50);
	sf::CircleShape button_bet(50);
	sf::CircleShape button_fold(50);
	button_call.setPosition(1400, 750);
	sf::Texture texture_call;
	if (!texture_call.loadFromFile("image/Call.jpg")) return;
	button_call.setTexture(&texture_call);
	sf::Texture texture_bet;
	if (!texture_bet.loadFromFile("image/Bet.jpg")) return;
	button_bet.setTexture(&texture_bet);
	sf::Texture texture_fold;
	if (!texture_fold.loadFromFile("image/Fold.jpg")) return;
	button_fold.setTexture(&texture_fold);

	button_bet.setPosition(1550, 750);

	button_fold.setPosition(1700, 750);
	window.draw(button_fold);
	window.draw(button_bet);
	window.draw(button_call);

}
void Graphics::BetWindow(int& playcap, int& playbet, int botbet) {
	int dop_dep = 0;
	bool flag = true;
	sf::RenderWindow window;
	//window.create(sf::VideoMode::getDesktopMode(), L"Ставка", sf::Style::Default);
	window.setSize(sf::Vector2u(600, 500));
	sf::RectangleShape background(sf::Vector2f(1920, 1080));
	sf::Texture texture_window;
	if (!texture_window.loadFromFile("image/Shut_up.jpg")) return;
	background.setTexture(&texture_window);
	sf::Font font;
	if (!font.loadFromFile("font/Inky-Thin-Pixels_0.ttf")) return;
	sf::String playerInput;
	sf::Text playerText;
	sf::Text def_Text;
	playerText.setCharacterSize(250);
	def_Text.setCharacterSize(250);
	playerText.setFillColor(sf::Color::Black);
	def_Text.setFillColor(sf::Color::Black);
	playerText.setFont(font);
	def_Text.setFont(font);
	def_Text.setPosition(300, 50);
	playerText.setPosition(1200, 50);
	def_Text.setString("Your bet: ");
	while (flag) {
		window.create(sf::VideoMode::getDesktopMode(), L"Ставка", sf::Style::Default);
		window.setSize(sf::Vector2u(400, 300));
		window.setPosition(sf::Vector2i(800, 400));
		while (window.isOpen()) {
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					window.close();

				if (event.type == sf::Event::TextEntered) {
					if (event.text.unicode < 128) {
						if (event.text.unicode == 8 && !playerInput.isEmpty()) {
							playerInput.erase(playerInput.getSize() - 1);
						}
						else {
							playerInput += static_cast<char>(event.text.unicode);
						}
						playerText.setString(playerInput);
					}
				}
				if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
					std::string str = playerInput.toAnsiString(); // Преобразование sf::String в std::string
					try {
						int inputValue = std::stoi(str); // Преобразование строки в целое число
						int dop_dep = inputValue;
						
						if ((playbet + dop_dep) >= botbet + 50 && playcap-dop_dep >= 0) {
							playbet += dop_dep;
							playcap -= dop_dep;
							flag = false;
							window.close();
							return;
						} 
						
						else {
							window.close();
						}
					}
					catch (const std::invalid_argument& ia) {
						std::cerr << "Неверный формат числа: " << ia.what() << std::endl;
					}
					catch (const std::out_of_range& oor) {
						std::cerr << "Число выходит за допустимый диапазон: " << oor.what() << std::endl;
					}

				}

			}
			window.clear();
			window.draw(background);
			window.draw(playerText);
			window.draw(def_Text);
			window.display();
		}

	}
}
void Graphics::Texture_Card(sf::RenderWindow& window, int& what_deck) {
	sf::RectangleShape background(sf::Vector2f(1920, 1080));
	sf::Texture texture_window;
	if (!texture_window.loadFromFile("image/Back.jpg")) return;
	background.setTexture(&texture_window);
	sf::RectangleShape card1(sf::Vector2f(300, 500));
	sf::Texture texture_card1;
	if (!texture_card1.loadFromFile("cards/13.jpg")) return;
	card1.setTexture(&texture_card1);
	sf::RectangleShape card2(sf::Vector2f(300, 500));
	sf::Texture texture_card2;
	if (!texture_card2.loadFromFile("cards1/13.png")) return;
	card2.setTexture(&texture_card2);
	sf::RectangleShape card3(sf::Vector2f(300, 500));
	sf::Texture texture_card3;
	if (!texture_card3.loadFromFile("cards2/13.jpg")) return;
	card3.setTexture(&texture_card3);
	card1.setPosition(200, 250);
	card2.setPosition(800, 250);
	card3.setPosition(1400, 250);
	while (window.isOpen()) {
		sf::Event event_play;
		sf::Vector2i mousePoz = sf::Mouse::getPosition(window);
		while (window.pollEvent(event_play)) {
			if (event_play.type == sf::Event::MouseButtonPressed) {
				if (event_play.key.code == sf::Mouse::Left) {
					if (card1.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
						what_deck = 0;
						return;
					}
					if (card2.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
						what_deck = 1;
						return;
					}
					if (card3.getGlobalBounds().contains(mousePoz.x, mousePoz.y)) {
						what_deck = 2;
						return;
					}
				}

			}
			window.clear();
			window.draw(background);
			window.draw(card1);
			window.draw(card2);
			window.draw(card3);
			window.display();
		}
	}
}
std::pair<int, int> getTwoMaxElements(const std::set<int>& s) {
    if (s.size() < 2) {
        throw std::length_error("Множество содержит менее двух элементов");
    }

    auto it = s.end();
    --it; // Первый максимальный элемент
    int max1 = *it;
    --it; // Второй максимальный элемент
    int max2 = *it;

    return {max1, max2};
}
void Graphics::VashShash(sf::RenderWindow& window, int a, int opencard) {
	sf::Font font;
	if (!font.loadFromFile("font/Inky-Thin-Pixels_0.ttf")) return;
	sf::Text Zdravstvuite_Aladin_Ia_Pashalka;
	Zdravstvuite_Aladin_Ia_Pashalka.setCharacterSize(100);
	Zdravstvuite_Aladin_Ia_Pashalka.setFillColor(sf::Color::Red);
	Zdravstvuite_Aladin_Ia_Pashalka.setFont(font);
	Zdravstvuite_Aladin_Ia_Pashalka.setString("YOUR TURN!");
	int xpos, ypos = 200;
	if (a == 0) {
		xpos = 75;
	}
	else if (a == 1) {
		xpos = 1500;
	}
	else {
		xpos = -1000;
	}
	Zdravstvuite_Aladin_Ia_Pashalka.setPosition(xpos, ypos);
	if (opencard <= 5) {
		window.draw(Zdravstvuite_Aladin_Ia_Pashalka);
	};
}
void Graphics::Win_Window(sf::RenderWindow& window, int a, int combination_number) {//1-игрок 0 - бот
	std::string names[] = { "Old Card", "Pair", "Two Pairs", "Set", " Strit", "Flash", "Full House", "Kare", " Strit Flash", "Clash Royale" };
	sf::Font font;
	if (!font.loadFromFile("font/Inky-Thin-Pixels_0.ttf")) return;
	sf::Text Win_text;
	Win_text.setCharacterSize(120);
	Win_text.setFont(font);
	sf::Text comb_text;
	comb_text.setCharacterSize(120);
	comb_text.setFont(font);
	if (a) {
		Win_text.setFillColor(sf::Color(20, 102, 5));
		comb_text.setFillColor(sf::Color(20, 102, 5));
		Win_text.setString("YOU WIN!");
	}
	else {
		Win_text.setFillColor(sf::Color(117, 11, 11));
		comb_text.setFillColor(sf::Color(117, 11, 11));
		Win_text.setString("BOT WIN!");
	}
	sf::FloatRect textRect = Win_text.getLocalBounds();
	Win_text.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	Win_text.setPosition(sf::Vector2f(1920 / 2.0f, 1080 / 2.0f));
	comb_text.setString(names[combination_number]);
	comb_text.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	comb_text.setPosition(sf::Vector2f(1920 / 2.0f, 1080 / 2.0f - 200));
	window.draw(Win_text);
	window.draw(comb_text);

}
void Graphics::Opred_cards(int mas[7], int combination_number, GameProcess::card* hand, GameProcess::card* table) {
	std::set<int> p;
	std::set<int>::iterator it;
	std::set<int>::iterator it1;
	int a = 0, b = 0, index = 0, c = 0;
	auto rit = p.rbegin();
	int helpmas[7]{};
	GameProcess::card help_mas[7];
	bool flag = false;
	switch (combination_number) {
	case 0: //Старшая карта Работает
		a = GameProcess::card::OldCard(hand, table, 5);
		mas[0] = (hand[0].get_value() == a ? 1 : 0);
		mas[1] = (hand[1].get_value() == a ? 1 : 0);
		for (int i = 0; i < 5; i++) {
			mas[i + 2] = (table[i].get_value() == a ? 1 : 0);
		}
		break;
	case 1: //Пара Работает
		a = GameProcess::card::Pair(hand, table, 5);
		mas[0] = (hand[0].get_value() == a ? 1 : 0);
		mas[1] = (hand[1].get_value() == a ? 1 : 0);
		for (int i = 0; i < 5; i++) {
			mas[i + 2] = (table[i].get_value() == a ? 1 : 0);
		}
		break;
	case 2: //Две пары Работает
		index = 0;
		if (hand[0].get_value() == hand[1].get_value()) { p.insert(hand[0].get_value()); }
		if (p.size() == 1) {
			for (int i = 0; i < 5; ++i) {
				for (int j = i + 1; j < 5; ++j) {
					if (table[i].get_value() == table[j].get_value()) { p.insert(table[i].get_value()); }
				}
			}
		}
		for (int i = 0; i < 5; ++i) {
			if ((table[i].get_value() == hand[0].get_value()) || (table[i].get_value() == hand[1].get_value())) { p.insert(table[i].get_value()); }
		}
		if (p.size() >= 1) {
			for (int i = 0; i < 5; ++i) {
				for (int j = i + 1; j < 5; ++j) {
					if (table[i].get_value() == table[j].get_value()) { p.insert(table[i].get_value()); }
				}
			}
		}
		rit = p.rbegin(); // Реверс-итератор на максимальный элемент
		a = *rit;
		++rit; // Следующий реверс-итератор на второй по величине элемент
		b = *rit;




		mas[0] = ((hand[0].get_value() == a) || (hand[0].get_value() == b) ? 1 : 0);
		mas[1] = ((hand[1].get_value() == a) || (hand[1].get_value() == b) ? 1 : 0);
		for (int i = 0; i < 5; i++) {
			mas[i + 2] = ((table[i].get_value() == a || table[i].get_value() == b) ? 1 : 0);
		}
		break;
	case 3: //Сет Работает
		a = GameProcess::card::Set(hand, table, 5);
		mas[0] = (hand[0].get_value() == a ? 1 : 0);
		mas[1] = (hand[1].get_value() == a ? 1 : 0);
		for (int i = 0; i < 5; i++) {
			mas[i + 2] = (table[i].get_value() == a ? 1 : 0);
		}
		break;
	case 4: //Стрит Работает?
		for (int i = 0; i < 5; i++) {
			helpmas[i+2] = table[i].get_value();
		}

		helpmas[0] = hand[0].get_value();
		helpmas[1] = hand[1].get_value();
		
		std::sort(helpmas, helpmas + 7);

		for (int i = 0; i <= 2; ++i) {

			if (helpmas[i] + 1 == helpmas[i + 1] &&
				helpmas[i + 1] + 1 == helpmas[i + 2] &&
				helpmas[i + 2] + 1 == helpmas[i + 3] &&
				helpmas[i + 3] + 1 == helpmas[i + 4]) {
				a = helpmas[i];
				b = helpmas[i + 4];
				break;
			}
		}
		
		for (int i = 0; i < 7;i++) {
			if (helpmas[i] == a || helpmas[i] == a + 1 || helpmas[i] == a + 2 || helpmas[i] == a + 3 || helpmas[i] == b) {
				mas[i] = 1;
			}
		}
		break;
	case 5: //Флэш Работает
		
		for (int i = 0; i < 5; i++) {
			mas[table[i].get_suit()] += 1;
			helpmas[i+2] = table[i].get_value();
		}
		mas[hand[0].get_suit()] += 1;
		helpmas[0] = hand[0].get_suit();
		mas[hand[1].get_suit()] += 1;
		helpmas[1] = hand[1].get_suit();
		for (int i = 0; i < 4; i++) {
			if (mas[i] >=5) { b = i; }//из этих мастей флэш
		}
		
		for (int i = 0; i < 2; i++) {
			mas[i] = (hand[i].get_suit() == b ? 1 : 0);
		}
		for (int i = 0; i < 5; i++) {
			mas[i + 2] = (table[i].get_suit() == b ? 1 : 0);
		}
		
		for (int i = 0; i < 7; i++) {
			if (mas[i] == 1) {
				a += 1;
			}
		}
		if (a > 5) {
			if (a == 6) {//в а будем записывать наименьшую карту флэша
				a = 100;
				for (int i = 0;i < 7; i++) {
					if (mas[i] == 1) {
						a = std::min(a, helpmas[i]);
					}
				}
				for (int i = 0; i < 2; i++) {
					mas[i] = ((hand[i].get_suit() == b && hand[i].get_value() !=a) ? 1 : 0);
				}
				for (int i = 0; i < 5; i++) {
					mas[i + 2] = ((table[i].get_suit() == b && table[i].get_value()!=a) ? 1 : 0);
				}

			}
			else {
				a = 100; b = 100;
				for (int i = 0; i < 7; i++) {
					if(helpmas[i] < a) {
						b = a;
						a = helpmas[i];
					}
				}
				for (int i = 0; i < 2; i++) {
					mas[i] = ((hand[i].get_suit() == b && hand[i].get_value() != a && hand[i].get_value()!=b) ? 1 : 0);
				}
				for (int i = 0; i < 5; i++) {
					mas[i + 2] = ((table[i].get_suit() == b && table[i].get_value() != a && table[i].get_value()!=b) ? 1 : 0);
				}
			}
		}
		break;
	case 6: //Фулл хаус Работает
		a = GameProcess::card::Set(hand, table, 5);
		if (hand[0].get_value() != a) {
			for (int i = 0;i < 5; i++) {
				if (hand[0].get_value() == table[i].get_value()) { b = std::max(b, table[i].get_value()); }
			}
		}
		if (hand[1].get_value() != a) {
			for (int i = 0;i < 5; i++) {
				if (hand[0].get_value() == table[i].get_value()) { b = std::max(b, table[i].get_value()); }
			}
		}
		
		for (int i = 0; i < 5; i++) {
			if (table[i].get_value() != a) {
				for (int j = i + 1; j < 5; j++) {
					if (table[i].get_value() == table[j].get_value()) {
						b = std::max(b, table[i].get_value());
					}
				}
			}
		}
		
		mas[0] = ((hand[0].get_value() == a) || (hand[0].get_value() == b) ? 1 : 0);
		mas[1] = ((hand[1].get_value() == a) || (hand[1].get_value() == b) ? 1 : 0);
		for (int i = 0; i < 5; i++) {
			mas[i + 2] = ((table[i].get_value() == a || table[i].get_value() == b) ? 1 : 0);
		}
		break;
	case 7://Каре Работает
		a = GameProcess::card::Kare(hand, table, 5);
		mas[0] = ((hand[0].get_value() == a) || (hand[0].get_value() == b) ? 1 : 0);
		mas[1] = ((hand[1].get_value() == a) || (hand[1].get_value() == b) ? 1 : 0);
		for (int i = 0; i < 5; i++) {
			mas[i + 2] = ((table[i].get_value() == a || table[i].get_value() == b) ? 1 : 0);
		}

	case 8: //Стрит флэш
		a = GameProcess::card::StritFlash(hand, table, 5);
		for (int i = 0; i < 5; i++) {
			mas[table[i].get_suit()] += 1;
		}
		mas[hand[0].get_suit()] += 1;
		mas[hand[1].get_suit()] += 1;
		for (int i = 0; i < 4; i++) {
			if (mas[i] == 5) { b = i; }//из этих мастей флэш
		}
		for (int i = 0; i < 5; i++) {
			helpmas[i] = table[i].get_value();
		}

		helpmas[5] = hand[0].get_value();
		helpmas[6] = hand[1].get_value();
		
		std::sort(helpmas, helpmas + 7);
		for (int i = 0; i <= 2; ++i) {

			if (helpmas[i] + 1 == helpmas[i + 1] &&
				helpmas[i + 1] + 1 == helpmas[i + 2] &&
				helpmas[i + 2] + 1 == helpmas[i + 3] &&
				helpmas[i + 3] + 1 == helpmas[i + 4]) {
				a = helpmas[i];
				b = helpmas[i + 4];
				break;
			}
		}
		
		for (int i = 0; i < 7;i++) {
			if (helpmas[i] == a || helpmas[i] == a + 1 || helpmas[i] == a + 2 || helpmas[i] == a + 3 || helpmas[i] == b) {
				mas[i] = 1;
			}
		}
		break;
	case 9: //Флеш рояль
		for (int i = 0; i < 5; i++) {
			mas[table[i].get_suit()] += 1;
		}
		mas[hand[0].get_suit()] += 1;
		mas[hand[1].get_suit()] += 1;
		for (int i = 0; i < 4; i++) {
			if (mas[i] == 4) { b = i; }//из этих мастей флэш
		}
		mas[0] = ((hand[0].get_suit() == b) && (hand[0].get_value() >= 10) ? 1 : 0);
		mas[1] = ((hand[1].get_suit() == b) && (hand[1].get_value() >= 10) ? 1 : 0);
		for (int i = 0; i < 5; i++) {
			mas[i+2] = ((hand[i].get_suit() == b) && (hand[i].get_value() >= 10) ? 1 : 0);
		}
	}
}
void Graphics::draw_win_card(sf::RenderWindow& window, int opencard, GameProcess::card deck[52], int podsvet[7], int WhoWin) {
	std::string names[5] = { "image/card.jpg", "image/card.jpg" , "image/card.jpg", "image/card.jpg" , "image/card.jpg" };
	

	GameProcess::card mycard;
	sf::RectangleShape Card;
	//Card.setFillColor(sf::Color::Black);
	Card.setSize(sf::Vector2f(150, 250));
	sf::RectangleShape Help;
	Help.setSize(sf::Vector2f(150, 250));
	mycard.card_X = 350; mycard.card_Y = 350; mycard.card_Step = 250;
	deck[0].card_X = 750; deck[0].card_Y = 50;
	deck[1].card_X = 950; deck[1].card_Y = 50;
	for (int i = 0; i < 2; i++) {
		sf::Texture texture;
		if (opencard < 6) {
			if (!texture.loadFromFile(names[i])) exit(1);
		}
		else {
			if (!texture.loadFromFile(deck[i].texture_name)) exit(1);
		}
		Card.setTexture(&texture);
		if (WhoWin == 0 && podsvet[i] == 1) {
			Card.setOutlineThickness(10);
			Card.setOutlineColor(sf::Color::Red);
		}
		Card.setPosition(deck[i].card_X, deck[i].card_Y);

		window.draw(Card);
		//Card.setFillColor(sf::Color::Black);
		Card.setOutlineThickness(0);
	}
	deck[2].card_X = 750; deck[2].card_Y = 650;
	deck[3].card_X = 950; deck[3].card_Y = 650;

	for (int i = 2; i < 4; i++) {
		if (WhoWin == 1 && podsvet[i - 2] == 1) {
			Card.setOutlineThickness(10);
			Card.setOutlineColor(sf::Color::Green);
		}

		sf::Texture texture;
		Card.setPosition(deck[i].card_X, deck[i].card_Y);
		deck[i].card_X += deck[i].card_Step;
		if (!texture.loadFromFile(deck[i].texture_name)) exit(1);
		Card.setTexture(&texture);
		window.draw(Card);
		//Card.setFillColor(sf::Color::Black);
		Card.setOutlineThickness(0);
	}

	if (opencard == 6) {
		opencard -= 1;
	}
	else if (opencard == 7) {
		opencard -= 2;
	}
	sf::RectangleShape nCard;
	Help.setSize(sf::Vector2f(170, 270));
	Help.setFillColor(sf::Color::Green);
	Card.setSize(sf::Vector2f(150, 250));
	for (int i = 4; i < 4 + opencard; i++) {
		sf::Texture texture;

		Card.setPosition(deck[i].card_X, deck[i].card_Y);

		deck[i].card_X += deck[i].card_Step;
		if (!texture.loadFromFile(deck[i].texture_name)) exit(1);
		Card.setTexture(&texture);
		if (podsvet[i - 2] == 1) {

			if (WhoWin) {

				Card.setOutlineThickness(10);
				Card.setOutlineColor(sf::Color::Green);
			}
			else {

				Card.setOutlineThickness(10);
				Card.setOutlineColor(sf::Color::Red);
			}
		}
		Card.setTexture(&texture);

		deck[i].card_X = 350 + (i - 4) * 250; deck[i].card_Y = 350;

		window.draw(Card);
		Card.setOutlineThickness(0);

	}
}
void Graphics::draw_all(sf::RenderWindow& window, sf::RectangleShape Back, sf::CircleShape button_fold, sf::CircleShape button_bet, sf::CircleShape button_call,
	int opencard, GameProcess::card deck[52], int botbet, int playbet, int botcap, int playcap, int a) {
	
		sf::CircleShape button(75);
		sf::Texture texture1;
		if (!texture1.loadFromFile("image/button.png")) return;
		button.setTexture(&texture1);
		button.setPosition(150, 800);
		window.clear();
		window.draw(Back);
		window.draw(button_fold);
		window.draw(button_bet);
		window.draw(button_call);
		window.draw(button);
		Graphics::draw_card(window, opencard, deck);
		Graphics::Bet_display(botbet, playbet, botcap, playcap, window);
		Graphics::VashShash(window, a, opencard);
		window.display();
	
}
void Graphics::draw_all_Win(sf::RenderWindow& window, sf::RectangleShape Back, sf::CircleShape button_fold, sf::CircleShape button_bet, sf::CircleShape button_call,
	int opencard, GameProcess::card deck[52], int botbet, int playbet, int botcap, int playcap, int a, int WhoWin, int podsvet[7], int combination_number) {
	sf::CircleShape button(75);
	sf::Texture texture1;
	if (!texture1.loadFromFile("image/button.png")) return;
	button.setTexture(&texture1);
	button.setPosition(150, 800);

	window.clear();
	window.draw(Back);
	window.draw(button_fold);
	window.draw(button_bet);
	window.draw(button_call);
	window.draw(button);
	Graphics::Bet_display(botbet, playbet, botcap, playcap, window);
	Graphics::VashShash(window, a, opencard);
	Graphics::draw_win_card(window, opencard, deck, podsvet, WhoWin);
	Graphics::Win_Window(window, WhoWin, combination_number);
	window.display();

}
