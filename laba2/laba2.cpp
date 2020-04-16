
#include <iostream>
#include <math.h>

using namespace std;

int f1(int* m, int n)
{
	int p = n - 1;
	for (int i = p; i >= 0; i--)
		cout << m[i] << " ";

	return 0;
}


int main()
{
	int n = 0;
	cout << "N = ";
	cin >> n;
	int* m = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> m[i];
	}
	f1(m, n);
	cout << endl;

	system("pause");
}