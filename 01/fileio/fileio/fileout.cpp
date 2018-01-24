#include <iostream>
#include <fstream>

using namespace std;

void fileout()
{
	const int n_data = 10;
	int data[n_data] = { 0, };
	for (int i = 0; i < n_data; ++i)  // create data
		data[i] = (i+1) * 10;

	ofstream out("input.txt");
	if (out.fail())
	{
		cout << "Error: can not open file\n";
		return;
	}
	
	for (int i = 0; i < n_data; ++i) // save data
		out << data[i] << " ";
	out.close();
}
