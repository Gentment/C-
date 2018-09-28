#include<stdio.h>

int sum(int a)
{
	auto int c = 0;
	static int b = 3;
	c += 1;
	b += 2;
	return (a + b + c);
}
int main()
{
	int i;
	int a = 2;
	for (i = 0; i < 5; i++)
	{
		printf("%d,", sum(a));
	}
}



//int FindSubString(char* pch)
//{
//	int   count = 0;
//	char  * p1 = pch;
//	while (*p1 != '\0')
//	{
//		if (*p1 == p1[1] - 1)
//		{
//			p1++;
//			count++;
//		}
//		else {
//			break;
//		}
//	}
//	int count2 = count;
//	while (*p1 != '\0')
//	{
//		if (*p1 == p1[1] + 1)
//		{
//			p1++;
//			count2--;
//		}
//		else {
//			break;
//		}
//	}
//	if (count2 == 0)
//		return(count);
//	return(0);
//}
//void ModifyString(char* pText)
//{
//	char  * p1 = pText;
//	char  * p2 = p1;
//	while (*p1 != '\0')
//	{
//		int count = FindSubString(p1);
//		if (count > 0)
//		{
//			*p2++ = *p1;
//			printf(p2, "%i", count);
//			while (*p2 != '\0')
//			{
//				p2++;
//			}
//			p1 += count + count + 1;
//		}
//		else {
//			*p2++ = *p1++;
//		}
//	}
//}
//void main(void)
//{
//	char text[32] = "XYBCDCBABABA";
//	ModifyString(text);
//	printf(text);
//}
//#include<vector>
//#include<iostream>
//
//class Solution {
//public:
//	vector<vector<int>> threeSum(vector<int>& nums) {
//
//	}
//private:
//	int nums[];
//};
//
//
//vector<vector<int>> threeSum(vector<int>& nums)
//{
//	vector<vector<int>> res;
//	qsort(nums.begin(), nums.end());
//	for (int i = 0; i < nums.size; i++)
//	{
//		if (nums[i] > 0)	break;
//		if (i > 0 && nums[i] == nums[i - 1]) continue;
//		int target = 0 - nums[i];
//		int k = i + 1, j = nums.size() - 1;
//		while (k < j)
//		{
//			if (nums[k] + nums[j] == target)
//		}
//	}
//	return;
//}
//int main()
//{
//	vector<vector<int>> vec;
//	
//	return 0;
//}


//if (a>b)
//{
//	if (a > c)
//	{
//		max = a;
//	}
//}
//else if (b>c)
//{
//	max = b;
//}
//else
//{
//	max = c;
//}
