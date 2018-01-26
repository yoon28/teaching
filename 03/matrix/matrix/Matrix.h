#ifndef _MATRIX_HEADER_H_
#define _MATRIX_HEADER_H_

class Matrix
{
	int r;
	int c;
	double* data;
	double** access;
public:
	Matrix();
	~Matrix();
	Matrix(int _r, int _c);
	Matrix(int _r, int _c, double *_data);
	int rows() { return r; };
	int cols() { return c; };
	double& elem(int _r, int _c) { return access[_r][_c]; };
};

#endif