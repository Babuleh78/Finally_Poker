#include "GameProcess.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <thread>
#include <iostream>
#include <string>
#include <conio.h>

void GameProcess::card::Create(card* deck, int what_deck) {
	srand(time(0));
	char names[] = { 'В', 'Д', 'К', 'Т' };

	int a = 0;
	for (int i = 0; i < 52; i++) {//Заполнение колоды
		if ((i % 13) + 2 > 10) {
			deck[i].set_name(names[a % 4]);
			a++;
		}
		if (what_deck == 0) {
			deck[i].texture_name = "cards/" + std::to_string(i+1) + ".jpg";
		}
		else if (what_deck == 1) {
			deck[i].texture_name = "cards1/" + std::to_string(i + 1) + ".png";
		}
		else {
			deck[i].texture_name = "cards2/" + std::to_string(i + 1) + ".jpg";
		}
		deck[i].suit = i / 13;
		deck[i].value = (i % 13) + 2;
	}

	for (int i = 0; i < 52; i++) {
		int j = std::rand() % 52;
		std::swap(deck[i], deck[j]);

	}
}


int GameProcess::card::OldCard(card* hand, card* table, int n) { // correct
	return std::max(hand[0].get_value(), hand[1].get_value());
}

int GameProcess::card::Pair(card* hand, card* table, int n) { // correct
	int a = 0;
	for (int i = 0; i < n; i++) {
		if (table[i].get_value() == hand[0].get_value() || table[i].get_value() == hand[1].get_value()) {
			a = std::max(a, table[i].get_value());
		}
	}
	if (hand[0].get_value() == hand[1].get_value()) {
		a = std::max(a, hand[0].get_value());
	}
	return a;
}

int GameProcess::card::TwoPairs(card* hand, card* table, int n) { // correct, but mb will be reworked cause of too many cycles Я на английском нихуя не понимаю
	std::set<int> p;
	int index = 0;
	if (hand[0].get_value() == hand[1].get_value()) { p.insert(hand[0].get_value()); }
	if (p.size() == 1) {
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (table[i].get_value() == table[j].get_value()) { p.insert(table[i].get_value()); }
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if ((table[i].get_value() == hand[0].get_value()) || (table[i].get_value() == hand[1].get_value())) { p.insert(table[i].get_value()); }
	}
	if (p.size() >= 1) {
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (table[i].get_value() == table[j].get_value()) { p.insert(table[i].get_value()); }
			}
		}
	}
	if (p.size() >= 2) { return *max_element(p.begin(), p.end()); }
	return 0;
}

int GameProcess::card::Set(card* hand, card* table, int n) { // correct
	if (hand[0].get_value() == hand[1].get_value()) {
		for (int i = 0; i < n; i++) {
			if (table[i].get_value() == hand[0].get_value()) {
				return hand[0].get_value();
			}
		}
		return 0;
	}
	else {
		int res[2] = { 0, 0 };
		int temp[2] = { 0, 0 };
		int a = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (table[i].get_value() == table[j].get_value() && temp[0] != table[i].get_value()) {
					temp[a] = table[i].get_value();
					++a;
				}
			}
		}
		for (int i = 0; i < 2; ++i) {
			if (hand[0].get_value() == temp[i] || hand[1].get_value() == temp[i]) { res[i] = temp[i]; }
		}
		return std::max(res[0], res[1]);
	}
}
bool GameProcess::card::is_five(std::vector<int> x, int n) { // help func for "strit"
	if (n < 5) { return false; }
	std::sort(x.begin(), x.end());
	if (x[4] == 14 && x[0] == 2) {
		x[4] = 1;
		std::sort(x.begin(), x.end());
	}
	for (int i = 4; i > 0; --i) {
		if (x[i] - x[i - 1] != 1) { return false; }
	}
	return true;
}

int GameProcess::card::Strit(card* hand, card* table, int n) { // correct
	
	int mas_h[2];
	std::vector<int> mas_t(n);
	for (int i = 0; i < n; ++i) { mas_t[i] = 0; }
	mas_h[0] = hand[0].get_value();
	mas_h[1] = hand[1].get_value();
	for (int i = 0; i < n; i++) {
		mas_t[i] = table[i].get_value();
	}

	std::sort(mas_t.begin(), mas_t.end());

	bool str_t = true;
	str_t = is_five(mas_t, n);

	if (str_t == true) {
		if (mas_h[0] - mas_t[n - 1] == 1 && mas_h[1] - mas_t[n - 1] == 2) { return mas_h[1]; }
		if (mas_h[0] - mas_t[n - 1] == 1) { return mas_h[0]; }
		else if (mas_h[1] - mas_t[n - 1] == 1) { return mas_h[1]; }
		for (int i = n - 1; i >= 0; --i) {
			if (mas_h[0] == mas_t[i] || mas_h[1] == mas_t[i]) {
				return mas_t[i];
			}
		}
	}
	bool flag;
	int all_val[15];
	for (int i = 0; i < 15; ++i) { all_val[i] = 0; }
	for (int i = 0; i < n; ++i) { ++all_val[table[i].get_value()]; }
	for (int i = 0; i < 2; ++i) { ++all_val[hand[i].get_value()]; }
	for (int i = 14; i >= 0; --i) {
		if (all_val[i] >= 1) {
			flag = true;
			for (int j = i - 1; j > i - 5; --j) {
				if (all_val[j] == 0) {
					flag = false;
					break;
				}
			}
			if (flag == true) { return i; }
		}
	}
	
	return 0;
}

int GameProcess::card::Flash(card* hand, card* table, int n) { // correct, but mb need to be checked better
	int suits[4] = { 0, 0, 0, 0 };
	for (int i = 0; i < n; ++i) {
		++suits[table[i].get_suit()];
	}
	for (int i = 0; i < 4; ++i) {
		if (suits[i] == 3) {
			if (hand[0].get_suit() == i && hand[1].get_suit() == i) {
				return std::max(hand[0].get_value(), hand[1].get_value());
			}
			else { break; }
		}
		else if (suits[i] >= 4) {
			if (hand[0].get_suit() == i && hand[1].get_suit() == i) {
				return std::max(hand[0].get_value(), hand[1].get_value());
			}
			else if (hand[0].get_suit() == i) {
				return hand[0].get_value();
			}
			else if (hand[1].get_suit() == i) {
				return hand[1].get_value();
			}
			else { break; }
		}
	}
	return 0;
}

int GameProcess::card::FullHouse(card* hand, card* table, int n) {
	int temp_p = 0;
	int all_value[15];
	for (int i = 0; i < 15; ++i) { all_value[i] = 0; }
	for (int i = 0; i < n; ++i) { ++all_value[table[i].get_value()]; }
	for (int i = 14; i >= 2; --i) {
		if (all_value[i] >= 3) {
			for (int j = 14; j >= 2; --j) {
				if (all_value[j] == 2) {
					temp_p = j;
					i = 0;
					break;
				}
			}
		}
	}
	for (int i = 0; i < 2; ++i) { ++all_value[hand[i].get_value()]; }
	for (int i = 14; i >= 2; --i) {
		if (all_value[i] >= 3) {
			for (int j = 14; j >= 2; --j) {
				if (all_value[j] == 2) {
					if (j != temp_p) {
						return i;
					}
				}
			}
		}
	}
	return 0;
}

int GameProcess::card::Kare(card* hand, card* table, int n) { // correct
	int a = 0;
	int temp[15];
	for (int i = 0; i < 15; ++i) { temp[i] = 0; }
	for (int i = 0; i < n; ++i) {
		++temp[table[i].get_value()];
	}
	for (int i = 2; i < 15; ++i) {
		if (temp[i] == 4) { return 0; }
		else if (temp[i] == 2) {
			if (hand[0].get_value() == i && hand[1].get_value() == i) { return i; }
		}
		else if (temp[i] >= 3) {
			if (hand[0].get_value() == i || hand[1].get_value() == i) { return i; }
		}
	}
	return 0;
}

int GameProcess::card::StritFlash(card* hand, card* table, int n) { // correct
	int a = card::Strit(hand, table, n), b = card::Flash(hand, table, n);
	if (a != 0 && b != 0) {
		if (a == b) { return a; }
	}
	return 0;
}

int GameProcess::card::FlashRoyale(card* hand, card* table, int n) { // correct, mb make stritflash and royalflash in 1 func
	std::vector<int> all;
	std::set<int> all_s;
	bool f = true;
	for (int i = 0; i < n; ++i) { all.push_back(table[i].get_value()); all_s.insert(table[i].get_suit()); }
	sort(all.begin(), all.end());
	if (all_s.size() == 1) {
		for (int i = n - 1; i > 0; --i) {
			if (all[i] - all[i - 1] != 1) { f = false; break; }
		}
		if (f == true) { return 0; }
	}
	int suits[4] = { 0, 0, 0, 0 };
	for (int i = 0; i < n; ++i) { ++(suits[table[i].get_suit()]); }
	++(suits[hand[0].get_suit()]); ++(suits[hand[1].get_suit()]);
	int index_suit = 0, max_count_index = 0;
	for (int i = 0; i < 4; ++i) {
		if (suits[i] > max_count_index) {
			max_count_index = suits[i];
			index_suit = i;
		}
	}
	if (max_count_index < 5) { return 0; }
	std::vector<int> all_for_fr;
	for (int i = 0; i < n; ++i) {
		if (table[i].get_suit() == index_suit) {
			all_for_fr.push_back(table[i].get_value());
		}
	}
	for (int i = 0; i < 2; ++i) {
		if (hand[i].get_suit() == index_suit) {
			all_for_fr.push_back(hand[i].get_value());
		}
	}
	sort(all_for_fr.begin(), all_for_fr.end());
	if (all_for_fr[4] != 14) { return 0; }
	for (int i = 4; i > 0; --i) {
		if (all_for_fr[i] - all_for_fr[i - 1] != 1) { return 0; }
	}
	return 14;
}
void GameProcess::card::BetCharge(int& botcap, int& botbet, int& playcap, int& playbet, int a) {
	if (a) {
		playcap += botbet + playbet;
	}
	else {
		botcap += botbet + playbet;
	}
	botbet = 0; playbet = 0;
}
int GameProcess::card::WhoWin(card* player, card* bot, card* table, int opencard, int& combination_number) {//1-победил игрок 0-победил бот
	int (*combination[10])(card * hand, card * table, int n) = { OldCard, Pair, TwoPairs, Set,Strit, Flash, FullHouse, Kare, StritFlash, FlashRoyale };
	char a[10][100]{ "Старшая карта ", "Пара ", "Две пары ", "Сет ", " Стрит ", "Флэш ", "Фулл Хаус ", "Каре ", "СФ ", "ФР " };
	int combplayer[10]{}, combbot[10]{};
	if (opencard != 102) {
		for (int i = 0; i < 10; i++) {
			combplayer[i] = combination[i](player, table, 5);
			
		}
		for (int i = 0; i < 10; i++) {
			
			combbot[i] = combination[i](bot, table, 5);
	
		}
		for (int i = 9; i >= 0; i--) {
			
			if (combbot[i] > combplayer[i]) {
				
				combination_number = i;
		
				return 0;
			}
			else if (combbot[i] < combplayer[i]) {
				
				combination_number = i;
				
				return 1;
			}
		}

		return 0;
	}
	return 2;
}
	
void GameProcess::card::Blind(int& botcap, int& botbet, int& playcap, int& playbet, int& whoblind) {//1 - игрок 0 - бот
	if (whoblind) {
		playcap -= 50;
		playbet += 50;	
		
	}
	else {
		botcap -= 50;
		botbet += 50;
	}

}


