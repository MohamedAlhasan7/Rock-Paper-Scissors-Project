#include "iostream"
#include "Game.h"
#include "cstdlib"
#include "ctime"
using namespace std;

int RandNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

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

enGameChoice ComputerChoice()
{
	return enGameChoice(RandNumber(1, 3));
}

enWinner WhoWinTheRound(stRoundInfo RoundInfo)
{
	if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
		return enWinner::Draw;

	switch (RoundInfo.Player1Choice)
	{
	case enGameChoice::Stone:
		return (RoundInfo.ComputerChoice == enGameChoice::Paper) ?
			enWinner::Computer : enWinner::Player1;
	case enGameChoice::Paper:
		return (RoundInfo.ComputerChoice == enGameChoice::Scissors) ?
			enWinner::Computer : enWinner::Player1;
	case enGameChoice::Scissors:
		return (RoundInfo.ComputerChoice == enGameChoice::Stone) ?
			enWinner::Computer : enWinner::Player1;
	}
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
		RoundInfo.ComputerChoice = ComputerChoice();
		RoundInfo.Winner = WhoWinTheRound(RoundInfo);
	}
}