#include <iostream>
#include <array>
using namespace std;
void main()
{
	array<int, 3> arr1;
	arr1.at(0) = 0;
	arr1[1] = 1;
	arr1[2] = 2;

	const int n = 3;
	array<int, n> arr2;

	for (int i = 0; i < arr2.size(); ++i)
		arr2.at(i) = i + 3;

	for (int i = 0; i < arr1.size(); ++i)
		cout << arr1.at(i) << endl;
	cout << endl;
	for (int i = 0; i < arr2.size(); ++i)
		cout << arr2.at(i) << endl;
	cout << endl;

	cout << arr1.front() << ", " << arr1.back() << endl;
	arr1.swap(arr2);

	for (int i = 0; i < arr1.size(); ++i)
		cout << arr1.at(i) << endl;
	cout << endl;
	for (int i = 0; i < arr2.size(); ++i)
		cout << arr2.at(i) << endl;
	cout << endl;
}