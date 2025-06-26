#include "game.h"  //"string","vector","player",'iostream","cstdlib","limits","ctime","unistd.h"

using namespace std;

int main()
{
	Game G;
	G.welcome();

	G.waitEnter();

	G.showAllPlayers();

	G.waitEnter();

	G.selectPlayers();
	G.showTeamPlayers();

	cin.ignore(numeric_limits<streamsize>::max(),'\n');//to clear input buffer
	G.waitEnter();
	G.toss();

	G.startFirstInnings();

	cin.ignore(numeric_limits<streamsize>::max(),'\n');//to clear input buffer
	G.startSecondInnings();
}
