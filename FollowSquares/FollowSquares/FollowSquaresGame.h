#pragma once
#include "olcConsoleGameEngineOOP.h"
#include "Square.h"
#include "GridLocation.h"
#include <vector>

class FollowSquaresGame : public olcConsoleGameEngineOOP
{
public:
  const int GROUND_COLOUR = BG_WHITE | FG_WHITE;

	FollowSquaresGame();
	~FollowSquaresGame();

protected:
 
  // Collection of squares.
  vector<Square> _squares;
  
  // My functions to make screen more readable.
  void setupSquares();
	void drawToScreen();
  void drawTitle(int xStart = 1);
  void movePieces();

  // Required functions for olcConsoleGameEngineOOP
  virtual bool OnUserCreate() override;
  virtual bool OnUserUpdate(float fElapsedTime) override;

};

