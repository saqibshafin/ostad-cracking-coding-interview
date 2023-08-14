// Time complexity: Not sure, but probably much faster than o(n^2)
// Space complexity: o(1)

// <---------- What exactly is meant by Brackets closed in same order?
// ---------->

#include <iostream>

using namespace std;

int main() {
  string bracesOnlyString;
  bool inOrder = true;

  cin >> bracesOnlyString;

  int size = bracesOnlyString.length();

  for (int i = 0; i < size; i++) {
    if (bracesOnlyString[i] == '(') {
      for (int j = i + 1; j < size; j++) {
        if (bracesOnlyString[j] == ')' && j < size) {
          bracesOnlyString.erase(bracesOnlyString.begin() + (i));
          bracesOnlyString.erase(bracesOnlyString.begin() + (j - 1));
          size = bracesOnlyString.length();

          i--;

          break;
        }
      }
    }

    if (bracesOnlyString[i] == '[') {
      for (int j = i + 1; j < size; j++) {
        if (bracesOnlyString[j] == ']' && j < size) {
          bracesOnlyString.erase(bracesOnlyString.begin() + (i));
          bracesOnlyString.erase(bracesOnlyString.begin() + (j - 1));
          size = bracesOnlyString.length();

          i--;

          break;
        }
      }
    }

    if (bracesOnlyString[i] == '{') {
      for (int j = i + 1; j < size; j++) {
        if (bracesOnlyString[j] == '}' && j < size) {
          bracesOnlyString.erase(bracesOnlyString.begin() + (i));
          bracesOnlyString.erase(bracesOnlyString.begin() + (j - 1));
          size = bracesOnlyString.length();

          i--;

          break;
        }
      }
    }

    if (size == 0) break;
  }

  for (int i = 0; i < size; i++) {
    if (bracesOnlyString[i] == '(' || bracesOnlyString[i] == ')' ||
        bracesOnlyString[i] == '[' || bracesOnlyString[i] == ']' ||
        bracesOnlyString[i] == '{' || bracesOnlyString[i] == '}') {
      inOrder = false;
      break;
    }
  }

  if (inOrder) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }

  return 0;
}

/*

Assignment on String

    Write a function that does the following task.

        Given a string s containing just the characters '(', ')', '{', '}', '['
and ']', determine if the input string is valid. An input string is valid if:

            1. Open brackets must be closed by the same type of brackets.

            2. Open brackets must be closed in the correct order.

            3. Every close bracket has a corresponding open bracket of the same
type.

    Also, mention the Time and Space Complexity of your solution


    Constraints:
        1 <= s.length <= 104
        s consists of parentheses only '()[]{}'.


    Example 1:
        Input: s = "()"
        Output: true

    Example 2:
        Input: s = "()[]{}"
        Output: true

    Example 3:
        Input: s = "(]"
        Output: false

    Example 4:
        Input: s = "(())"
        Output: true

    Example 5:
        Input: s = "(()"
        Output: false

    Example 6:
        Input: s = "(([)])"  // Brackets not closed in the same order, right?
        Output: ?

*/