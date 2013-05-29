/*HEADER FILE*/

#include <windows.h> //include your own stuff, this is just a reference

class Singleton
{
	public:
		Singleton();
		virtual ~Singleton();
		static Singleton* Instance(); //Refer all calls to the singleton as "Singleton::Instance()->blah"
		
	//Singleton Variables go here (these can be modifed anywhere)
	private:
		int value;
	
	//Singleton Methods go here (no modification, black box approach)
	private:
		void MethodOne(int someValue);
		char* GetString(char* name);
		bool VerifyNumber(int pin, int input);
		
	//Example of structure declerations
	struct someObject
	{
		int bigVal;
		unsigned long uniqueId;
		char name[30];
		CString password;
	};
	
	someObject myArrayObject[300];
	CList<someObject*, someObject*> myListObject;
	
};

/*END OF HEADER FILE*/


