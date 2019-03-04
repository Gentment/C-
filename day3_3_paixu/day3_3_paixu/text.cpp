#include<iostream>

using namespace std;

//√∞≈›≈≈–Ú
void BubbleSort(int *arr,int n)
{
	int flag = 1;
	for (int i = 0; i < n; i++)
	{
		flag = 0;
		for (int j = i+1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}


void SelectSort(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i+1; j < n; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}

		if (min != i)
		{
			swap(arr[min], arr[i]);
		}
	}
}

void InsertSort(int *arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		int temp = arr[i];
		int j = i;
		while (j > 0 && arr[j-1] > temp)
		{
			arr[j] = arr[j-1];
			j--;
		}
		if (j != i)
		{
			arr[j] = temp;
		}
	}
}


void ShellSort(int *arr, int n)
{
	int gap = 1;
	while (gap < n)
	{
		gap = gap * 3 + 1;
	}

	while (gap > 0)
	{
		for (int i = 0; i < n; i++)
		{
			int temp = arr[i];
			int j = i - gap;
			while (j>=0&&arr[j]>temp)
			{
				arr[gap + j] = arr[j];
				j -= gap;
			}
			arr[gap + j] = temp;
		}
		gap /= 3;
	}
}

int main()
{
	//int arr[10] = { 9,5,6,7,8,1,3,2,4,0 };

	//BubbleSort(arr, 10);

	
	
	int arr[10] = { 9,5,6,7,8,1,3,2,4,0 };
	ShellSort(arr, 10);

	for (size_t i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}