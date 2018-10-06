#define _CRT_SECURE_NO_WARNINGS 0
 #include<stdio.h>


//整形：123456


int add(int a , int b)
{
	return a + b;
}


int sum(int a ,int b)
{
	int c = a + b;
	int ret = add(a,b);


	return 0;
}


int div(int a,int b)
{
	int c = a - b;
	return c;
}


int main()
{

	// 求和

	//int ret = sum(1, 2);

	//int n = div(5,3);
	//printf("%d \n", n);

	//printf("%d\n",ret);

	//int a = 0;
	//int b = 0;
	//int max = 0;

	//printf("请输入\n");
	//scanf("%d %d",&a,&b);

	//if (a>b)
	//{
	//	max = a;
	//}
	//else
	//{
	//	max = b;
	//}

	//printf("%d\n", max);

	//for (int i = -5; i < 5; i++)
	//{
	//	printf("%d  " ,i);
	//}
	//int i = 0;
	//do
	//{
	//	printf("%d  " ,i);
	//	i++;
	//} while (i <10);


	int arr[10] = {0};
	//int size = sizeof(arr) / sizeof(arr[0]);
	//printf("size: %d\n",size);
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 2;
		//printf("%d  ",arr[i]);
	}

	for (int i = 0; i < 10; i++)
	{		
		printf("%d  ", arr[i]);
	}
	//scanf("%d", &b);

	//if (a > b)  max = a;
	return 0;
}