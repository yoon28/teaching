#include <iostream>
#include "Matrix.h"
using namespace std;

void main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "err: Must input two arguments\n";
		return;
	}
	char* program_name = argv[0];
	cout << "This program is '" << program_name << "'." << endl;
	int in1 = atoi(argv[1]); // first argument
	int in2 = atoi(argv[2]); // second argument
	Matrix mat(in1, in2);
	printf("Number of rows: %d\n", mat.getRows());
	printf("Number of columns: %d\n", mat.getCols());
}