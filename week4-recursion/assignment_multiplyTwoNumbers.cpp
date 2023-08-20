// Time complexity: o(x), with x being the smaller number between a & b
// Time complexity: o(x), with x being the smaller number between a & b (the
//   recursive call depth is x)

#include <iostream>

using namespace std;

int recursivelyMultiply(int, int, bool);

int main() {
  int a, b;
  cin >> a >> b;

  bool aIsLarger = a > b;

  int product = recursivelyMultiply(a, b, aIsLarger);

  cout << product << endl;
}

int recursivelyMultiply(int a, int b, bool aIsLarger) {
  // when any of the inputs is 0:
  if (a == 0 || b == 0) {
    return 0;
  }

  // base condition:
  if (a == 1 || b == 1) {
    int result;
    if (aIsLarger) {
      result = a;
    } else {
      result = b;
    }
    return result;
  }

  // recursive case:
  int result;
  if (aIsLarger) {  // the goal is to keep adding the larger number with itself,
                    // as long as the smaller number doesn't become equal to 1.
    result = a + recursivelyMultiply(a, --b, aIsLarger);  // "--b" same as (b-1)
  } else {
    result = b + recursivelyMultiply(--a, b, aIsLarger);
  }

  return result;
}

/*

Assignment on Recursion

    Write a function that does the following task:

    Write a recursive function to multiply given two positive integers ‘a’ and
‘b’ without using the * operator (multiplication operator). You can only use +
operator (addition operator) and - operator (subtraction operator).

    Also, mention the Time and Space Complexity of your solution


    Constraints:

        1 <= a, b <= 105


    Example 1:
        Input: a = 4, b = 5
        Output: 20

    Example 2:
        Input: a = 3, b = 3
        Output: 9

    Example 3:
        Input: a = 0, b = 2
        Output: 0

*/