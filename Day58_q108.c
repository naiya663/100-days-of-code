// Q108: Write a Program to take an integer array nums. Print an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i]. The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int nums[n], answer[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    // Step 1: Build prefix products
    answer[0] = 1;
    for(int i = 1; i < n; i++) {
        answer[i] = answer[i - 1] * nums[i - 1];
    }

    // Step 2: Multiply with suffix products
    int suffix = 1;
    for(int i = n - 1; i >= 0; i--) {
        answer[i] = answer[i] * suffix;
        suffix *= nums[i];
    }

    // Print result
    printf("[");
    for(int i = 0; i < n; i++) {
        printf("%d", answer[i]);
        if(i != n - 1) printf(",");
    }
    printf("]");

    return 0;
}


/*
Sample Test Cases:
Input 1:
nums = [1,2,3,4]
Output 1:
[24,12,8,6]

Input 2:
nums = [-1,1,0,-3,3]
Output 2:
[0,0,9,0,0]

*/