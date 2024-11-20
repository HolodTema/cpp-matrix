cmake_minimum_required(VERSION 3.28)

project(CppMatrix)

add_executable(main main.cpp
	Matrix.h
	Matrix.cpp
	matrixExceptions.h
	MatrixLinearSpace.h
	MatrixLinearSpace.cpp
)
