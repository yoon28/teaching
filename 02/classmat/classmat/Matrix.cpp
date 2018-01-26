#include "Matrix.h"

Matrix::Matrix()
{
	cout << "create\n";
};
Matrix::~Matrix()
{
	cout << "delete\n";
};
Matrix::Matrix(int _r, int _c)
{
	cout << "create and init\n";
	rows = _r; cols = _c;
}
void Matrix::setRows(int _r)
{
	rows = _r;
};
void Matrix::setCols(int _c)
{
	cols = _c;
};
int Matrix::getRows()
{
	return rows;
};
int Matrix::getCols()
{
	return cols;
};