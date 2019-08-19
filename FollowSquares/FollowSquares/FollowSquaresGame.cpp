#include "FollowSquaresGame.h"
#include "Square.h"
#include <thread>
#include <chrono>
#include <time.h>

bool FollowSquaresGame::OnUserCreate()
{
  srand((int)time(NULL));
  setupSquares();
  return true;
}

/// Main game loop.
bool FollowSquaresGame::OnUserUpdate(float fElapsedTime)
{
  // If space was pressed this frame, move!
  if (m_keys[VK_SPACE].bPressed) movePieces();

  drawToScreen();
  // sleep for 10ms, no need to run at a bajillion frames per second.
  this_thread::sleep_for(chrono::milliseconds(10));
  return true;
}

void FollowSquaresGame::movePieces()
{
  for (unsigned int i = 0; i < _squares.size(); i++)
  {
    // Create a simply named reference to _squares[i]
    // If it's not a reference you'll be editing a copy, not changing the original.
    Square& square = _squares[i];
    if (i == 0)  // Move the leading (black) square: increment x by 1, y increments a random from -1 to 1
    {
      int newY = square.location.yGrid + (-1 + (rand() % 3));
      if (newY == ScreenHeight()) newY = 0;
      if (newY < 0) newY = ScreenHeight()-1;

      int newX = square.location.xGrid + 1;
      if (newX == ScreenWidth()) newX = 0;

      square.MoveTo(newX, newY);
    } else
    {
      // Move square i square i-1's oldLocation. 3 follows 2, 2 follows 1 etc. 
      square.MoveTo( _squares[i-1].oldLocation.xGrid, _squares[i - 1].oldLocation.yGrid);
    }
  }
}

/// Draw our snake game to screen in current state
void FollowSquaresGame::drawToScreen()
{
  //  Clear the screen with ground colour
  Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_SOLID, GROUND_COLOUR);

  drawTitle(0);

  for (unsigned int i = 0; i < _squares.size(); i++)
  {
    // a reference (&) to _squares[i] saves us having [i] cluttering up the call to Draw. Less confusing to read.
    Square& square = _squares[i]; 
    Draw(square.location.xGrid, square.location.yGrid, PIXEL_SOLID, square.colour);
  }
}

/// Draw KRGB dramatically at top of screen starting from xStart
void FollowSquaresGame::drawTitle(int xStart)
{
  DrawString(xStart, 0, L"K", BG_BLACK | FG_WHITE);
  DrawString(xStart + 1, 0, L"R", BG_RED | FG_WHITE);
  DrawString(xStart + 2, 0, L"G", BG_GREEN | FG_WHITE);
  DrawString(xStart + 3, 0, L"B", BG_BLUE | FG_WHITE);
  DrawString(xStart + 4, 0, L"Y", BG_YELLOW | FG_WHITE);
}

/// Sets colours and starting places for each square
void FollowSquaresGame::setupSquares()
{
  // Add black, red, green and blue squares to _squares vector.
  _squares.push_back(Square(8, 2, FG_BLACK));
  _squares.push_back(Square(6, 4, FG_RED));
  _squares.push_back(Square(4, 3, FG_GREEN));
  _squares.push_back(Square(2, 2, FG_BLUE));
  _squares.push_back(Square(0, 3, FG_YELLOW));
}

// Constructor/Destructor

FollowSquaresGame::FollowSquaresGame()
{
}

FollowSquaresGame::~FollowSquaresGame()
{
}
