#ifndef _SHAPE_H
#define _SHAPE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct _Shape Shape;

typedef void	(*fptrDisplayInfo)(Shape*);
typedef void	(*fptrDelete)(Shape*) ;

typedef struct _Shape
{
	void* DerivedObj;
	char* String;
	//function pointer interface to access member functions
	fptrDisplayInfo Display; // display information
	fptrDelete		Delete;
}Shape;

Shape* new_Shape(const char* String);	//constructor
void delete_Shape(Shape* const Shapeobj);	//destructor

void Shape_DisplayInfo(Shape* const ShapeObj);



#endif
