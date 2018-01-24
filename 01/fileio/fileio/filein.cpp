#include <iostream>
#include <fstream>

using namespace std;

void filein()
{
	ifstream input("input.txt");
	if (input.fail())
	{
		cout << "Error: can not open file\n";
		return;
	}

	const int n_data = 10;
	int data[n_data] = { 0, }; // data memory to load
	int i = 0;
	while (!input.eof())
	{
		input >> data[i]; // load data
		++i;
	}
	input.close();
	for (i = 0; i < n_data; ++i) // print data
		cout << data[i] << endl;
}
