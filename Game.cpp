#include "iostream"
#include "Game.h"
using namespace std;

enGameChoice Player1Choice()
{
	int Choice;
	do
	{
		cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
		cin >> Choice;
	} while (Choice < 1 || Choice > 3);
	return enGameChoice(Choice);
}

stGameResults PlayGame(short HowManyRounds)
{
	stRoundInfo RoundInfo;
	short Player1Wintimes = 0;
	short ComputerWintimes = 0;
	short Drawtimes = 0;

	for (int GameRound = 1; GameRound <= HowManyRounds; GameRound++)
	{
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.Player1Choice = Player1Choice();
	}
}