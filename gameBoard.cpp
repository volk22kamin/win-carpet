#include <iostream>

using namespace std;

int main()
{
	// variables definition 
	int nFirstUserX;
	int nFirstUserY;
	int nSecondUserX;
	int nSecondUserY;
	int nUsersChoice;
	int nWinCarpetX;
	int nWinCarpetY;
	int nwinCarpetLength;
	int nAsteristLoop;
	int nFirstPlayerWins = 0;
	int nSecondPlayerWins = 0;
	char AnotherGame;


	// board variables
	int nX;
	int nY;
	int nTurns;
	int nUseCarpetY;
	int nBoardSize = 12;



	// board loop
	
	AnotherGame = 'y';
	while (AnotherGame == 'y' || AnotherGame == 'Y')
	{
		nTurns = 0;
		// getting position from players
		cout << "player number 1 please enter your starting position: " << endl;
		cin >> nFirstUserX;
		cin >> nFirstUserY;
		cout << "player number 2 please enter your starting position: " << endl;
		cin >> nSecondUserX;
		cin >> nSecondUserY;
		cout << "please enter the winning carpet left coordinates(X and Y) and what length :" << endl;
		cin >> nWinCarpetX;
		cin >> nWinCarpetY;
		cin >> nwinCarpetLength;

		while (((nFirstUserX != nWinCarpetX) || (nFirstUserY != nWinCarpetY)) &&
			((nSecondUserX != nWinCarpetX) || (nSecondUserY != nWinCarpetY)))
		{
			// if users choice is out of range of 1 - 10
			if ((nFirstUserX <= 0 || nFirstUserX >= nBoardSize - 1) || (nFirstUserY <= 0 || nFirstUserY >= nBoardSize - 1))
			{
				cout << "1 - you are out of range enter position again: " << endl;
				cin >> nFirstUserX;
				cin >> nFirstUserY;
				nTurns--;
			}
			else if ((nSecondUserX <= 0 || nSecondUserX >= nBoardSize - 1) || (nSecondUserY <= 0 || nSecondUserY >= nBoardSize - 1)||
				(nSecondUserX == nFirstUserX && nSecondUserY == nFirstUserY))
			{
				cout << "2 - you are out of range or the position you chose was taken, enter position again: " << endl;
				cin >> nSecondUserX;
				cin >> nSecondUserY;
				nTurns--;
			}
			else if ((0 > nWinCarpetX || nBoardSize - 1 <= nWinCarpetX) || (0 > nWinCarpetY || nBoardSize - 1 <= nWinCarpetY))
			{
				cout << "please enter the winning carpet left coordinates(X and Y) and what length :" << endl;
				cin >> nWinCarpetX;
				cin >> nWinCarpetY;
				cin >> nwinCarpetLength;
				nTurns--;
			}
			else
			{// if users choice is in range of 1 - 10
				for (nX = 0; nX < nBoardSize; nX++)
				{
					cout << endl;
					for (nY = 0; nY < nBoardSize; nY++)
					{	// if its line 1 or 12
						if ((nX == 0) || (nX == 11))
						{
							cout << "# ";
						}
						else
						{	// if its line 1 or 12
							if ((nY == 0) || (nY == 11))
							{
								cout << "# ";
							}
							// printing the carpet
							else if ((nWinCarpetX == nX) && (nWinCarpetY == nY))
							{
								cout << "* ";
								nUseCarpetY = nWinCarpetY;
								for (nAsteristLoop = 1; nAsteristLoop < nwinCarpetLength; nAsteristLoop++)
								{
									nUseCarpetY++;
									nY++;
									cout << "* ";
								}
							}
							else if ((nFirstUserX == nX) && (nFirstUserY == nY))
							{
								cout << "1 ";
							}
							else if ((nSecondUserX == nX) && (nSecondUserY == nY))
							{
								cout << "2 ";
							}
							else
							{	//the rest of the field
								cout << "_ ";
							}
						}
					}

				}

				// Game logic
				// movement for first user
				// if players move not accupied by the other player
				if (nFirstUserX != nSecondUserX || nFirstUserY != nSecondUserY)
				{
					if (nTurns % 2 == 0)
					{
						//getting first user move
						cout << endl;
						cout << "1 - please enter your move: " << endl;
						cin >> nUsersChoice;

						switch (nUsersChoice)
						{
						case (8):
						{
							nFirstUserX--;
							break;
						}
						case (2):
						{
							nFirstUserX++;
							break;
						}
						case (6):
						{
							nFirstUserY++;
							break;
						}
						case (4):
						{
							nFirstUserY--;
							break;
						}

						default:
						{
							break;
						}
						}
					}
					// if second player move
					else
					{
						//getting second user move
						cout << endl;
						cout << "2 - please enter your move: " << endl;
						cin >> nUsersChoice;

						switch (nUsersChoice)
						{
						case (8):
						{
							nSecondUserX--;
							break;
						}
						case (2):
						{
							nSecondUserX++;
							break;
						}
						case (6):
						{
							nSecondUserY++;
							break;
						}
						case (4):
						{
							nSecondUserY--;
							break;
						}

						default:
						{
							break;
						}
						}
					}
				}
				// if one to go on a taken square
				if (nSecondUserX == nFirstUserX && nSecondUserY == nFirstUserY)
				{
					if (nTurns % 2 == 0)
					{
						switch (nUsersChoice)
						{
						case (8):
						{
							nFirstUserX++;
							break;
						}
						case (2):
						{
							nFirstUserX--;
							break;
						}
						case (6):
						{
							nFirstUserY--;
							break;
						}
						case (4):
						{
							nFirstUserY++;
							break;
						}

						default:
						{
							break;
						}
						}
					}
					else
					{
						switch (nUsersChoice)
						{
						case (8):
						{
							nSecondUserX++;
							break;
						}
						case (2):
						{
							nSecondUserX--;
							break;
						}
						case (6):
						{
							nSecondUserY--;
							break;
						}
						case (4):
						{
							nSecondUserY++;
							break;
						}

						default:
						{
							break;
						}
						}
					}
					cout << endl;
					cout << "this position is taken " << endl;

				}
			}
			nTurns++;
		}
		// winning msg
		if (nTurns % 2 != 0)
		{
			cout << "player 1 won! " << endl;
			nFirstPlayerWins++;
		}
		else
		{
			cout << "player 2 won! " << endl;
			nSecondPlayerWins++;
		}

	// asking to play again
	cout << " would you like to play again? (Y or N) " << endl;
	cin >> AnotherGame;
	}
	// statistics msg
	cout << "1 - player had " << nFirstPlayerWins << " wins" << endl;
	cout << "2 - player had " << nSecondPlayerWins << " wins" << endl;
	if (nFirstPlayerWins > nSecondPlayerWins)
	{
		cout << "1 - player won " << endl;
	}
	else if (nFirstPlayerWins < nSecondPlayerWins)
	{
		cout << "2 - player won " << endl;
	}
	else
	{
		cout << "it's a tie " << endl;
	}

}
/*TO DO: make a rechtangle from the number chosen for the length of the magic carpet */
/*
check a faster way to move a player one step back and not using switch case every time

*/
/*
if ill automaticly take step back when out of range the request of positioning will not appear(i think) 
*/