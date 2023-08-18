// Time complexity: Not sure, but probably much faster than o(n^2)
// Space complexity: o(1)

// <---------- What exactly is meant by Brackets closed in same order?
// ---------->

// #include <iostream>
#include <bits/stdc++.h>

#include <chrono>

using namespace std;

int main() {
  string bracesOnlyString;
  bool inOrder = true;

  cin >> bracesOnlyString;

  int size = bracesOnlyString.length();

  /*
    https://www.geeksforgeeks.org/measure-execution-time-with-high-precision-in-c-c/
  */

  // struct timespec start, end;

  // clock_gettime(CLOCK_MONOTONIC, &start);

  auto startt = chrono::high_resolution_clock::now();

  // unsync the I/O of C and C++.
  ios_base::sync_with_stdio(false);

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

  // // stop timer.
  // // clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
  // // clock_gettime(CLOCK_REALTIME, &end);
  // clock_gettime(CLOCK_MONOTONIC, &end);

  auto endd = chrono::high_resolution_clock::now();

  // // Calculating total time taken by the program.
  // double time_taken;
  // time_taken = (end.tv_sec - start.tv_sec) * 1e9;
  // time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;

  // cout << "Time taken by program is : " << fixed << time_taken
  //      << setprecision(9);
  // cout << " sec" << endl;

  // Calculating total time taken by the program.
  double time_takenn =
      chrono::duration_cast<chrono::nanoseconds>(endd - startt).count();

  time_takenn *= 1e-9;

  cout << "Time taken by program is : " << fixed << time_takenn
       << setprecision(9);
  cout << " sec" << endl;

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