#include  "game.h" //"string","vector","player",'iostream","cstdlib","limits","ctime"
#include <unistd.h>


Game::Game()
{
	playersPerTeam=4;
	maxBalls=6;
	totalPlayers=11;

	players[0]="Rohit";
	players[1]="Hardik";
	players[2]="Virat";
	players[3]="Rishabh";
	players[4]="Sarfaraz";
	players[5]="Sanju";
	players[6]="Shivam";
	players[7]="Axar Patel";
	players[8]="Ravindra";
	players[9]="Kuldeep";
	players[10]="Yuzvendra";

	isFirstInnings=false;
	teamA.name="Team A";
	teamB.name="Team B";
}

void Game::welcome()
{
	cout<<"--------------------------------------------";
	cout<<"\n|***************CRICSID******************|";
	cout<<"\n|                                        |";
	cout<<"\n|\t  VIRTUAL CRICKET\t\t |";
	cout<<"\n------------------------------------------";

	cout<<"\n\n\n\n-------------------------------------------";
	cout<<"\n|*************INSTRUCTIONS****************|";
	cout<<"\n|                                         |";
	cout<<"\n|1.Create 2 teams with 4 players          |";
	cout<<"\n|2.Lead the toss and decide the choice of |";
	cout<<"\n|  your game                              |";
	cout<<"\n|3.Each innings has 6 balls               |";
	cout<<"\n-------------------------------------------";
}

void Game::showAllPlayers()
{
	cout<<"\n\n\n-------------------------------------------";
	cout<<"\n|*************PLAYERS ARE****************|";//INSTRUCTONS
	cout<<"\n-------------------------------------------";

	for(int i=0;i<totalPlayers;i++)
	{
		cout<<"\n\t["<<i<<"]"<<players[i]<<endl;
	}
	cout<<"\n-------------------------------------------";
}

/*void Game::showAllPlayers()
{
	cout<<"\n\n\n\n-------------------------------------------";
	cout<<"\n|*************PLAYERS ARE****************|";//INSTRUCTONS
	cout<<"\n-------------------------------------------";
	cout<<"\n\t"<<players[0]<<endl;
	cout<<"\t"<<players[1]<<endl;
	cout<<"\t"<<players[2]<<endl;
	cout<<"\t"<<players[3]<<endl;
	cout<<"\t"<<players[5]<<endl;
	cout<<"\t"<<players[6]<<endl;
	cout<<"\t"<<players[7]<<endl;
	cout<<"\t"<<players[8]<<endl;
	cout<<"\t"<<players[9]<<endl;
	cout<<"\t"<<players[10]<<endl;
	cout<<"\n-------------------------------------------";
}*/

void Game::waitEnter()
{
	cout << "\n\nPress Enter to continue...";
	while (std::cin.get()!='\n');
}

int Game::takeIntegerInput()
{
	int n;

	while(!(cin>>n))
	{
		cin.clear();//clears input
		cin.ignore(numeric_limits<streamsize>::max(),'\n');//clears input buffer memory
		cout<<"INVALID!\nEnter a VALID INPUT!";
	}
	return n;
}

bool Game::validatePlayer(int index)
{
	int n;
	vector<Player>players;

	players=teamA.players;
	n=players.size();
	for (int i=0;i<n;i++)
	{
		if(players[i].id==index)
		{
			return false;
		}
	}

	players=teamB.players;
	n=players.size();
	for (int i=0;i<n;i++)
	{
		if(players[i].id==index)
		{
			return false;
		}
	}

	return true;
}



void Game::selectPlayers()
{
	cout<<"\n\n\n-------------------------------------------";
	cout<<"\n|********CREATE TEAM(A) & TEAM(B)*********|";//INSTRUCTONS
	cout<<"\n-------------------------------------------";

	cout<<"\n\n\n\n-------------------------------------------";
	cout<<"\n|*************INSTRUCTIONS****************|";
	cout<<"\n|                                         |";
	cout<<"\n| INPUT THE CORRESPONDING NUMBER FOR THE  |";
	cout<<"\n|     SELECTED PLAYER FOR EACH TEAM       |";
	cout<<"\n-------------------------------------------";

	for(int i=0;i<playersPerTeam;i++)
	{
		//TEAM(A)
		teamASelection:
			cout<<endl<<"Select Player "<<i+1<<" for TEAM(A):";

			int playerIndexTeamA=takeIntegerInput();

			if(playerIndexTeamA<0 || playerIndexTeamA>10)
			{
				cout<<"\nPLASE SELECT FROM GIVEN POOL OF PLAYERS!";
				goto teamASelection;
			}
			else if(!validatePlayer(playerIndexTeamA))
			{
				cout<<"\nPLAYER HAS BEEN ALREADY SELECTED!";
				goto teamASelection;
			}
			else
			{
				Player teamAPlayer;
				teamAPlayer.id=playerIndexTeamA;
				teamAPlayer.name=players[playerIndexTeamA];
				teamA.players.push_back(teamAPlayer);
			}

		//TEAM(B)
		teamBSelection:
			cout<<endl<<"Select Player "<<i+1<<" for TEAM(B):";

			int playerIndexTeamB=takeIntegerInput();

			if(playerIndexTeamB<0 || playerIndexTeamB>10)
			{
				cout<<"\nPLASE SELECT FROM GIVEN POOL OF PLAYERS!";
				goto teamBSelection;
			}
			else if(!validatePlayer(playerIndexTeamB))
			{
				cout<<"\nPLAYER HAS BEEN ALREADY SELECTED!";
				goto teamBSelection;
			}
			else
			{
				Player teamBPlayer;
				teamBPlayer.id=playerIndexTeamB;
				teamBPlayer.name=players[playerIndexTeamB];
				teamB.players.push_back(teamBPlayer);
			}
	}
}

void Game::showTeamPlayers()
{
	cout<<"\n\n\n--------------------------\t\t-------------------------";
	cout<<"\n|********TEAM(A)********|\t\t|**********TEAM(B)********|";
	cout<<"\n------------------------\t\t-------------------------";
	for(int i=0;i<playersPerTeam;i++)
	{
		cout<<"\n|\t"<<"["<<i<<"]"<<teamA.players[i].name<<"\t|"
				<<"\t\t"<<"|\t"<<"["<<i<<"]"<<teamB.players[i].name<<"\t|"<<endl;
	}
	cout<<"\n-------------------------\t\t------------------------"<<endl;
}

void Game::toss()
{
	cout<<"\n--------------------------";
	cout<<"\n***********TOSS***********";
	cout<<"\n--------------------------";
	cout<<"\n\nTOSSING THE COIN!\n\n";

	srand(time(NULL));
	int randomValue=rand()%2;

	usleep(5000000);

	switch(randomValue)
	{
		case 0:
			cout<<"TEAM A WON!"<<endl<<endl;
			tossChoice(teamA);
			break;

		case 1:
			cout<<"TEAM B WON!"<<endl<<endl;
			tossChoice(teamB);
			break;
	}
}

void Game::tossChoice(Team tossWinnerTeam)
{
	cout<<"ENTER 1 to BAT or Enter 2 to BOWL\n";
	cout<<"1.BAT\n2.BOWL";

	int choice=takeIntegerInput();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');//to clear input buffer

	switch (choice)
	{
			case 1:
				cout << endl << tossWinnerTeam.name << " won the toss and elected to bat first\n\n";

				if (tossWinnerTeam.name.compare("Team-A") == 0)
				{	 // if Team-A is the toss winner
					battingTeam = &teamA;
					bowlingTeam = &teamB;
				}
				else
				{	// else Team-B is the toss winner
					battingTeam = &teamB;
					bowlingTeam = &teamA;
				}

				break;
			case 2:
				cout << endl << tossWinnerTeam.name << " won the toss and choose to bowl first\n\n";

				if (tossWinnerTeam.name.compare("Team-A") == 0)
				{	// if Team-A is the toss winner
					bowlingTeam = &teamA;
					battingTeam = &teamB;
				}
				else
				{	// else Team-B is the toss winner
					bowlingTeam = &teamB;
					battingTeam = &teamA;
				}

				break;
			default:
				cout << endl << "Invalid input. Please try again:\n\n";
				tossChoice(tossWinnerTeam);
				break;
	}
}

void Game::startFirstInnings()
{
	cout<<"\t\t||FIRST INNINGS||\n\n";

	isFirstInnings=true;

	initializePlayers();
	playInnings();

}

void Game::initializePlayers()
{
	batsman=&battingTeam->players[0];
	bowler=&bowlingTeam->players[0];

	cout<<battingTeam->name<<":"<<batsman->name<<" is Batting\n";
	cout<<bowlingTeam->name<<":"<<bowler->name<<" is Bowling\n";
}

void Game::playInnings()
{
	cin.ignore(numeric_limits<streamsize>::max(),'\n');//to clear input buffer
	for(int i=0;i<maxBalls;i++)
	{
		cout<<"Press Enter to bowl!\n";
		getchar();
		cout<<"BOWLING\n";
		bat();

		if(!validateInningsScore())
		{
			break;
		}
	}
}

void Game::bat()
{
	srand(time(NULL));
	int runsScored=rand()%7;

	//scorecard(batting)
	batsman->runsScored = batsman->runsScored+runsScored;
	battingTeam->totalRunsScored = battingTeam->totalRunsScored+runsScored;
	batsman->ballsPlayed = batsman->ballsPlayed+1;

	//Scorecard(bowling)
	bowler->ballsBowled = bowler->ballsBowled + 1;
	bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled + 1;
	bowler->runsGiven = bowler->runsGiven + runsScored;

	if (runsScored != 0)
	{
		// if runsScored = 1, 2, 3, 4, 5, or 6
	    cout<<endl<<bowler->name<<" to "<<batsman->name<<" "<<runsScored<<" runs!\n\n";
	    showGameScorecard();
	}
	else
	{
		// else runScored = 0 and the batsman is ‘OUT’
		cout<<endl<<bowler->name<<" to "<<batsman->name<<" "<<"OUT\n\n";
	   	battingTeam->wicketsLost = battingTeam->wicketsLost + 1;
	   	bowler->wicketsTaken = bowler->wicketsTaken + 1;

	   	showGameScorecard();

	   	int nextPlayerIndex = battingTeam->wicketsLost;
	   	batsman = &battingTeam->players[nextPlayerIndex];
   }

}

bool Game::validateInningsScore()
{
	if(isFirstInnings)
	{
		if(	battingTeam->wicketsLost== playersPerTeam || bowlingTeam ->totalBallsBowled==maxBalls)
		{
			cout<<"\t\t ||| FIRST INNINGS ENDS ||| \n\n";
			cout<<battingTeam->name<<" "<< battingTeam->totalRunsScored<<" - "<<battingTeam->wicketsLost<< " ("<<bowlingTeam->totalBallsBowled<<")\n";
			cout<<bowlingTeam->name<<" needs "<<battingTeam->totalRunsScored + 1<<" runs to win the match\n\n";
			return false;
		}
	}
	else
	{
		 if (battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls)
		{
			 cout << "\t\t ||| SECOND INNINGS ENDS ||| \n\n";
			 cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - " << battingTeam->wicketsLost<< " (" << bowlingTeam->totalBallsBowled << ")\n";
			 if (battingTeam->totalRunsScored > bowlingTeam->totalRunsScored)
			 {
				 cout << battingTeam->name << " wins the match!\n";
			 }
			 else if (battingTeam->totalRunsScored < bowlingTeam->totalRunsScored)
			 {
		         cout << bowlingTeam->name << " wins the match!\n";
			 }
		     else
		     {
		    	 cout << "The match is a draw!\n";
		     }
			 displayMatchSummary();
			 return false;
		}
	}
	return true;
}

void Game::showGameScorecard()
{
	cout<<"------------------------------------------------------------------------------\n\n";
	 cout << "\t"<<battingTeam->name<<"  "<< battingTeam->totalRunsScored<<" - "<< battingTeam->wicketsLost<<" ("<<bowlingTeam->totalBallsBowled<<") | "<<batsman->name
		<<" "<<batsman->runsScored<<" ("<<batsman->ballsPlayed<<") \t"<<bowler->name<<" "<<bowler->ballsBowled<<" - "<<bowler->runsGiven<<" - "<<bowler->wicketsTaken<<"\n";
	cout<<"------------------------------------------------------------------------------\n\n";
}

void Game::startSecondInnings()
{
	cout << "\t\t||SECOND INNINGS||\n\n";
	isFirstInnings = false;

    // Switch batting and bowling teams for the second innings
	Team *temp = battingTeam;
    battingTeam = bowlingTeam;
    bowlingTeam = temp;

    // Initialize players
    initializePlayers();
    playInnings();
}

void Game::finalScoreBoard(Team *team) {
    cout << team->name << " " << team->totalRunsScored << "-" << team->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ")\n";
    cout << "=====================================\n";
    cout << "| PLAYER    | BATTING    | BOWLING   |\n";
    cout << "-------------------------------------\n";

    for (int i = 0; i < playersPerTeam; i++) {
        Player *player = &team->players[i];
        cout << "| [" << i << "] " << player->name;

        // Adjust spacing for alignment
        if (player->name.length() < 6) cout << "\t";

        // Display batting details
        cout << "    " << player->runsScored << "(" << player->ballsPlayed << ")";

        // Display bowling details
        cout << "     " << player->ballsBowled << "-" << player->runsGiven << "-" << player->wicketsTaken << " |\n";
        cout << "-------------------------------------\n";
    }
    cout << endl;
}

void Game::displayMatchSummary() {
    cout << "\t\t ||| MATCH ENDS |||\n\n";
    finalScoreBoard(battingTeam);  // Print scoreboard of the batting team
    finalScoreBoard(bowlingTeam);  // Print scoreboard of the bowling team
}
