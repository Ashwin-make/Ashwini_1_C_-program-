include <stdlib.h>

int main() {
    int *arr, n, i, sum = 0;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1; 
    }

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i]; 
    }

    printf("Sum of the elements: %d\n", sum);

    free(arr);

    return 0;
}