#include <iostream>

using namespace std;

/*
实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:

输入: 2.00000, 10
输出: 1024.00000
示例 2:

输入: 2.10000, 3
输出: 9.26100
示例 3:

输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
说明:

-100.0 < x < 100.0
n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。*/
double power(double x, int n)
{
	if (n == 0)
	{
		return 1;
	}
	double half = power(x, n / 2);
	if (n % 2 == 0)
	{
		return half * half;
	}
	return x * half*half;
}
double myPow(double x,int n)
{

	if (n<0)
	{
		return 1 / power(x,-n);
	}
	return power(x, n);
}

int main()
{
	double ret = myPow(2,-1);
	printf("%f\n", ret);
	return 0;
}