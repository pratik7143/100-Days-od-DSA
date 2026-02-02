#include <stdio.h>
#include <time.h>
void function(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= 100; k++) {
                printf("UPES");
            }
        }
    }
}
int main() {
    int n;
    printf("Enter the value of n:");
    scanf("%d",&n);
    clock_t start, end;
    double cpu_time_used;
    start = clock();   
    function(n);        
    end = clock();     
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\n\nActual Execution Time: %f seconds\n", cpu_time_used);
    return 0;
}

