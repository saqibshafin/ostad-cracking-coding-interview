// Time complexity: O(n^2)
// Space complexity: O(n^2)

#include <iostream>

using namespace std;

/* lis() returns the length of the longest increasing
subsequence in arr[] of size n */
int lis(int arr[], int n) {
    int *lis, i, j, max = 0;
    lis = (int *)malloc(sizeof(int) * n);

    /* Initialize LIS values for all indexes */
    for (i = 0; i < n; i++)
        lis[i] = 1;

    /* Compute optimized LIS values in bottom up manner */
    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;

    /* Pick maximum of all LIS values */
    for (i = 0; i < n; i++)
        if (max < lis[i])
            max = lis[i];

    /* Free memory to avoid memory leak */
    free(lis);

    return max;
}

/* Driver program to test above function */
int main() {
    // int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int arr[] = {0, 1, 0, 3, 2, 3};
    // int arr[] = {7, 7, 7, 7, 7, 7, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of the longest increasing subsequence is " << lis(arr, n)
         << endl;
    return 0;
}

// this code is contributed by shivanisinghss2110

/*

Write a function that does the following task.



Given an integer array nums, return the length of the longest strictly
increasing

subsequence.



Mention the time and space complexity of your solution.



Constraints:



    1 <= nums.length <= 2500



    -10^4 <= nums[i] <= 10^4





Example 1:

Input: nums = [10,9,2,5,3,7,101,18]

Output: 4

Explanation: The longest increasing subsequence is [2,3,7,101], therefore the
length is 4.



Example 2:

Input: nums = [0,1,0,3,2,3]

Output: 4



Example 3:

Input: nums = [7,7,7,7,7,7,7]

Output: 1
*/