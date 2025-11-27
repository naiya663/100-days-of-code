#include <stdio.h>

// Recursive function to find ceil index
int findCeil(int arr[], int low, int high, int x, int ansIndex) {
    if (low > high)
        return ansIndex;

    int mid = (low + high) / 2;

    if (arr[mid] == x)
        return mid;  // exact match → this is the ceil
    else if (arr[mid] < x)
        return findCeil(arr, mid + 1, high, x, ansIndex);  // go right
    else
        return findCeil(arr, low, mid - 1, x, mid);  // possible ceil, go left
}

int main() {
    int n, x;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter x: ");
    scanf("%d", &x);

    int index = findCeil(arr, 0, n - 1, x, -1);

    printf("%d\n", index);
    return 0;
}
