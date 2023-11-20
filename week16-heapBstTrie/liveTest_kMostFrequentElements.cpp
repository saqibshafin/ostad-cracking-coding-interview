// Time complexity:
// Space complexity:

#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Comparator function to sort pairs
// according to second value
bool cmp(pair<int, int> &a, pair<int, int> &b) { return a.second < b.second; }

// Function to sort the map according
// to value in a (key-value) pairs
void sort(map<int, int> &M) {

    // Declare vector of pairs
    vector<pair<int, int>> A;

    // Copy key-value pair from Map
    // to vector of pairs
    for (auto &it : M) {
        A.push_back(it);
    }

    // Sort using comparator function
    sort(A.begin(), A.end(), cmp); // FIXME

    // Print the sorted value
    int k = 2;
    // for (int i = 0; i < A.size(); i++) {
    for (int i = 0; i < k; i++) {
        cout << A[i].first << ' ' << A[i].second << endl;
    }
}

vector<int> mostFrequentElements(vector<int> numbers) {
    // generate an ordered map which contains the number of times each unique
    // number appeared
    map<int, int> no_of_instances;
    for (auto number : numbers) {
        // when you find a number for the first time, add 1 to it's
        // corresponding map
        no_of_instances[number] = no_of_instances[number] + 1;
    }

    // chose the first 'k' elements/values from the map:
    sort(no_of_instances);
}

/*

Write a function that does the following task.



Given an integer array nums and an integer k, return the k most frequent
elements. You may return the answer in any order.



Mention the time and space complexity of your solution.



Constraints:

    1 <= nums.length <= 10^5

    -10^4 <= nums[i] <= 10^4

    k is in the range [1, the number of unique elements in the array].

    It is guaranteed that the answer is unique.


Examples from BingChat:

    For example, suppose the input is nums = [1, 1, 1, 2, 2, 3] and k = 2.
The output should be [1, 2], because 1 and 2 are the two most frequent
elements in the array, each appearing three and two times respectively. The
order of the output does not matter, so [2, 1] is also a valid output.

    Another example is nums = [4, 5, 6, 7, 8, 9] and k = 3. The output can
be any three elements from the array, because they all appear only once, so
they are equally frequent. For example, the output can be [4, 5, 6], or [7,
8, 9], or [6, 7, 8], or any other combination of three elements from the
array.



Example 1:



Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]



Example 2:



Input: nums = [1], k = 1

Output: [1]

*/