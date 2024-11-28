include <stdio.h>
#include <stdio.h>

void reverseArray(int *arr, int size) {
    int *start = arr;        
    int *end = arr + size - 1; 
    int temp;

    while (start < end) 
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }

int main() {
    int arr[100], n, i;
  
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter %d elements of the array:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    reverseArray(arr, n);

    printf("Reversed array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
