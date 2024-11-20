#include <iostream>

#include "Matrix.h"

int main() {
	int *arr = new int[9]{1, 0, 0, 0, 1, 0, 0, 0, 1};
	Matrix matrix = Matrix("A", 3, 3, arr);
	int element = matrix.getElement(5, 8);
	return 0;
}
