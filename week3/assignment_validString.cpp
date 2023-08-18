// Time complexity: o(n^2)
// Space complexity: o(1)

// <---------- What exactly is meant by Brackets closed in same order?
// ---------->

// #include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
  string bracesOnlyString;
  bool inOrder = true;

  cin >> bracesOnlyString;
  // cout << bracesOnlyString << endl;

  int size = bracesOnlyString.length();
  // cout << size << endl;

  // /* Time function returns the time since the
  //       Epoch(jan 1 1970). Returned time is in seconds. */
  // time_t start, end;

  // /* You can call it like this : start = time(NULL);
  //   in both the way start contain total time in seconds
  //   since the Epoch. */
  // time(&start);

  struct timespec start, end;

  clock_gettime(CLOCK_MONOTONIC, &start);  // unsync the I/O of C and C++.

  ios_base::sync_with_stdio(false);

  for (int i = 0; i < size; i++) {
    if (bracesOnlyString[i] == '(') {
      for (int j = i + 1; j < size; j++) {
        if (bracesOnlyString[j] == ')') {
          bracesOnlyString[i] = '1',
          bracesOnlyString[j] = '1';  // '1' for 1st bracket
          break;
        }
      }
    }

    if (bracesOnlyString[i] == '[') {
      for (int j = i + 1; j < size; j++) {
        if (bracesOnlyString[j] == ']') {
          bracesOnlyString[i] = '2',
          bracesOnlyString[j] = '2';  // '2' for 1st bracket
          break;
        }
      }
    }

    if (bracesOnlyString[i] == '{') {
      for (int j = i + 1; j < size; j++) {
        if (bracesOnlyString[j] == '}') {
          bracesOnlyString[i] = '3',
          bracesOnlyString[j] = '3';  // '3' for 1st bracket
          break;
        }
      }
    }

    // cout << i << ": " << bracesOnlyString[i] << ", ";
  }
  // cout << endl;

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

  // time(&end);

  // // Calculating total time taken by the program.
  // double time_taken = double(end - start);
  // cout << "Time taken by program is : " << fixed << time_taken
  //      << setprecision(5);
  // cout << " sec " << endl;

  // stop timer.
  // clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
  // clock_gettime(CLOCK_REALTIME, &end);
  clock_gettime(CLOCK_MONOTONIC, &end);

  // Calculating total time taken by the program.
  double time_taken;
  time_taken = (end.tv_sec - start.tv_sec) * 1e9;
  time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;

  cout << "Time taken by program is : " << fixed << time_taken
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