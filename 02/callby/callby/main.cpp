#include <iostream>

using namespace std;

//call by value
void callbyvalue(int _a, int _b)
{
	int tmp = _a;
	_a = _b;
	_b = tmp;
}

//call by pointer
void callbypointer(int* _a, int* _b)
{
	int tmp = *_a;
	*_a = *_b;
	*_b = tmp;
}

//call by reference
void callbyreference(int& _a, int& _b)
{
	int tmp = _a;
	_a = _b;
	_b = tmp;
}
void main()
{
	int a10 = 10;
	int b20 = 20;
	{
		int tmp = a10;
		a10 = b20;
		b20 = tmp;
	}
	cout << "changed in main func" << endl;
	cout << "a10: " << a10 << endl;
	cout << "b20: " << b20 << endl << endl;

	a10 = 10;	// re-initialize
	b20 = 20;
	callbyvalue(a10, b20);   // call by value
	cout << "call by value:" << endl;
	cout << "a10: " << a10 << endl;
	cout << "b20: " << b20 << endl << endl;

	a10 = 10;	// re-initialize
	b20 = 20;
	callbypointer(&a10, &b20);   // call by pointer
	cout << "call by pointer:" << endl;
	cout << "a10: " << a10 << endl;
	cout << "b20: " << b20 << endl << endl;

	a10 = 10;	// re-initialize
	b20 = 20;
	callbyreference(a10, b20);   // call by reference
	cout << "call by reference:" << endl;
	cout << "a10: " << a10 << endl;
	cout << "b20: " << b20 << endl << endl;
}
