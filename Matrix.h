#ifndef MATRIX_H

#define MATRIX_H

#include "matrixExceptions.h"
#include "MatrixLinearSpace.h"
#include <stdexcept>

class Matrix {
private:
	char *name_;

	unsigned int rows_;
	unsigned int columns_;

	int *matrix_;

public:
	Matrix(char *name, unsigned int rows, unsigned int columns):
		name_(name)
	{
		if (rows==0) {
			throw InvalidRowsValueException();
		}
		rows_ = rows;
		
		if (columns==0) {
			throw InvalidColumnsValueException();
		}
		columns_ = columns;
		
		try {
			matrix_ = new int[rows*columns];
		}
		catch (std::bad_alloc) {
			throw UnableToAllocateMatrixException();
		}
	}

	Matrix(char *name, unsigned int rows, unsigned int columns, int *data): Matrix(name, rows, columns) {
		if (data == nullptr) {
			throw InvalidMatrixDataException();
		}
		matrix_ = data;
	}

	~Matrix() {
		delete[] matrix_;
	}

	char * getName() const noexcept {
		return name_;
	}

	unsigned int getRows() const noexcept {
		return rows_;
	}

	unsigned int getColumns() const noexcept {
		return columns_;
	}

	unsigned int getAmountElements() const noexcept {
		return rows_ * columns_;
	}

	int * getData() const noexcept {
		return matrix_;
	}

	bool isSquare() const noexcept;

	bool isZero() const noexcept;

	bool isUnit() const noexcept;

	int getElement(unsigned int column, unsigned int row) const noexcept;

	void printInfo() const noexcept;

	MatrixLinearSpace getMatrixLinearSpace() const noexcept;

};
#endif
