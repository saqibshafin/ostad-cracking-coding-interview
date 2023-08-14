// Time complexity: o(n)
// Space complexity: o(1) --- Right?

#include <iostream>
#include <vector>

using namespace std;

string shuffleString(string, int*, int);

int main() {
  string inputString;
  cin >> inputString;

  int size = inputString.length();

  int indices[size];

  for (int i = 0; i < size; i++) {
    cin >> indices[i];
  }

  string shuffledString = shuffleString(inputString, indices, size);

  for (int i = 0; i < size; i++) {
    cout << shuffledString[i];
  }
  cout << endl;

  return 0;
}

string shuffleString(string inputString, int indices[], int size) {
  char shuffledString[size];

  for (int i = 0; i < size; i++) {
    shuffledString[indices[i]] = inputString[i];
  }

  return shuffledString;
}

/*

Live Coding Test:

Write a function that does the following task.



You are given a string s and an integer array indices of the same length. The
string s will be shuffled such that the character at the ith position moves to
indices[i] in the shuffled string. Return the shuffled string.



Also, mention the Time and Space Complexity of your solution



Constraints:

    s.length == indices.length == n

    1 <= n <= 100

    s consists of only lowercase English letters.

    0 <= indices[i] < n

    All values of indices are unique.



Example 1:

Input: s = "mamacode", indices =  [4,5,6,7,0,1,2,3]

Output: "codemama"

Explanation: As shown, "mamacode" becomes "codemama" after shuffling.



Example 2:

Input: s = "dosta", indices =  [4,0,1,2,3]

Output: "ostad"

Explanation: After shuffling, each character remains in its position.



Example 3:

Input: s = "abc", indices = [1,0,2]

Output: "bac"

Explanation: After shuffling, each character remains in its position.

*/