#include<stdio.h>
class Test
{
public:
	Test();
	~Test();
	int a = 0;

private:

};

Test::Test()
{
}

Test::~Test()
{
}

int main()
{
	printf("%d\n", sizeof(Test));
	return 0;
}