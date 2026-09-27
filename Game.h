#pragma once
#include <string>
using namespace std;

enum enGameChoice
{
	Stone = 1,
	Paper = 2,
	Scissors = 3
};

enum enWinner
{
	Player1 = 1,
	Computer = 2,
	Draw = 3
};

struct stRoundInfo
{
	short RoundNumber = 0;
	enGameChoice Player1Choice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName;
};

struct stGameResults
{
	short GameRounds = 0;
	short Player1Wintimes = 0;
	short ComputerWintimes = 0;
	short Drawtimes = 0;
	enWinner GameWinner;
	string WinnerName;
};

int ReadNumber(string Message);

int RandNumber(int From, int To);

enGameChoice Player1Choice();

enGameChoice ComputerChoice();

enWinner WhoWinTheRound(stRoundInfo RoundInfo);

enWinner WhoWonTheGame(short Player1Wintimes, short ComputerWintimes);

string WinnerName(enWinner Winner);

string ChoiceName(enGameChoice GameChoice);

void PrintRoundResults(stRoundInfo RoundInfo);

void ScreenColor(enWinner Winner);

stGameResults PlayGame(short HowManyRounds);

void StartGame();