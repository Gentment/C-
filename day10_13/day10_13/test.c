// write your code here
#define _CRT_SECURE_NO_WARNINGS 0
#include<stdio.h>
int getDayNum(int month, int day)
{

	int s1 = 1, n = 1, s2, k;
	while (s1 <= 62)
	{
		s1 += n;
		n++;
	}//n为两个月总共要停电的天数 

	s2 = 1;
	k = 1;
	while (s2 <= (month - 7) * 31 + day)
	{
		s2 += k;
		k++;
	}//k为 Redraiment回到家时已停电的天数 


	return (n - k); //n-k为剩下还要停的天数 

}
//
//int main()
//{
//	char arr[10] = { 0 };
//	scanf("%s", arr);
//	int month = (int)arr[0]-'0';
//	int day =  0;
//	if (arr[3])
//	{
//		day = ((int)arr[2] - '0') * 10 + (int)arr[3] - '0';
//	}else
//	{
//		day = (int)arr[2]-'0';
//	}
//	printf("%d  %d\n", month, day);
//	int ret = getDayNum(month, day);
//	printf("%d\n", ret);
//
//	return 0;
//}

//int main()
//{
//	int month;
//	int day;
//	scanf("%d%d", &month, &day);
//	int ret = getDayNum(month, day);
//	printf("%d\n", ret);
//	return 0;
//}


int add(int a, int b)
{
	return  (b == 0) ?a: add(a^b, (a&b) << 1);

	/*
	if(b == 0)
		return a;
	else
	return add(a^b,(a&b)<<1);
	
	*/
}

int negtive(int n)
{
	return add(~n,1);
}
int Sub(int a, int b)
{
	return add(a, negtive(b));
}
//


int getSign(int n)
{
	return n >> 31;
}

int PosAbs(int n)
{
	return (getSign(n) & 1) ? negtive(n) : n;
}

int Mul(int a, int b)
{
	int flag = 0; // 
	if (getSign(a) ^ getSign(b))
		flag = 1;

	a = PosAbs(a);
	b = PosAbs(b);

	int res = 0;
	while (b | 0)
	{
		if (b & 1)
		{
			res = add(res, a);
		}
		a = a << 1;
		b = b >> 1;
	}

	return flag == 1 ? negtive(res) : res;
}

int Div(int a, int b)
{
	if (b == 0)
	{
		return 0;
	}
	int falg = 0;
	if (getSign(a) ^ getSign(b))
		falg = 1;
	a = PosAbs(a);
	b = PosAbs(b);

	int res = 0;
	while (a>=b)
	{
		res = add(res, 1);
		a = Sub(a, b);
	}
	return falg == 1 ? negtive(res) : res;
}


int main()
{

	int a = 10;
	int b = 2;

	int ad = add(a, b);
	printf("add:%d\n", ad);
	int su = Sub(a, b);
	printf("Sub:%d\n", su);
	int mu = Mul(a, b);
	printf("Mul:%d\n", mu);
	int di = Div(a, b);
	printf("Div:%d\n", di);
	return 0;
}