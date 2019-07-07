#include<iostream>
using namespace std;
int main()
{
	int arr[] = { 0 };
	int count = 0;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= n - 1; j++)
		{
			if (arr[i] > arr[j])
			{
				count++;
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	cout << count << endl;
	return 0;
}
