#include "AI.h"

float AI::PairChance(GameProcess::card* RemDeck, GameProcess::card* table, int a, int n, int opencard) {
	float allcombo = n * (n - 1) / 2;
	float win = 0;
	GameProcess::card* Ntable = new GameProcess::card[opencard];
	for (int i = 0; i < opencard; i++) {
		Ntable[i] = table[i];
	}
	GameProcess::card PotencialHand[2];
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			PotencialHand[0] = RemDeck[i];
			PotencialHand[1] = RemDeck[j];
			if (GameProcess::card::Pair(PotencialHand, Ntable, opencard) > a) {
				
				win += 1;
			}
		}
	}
	delete[] Ntable;
	return win / allcombo;
}

float AI::TwoPairsChance(GameProcess::card* RemDeck, GameProcess::card* table, int a, int n, int opencard) {
	float allcombo = n * (n - 1) / 2;
	float win = 0;
	GameProcess::card* Ntable = new GameProcess::card[opencard];
	for (int i = 0; i < opencard; i++) {
		Ntable[i] = table[i];
	}
	GameProcess::card PotencialHand[2];
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			PotencialHand[0] = RemDeck[i];
			PotencialHand[1] = RemDeck[j];
			if (GameProcess::card::TwoPairs(PotencialHand, Ntable, opencard) > a) {
				win += 1;
			}
		}
	}
	delete[] Ntable;
	return win / allcombo;
}

float AI::SetChance(GameProcess::card* RemDeck, GameProcess::card* table, int a, int n, int opencard) {
	float allcombo = n * (n - 1) / 2;
	float win = 0;
	GameProcess::card PotencialHand[2];
	GameProcess::card* Ntable = new GameProcess::card[opencard];
	for (int i = 0; i < opencard; i++) {
		Ntable[i] = table[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			PotencialHand[0] = RemDeck[i];
			PotencialHand[1] = RemDeck[j];
			if (GameProcess::card::Set(PotencialHand, Ntable, opencard) > a) {
				win += 1;
			}
		}
	}
	delete[] Ntable;
	return win / allcombo;
}

float AI::StritChance(GameProcess::card* RemDeck, GameProcess::card* table, int a, int n, int opencard) {
	float allcombo = n * (n - 1) / 2;
	float win = 0;
	GameProcess::card* Ntable = new GameProcess::card[opencard];
	for (int i = 0; i < opencard; i++) {
		Ntable[i] = table[i];
	}
	GameProcess::card PotencialHand[2];
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			PotencialHand[0] = RemDeck[i];
			PotencialHand[1] = RemDeck[j];
			if (GameProcess::card::Strit(PotencialHand, Ntable, opencard) > a) {
				win += 1;
			}
		}
	}
	delete[] Ntable;
	return win / allcombo;
}

float AI::FlashChance(GameProcess::card* RemDeck, GameProcess::card* table, int a, int n, int opencard) {
	float allcombo = n * (n - 1) / 2;
	float win = 0;
	GameProcess::card* Ntable = new GameProcess::card[opencard];
	for (int i = 0; i < opencard; i++) {
		Ntable[i] = table[i];
	}
	GameProcess::card PotencialHand[2];
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			PotencialHand[0] = RemDeck[i];
			PotencialHand[1] = RemDeck[j];
			if (GameProcess::card::Flash(PotencialHand, Ntable, opencard) > a) {
				win += 1;
			}
		}
	}
	delete[] Ntable;
	return win / allcombo;
}

float AI::FullHouseChance(GameProcess::card* RemDeck, GameProcess::card* table, int a, int n, int opencard) {
	float allcombo = n * (n - 1) / 2;
	float win = 0;
	GameProcess::card* Ntable = new GameProcess::card[opencard];
	for (int i = 0; i < opencard; i++) {
		Ntable[i] = table[i];
	}
	GameProcess::card PotencialHand[2];
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			PotencialHand[0] = RemDeck[i];
			PotencialHand[1] = RemDeck[j];
			if (GameProcess::card::FullHouse(PotencialHand, Ntable, opencard) > a) {
				win += 1;
			}
		}
	}
	delete[] Ntable;
	return win / allcombo;
}

float AI::KareChance(GameProcess::card* RemDeck, GameProcess::card* table, int a, int n, int opencard) {
	float allcombo = n * (n - 1) / 2;
	float win = 0;
	GameProcess::card PotencialHand[2];
	GameProcess::card* Ntable = new GameProcess::card[opencard];
	for (int i = 0; i < opencard; i++) {
		Ntable[i] = table[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			PotencialHand[0] = RemDeck[i];
			PotencialHand[1] = RemDeck[j];
			if (GameProcess::card::Kare(PotencialHand, table, opencard) > a) {
				win += 1;
			}
		}
	}
	delete[] Ntable;
	return win / allcombo;
}

float AI::StritFlashChance(GameProcess::card* RemDeck, GameProcess::card* table, int a, int n, int opencard) {
	float allcombo = n * (n - 1) / 2;
	float win = 0;
	GameProcess::card* Ntable = new GameProcess::card[opencard];
	for (int i = 0; i < opencard; i++) {
		Ntable[i] = table[i];
	}
	GameProcess::card PotencialHand[2];
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			PotencialHand[0] = RemDeck[i];
			PotencialHand[1] = RemDeck[j];
			if (GameProcess::card::StritFlash(PotencialHand, Ntable, opencard) > a) {
				win += 1;
			}
		}
	}
	delete[] Ntable;
	return win / allcombo;
}

float AI::FlashRoyaleChance(GameProcess::card* RemDeck, GameProcess::card* table, int a, int n, int opencard) {
	float allcombo = n * (n - 1) / 2;
	float win = 0;
	GameProcess::card PotencialHand[2];
	GameProcess::card* Ntable = new GameProcess::card[opencard];
	for (int i = 0; i < opencard; i++) {
		Ntable[i] = table[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			PotencialHand[0] = RemDeck[i];
			PotencialHand[1] = RemDeck[j];
			if (GameProcess::card::FlashRoyale(PotencialHand, Ntable, opencard) > a) {
				win += 1;
			}
		}
	}
	delete[] Ntable;
	return win / allcombo;
}

void AI::EqualizeBet(int& botcap, int& botbet,int playbet) {
	int b = -botbet + playbet;
	if (botcap - b < 0) {
		b = botcap;
		botbet += b;
		botcap -= b;
	}
	else {
		botbet += b;
		botcap -= b;
	}
	return;
}
void AI::BotBet(int& botcap, int& botbet, int agressive_count, int playbet) {
	
	if (botbet + 50 * agressive_count < playbet) {
		AI::EqualizeBet(botcap, botbet, playbet);
		return;
	}
	if (botcap - 50 * agressive_count >=0) {


		botcap -= 50 * agressive_count;
		botbet += 50 * agressive_count;
	}
	else {
		AI::EqualizeBet(botcap, botbet, playbet);
	}
	
}
void AI::Fold(int &botcap, int &botbet, int& playcap, int& playbet, int& opencard, int& WhoBlind, bool& fold_check) {
	fold_check = true;
	
     if(WhoBlind){
		WhoBlind = 0;
	}
	else {
		WhoBlind = 1;
	}
	if (botbet == 0) {
		playcap += playbet;
		playbet = 0;
	}
	GameProcess::card::BetCharge(botcap, botbet, playcap, playbet, 1);
	return;
}
void AI::AIBet(int& botcap, int& botbet, int& playcap, int& playbet, int opencard, GameProcess::card* hand, GameProcess::card* table, int& WhoBlind, bool& fold_check) {
	//std::this_thread::sleep_for(std::chrono::seconds(1)); 
	int (*combination[9])(GameProcess::card * hand, GameProcess::card * table, int n) = { GameProcess::card::Pair, GameProcess::card::TwoPairs, GameProcess::card::Set,
		GameProcess::card::Strit, GameProcess::card::Flash, GameProcess::card::FullHouse, 
		GameProcess::card::Kare,GameProcess::card::StritFlash, GameProcess::card::FlashRoyale };
	float (*chances[9])(GameProcess::card * RemDeck, GameProcess::card * table, int a, int n, int opencard) = { AI::PairChance, AI::TwoPairsChance, AI::SetChance, 
		AI::StritChance, AI::FlashChance, AI::FullHouseChance, AI::KareChance, AI::StritFlashChance, AI::FlashRoyaleChance };
	
	int wincombo[9]{}; //если вдруг уже собрана комбинация
	float realchances[9]{};
	float agressive_count = 0;//то, на сколько будет умножаться на 50 при ставке
	
	GameProcess::card card1 = hand[0], card2 = hand[1];
	for (int i = 0; i < 9;i++) {
		wincombo[i] = combination[i](hand, table, opencard);

	}
	if (opencard != 0) {
		GameProcess::card* RemDeck = new GameProcess::card[50 - opencard]; //Оставшиеся карты
		GameProcess::card* BadCards = new GameProcess::card[2 + opencard]; // Известные боту карты
		std::this_thread::sleep_for(std::chrono::seconds(1));
		BadCards[0] = hand[0];
		BadCards[1] = hand[1];
		for (int i = 2; i < opencard + 2; i++) {
			BadCards[i] = table[i-2];
		}
		int n = 50 - opencard;
		bool flag;
		GameProcess::card Karta;
		int i = 0, count = 0;
		while (i < 52) {//Заполнение колоды
			flag = true;
			Karta.set_suit(i / 13);
			Karta.set_value((i % 13) + 2);
			for (int g = 0; g < 2 + opencard; g++) {
				if (Karta.get_value() == BadCards[g].get_value() && Karta.get_suit() == BadCards[g].get_suit()) {
					flag = false;
					count += 1;
					break;
				}
			}
			if (flag) {
				RemDeck[i - count] = Karta;
			}
			i += 1;
		}
		for (int i = 0; i < 9;i++) {
			realchances[i] = ((100- (chances[i](RemDeck, table, wincombo[i], n, opencard) * 100)));
			wincombo[i] = combination[i](hand, table, opencard);
			

		}
		delete[] RemDeck;
		delete[] BadCards;
		if (opencard == 3) {//На данный момент можно сделать вывод только о следующих комбинациях: Пара(0), две пары(1), сет(2), максимум стрит(3) и флэш(4)
			int random = rand() % 4;
			int bluf_or_not = rand() % 5;//Шанс на блеф 20
			bool poor_player = false;
			if ((botcap - playcap >= 300) && (botcap - playcap <= 500)) {
				agressive_count += 0, 5;
				bluf_or_not = rand() % 7;//шанс на блеф 42
			}
			else if (botcap - playcap >= 500) { //шанс на блеф 60
				agressive_count += 1,5;
				poor_player = true;
				bluf_or_not = rand() % 10;
			}
			if (wincombo[1] >0 || wincombo[2]>0 || wincombo[3] > 0 || wincombo[4] > 0) {//Если уже собран стрит, флэш, сет или две пары
				bluf_or_not = rand() % 10;
				agressive_count += 2, 5;
			}
			if (playbet >= 300) {
				if (agressive_count >= 2) {
					if (bluf_or_not > 4) {
						AI::EqualizeBet(botcap, botbet, playbet);
						return;
					}
					else {
						AI::BotBet(botcap, botbet, random + agressive_count, playbet);
						return;
					}
					
				}
				else {
					if (bluf_or_not > 4) {
						AI::EqualizeBet(botcap, botbet, playbet);
						return;
					}
					else {
						AI::Fold(botcap, botbet, playcap, playbet, opencard, WhoBlind, fold_check);
						return;
					}
				}
			}
			if (agressive_count >= 2, 5) {
				if (poor_player && bluf_or_not < 4) {
					AI::BotBet(botcap, botbet, agressive_count + random, playbet);
					return;
				}
				else if (poor_player) {
					if (bluf_or_not >= 4) {
						AI::EqualizeBet(botcap, botbet, playbet);
						return;
					}
					else {
						AI::BotBet(botcap, botbet, agressive_count, playbet);
						return;
					}
				}
			}
			//Если есть шанс собрать что-то вкусненькое
			for (int i = 1; i < 4;i++) {//Исправил
				if (realchances[i] > (100 / agressive_count - agressive_count * 9)) {
					if (bluf_or_not) {
						AI::EqualizeBet(botcap, botbet, playbet);
						return;
					}
					else {
						AI::BotBet(botcap, botbet, agressive_count + i - 2, playbet);
						return;
					}
				}
			}
			//Предположим, есть пара
			if (wincombo[0] != 0) {
				if (poor_player) {
					AI::BotBet(botcap, botbet, agressive_count + random, playbet);
					return;
				}
				else {
					EqualizeBet(botcap, botbet, playbet);
					return;
				}
				if (wincombo[0] >= 9) {
					AI::BotBet(botcap, botbet, agressive_count + random, playbet);
					return;
				}
				else {
					if (random >=2) {
						AI::EqualizeBet(botcap, botbet, playbet);
						return;
					}
					else {
						AI::BotBet(botcap, botbet, agressive_count, playbet);
						return;
					}
				}
			}
			else if (wincombo[0] == 0 && playbet >= 200) {
				if (bluf_or_not > 2) {
					AI::EqualizeBet(botcap, botbet, playbet);
					return;
				}
				else {
					AI::Fold(botcap, botbet, playcap, playbet, opencard, WhoBlind, fold_check);
					return;
				}
			}
			//Если комбинаций нет
			if (agressive_count <= 1, 5) {
				if (playbet - botbet >= 150) {
					if (poor_player || bluf_or_not>4) {
						AI::EqualizeBet(botcap, botbet, playbet);
						return;
					}
					else if (bluf_or_not == 7){
						AI::BotBet(botcap, botbet, 4, playbet);
						return;
					}
				}
				else {
					AI::EqualizeBet(botcap, botbet, playbet);
					return;
				}
			}
			AI::EqualizeBet(botcap, botbet, playbet);
			return;
			
		}
		else if (opencard == 4) {
			
			int random = rand() % 4;
			int bluf_or_not = rand() % 5;//Шанс на блеф 20
			bool poor_player = false;
			if (playbet <= 200 && playcap <= 600) {
				agressive_count += 1;
			}
			if ((botcap - playcap >= 300) && (botcap - playcap <= 500)) {
				agressive_count += 1,5;
				bluf_or_not = rand() % 7;//шанс на блеф 42
			}
			else if (botcap - playcap >= 500) { //шанс на блеф 60
				agressive_count += 2;
				poor_player = true;
				bluf_or_not = rand() % 10;
			}
			if (wincombo[2] > 0 || wincombo[3] > 0 || wincombo[4] > 0) {
				bluf_or_not = rand() % 7;
				agressive_count += 2;
			}
			if (playbet >= 450) {
				if (agressive_count >= 2,5) {
					if (bluf_or_not > 4) {
						AI::EqualizeBet(botcap, botbet, playbet);
						return;
					}
					else {
						AI::BotBet(botcap, botbet, random + agressive_count, playbet);
						return;
					}

				}
				else {
					if (bluf_or_not > 5) {
						AI::EqualizeBet(botcap, botbet, playbet);
						return;
					}
					else {
						AI::Fold(botcap, botbet, playcap, playbet, opencard, WhoBlind, fold_check);
						return;
					}
					
				}
			}
			//Если уже собрана идеальная рука
			for (int i = 8; i >= 5; i--) {
				if (wincombo[i] > 0) {
					if (bluf_or_not) {
						if (random > 2) {
							AI::EqualizeBet(botcap, botbet, playbet);
							return;
						}
						else {
							AI::BotBet(botcap, botbet, 3+random, playbet);
							return;
						}
					}
					else {
						AI::BotBet(botcap, botbet, 5+random, playbet);
						return;
					}
				}
			}
			//Если собрана хорошая рука
			if (agressive_count >= 2, 5) {
				if (poor_player && bluf_or_not < 4) {
					AI::BotBet(botcap, botbet, agressive_count + random, playbet);
					return;
				}
				else if (poor_player) {
					if (bluf_or_not >= 4) {
						AI::EqualizeBet(botcap, botbet, playbet);
						return;
					}
					else {
						AI::BotBet(botcap, botbet, agressive_count, playbet);
						return;
					}
				}
			}
			//Если есть шанс собрать что-то вкусненькое UPD Это не так работает, олух. БЕЗДАРЬ! ОГУЗОК! ОГРЫЗОК! ДАРМОЕД! Шеф, ну нафига вообще эти этикетки снимать?
			//Для баланса вселенной, ведь где-то в Африке есть такой же огузок, как и ты, который приклеееивает эти этикетки
			for (int i = 1; i <4 ;i++) {//Исправил
				if (realchances[i] > (100 / agressive_count - agressive_count * 9) && wincombo[0]!=0) {
					if (bluf_or_not) {
						AI::EqualizeBet(botcap, botbet, playbet);
						return;
					}
					else {
						AI::BotBet(botcap, botbet, agressive_count + i - 2, playbet);
						return;
					}
				}
			}
			//Предположим, есть хорошая пара или две
			if (wincombo[0] >= 9 || wincombo[1]!=0) {
				if (poor_player) {
					AI::BotBet(botcap, botbet, agressive_count + random, playbet);
					return;
				}
				else {
					EqualizeBet(botcap, botbet, playbet);
					return;
				}
				if (wincombo[0] >= 9) {
					AI::BotBet(botcap, botbet, agressive_count + random, playbet);
					return;
				}
				else {
					if (random >= 2) {
						AI::EqualizeBet(botcap, botbet, playbet);
						return;
					}
					else {
						AI::BotBet(botcap, botbet, agressive_count, playbet);
						return;
					}
				}
			}
			//Если комбинаций нет
			if (agressive_count <= 1, 5) {
				if (playbet - botbet >= 150) {
					if (poor_player || bluf_or_not > 4) {
						AI::EqualizeBet(botcap, botbet, playbet);
						return;
					}
					else if (bluf_or_not == 6) {
						AI::BotBet(botcap, botbet, 6, playbet);
						return;
					}
					else {
						AI::Fold(botcap, botbet, playcap, playbet, opencard, WhoBlind, fold_check);
						return;
					}
				}
				else {
					if (random % 3 == 0) {
						AI::EqualizeBet(botcap, botbet, playbet);
						return;
					}
					else {
						AI::BotBet(botcap, botbet, random + 2, playbet);
						return;
					}
				}
			}
			AI::EqualizeBet(botcap, botbet, playbet);
			return;

		}
		else if (opencard == 5) {
			int random = rand() % 4;
			int bluf_or_not = rand() % 5;//Шанс на блеф 20
			bool poor_player = false;
			//пора играть агрессивно
			if (playbet <= 200 && playcap <= 600) {
				agressive_count += 1;
			}
			if ((botcap - playcap >= 300) && (botcap - playcap <= 500)) {
				agressive_count += 1, 5;
				bluf_or_not = rand() % 6;
			}
			else if (botcap - playcap >= 500) { //шанс на блеф 20;
				agressive_count += 2,5;
				poor_player = true;
				bluf_or_not = rand() % 5;
			}

			//Если уже собрана идеальная рука
			for (int i = 8; i >= 4; i--) {
				if (wincombo[i] > 0) {
					if (playcap - playbet <=400) {
						AI::BotBet(botcap, botbet, i, playbet);
						return;
					}
					else if(bluf_or_not >4) {
						AI::BotBet(botcap, botbet, i -2, playbet);
						return;
					}
					else {
						AI::BotBet(botcap, botbet, i+random-3, playbet);
						return;
					}
				}
			}
			if (wincombo[2] >= 9 || wincombo[3] > 0 || wincombo[4] > 0) {
				agressive_count += 2;
			}
			if (playbet >= 500 && agressive_count < 2) {
				if (bluf_or_not == 7) {
					AI::BotBet(botcap, botbet, 10 + random, playbet);
					return;
				}
				else {
					AI::Fold(botcap, botbet, playcap, playbet, opencard, WhoBlind, fold_check);
					return;
				}
			}
			//Если собрана хорошая рука
			if (agressive_count >= 2, 5) {
				if (poor_player) {
					AI::BotBet(botcap, botbet, agressive_count + random+2, playbet);
					return;
				}
				else {
					AI::BotBet(botcap, botbet, agressive_count + random, playbet);
					return;
				}
			}
			if (playbet - botbet >= 200) {
				if (realchances[2] >= 50 && wincombo[2]!=0) {
					AI::BotBet(botcap, botbet, 3+random, playbet);
					return;
				}
				else if ((realchances[1] >= 60) && wincombo[1]!=0) {
					AI::BotBet(botcap, botbet, 2 + random, playbet);
					return;
				}
				else{
					AI::Fold(botcap, botbet, playcap, playbet, opencard, WhoBlind, fold_check);
					return;
				}
			}
			AI::EqualizeBet(botcap, botbet, playbet);
			return;
		}
		

	}
	else {
		int random = rand() % 4;
		int sum_value = card1.get_value() + card2.get_value();
		bool poor_player = false;
		if ((botcap - playcap >= 300) && (botcap - playcap <= 500)){
			agressive_count += 0, 5;
		}
		else if (botcap - playcap >= 500) {
			agressive_count += 1,5;
			poor_player = true;
		}
		if (card1.get_suit() == card2.get_suit()) { agressive_count += 0,5; }
		if (sum_value >= 22) {
			agressive_count += 1, 5;
		}
		else if (sum_value >= 18) {
			agressive_count += 1;
		}
		else if (sum_value >= 10) {
			agressive_count += 0, 5;
		}
		if (playbet == botbet) {
			if (agressive_count <= 1) { AI::EqualizeBet(botcap, botbet, playbet); }
			else if (agressive_count >= 2, 5) {
				if (poor_player) {
					AI::BotBet(botcap, botbet, agressive_count, playbet);
					return;
				}
				else {
					AI::EqualizeBet(botcap, botbet, playbet);
					return;
				}
			}
			else {
				AI::EqualizeBet(botcap, botbet, playbet);
				return;
			}
		}
		else if (playbet >= 150) {//Игрок агрессивен на начальном этапе
			
			if (agressive_count >= 2) {
				if (poor_player) {
					AI::BotBet(botcap, botbet, 3 + random, playbet);
					return;
				}
				else {
					AI::EqualizeBet(botcap, botbet, playbet);
					return;
				}
			}
			else if (botcap - playcap >= -1000) {
				AI::EqualizeBet(botcap, botbet, playbet);
				return;
			}
			else {
				AI::Fold(botcap, botbet, playcap, playbet, opencard, WhoBlind, fold_check);
				return;
			}
		}
		else if (playbet < 150) {
			AI::EqualizeBet(botcap, botbet, playbet);
			return;
		}
		else {
			AI::Fold(botcap, botbet, playcap, playbet, opencard, WhoBlind, fold_check);
			return;
		}
		AI::EqualizeBet(botcap, botbet, playbet);
		return;
	}
}













