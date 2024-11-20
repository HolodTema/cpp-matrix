#include "Matrix.h"
#include <iostream>
#include "matrixExceptions.h"

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


