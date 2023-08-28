// Time complexity: 0(n/2)
// Space complexity: 0(n), where n is the depth of the recursive calling.

#include <iostream>

using namespace std;

bool isPalindrome(string, int, int);

int main() {
  string s;
  cin >> s;

  bool is_a_palindrome = isPalindrome(s, s.size(), 0);

  if (is_a_palindrome) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
}

bool isPalindrome(string s, int length, int startIndex) {
  if (length % 2 == 0) { // if length is Even
    // base case 1:
    if (startIndex == length / 2 - 1) {
      // "length/2 - 1", because, we are working with indices.
      if (s[startIndex] == s[startIndex + 1]) {
        return true;
      } else {
        return false;
      }
    }
  } else { // if length is Odd
    // base case 2:
    if (startIndex == length / 2) {
      return true;
    }
  }

  // recursive case:
  bool isAMatch = isPalindrome(s, length, startIndex + 1);

  if (isAMatch && s[startIndex] == s[length - 1 - startIndex]) {
    return true;
  } else {
    return false;
  }
}

/*
    Test cases:
        defdeff false
        defdefd false
        defdfef false
        defdfed true
*/

/*

    Write a function that does the following task:

    Given a string s, return true if it is a palindrome, or false otherwise.
    The input string is given as a string ‘s’.
    You must use Recursion to solve the problem.

    Also, mention the Time and Space Complexity of your solution.

    Constraints:
        1 <= s.length <= 105

    Example 1:
    Input: s = "madam"
    Output: true

    Example 2:
    Input: s = "adam"
    Output: false

    Example 3:
    Input: s = "tenet"
    Output: true

*/