#include <stdio.h>
void reverseArray(int arr[], int n) {
    int temp, start = 0, end = n - 1;
    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
int main() {
    int n, i;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    printf("Original: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    reverseArray(arr, n);
    printf("\nReversed: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}