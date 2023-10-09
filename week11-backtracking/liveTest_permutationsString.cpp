// Time complexity: O(N!)
// Space complexity: O(N)

// ---------------------DOESN'T WORK, NONE OF THEM.---------------------

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

void generatePermutations(int, std::vector<char>, //
                          std::vector<int>,       //
                          std::vector<char>       //
);

void genPerm(std::vector<char> &,             //
             std::unordered_map<int, bool>,   //
             std::vector<char> &,             //
             std::vector<std::vector<char>> & //
);

int main() {
    std::string input = "abc";
    std::vector<char> inputVec;
    for (int i = 0; i < input.size(); i++) {
        // std::cout << input[i];
        inputVec.push_back(input[i]);
        // std::cout << inputVec.back();
    }
    std::cout << std::endl;

    // std::vector<int> used = {0, 0, 0};
    // std::vector<char> permutation;

    // generatePermutations(0, inputVec, used, permutation);

    // ------------OR------------

    std::unordered_map<int, bool> taken;
    std::vector<std::vector<char>> result;
    std::vector<char> permutation;

    genPerm(inputVec, taken, permutation, result);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            std::cout << result[i][j];
        }
    }
    std::cout << std::endl;
}

void generatePermutations(int insertAt,                 //
                          std::vector<char> inputVec,   //
                          std::vector<int> used,        //
                          std::vector<char> permutation //
) {
    // base case
    if (insertAt == inputVec.size() - 1) {
        for (int i = 0; i < permutation.size(); i++) {
            std::cout << permutation[i];
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < inputVec.size(); i++) {
        if (!used[i]) {
            used[i] = 1;
            permutation.push_back(inputVec[i]); // SEGFAULT...
            generatePermutations(insertAt + 1, inputVec, used, permutation);
            used[i] = 0;
        }
    }
}

void genPerm(std::vector<char> &A,                  //
             std::unordered_map<int, bool> taken,   //
             std::vector<char> &B,                  //
             std::vector<std::vector<char>> &result //
) {
    // base case
    if (B.size() == A.size()) {
        result.push_back(B);
        return;
    }

    for (int i = 0; i < A.size(); i++) {
        if (!taken[A[i]] == false) {
            taken[A[i]] == true;
            B.push_back(A[i]);
            genPerm(A, taken, B, result);
            taken[A[i]] == true;
            B.pop_back();
        }
    }
}

/*

Question

Write a function that does the following task.



Given a string, return all possible permutations of that string.



Mention the time and space complexity of your solution.



Constraints:

    all the characters in the string are unique.



Example 1:



Input: “abc”

Output: [ “abc”, “acb”, “bac”, “bca”, “cab”, “cba” ]



Example 2:



Input: “xy”

Output: [ “xy”, “yx” ]




*/