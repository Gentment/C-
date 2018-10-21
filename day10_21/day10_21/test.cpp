#include<stdio.h>
#include<string.h>
struct Student
{
	void StudentInfo(char name[],int age)
	{
		strcpy(_name,name);
		_age = age;
	}
	
	void StudentPrint()
	{

	}

	char _name[20];
	int _age;
};

int main()
{


}