// Doesn't work. My BAD.

// Time Complexity:
// Space Complexity:

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int sizeNums1, sizeNums2;
    vector<int> nums1, nums2;
    int m, n; // m+n = size of nums1, n = size of nums2
    //
    cin >> sizeNums1 >> m;
    int mTemp = sizeNums1;
    while (mTemp > 0) {
        int x;
        cin >> x;
        nums1.push_back(x);

        mTemp--;
    }
    cin >> sizeNums2 >> n;
    int nTemp = sizeNums2;
    while (nTemp > 0) {
        int x;
        cin >> x;
        nums2.push_back(x);

        nTemp--;
    }
    //
    // cout << nums1.back() << " ";
    // cout << nums2.back() << " ";
    // nums1.insert(nums1.begin() + 1, 22);
    // for (int i = 0; i < m; i++) {
    //     cout << nums1[i] << " ";
    // }

    bool mIsLarger = sizeNums1 > sizeNums2;
    mTemp = m, nTemp = n;
    if (mIsLarger) {
        for (int i = 0; i < m + n; i++) {
            if (nums1[i] < nums2[i]) {
                continue;
            } else if (nums1[i] == nums2[i]) {
                nums1.insert(nums1.begin() + i + 1, nums2[i]);
                nums1.pop_back();
                i++;
            } else if (nums1[i] > nums2[i]) {
                // shift nums1 1 step right and put nums2 before it:
                nums1.insert(nums1.begin() + i, nums2[i]);
                nums1.pop_back();
                i++;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (nums1[i] < nums2[i]) {
                continue;
            } else if (nums1[i] == nums2[i]) {
                nums1.insert(nums1.begin() + i + 1, nums2[i]);
                nums1.pop_back();
            } else if (nums1[i] > nums2[i]) {
                // shift nums1 1 step right and put nums2 before it:
                nums1.insert(nums1.begin() + i, nums2[i]);
                nums1.pop_back();
            }
        }
    }

    //
    for (int i = 0; i < m + n; i++) {
        cout << nums1[i] << " ";
    }
}

/*

    Assignment on Sorting

    Assignment:
        Write a function that does the following task.

    You are given two integer arrays nums1 and nums2, sorted in ascending order,
   and two integers m and n, representing the number of elements in nums1 and
   nums2 respectively.

    Merge nums1 and nums2 into a single array sorted in ascending order and
   store it in nums1.

    The final sorted array should not be returned by the function, but instead
   be stored inside the array nums1. To accommodate this, nums1 has a length of
   m + n, where the first m elements denote the elements that should be merged,
   and the last n elements are set to 0 and should be ignored. nums2 has a
   length of n.

    Also, mention the Time and Space Complexity of your solution.

    Constraints:
        nums1.length == m + n
        nums2.length == n
        0 <= m, n <= 200
        1 <= m + n <= 200
        -109 <= nums1[i], nums2[j] <= 109

    Example 1:
        Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
        Output: [1,2,2,3,5,6]
        Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
        The result of the merge is [1,2,2,3,5,6]

    Example 2:
        Input: nums1 = [1], m = 1, nums2 = [], n = 0
        Output: [1]
        Explanation: The arrays we are merging are [1] and [].
        The result of the merge is [1].

    Example 3:
        Input: nums1 = [0], m = 0, nums2 = [1], n = 1
        Output: [1]
        Explanation: The arrays we are merging are [] and [1].
        The result of the merge is [1].

    Note that because m = 0, there are no elements in nums1. The 0 is only there
   to ensure the merge result can fit in nums1.

*/