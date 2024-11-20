
#ifndef MATRIX_LINEAR_SPACE_H
#define	MATRIX_LINEAR_SPACE_H

#include "Matrix.h"
#include "matrixExceptions.h"

class Matrix;

class MatrixLinearSpace {
private:
	unsigned int rows_;
	unsigned int columns_;

public:
	MatrixLinearSpace(unsigned int rows, unsigned int columns) {
		if (rows == 0) {
			throw InvalidRowsValueException();
		}

		if (columns == 0) {
			throw InvalidColumnsValueException();
		}
		
		rows_ = rows;
		columns_ = columns;
	}

	unsigned int getRows() const noexcept {
		return rows_;
	}

	unsigned int getColumns() const noexcept {
		return columns_;
	}

	bool operator==(const MatrixLinearSpace &anotherSpace) const {
		return this->isEqual(anotherSpace);
	}

	bool operator!=(const MatrixLinearSpace &anotherSpace) const {
		return !(this->isEqual(anotherSpace));
	}

	bool isEqual(const MatrixLinearSpace&) const noexcept;

	bool containsMatrix(const Matrix &matrix);

};

#endif

	
