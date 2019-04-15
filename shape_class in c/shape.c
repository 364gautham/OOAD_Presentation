#include "shape.h"


  Shape* new_Shape(const char* String){

	Shape* Obj = NULL;
	//allocating memory
	Obj = (Shape*)malloc(sizeof(Shape));
	if (Obj == NULL)
		return NULL;

	Obj->DerivedObj = Obj; //pointing to itself
	Obj->String = (char*)malloc(sizeof(char)*(strlen(String)+1));
	strcpy(Obj->String, String);

	//Initializing interface for access to functions
	Obj->Delete = delete_Shape;			//destructor pointing to destrutor of itself
	Obj->Display = Shape_DisplayInfo;

	return Obj;
}

void delete_Shape(Shape* const ShapeObj){
	if(ShapeObj!= NULL){
	   free(ShapeObj->String);
	   free(ShapeObj);
	}
}

void Shape_DisplayInfo(Shape* const ShapeObj){
	printf("I am a base: %s \n", ShapeObj->String);
}
