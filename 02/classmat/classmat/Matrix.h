#include <iostream>
using namespace std;
class Matrix
{
	int rows;
	int cols;
public:
	Matrix();
	~Matrix();
	Matrix(int _r, int _c);
	void setRows(int _r);
	void setCols(int _c);
	int getRows();
	int getCols();
};