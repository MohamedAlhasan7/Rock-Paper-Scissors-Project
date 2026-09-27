#pragma once

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