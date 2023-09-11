// SEGFAULT, doesn't work.

// Time Complexity:
// Space Complexity:

#include <iostream>
#include <vector>

using namespace std;

vector<int> sort(vector<int>); // mergeSort
vector<int> merge(vector<int>, vector<int>);

int main() {
    vector<int> nums;
    nums.push_back(7);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(5);

    vector<int> sorted = sort(nums);

    for (int i = 0; i < sorted.size(); i++) {
        cout << sorted[i] << " ";
    }
}

vector<int> sort(vector<int> nums) {
    //
    if (nums.size() == 1)
        return nums;

    vector<int> array1;
    for (int i = 0; i < nums.size() / 2; i++) {
        array1.push_back(nums[i]);
    }
    vector<int> array2;
    for (int i = nums.size() / 2 + 1; i < nums.size(); i++) {
        array2.push_back(nums[i]);
    }

    array1 = sort(array1);
    array2 = sort(array2);

    return merge(array1, array2);
}

vector<int> merge(vector<int> a, vector<int> b) {
    vector<int> c;

    while (!a.empty() && !b.empty()) {
        if (a[0] > b[0]) {
            c.push_back(b[0]);
            b.erase(b.begin());
        } else {
            c.push_back(a[0]);
            a.erase(a.begin());
        }
    }

    // at this point, either a or b is empty

    while (!a.empty()) {
        c.push_back(a[0]);
        a.erase(a.begin());
    }
    while (!b.empty()) {
        c.push_back(b[0]);
        b.erase(b.begin());
    }

    return c;
}

/*

Write a function that does the following task.

    Given an array of integers nums, sort the array in ascending order and
return it.

    You must solve the problem in O(nlog(n)) time complexity and with the
smallest space complexity possible. You shouldn't use any built-in sorting
functions.





    Constraints:

        1 <= nums.length <= 5 * 104

        -5 * 104 <= nums[i] <= 5 * 104



    Example 1:

    Input: nums = [5,2,3,1]

    Output: [1,2,3,5]



    Example 2:

    Input: nums = [5,1,1,2,0,0]

Output: [0,0,1,1,2,5]

*/