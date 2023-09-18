//   You asked to find the minimum number in O(log_n) time, but how? It's not
// ordered properly! Ordering will take O(n) time...

#include <iostream>
#include <vector>

int findTarget(int targetNumber, std::vector<int>);

int main() {
    std::vector<int> nums;
    int size, targetNumber;
    std::cin >> targetNumber >> size;
    for (int i = 0; i < size; i++) {
        int x;
        std::cin >> x;
        nums.push_back(x);
    }
    // for (int i = 0; i < size; i++) {
    //     std::cout << nums[i];
    // }

    int targetNumIndex = findTarget(targetNumber, nums);
    std::cout << targetNumIndex << std::endl;

    return 0;
}

int findTarget(int targetNumber, std::vector<int> nums) {
    int start = 0, end = nums.size() - 1; // start and end indices

    while (start < end) {
        int mid = start + (end - start) / 2;

        if (nums[mid] == targetNumber) {
            return mid;
        } else if (nums[mid] < targetNumber) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return -1;
}

/*

Assignment on Searching

    Write a function that does the following task:

    Suppose an array of length n sorted in ascending order is rotated between 1
and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:


    [4,5,6,7,0,1,2] if it was rotated 4 times.
    [0,1,2,4,5,6,7] if it was rotated 7 times.
    Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results
in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

    Given the sorted rotated array nums of unique elements, return the minimum
element of this array.

    You must write an algorithm that runs in O(log n) time.

    Constraints:
        n == nums.length
        1 <= n <= 5000
        -5000 <= nums[i] <= 5000

        All the integers of nums are unique.

        nums is sorted and rotated between 1 and n times.

    Example 1:
        Input: nums = [3,4,5,1,2]
        Output: 1
        Explanation: The original array was [1,2,3,4,5] rotated 3 times.

    Example 2:
        Input: nums = [4,5,6,7,0,1,2]
        Output: 0
        Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4
times.

    Example 3:
        Input: nums = [11,13,15,17]
        Output: 11
        Explanation: The original array was [11,13,15,17] and it was rotated 4
times.

*/