
#include "shape.h"
#include "circle.h"
#include "square.h"


int main()
{
	// creating objects -calls constructor
	Shape* CircleObj = new_Circle("Circle");
  Shape* SquareObj = new_Square("Square");

 // polymorphism
	CircleObj->Display(CircleObj);
	SquareObj->Display(SquareObj);
//calling destructors
	CircleObj->Delete(CircleObj);
	SquareObj->Delete(SquareObj);

	return 0;
}
