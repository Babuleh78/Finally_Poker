
#pragma once
#include <SFML/Graphics.hpp>
namespace GameProcess {
	class card {
	public:

		float card_X;
		float card_Y;
		int card_Step;
		std::string texture_name;
		sf::Texture texture;

		static void Create(card* deck, int What_deck);
		
	
		card() : card_X(0.0f), card_Y(0.0f), card_Step(0), value(0), suit(0), name('\0'), texture_name("1") {}
		static int OldCard(card* hand, card* table, int n);
		static int Pair(card* hand, card* table, int n);
		static int TwoPairs(card* hand, card* table, int n);
		static int Set(card* hand, card* table, int n);
		static int Strit(card* hand, card* table, int n);
		static int Flash(card* hand, card* table, int n);
		static int FullHouse(card* hand, card* table, int n);
		static int Kare(card* hand, card* table, int n);
		static int StritFlash(card* hand, card* table, int n);
		static int FlashRoyale(card* hand, card* table, int n);
		static bool is_five(std::vector<int> x, int n);
		static int WhoWin(card* player, card* bot, card* table, int opencard, int& combination_number);
		static void Blind(int& botcap, int& botbet, int& playcap, int& playbet, int& whoblind);
		static void BetCharge(int& botcap, int& botbet, int& playcap, int& playbet, int a);
	
		friend std::ostream& operator<<(std::ostream& out, card& obj) {
			out << obj.get_value();
			if (obj.get_suit() == 0) {
				out << " треф";
			}
			else if (obj.get_suit() == 1) {
				out << " черви";
			}
			else if (obj.get_suit() == 2) {
				out << " пики";
			}
			else {
				out << " буби";
			}
			return out;
		}
		int get_value() {
			return value;
		}
		int get_suit() {
			return suit;
		}
		char get_name() {
			return name;
		}
		void set_value(int _value) {
			if (_value < 2 || _value>14) { return; }
			value = _value;
		}
		void set_suit(int _suit) {
			if (_suit > 3 || _suit < 0) { return; }
			suit = _suit;
		}
		void set_name(char _name) {
			name = _name;
		}
	private:

		card(sf::RenderWindow& window, float card_X = 350, float card_Y = 350, int card_Step = 80){};
		char name; // Имя карты старше 10 для красивого отображения
		
		int suit;//	
		
		int value; // "Вес" карты, от 2 до 14 Валет 11 Дама 12 Король 13 Туз 14
		
		
	};
}
