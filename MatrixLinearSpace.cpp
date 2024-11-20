#include "Matrix.h"
#include "MatrixLinearSpace.h"


bool MatrixLinearSpace::isEqual(const MatrixLinearSpace &anotherSpace) const noexcept {
	return rows_ == anotherSpace.getRows() && columns_ == anotherSpace.getColumns();
}

bool MatrixLinearSpace::containsMatrix(const Matrix &matrix) {
	return rows_ == matrix.getRows() && columns_ == matrix.getColumns();
}

