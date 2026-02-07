#include <stdio.h>
int removeDuplicates(int arr[], int n) {
    int i, j = 0;
    for (i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
    return j + 1;
}
int main() {
    int n, i, newSize;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter sorted elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    printf("Original: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    newSize = removeDuplicates(arr, n);
    printf("\nAfter removing duplicates: ");
    for (i = 0; i < newSize; i++)
        printf("%d ", arr[i]);
    printf("\nNew size: %d\n", newSize);
    return 0;
}