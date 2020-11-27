#pragma once
#include <assert.h>

template<typename T>
class Array2D
{
public:
	Array2D(){}
	Array2D(int rows, int columns)
		:
		_rows(rows),
		_colums(columns),
		_array(new T[_rows * _colums])
	{
		for (int i = 0; i < _rows * _colums; i++)
		{
			_array[i] = 0;
		}
	}

	Array2D(const Array2D<T>& other)
	{
		*this = other;
	}

	~Array2D()
	{
		delete[] _array;
		_array = nullptr;
	}

	Array2D<T>& operator=(const Array2D<T>& other)
	{
		delete[] _array;
		_array = nullptr;

		_rows = other._rows;
		_colums = other._colums;
		_array = new T[_rows * _colums];

		for (int i = 0; i < _rows * _colums; i++)
		{
			_array[i] = other._array[i];
		}

		return *this;
	}

	T Get(int row, int colum) const
	{
		assert(row < _rows);
		assert(row >= 0);
		assert(colum < _colums);
		assert(colum >= 0);

		return _array[_colums * row + colum];
	}
	void Set(int row, int colum, T value)
	{
		assert(row < _rows);
		assert(row >= 0);
		assert(colum < _colums);
		assert(colum >= 0);

		_array[_colums * row + colum] = value;
	}

	// getters
	int GetColumns() const { return _colums; }
	int GetRows() const { return _rows; }

private:
	int _rows;
	int _colums;
	T* _array = nullptr;

};
