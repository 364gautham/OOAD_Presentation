#include "square.h"

Shape* new_Square(const char* String){
	Square* SqObj;
	Shape* Obj;
	Obj = new_Shape(String);	//calling base class construtor
	//allocating memory
	SqObj = (Square*)malloc(sizeof(Square));
	if (SqObj == NULL)	{
		Obj->Delete(Obj);
		return NULL;
	}
	Obj->DerivedObj = SqObj; //pointing to derived object

	//initialising derived class members
	SqObj->String = (char*)malloc(sizeof(char)*(strlen(String)+1));
	strcpy(SqObj->String, String);



	//Changing base class interface to access derived class functions
	Obj->Delete = delete_Square;			//Shape destructor pointing to destrutor of Square
	Obj->Display = Square_DisplayInfo;

	return Obj;
}

void delete_Square(Shape* const ShapeObj)
{
	Shape* Sqobj;
	Sqobj = ShapeObj->DerivedObj;
	//destroy derived obj
	free(Sqobj->String);
	free(Sqobj);
	//destroy base Obj
	delete_Shape(ShapeObj);
}

void Square_DisplayInfo(Shape* const ShapeObj)
{
  Square* Sqobj;
	//displaying Shape info
	//Shape_DisplayInfo(ShapeObj);
	Sqobj = ShapeObj->DerivedObj;
	//displaying Square Instance specific info
	printf("I am a: %s\n", Sqobj->String);
}
