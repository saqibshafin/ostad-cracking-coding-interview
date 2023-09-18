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

    int targetNumIndex = findTarget(targetNumber, nums);
    std::cout << targetNumIndex << std::endl;

    return 0;
}

int findTarget(int targetNumber, std::vector<int> nums) {
    int start = 0, end = nums.size() - 1; // start and end indices

    while (start <= end) {
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

Live Coding Test:

    Write a function that does the following task.

    Given an array of integers nums which is sorted in ascending order, and an
integer target, write a function to search target in nums. If target exists,
then return its index. Otherwise, return -1.

    You must write an algorithm with O(log n) runtime complexity.

    Constraints:

        1 <= nums.length <= 10^4

        -10^4 < nums[i], target < 10^4

        All the integers in nums are unique.

        nums is sorted in ascending order.



    Example 1:

    Input: nums = [-1,0,3,5,9,12], target = 9

    Output: 4

    Explanation: 9 exists in nums and its index is 4



    Example 2:

    Input: nums = [-1,0,3,5,9,12], target = 2

    Output: -1

    Explanation: 2 does not exist in nums so return -1

*/