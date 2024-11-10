# CSV to Matrix Library in C
## _A Simple Library for Handling CSV Data and Matrix Operations in C_

This project provides a C library to convert CSV files into matrices, supporting matrix operations such as creation, destruction, setting and getting values, and dimension retrieval. It includes a flexible design for working with double-precision matrices and parsing CSV data into matrix format.

## Features

- **Matrix Creation**: Dynamically allocate and create matrices of any size.
- **Matrix Operations**: Set and retrieve values at specific positions, copy matrices, and access matrix dimensions.
- **CSV Import**: Parse CSV files and convert them into matrix structures.
- **Matrix Destruction**: Clean up memory used by matrices to prevent memory leaks.

## Data Structures Included

### 1. **Matrix (mlfw_matrix_double)**

The `mlfw_matrix_double` structure represents a matrix with double precision values. It supports operations like setting and getting values, getting dimensions, and copying data.

**Key Operations:**
- `mlfw_create_matrix_double()`: Create a matrix with specified rows and columns.
- `mlfw_destroy_matrix_double()`: Destroy a matrix and free the allocated memory.
- `mlfw_matrix_double_set()`: Set a value at a specific row and column.
- `mlfw_matrix_double_get()`: Get a value from a specific row and column.
- `mlfw_matrix_double_get_row()`: Get the number of rows in a matrix.
- `mlfw_matrix_double_get_column()`: Get the number of columns in a matrix.
- `mlfw_matrix_double_get_dimensions()`: Retrieve both row and column dimensions.
- `mlfw_matrix_double_copy()`: Copy the data from one matrix to another.
- `mlfw_matrix_double_from_csv()`: Import a matrix from a CSV file.


## Installation

To use the library, clone the repository and include the header files in your project.

```sh
git clone https://github.com/kanishk-chouhan/CSV-to-Matrix-Library-in-C.git
```
Add the .c and .h files to your project and compile them along with your application.

## Library Files:

- **Header files**: Located in the include directory.
- **Compiled library**: The .lib and .a files are in the lib directory.
- **Source files**: The C source code is located in the src directory.

## Usage

Example 1: Creating a Matrix and Setting Values
To create a matrix, set values, and get a value from a specific position, you can follow this example:

```#include "mlfw_matrix.h"
int main() {
    dimension_t rows = 3, columns = 3;
    
    // Create a 3x3 matrix
    mlfw_matrix_double *matrix = mlfw_create_matrix_double(rows, columns);
    
    // Set values at specific positions
    mlfw_matrix_double_set(matrix, 0, 0, 1.0);
    mlfw_matrix_double_set(matrix, 1, 1, 2.0);
    mlfw_matrix_double_set(matrix, 2, 2, 3.0);

    // Retrieve a value
    printf("Value at [0][0]: %f\n", mlfw_matrix_double_get(matrix, 0, 0));

    // Clean up memory
    mlfw_destroy_matrix_double(matrix);
    return 0;
}
```

Example 2: Importing a Matrix from a CSV File
To load a matrix from a CSV file, you can use the mlfw_matrix_double_from_csv() function. This function parses a CSV file and creates a matrix from it.

```#include "mlfw_matrix.h"
int main() {
    const char *fileName = "matrix.csv";
    
    // Import matrix from CSV
    mlfw_matrix_double *matrix = mlfw_matrix_double_from_csv(fileName);
    
    // Use the matrix (e.g., print values, access dimensions, etc.)
    // Example: Print dimensions
    dimension_t rows, columns;
    mlfw_matrix_double_get_dimensions(matrix, &rows, &columns);
    printf("Matrix dimensions: %u x %u\n", rows, columns);
    
    // Clean up memory
    mlfw_destroy_matrix_double(matrix);
    return 0;
}
```

Compilation:
To compile the code, make sure to link the mlfw_mat_double.c file (or the compiled library if using the .lib or .a file):

```sh
Copy code
gcc -o matrix_example main.c mlfw_mat_double.c -lm
./matrix_example
```
If you are using the library file, the command would be:

```sh
gcc -o matrix_example main.c -L./lib -lml_lib -lm
./matrix_example
```

## Test Cases
You can create test cases to verify the functionality of the library. Place the test files in the testcases folder and use any testing framework of your choice (e.g., CUnit or a simple custom test harness).

# Contact
##### Email: itskanishk36@gmail.com
##### LinkedIn: https://www.linkedin.com/in/kanishk-chouhan/
