#include "shape.h"
#include <string.h>
#include <stdio.h>


typedef struct _Circle Circle;

typedef struct _Circle
{
	Shape* BaseObj;
	char* String;
}Circle;

Shape* new_Circle(const char* String);	//constructor
void delete_Circle(Shape* const ShapeObj);	//destructor

void Circle_DisplayInfo(Shape* const ShapeObj);
