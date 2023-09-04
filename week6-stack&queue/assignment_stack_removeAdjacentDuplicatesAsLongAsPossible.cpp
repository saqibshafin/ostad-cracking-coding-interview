// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <stack>

using namespace std;

int main() {
    string str;
    cin >> str;

    stack<char> charStack;

    for (auto eChar : str) { // eChar for "elementChar"
        if (charStack.empty()) {
            charStack.push(eChar);
        } else {
            if (eChar == charStack.top()) {
                charStack.pop();
            } else {
                charStack.push(eChar);
            }
        }
    }

    stack<char> charStackReversed;
    while (!charStack.empty()) {
        // cout << ' ' << charStack.top() << endl;
        charStackReversed.push(charStack.top());
        charStack.pop();
    }
    while (!charStackReversed.empty()) {
        cout << charStackReversed.top();
        charStackReversed.pop();
    }
    cout << endl;
}

/*

    Assignment on Stack and Queue

    Write a function that does the following task.

    You are given a string s consisting of lowercase English letters. A
    duplicate removal consists of choosing two adjacent and equal letters and
    removing them.

    We repeatedly make duplicate removals on s until we no longer can.

    Return the final string after all such duplicate removals have been made. It
    can be proven that the answer is unique.

    Also, mention the Time and Space Complexity of your solution.

    Constraints:
        1 <= s.length <= 105
        s consists of lowercase English letters.

    Example 1:
        Input: s = "abbaca"
        Output: "ca"
    Explanation:
        For example, in "abbaca" we could remove "bb" since the letters are
   adjacent and equal, and this is the only possible move.  The result of this
   move is that the string is "aaca", of which only "aa" is possible, so the
   final string is "ca".

    Example 2:
        Input: s = "azxxzy"
        Output: "ay"
    Explanation:
        For example, in "azxxzy" we could remove "xx" since the letters are
   adjacent and equal, and this is the only possible move.  The result of this
   move is that the string is "azzy", of which only "zz" is possible, so the
   final string is "ay".

*/