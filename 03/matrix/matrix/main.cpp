#include <iostream>
#include <fstream>
#include "Matrix.h"

using namespace std;

void main()
{
	ifstream fin("A.txt");
	if (!fin.is_open())
		return;

	int row, col;
	fin >> row;
	fin >> col;

	double *raw = new double[row*col];
	int idx = 0;
	while (fin >> raw[idx])
		++idx;

	_ASSERT(idx == row * col);

	Matrix mat(row, col, raw);
	for (int i = 0; i < mat.rows(); ++i)
	{
		for (int j = 0; j < mat.cols(); ++j)
		{
			cout << mat.elem(i, j) << ", ";
		}
		cout << endl;
	}

	Matrix mat2(2, 2);
	for (int i = 0; i < mat2.rows(); ++i)
		for (int j = 0; j < mat2.cols(); ++j)
			mat2.elem(i, j) = i + j;
	for (int i = 0; i < mat2.rows(); ++i)
	{
		for (int j = 0; j < mat2.cols(); ++j)
		{
			cout << mat2.elem(i, j) << ", ";
		}
		cout << endl;
	}

	delete[] raw;
}