#include <stdio.h>

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    int freq[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        freq[i] = -1;   // Initialize frequency array
    }

    for(i = 0; i < n; i++) {
        if(freq[i] == -1) {
            int count = 1;

            for(int j = i + 1; j < n; j++) {
                if(arr[i] == arr[j]) {
                    count++;
                    freq[j] = 0;   // Mark as counted
                }
            }

            freq[i] = count;
        }
    }

    printf("\nElement\tFrequency\n");
    for(i = 0; i < n; i++) {
        if(freq[i] != 0) {
            printf("%d\t%d\n", arr[i], freq[i]);
        }
    }

    return 0;
}
