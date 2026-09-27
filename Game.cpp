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

enWinner WhoWonTheGame(short Player1Wintimes, short ComputerWintimes)
{
	if (Player1Wintimes > ComputerWintimes)
		return enWinner::Player1;
	else if (ComputerWintimes > Player1Wintimes)
		return enWinner::Computer;
	else
		return enWinner::Draw;
}

string WinnerName(enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::Player1:
		return "Player1";
	case enWinner::Computer:
		return "Computer";
	case enWinner::Draw:
		return "Draw";
	}
}

string ChoiceName(enGameChoice GameChoice)
{
	switch (GameChoice)
	{
		case enGameChoice::Stone:
		return "Stone";
		case enGameChoice::Paper:
		return "Paper";
		case enGameChoice::Scissors:
		return "Scissors";
	}
}

void PrintRoundResults(stRoundInfo RoundInfo)
{
	cout << "\n_______________ Round [" << RoundInfo.RoundNumber << "] _______________\n\n";
	cout << "Player1 Choice: " << ChoiceName(RoundInfo.Player1Choice) << endl;
	cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner   : [" << RoundInfo.WinnerName << "]\n";
	cout << "_________________________________________\n" << endl;
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
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

		if (RoundInfo.Winner == enWinner::Player1)
			Player1Wintimes++;
		else if (RoundInfo.Winner == enWinner::Computer)
			ComputerWintimes++;
		else
			Drawtimes++;

		PrintRoundResults(RoundInfo);
	}
	return { HowManyRounds, Player1Wintimes, ComputerWintimes, Drawtimes, WhoWonTheGame(Player1Wintimes, ComputerWintimes), WinnerName(WhoWonTheGame(Player1Wintimes, ComputerWintimes)) };
}