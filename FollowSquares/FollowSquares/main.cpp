#include <iostream>
#include "FollowSquaresGame.h"

using namespace std;

int main()
{
	FollowSquaresGame game;

	game.ConstructConsole(20, 6, 48, 48);
	game.Start();
	return 0;
}