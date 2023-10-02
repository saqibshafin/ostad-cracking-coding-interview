// Time complexity:
// Space complexity:

#include <algorithm>
#include <iostream>
#include <vector>

bool sortCol(const std::vector<int> &v1, const std::vector<int> &v2) {
    return v1[1] < v2[1]; // sorting based on the 2nd column (index=1)
}

int main() {
    int row = 5, col = 2;
    std::vector<std::vector<int>> twoDVect = {
        {1, 4}, {8, 9}, {4, 6}, {2, 3}, {2, 4},
    };
    // int row = 3, col = 2;
    // std::vector<std::vector<int>> twoDVect = {
    //     {1, 9},
    //     {2, 3},
    //     {5, 7},
    // };

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << twoDVect[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // calculating difference between each interval:
    for (int i = 0; i < row; i++) {
        twoDVect[i].push_back(twoDVect[i][1] - twoDVect[i][0]);
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col + 1; j++) {
            std::cout << twoDVect[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // sorting based on the 2nd column:
    std::sort(twoDVect.begin(), twoDVect.end(), sortCol);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col + 1; j++) {
            std::cout << twoDVect[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

/*

Assignment on Greedy algorithms

Write a function that does the following task.



Given a set of N intervals denoted by 2D array A of size N x 2, the task is to
find the length of maximal set of mutually disjoint intervals.

Two intervals [x, y] & [p, q] are said to be disjoint if they do not have any
point in common.

Return a integer denoting the length of maximal set of mutually disjoint
intervals

Mention the time and space complexity of your solution.



Constraints:



    1 <= N <= 10^5



    1 <= A[i][0] <= A[i][1] <= 10^9



Example 1:

Input: A = [ [1, 4], [2, 3], [4, 6], [8, 9] ]

Output: 3



Example 2:

Input :  A = [ [1, 9], [2, 3], [5, 7] ]

Output: 2



Explanation 1:

 Intervals: [ [1, 4], [2, 3], [4, 6], [8, 9] ]

 Intervals [2, 3] and [1, 4] overlap.

 We must include [2, 3] because if [1, 4] is included then we cannot include [4,
6].

 We can include at max three disjoint intervals: [[2, 3], [4, 6], [8, 9]]



Explanation 2:

 Intervals: [ [1, 9], [2, 3], [5, 7] ]

 We can include at max two disjoint intervals: [[2, 3], [5, 7]]

*/