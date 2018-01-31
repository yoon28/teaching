#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
int main()
{
	ifstream fin("A.txt");
	if (!fin.is_open())
		return -1;

	int row, col;
	fin >> row;
	fin >> col;
	
	double *raw = new double[row*col];
	int idx = 0;
	while (fin >> raw[idx])
		++idx;

	_ASSERT(idx == row * col);
	
	ifstream fin2("B.txt");
	if (!fin2.is_open())
		return -1;

	int row2, col2;
	fin2 >> row2;
	fin2 >> col2;
	double *raw2 = new double[row2*col2];
	idx = 0;
	while (fin2 >> raw2[idx])
		++idx;

	_ASSERT(idx == row2 * col2);

	Matrix<double> mat(row, col, raw);
	Matrix<double> mat2(row2, col2, raw2);

	delete[] raw;
	delete[] raw2;

	for (int i = 0; i < mat.rows(); ++i)
	{
		for (int j = 0; j < mat.cols(); ++j)
		{
			cout << mat.elem(i, j) <<", ";
		}
		cout << endl;
	}

	for (int i = 0; i < mat2.rows(); ++i)
	{
		for (int j = 0; j < mat2.cols(); ++j)
		{
			cout << mat2.elem(i, j) << ", ";
		}
		cout << endl;
	}

	Matrix<double> matrix(3, 2);
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			matrix.elem(i, j) = i + j;
			cout << matrix.elem(i, j) << ", ";
		}
		cout << endl;
	}

	Matrix<double> mat3 = mat - mat2;

	for (int i = 0; i < mat3.rows(); ++i)
	{
		for (int j = 0; j < mat3.cols(); ++j)
		{
			cout << mat3.elem(i, j) << ", ";
		}
		cout << endl;
	}
	
	mat2.transpose();
	for (int i = 0; i < mat2.rows(); ++i)
	{
		for (int j = 0; j < mat2.cols(); ++j)
		{
			cout << mat2.elem(i, j) << ", ";
		}
		cout << endl;
	}

	Matrix<double> mat4 = mat * mat2 ;
	for (int i = 0; i < mat4.rows(); ++i)
	{
		for (int j = 0; j < mat4.cols(); ++j)
		{
			cout << mat4.elem(i, j) << ", ";
		}
		cout << endl;
	}

	Matrix<double> mat5 = 10 * mat4 * 2.0;
	for (int i = 0; i < mat5.rows(); ++i)
	{
		for (int j = 0; j < mat5.cols(); ++j)
		{
			cout << mat5.elem(i, j) << ", ";
		}
		cout << endl;
	}
	return 0;
}