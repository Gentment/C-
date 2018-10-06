#include<stdio.h>

#if 0


/*一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。*/

int jumpFloor(int number) {
	if (number == 1)
	{
		return 1;
	}
	int a = 1;
	int b = 1;
	int c = a+b;

	while (number>2)
	{
		a = b; 
		b = c;
		c = a + b;
		number--;
	}
	return c;
}

int jump(int n )
{
	if (n <2)
	{
		return 1;
	}

	return jump(n - 1) + jump(n - 2);
}
#endif // 0

/*一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。*/
/*
f(n) = f(n-1)+f(n-2) + ... +f(1)
f(n-1) = f(n-2)+f(n-3)+ ... f(1)

f(n) = 2*f(n-1)
*/
int jumpFloorII(int number) {
	if (number < 1)
	{
		return 0;
	}
	if (number == 1)
	{
		return 1;
	}

	return 2 * jumpFloorII(number - 1);
}

/*题目描述
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/
int rectCover(int number) {
		if (number <= 3)
			return number;
		int first = 1;
		int second = 2;
		int sum ;
		while (number >= 3)
		{
			sum = first + second;
			first = second;
			second = sum;
			number--;
		}
		return sum;
}



	double power(double base, int exponent)
	{
		double tmp = base;
		for (int i = 1; i < exponent; ++i)
		{
			tmp = tmp * base;
		}
		return tmp;
	}
	double Power(double base, int exponent) {
		

		if (exponent < 0)
		{
			return 1 / power(base, -exponent);
		}
		if (exponent == 0)
			return 1;
		else {
			return power(base, exponent);
		}

	}
	/*求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。*/
int Sum_Solution(int n);
	int i = 0;
	int Sum(int n )
	{
		i = i + n;
		n--;
	return 	Sum_Solution(n);
	
	}
int Sum_Solution(int n) {

	return n==0 ? i : Sum(n);
//	return n == 3 ? 1,2 : 2;
}

/*写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。*/
int Add(int num1, int num2)
{
	return num2== 0 ? num1:Add(num1^num2,(num1&num2)<<1);
}
//int Div(int num1, int num2)
//{
//
//}

/*
void replaceSpace(char *str, int length) {
	if (str == NULL||length<0)
		return;
	int newlength = length;
	for(int i=0;i<newlength;i++)
	{
		while (str[i] == ' ')
		{
			newlength+=2;
			//遇到第一个空格后,就开始把后面的往后移动两个字符的位置
			for (int j = newlength; j > i+2; j--)
			{
				str[j] = str[j - 2];
			}
			str[i++] = '%';
			str[i++] = '2';
			str[i++] = '0';

		}
	}
}
*/
void replaceSpace(char *str, int length)
{
	char *dest = str;	
	int n = 0;	
	for (int i = 0; i < length; i++) 
	{ 
		if (str[i] == ' ')			
			n++;
	}	
	int j = length + n * 2 - 1;	
	for (int i = length - 1; i >= 0; i--) 
	{
		if (dest[i] == ' ')
		{
			str[j--] = '0';
			str[j--] = '2';
			str[j--] = '%'; 
		}
		else
		{
			str[j--] = dest[i];
		}
	}
}
int  NumberOf1(int n) {
	int count = 0;
	while (n)
	{
		count++;
		n = n & (n - 1);
	}
	return count;
}
int main()
{
	printf("%d\n",NumberOf1(-1));
	return 0;
}

#if 0


int main()
{
	char str[20] =  "We Are Happy" ;
	printf("%s\n",str);
//	int length = sizeof(str) / sizeof(str[0]);
//	printf("%d\n", length);
	replaceSpace(str, 20);
	printf("%s\n", str);
//	printf("%d\n", length);

//	printf("%d\n", Div(1, 1));
//	printf("%d\n", Add(1, 1));
//	printf("%d\n", Sum_Solution(3));
//	printf("%f\n", Power(2, -3));
//	printf("%d\n", jumpFloorII(3));
//	printf("%d\n",jump(6));
//	printf("%d\n", rectCover(5));
	return 0;
}
#endif // 0


#if 0


#include"Shape.h"
#include"Circle.h"
#include"Rect.h"
int main()
{
	Shape *shape1 = new Rect(3,4);
	Shape *shape2 = new Circle(3);
	cout << "12324"<<endl;
	shape1->calcArea();
	cout << shape1->calcArea() << endl;
	shape2->calcArea();
	cout << shape2->calcArea() << endl;

	delete shape1;
	delete shape2;

	system("pause");
	return 0;
}

#endif // 0
