
#ifndef MATRIX_EXCEPTIONS_H
#define MATRIX_EXCEPTIONS_H

#include <stdexcept>

class InvalidRowsValueException: public std::exception {
	const char* what() const noexcept override {
		return "Error: matrix rows value must be integer positive value\n";
	}
};

class InvalidColumnsValueException: public std::exception {
	const char* what() const noexcept override {
		return "Error: matrix columns value must be integer positive value\n";
	}
};

class UnableToAllocateMatrixException: public std::exception {
	const char* what() const noexcept override {
		return "Error: unable to allocate memory for matrix\n";
	}
};

class InvalidMatrixDataException: public std::exception {
	const char* what() const noexcept override {
		return "Error: matrix data array is invalid\n";
	}
};

class InvalidMatrixIndexException: public std::exception {
	const char* what() const noexcept override {
		return "Error: matrix index is invalid\n";
	}
};

class InvalidMatrixAdditionException: public std::exception {
	const char* what() const noexcept override {
		return "Error: to add one matrix to another, these matrices must be of the same linear space\n";
	}
};

#endif
