#include <iostream>

// Function to create a matrix dynamically
int** createMatrix(int rows, int cols) {
    int** matrix = new int*[rows]; // Create an array of row pointers
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols]; // Create each row
    }
    return matrix;
}

// Function to delete a dynamically allocated matrix
void deleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i]; // Delete each row
    }
    delete[] matrix; // Delete the array of row pointers
}

// Function to input values into the matrix
void MatrixCreate(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << "Matrix [" << i << "] [" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }
}

// Function to multiply two matrices
int** MatrixMultiply(int** A, int rowsA, int colsA, int** B, int rowsB, int colsB) {
    if (colsA != rowsB) {
        std::cerr << "Matrix multiplication not possible: incompatible dimensions." << std::endl;
        return nullptr;
    }

    int** result = createMatrix(rowsA, colsB); // Create result matrix
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0; // Initialize result matrix
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j]; // Multiply and accumulate
            }
        }
    }
    return result; // Return the resulting matrix
}

// Function to display a matrix
void displayMatrix(int** matrix, int rows, int cols) {
    std::cout << "::MATRIX::" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << matrix[i][j] << " "; // Print each element
        }
        std::cout << std::endl; // Move to the next line after each row
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB;

    // Input for Matrix A
    std::cout << "Enter the number of rows in Matrix A: ";
    std::cin >> rowsA;
    std::cout << "Enter the number of columns in Matrix A: ";
    std::cin >> colsA;

    int** matrixA = createMatrix(rowsA, colsA); // Create Matrix A
    MatrixCreate(matrixA, rowsA, colsA); // Input values for Matrix A

    // Input for Matrix B
    std::cout << "Enter the number of rows in Matrix B: ";
    std::cin >> rowsB;
    std::cout << "Enter the number of columns in Matrix B: ";
    std::cin >> colsB;

    int** matrixB = createMatrix(rowsB, colsB); // Create Matrix B
    MatrixCreate(matrixB, rowsB, colsB); // Input values for Matrix B

    // Multiply matrices
    int** result = MatrixMultiply(matrixA, rowsA, colsA, matrixB, rowsB, colsB);

    // Display the result if multiplication was successful
    if (result) {
        std::cout << "Result of Matrix A * Matrix B:" << std::endl;
        displayMatrix(result, rowsA, colsB);
        
        // Clean up the result matrix
        deleteMatrix(result, rowsA);
    }

    // Clean up the matrices
    deleteMatrix(matrixA, rowsA);
    deleteMatrix(matrixB, rowsB);

    return 0;
}
