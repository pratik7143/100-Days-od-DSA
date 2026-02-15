void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int rows = matrixSize;
    int cols = matrixColSize[0];
    
    int i, j;
    int firstRowZero = 0;
    int firstColZero = 0;

    // Step 1: Check if first row has zero
    for (j = 0; j < cols; j++) {
        if (matrix[0][j] == 0) {
            firstRowZero = 1;
            break;
        }
    }

    // Step 2: Check if first column has zero
    for (i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) {
            firstColZero = 1;
            break;
        }
    }

    // Step 3: Use first row & column as markers
    for (i = 1; i < rows; i++) {
        for (j = 1; j < cols; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Step 4: Set cells to zero based on markers
    for (i = 1; i < rows; i++) {
        for (j = 1; j < cols; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Step 5: Zero first row if needed
    if (firstRowZero) {
        for (j = 0; j < cols; j++) {
            matrix[0][j] = 0;
        }
    }

    // Step 6: Zero first column if needed
    if (firstColZero) {
        for (i = 0; i < rows; i++) {
            matrix[i][0] = 0;
        }
    }
}
