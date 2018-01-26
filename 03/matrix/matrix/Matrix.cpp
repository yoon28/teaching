#include <iostream>
#include "Matrix.h"

Matrix::Matrix()
{
	r = 0;
	c = 0;
}

Matrix::~Matrix()
{
	delete[] data;
	delete[] access;
}

Matrix::Matrix(int _r, int _c)
{
	r = _r;
	c = _c;
	data = new double[r*c];
	access = new double*[r];

	for (int i = 0; i < r; ++i)
		access[i] = &data[i*c]; // data + (i*c);
	memset(data, 0, r*c * sizeof(double)); // init
}

Matrix::Matrix(int _r, int _c, double *_data)
{
	r = _r;
	c = _c;
	data = new double[r*c];
	access = new double*[r];

	for (int i = 0; i < r; ++i)
		access[i] = &data[i*c]; // data + (i*c);
	
	memcpy(data, _data, r*c * sizeof(double));
}

