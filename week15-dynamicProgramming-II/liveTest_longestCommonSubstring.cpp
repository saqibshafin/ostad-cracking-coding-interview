// Time complexity: O(n^2)
// Space complexity: O(n^2)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lcs(string A, string B) {
    int n = A.size(), m = B.size();
    vector<vector<int>> lcs(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i - 1] == B[j - 1]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            } else {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }

    return lcs[n][m];
}

int main() {
    int x = lcs("ace", "abcde");
    // int x = lcs("abc", "def");

    cout << x << endl;
}

/*

Write a function that does the following task.



Given two strings text1 and text2, return the length of their longest common
subsequence. If there is no common subsequence, return 0.



A subsequence of a string is a new string generated from the original string
with some characters (can be none) deleted without changing the relative
order of the remaining characters.



For example, "ace" is a subsequence of "abcde".

A common subsequence of two strings is a subsequence that is common to both
strings.



Mention the time and space complexity of your solution.



Constraints:

    1 <= text1.length, text2.length <= 1000

    text1 and text2 consist of only lowercase English characters.



Example 1:

Input: text1 = "abcde", text2 = "ace"

Output: 3

Explanation: The longest common subsequence is "ace" and its length is 3.



Example 2:

Input: text1 = "abc", text2 = "abc"

Output: 3

Explanation: The longest common subsequence is "abc" and its length is 3.



Example 3:

Input: text1 = "abc", text2 = "def"

Output: 0

Explanation: There is no such common subsequence, so the result is 0.

*/