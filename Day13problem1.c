#include <stdio.h>

void boundaryToCenter(int matrix[100][100], int row, int col) {
    int top = 0, bottom = row - 1;
    int left = 0, right = col - 1;

    while (top <= bottom && left <= right) {

        // Left to Right
        for (int i = left; i <= right; i++)
            printf("%d ", matrix[top][i]);
        top++;

        // Top to Bottom
        for (int i = top; i <= bottom; i++)
            printf("%d ", matrix[i][right]);
        right--;

        // Right to Left
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                printf("%d ", matrix[bottom][i]);
            bottom--;
        }

        // Bottom to Top
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                printf("%d ", matrix[i][left]);
            left++;
        }
    }
}

int main() {
    int matrix[100][100];
    int r, c;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter matrix elements:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &matrix[i][j]);

    printf("Boundary to Center Walk:\n");
    boundaryToCenter(matrix, r, c);

    return 0;
}
