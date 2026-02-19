#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void pairClosestToZero(int arr[], int n)
{
    if (n < 2) {
        printf("Not enough elements\n");
        return;
    }
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
    int left = 0, right = n - 1;
    int minSum = INT_MAX;
    int bestLeft = left, bestRight = right;
    while (left < right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < abs(minSum)) {
            minSum = sum;
            bestLeft = left;
            bestRight = right;
        }
        if (sum < 0)
            left++;
        else
            right--;
    }
    printf("Pair closest to zero: %d and %d (Sum = %d)\n",
           arr[bestLeft], arr[bestRight], minSum);
}
int main()
{
    int arr[] = {1, 60, -10, 70, -80, 85};
    int n = sizeof(arr) / sizeof(arr[0]);

    pairClosestToZero(arr, n);

    return 0;
}





