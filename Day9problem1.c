#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    printf("Enter name: ");
    scanf("%s", name);

    int i = 0, j = strlen(name) - 1;
    while(i < j){
        char t = name[i];
        name[i] = name[j];
        name[j] = t;
        i++;
        j--;
    }

    printf("Mirrored Name: %s\n", name);
    return 0;
}
