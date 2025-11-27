//Q119: Write a program to take an integer array as input. Only one element will be repeated. Print the repeated element. Try to find the result in one single iteration.

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);  // Size of array

    int arr[n];
    int visited[n];   // To track seen elements

    // Initialize visited array to 0
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int repeated = -1;

    // One single iteration to find duplicate
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        if (visited[arr[i]] == 1) {
            repeated = arr[i];
            break;    // Stop early once found
        }
        visited[arr[i]] = 1;
    }

    printf("%d", repeated);
    return 0;
}


/*
Sample Test Cases:
Input 1:
nums1 = [1,3,3,4]
Output 1:
3

Input 2:
nums1 = [1,2,2]
Output 2:
2

Input 3:
nums1 = [0,4,1,1,5]
Output 3:
1

*/