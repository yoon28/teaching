#ifndef _MATRIX_HEADER_H_
#define _MATRIX_HEADER_H_

#include <vector>

template <class T>
class Matrix
{
private:
	int r, c;
	std::vector<std::vector<T>> data;

public:
	Matrix() { r = 0; c = 0; };
	Matrix(int row, int col);
	Matrix(int row, int col, T* rawdata);
	~Matrix();

	int cols() { return c; }
	int rows() { return r; }
	T& elem(int row, int col) { return data[row][col]; };

	void transpose();
	Matrix<T> transposeCopyto();
	Matrix<T> operator+(Matrix<T> &B);
	Matrix<T> operator-(Matrix<T> &B);
	Matrix<T> operator*(Matrix<T> &B);
	Matrix<T> operator*(T k);

	friend Matrix<T> operator*(T k, Matrix<T> &B) { return B * k; };
};

template <class T>
Matrix<T>::Matrix(int row, int col) 
{
	r = row;
	c = col;
	for (int i = 0; i < r; ++i)
		data.push_back(std::vector<T>(c));
}

template <class T>
Matrix<T>::Matrix(int row, int col, T* rawdata) 
{
	r = row;
	c = col;
	int k = 0;
	for (int i = 0; i < r; ++i)
	{
		std::vector<T> temp;
		for (int j = 0; j < c; ++j)
		{
			temp.push_back(rawdata[k]);
			++k;
		}
		data.push_back(temp);
	}
}

template <class T>
Matrix<T>::~Matrix() 
{
	data.clear();
}

template <class T>
void Matrix<T>::transpose() 
{
	std::vector<std::vector<T>> buff;
	int r2 = c;
	int c2 = r;
	for (int i = 0; i < r2; ++i)
		buff.push_back(std::vector<T>(c2));

	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			buff[j][i] = data[i][j];
		
	r = r2;
	c = c2;
	data.swap(buff);
}

template <class T>
Matrix<T> Matrix<T>::transposeCopyto()
{
	Matrix<T> trans(c, r);
	
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			trans.elem(j, i) = data[i][j];

	return trans;
}

template <class T>
Matrix<T> Matrix<T>::operator+(Matrix<T> &B)
{
	_ASSERT((c == B.cols()) && (r == B.rows()));
	
	Matrix<T> C(r, c);

	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			C.elem(i, j) = data[i][j] + (B.elem(i, j));

	return C;
}
template <class T>
Matrix<T> Matrix<T>::operator-(Matrix<T> &B) 
{
	_ASSERT((c == B.cols()) && (r == B.rows()));

	Matrix<T> C(r, c);

	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			C.elem(i, j) = data[i][j] - (B.elem(i, j));

	return C;
}
template <class T>
Matrix<T> Matrix<T>::operator*(Matrix<T> &B)
{
	_ASSERT(c == B.rows());
	
	int r2 = r;
	int c2 = B.cols();
	int K = c;
	Matrix<T> C(r2, c2);

	for (int i = 0; i < r2; ++i)
	{
		for (int j = 0; j < c2; ++j)
		{
			T sum = 0;
			for (int k = 0; k < K; ++k)
			{
				sum += data[i][k] * B.elem(k, j);
			}
			C.elem(i, j) = sum;
		}
	}

	return C;
}
template <class T>
Matrix<T> Matrix<T>::operator*(T k)
{
	Matrix<T> C(r, c);

	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			C.elem(i, j) = data[i][j] * k;

	return C;
}

#endif
