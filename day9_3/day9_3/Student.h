#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
	Student();
	~Student();
	void setNmae(string);
	string getName();
	int setAge(int);
	int getAge();
private:
	string m_strName;
	int m_age;
};

void Student::setNmae(string _name)
{
	m_strName = _name;
}
string Student::getName()
{
	return m_strName;
}
int Student::setAge(int age)
{
	return m_age = age;
}

int Student::getAge()
{
	return m_age;
}
Student::Student()
{
}

Student::~Student()
{
}