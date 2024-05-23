
#pragma once
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <thread>
#include <string>
#include <random>
#include <ctime>
#include "GameProcess.h" 
class AI {

public:
	static float PairChance(GameProcess::card* RemDeck, GameProcess::card* table, int a, int n, int opencard);
	static float TwoPairsChance(GameProcess::card* RemDeck, GameProcess::card* table, int a, int n, int opencard);
	static float SetChance(GameProcess::card* RemDeck, GameProcess::card* table, int a, int n, int opencard);
	static float StritChance(GameProcess::card* RemDeck, GameProcess::card* table, int a, int n, int opencard);
	static float FlashChance(GameProcess::card* RemDeck, GameProcess::card* table, int a, int n, int opencard);
	static float FullHouseChance(GameProcess::card* RemDeck, GameProcess::card* table, int a, int n, int opencard);
	static float KareChance(GameProcess::card* RemDeck, GameProcess::card* table, int a, int n, int opencard);
	static float StritFlashChance(GameProcess::card* RemDeck, GameProcess::card* table, int a, int n, int opencard);
	static float FlashRoyaleChance(GameProcess::card* RemDeck, GameProcess::card* table, int a, int n, int opencard);
	static void AIBet(int& botcap, int& botbet, int& playcap, int& playbet, int opencard, GameProcess::card* hand, GameProcess::card* table, int& WhoBlind, bool& fold_check);
	static void EqualizeBet(int& botcap, int& botbet, int playbet);
	static void BotBet(int& botcap, int& botbet, int agressive_count, int playbet);
	static void Fold(int &botcap, int& botbet, int& playcap, int& playbet, int& opencard, int& WhoBlind, bool& fold_check);
private:

	

};

struct combs_help;

bool show_cards();
