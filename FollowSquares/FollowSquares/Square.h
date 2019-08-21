#pragma once
#include "GridLocation.h"

class Square
{
public:

  int colour = 0;
  GridLocation location;
  GridLocation oldLocation;
  Square * leader_p;


  void Move();
  void MoveTo( int x, int y );

  // Constructor and Destructor
  Square(int x, int y, int colour);
  ~Square();
};

