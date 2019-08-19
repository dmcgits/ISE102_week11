#include "Square.h"

Square::Square(int x, int y, int colour)
{
  location.xGrid = x;
  location.yGrid = y;
  Square::colour = colour;
}

void 
Square::Move()
{
	return;
}

void
Square::MoveTo(int xNew, int yNew)
{
  // Preserve our current location for followers
  oldLocation.xGrid = location.xGrid;
  oldLocation.yGrid = location.yGrid;    

  // Move to the new spot.
  location.xGrid = xNew;
  location.yGrid = yNew;
	
  return;
}

Square::~Square()
{
}
