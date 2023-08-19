// Time complexity: O(n^2)
// Space complexity: O(1)

#include <iostream>
#include <vector>

using namespace std;

int* targetSum(int* nums, int target, int size);
// vector<int> targetSum(vector<int> nums, int target); 
/*
    Using std::vector is the recommended approach for returning arrays from functions in 
    C++ as it handles memory management for you and provides more safety.
*/

int main (){
    int size;
    cin >> size;

    int* nums = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }
    // for (int i = 0; i < size; i++) {
    //     cout << nums[i] << " ";
    // }
    // cout << endl;
    
    int target;
    cin >> target;

    int* targetSumItems = targetSum(nums, target, size);

    // int sizeTargetSumArray = sizeof(targetSumItems) / sizeof(targetSumItems[0]); // error
    int sizeTargetSumArray = 2;
    for (int i=0; i<sizeTargetSumArray; i++) {
        cout << targetSumItems[i] << ' ';
    }
    cout << endl;
    
    return 0;
}

int* targetSum(int* nums, int target, int size) {
    int* targetSum = new int[2];
    // int* targetSum[] = {0, 0, 0};
    // int x = sizeof(targetSum) / sizeof(targetSum[0]); // error
    // int x = *(&nums + 1) - nums; // error
    
    // int x = 3;
    // for (int i=0; i<x; i++){
    //     cout << targetSum[i] << ' ';
    // }
    // cout << x << endl;

    bool done = false;

    // int size = sizeof(nums) / sizeof(nums[0]); // error
    
    for (int i=0; i<size; i++){
        int numAtI = nums[i];
        if (numAtI > target) continue;

        for (int j=i+1; j<size; j++) {
            int numAtJ = nums[j];
            if (numAtJ > target) continue;

            int sum = nums[i] + nums[j];
            if (sum == target) {
                targetSum[0] = i;
                targetSum[1] = j;
                
                done = true;
                break;
            }
        }

        if (done == true) break;
    }
    
    return targetSum;
}



/*

    Write a function that does the following task.

    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

    You may assume that each input would have exactly one solution, and you may not use the same element twice.

    You can return the answer in any order.

    Also, mention the Time and Space Complexity of your solution

    Use of C++ or JavaScript is preferred.
    

    Constraints: 

    2 <= nums.length <= 104 

    -109 <= nums[i] <= 109 

    -109 <= target <= 109

    Only one valid answer exists.
    

    Example 1:

    Input: nums = [2,7,11,15], target = 9

    Output: [0,1]

    Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
    

    Example 2:

    Input: nums = [3,2,4], target = 6

    Output: [1,2]
    

    Example 3:

    Input: nums = [3,3], target = 6

    Output: [0,1]

*/