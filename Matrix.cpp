#include "Matrix.h"
#include <iostream>
#include <cstring>
#include <stdexcept>
#include "matrixExceptions.h"
#include "MatrixLinearSpace.h"

bool Matrix::isSquare() const noexcept {
	return columns_ == rows_;
}

bool Matrix::isZero() const noexcept {
	for (int i = 0; i<rows_*columns_; ++i) {
		if (matrix_[i] != 0) {
			return false;
		}
	}
	return true;
}


bool Matrix::isUnit() const noexcept {
	if (!isSquare()) {
		return false;
	};

	for (int i = 0; i<=rows_*columns_; ++i) {
		if (i/rows_ == i%rows_) {
			if (matrix_[i] != 1) {
				return false;
			}
		}
		else {
			if (matrix_[i] != 0) {
				return false;
			}
		}
	}
	return true;
}

int Matrix::getElement(unsigned int column, unsigned int row) const noexcept {
	if (column > columns_ || row >= rows_) {
		throw InvalidMatrixIndexException();
	}
	return matrix_[row*columns_ + column];
}

void Matrix::printInfo() const noexcept {
	std::cout << "Matrix " << name_ << ":\nrows: " << rows_ << "; columns: " << columns_ << "\n";
	for (int i = 0; i<rows_; ++i) {
		for (int j = 0; j<columns_; ++j) {
			std::cout << matrix_[i*columns_ + j] << "\t";
		}
		std::cout << "\n";
	}
}


Matrix operator+(const Matrix &matrix1, const Matrix &matrix2) {
	MatrixLinearSpace space1 = matrix1.getMatrixLinearSpace();
	MatrixLinearSpace space2 = matrix2.getMatrixLinearSpace();

	if (space1 != space2) {
		throw InvalidMatrixAdditionException();
	}

	int *data1 = matrix1.getData();
	int *data2 = matrix2.getData();

	unsigned int resultDataLen = matrix1.getAmountElements();
	
	int *resultData;
	try {
		resultData = new int[resultDataLen];
	}
	catch(std::bad_alloc &e) {
		throw UnableToAllocateMatrixException();
	}

	for (int i = 0; i<resultDataLen; ++i) {
		resultData[i] = data1[i] + data2[i];
	}

	char *resultName = strcat(matrix1.getName(), "+");
	resultName = strcat(resultName, matrix2.getName());

	return Matrix(resultName, matrix1.getRows(), matrix1.getColumns(), resultData);
}

MatrixLinearSpace Matrix::getMatrixLinearSpace() const noexcept {
	return MatrixLinearSpace(rows_, columns_);
}


