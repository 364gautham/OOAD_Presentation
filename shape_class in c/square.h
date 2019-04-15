#include "shape.h"
#include <string.h>
#include <stdio.h>

typedef struct _Square
{
	Shape* BaseObj;
	char* String;
}Square;

Shape* new_Square(const char* String);	//constructor
void delete_Square(Shape* const ShapeObj);	//destructor

void Square_DisplayInfo(Shape* const ShapeObj);
