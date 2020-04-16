#include <iostream>
#include <math.h>
using namespace std;
float F1(float x)
{
	float result = 0;
	if (x >= 0)
	{
		result = (x * x) + (2 * x) + 1;
	}
	else
	{
		result = abs(x - 9);
	}
	return result;
}
float F2(float& x)
{
	x = F1(x);
	return x;
}
int main() {
	int start = 0;
	cout << "Input start: ";
	cin >> start;
	int stop = 0;
	cout << "Input stop:  ";
	cin >> stop;
	cout << "Function 1: " << endl;
	for (int i = start; i < stop; i++)
	{
		float f = F1(i);
		cout << "i = " << i << "; F1(i) = " << f << endl;
	}
	cout << "Function 2: " << endl;
	for (float i = start; i < stop; i++)
	{
		cout << "i = " << i << "; F2(i) = " << F2(i) << endl;
	}
	system("pause");
	return 0;
}
