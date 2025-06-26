#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "team.h"  //"string","vector","player"
using namespace std;

class Game
{
public:
	Game();
	int playersPerTeam;
	int maxBalls;
	int totalPlayers;
	std::string players[11];

	bool isFirstInnings;
	Team teamA,teamB;
	Team *battingTeam,*bowlingTeam;
	Player *batsman,*bowler;

	void welcome();
	void showAllPlayers();
	void waitEnter();
	int takeIntegerInput();
	void selectPlayers();
	bool validatePlayer(int);
	void showTeamPlayers();
	void toss();
	void tossChoice(Team);
	void startFirstInnings();
	void initializePlayers();
	void playInnings();
	void bat();
	bool validateInningsScore();
	void showGameScorecard();
	void startSecondInnings();
	void finalScoreBoard(Team *Team);
	void displayMatchSummary();
};

