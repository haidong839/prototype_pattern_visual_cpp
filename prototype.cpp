// prototype.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <map>

using namespace std;
using namespace System;

ref class Shape{
private:
	String^  id;
public:
	String^ type;
	virtual void  draw() = 0;
	virtual Shape^ clone() = NULL;
	String^ getType(){
		return type;
	} 
	String^ getId() {
		return id;
	}  
	void setId(String^ id) {
		this->id = id;
	}

	~Shape(){;}
};


ref class Circle : Shape {
public:
	Circle(){
		type = "Circle";
	}
	virtual void draw() override {
		Console::WriteLine("Inside Circle::draw() method.");
	}
	virtual Shape^ clone() override {
		return gcnew Circle();
	}
};

ref class Square : Shape {
public:
	Square(){
		type = "Square";
	}
	virtual void draw() override {
		Console::WriteLine("Inside Square::draw() method.");
	}
	virtual Shape^ clone() override {
		return gcnew Square();
	}
};

ref class ShapeCache {

private:	
	Circle^  cacheCircle;
	Square^  cacheSquare;
public:
	ShapeCache(){		
		cacheCircle = gcnew Circle();
		cacheCircle->setId("1");
		cacheSquare = gcnew Square;
		cacheSquare->setId("2");
	}

	~ShapeCache(){
		if(cacheCircle) 
			delete cacheCircle;
		if(cacheSquare)
			delete cacheSquare;
	}

	Shape^ getShape(String^ shapeId) {
		
		if(!String::Compare(shapeId, "1"))
			return cacheCircle->clone();
		return cacheSquare->clone();
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	  ShapeCache^ myShapeCache = gcnew ShapeCache;

      Shape^ clonedShape = (Shape^) myShapeCache->getShape("1");
      Console::WriteLine(clonedShape->getType());		

      Shape^ clonedShape2 = (Shape^) myShapeCache->getShape("2");
      Console::WriteLine(clonedShape2->getType());		
	  Console::ReadLine();
	return 0;
}

