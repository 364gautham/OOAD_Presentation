#include "circle.h"


Shape* new_Circle(const char* String){
	Circle* CircObj;
	Shape* Obj;
	Obj = new_Shape(String);	//calling base class construtor
	//allocating memory
	CircObj = (Circle*)malloc(sizeof(Circle));
	if (CircObj == NULL)	{
		Obj->Delete(Obj);
		return NULL;
	}
	Obj->DerivedObj = CircObj; //pointing to derived object

	//initialising derived class members
	CircObj->String = (char*)malloc(sizeof(char)*(strlen(String)+1));
	strcpy(CircObj->String, String);

	//Changing base class interface to access derived class functions
	Obj->Delete = delete_Circle;			//Shape destructor pointing to destrutor of Circle
	Obj->Display = Circle_DisplayInfo;

	return Obj;
}

void delete_Circle(Shape* const ShapeObj)
{
	Shape* Circobj;
	Circobj = ShapeObj->DerivedObj;
	//destroy derived obj
	free(Circobj->String);
	free(Circobj);
	//destroy base Obj
	delete_Shape(ShapeObj);
}

void Circle_DisplayInfo(Shape* const ShapeObj)
{
	Circle* CircObj;
	//displaying Shape info
	//Shape_DisplayInfo(ShapeObj);
	CircObj = ShapeObj->DerivedObj;
	//displaying Circle Instance specific info
	printf("I am a: %s\n", CircObj->String);
}
