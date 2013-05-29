#include "Singleton.h"

Singleton()* self;

Singleton::Singleton()
{
	//Initialize all your setup variables here
	self = this;
	bigVal = 10;
	password = "This Is the Password";
}

//This is when the Singleton is destroyed
Singleton::~Singleton()
{
	//Put everything that you want killed here
	self = NULL;
}

//Singleton Self Reference
Singleton* Singleton::Instance()
{
	if(self)
		return self;
	else
		return new Instance();
}


/*--------------------------------------------------------------------------------*/
/*-----------------------PUT YOUR METHODS DOWN HERE-------------------------------*/
/*--------------------------------------------------------------------------------*/
void Singleton::MethodOne(int someValue)
{
	//Example method 1
}

char* Singleton::GetString(char* name)
{
	//Example method 2
	return "Return some string";
}

bool Singleton::VerifyNumber(int pin, int input)
{
	//Example Method 3
	if(pin != input)
	{
		return false;
	}
	
	return true;
}