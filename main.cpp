#include <iostream>

#include "Matrix.h"
#include "MatrixLinearSpace.h"

int main() {
	int *arr1 = new int[9]{1, 0, 0, 0, 1, 0, 0, 0, 1};
	Matrix matrix1 = Matrix("A", 3, 3, arr1);

	MatrixLinearSpace space1 = matrix1.getMatrixLinearSpace();

	int *arr2 = new int[9]{0, 0, 0, 0, 0, 0, 0, 0, 0};
	Matrix matrix2 = Matrix("B", 3, 3, arr2);
	
	MatrixLinearSpace space2 = matrix2.getMatrixLinearSpace();

	std::cout << space1.isEqual(space2);
	return 0;
}
