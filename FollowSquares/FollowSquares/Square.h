#pragma once
#include "GridLocation.h"

class Square
{
public:

  int colour = 0;
  GridLocation location;
  GridLocation oldLocation;
  
  void Move();
  void MoveTo( int x, int y );
  
  Square * leader_p;

  // Constructor and Destructor
  Square(int x, int y, int colour);
  ~Square();


};

