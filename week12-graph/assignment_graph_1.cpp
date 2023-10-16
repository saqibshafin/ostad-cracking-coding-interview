// Time complexity:
// Space complexity:

#include <iostream>
#include <vector>

int main() {
    int nodes = 4;
    std::vector<std::vector<int>> edges = {
        {1, 2},
        {2, 3},
    };
    // std::vector<int> x = {7};
    // edges.push_back({x});
    edges.push_back({4});
    edges.push_back({5});

    for (auto edge : edges) {
        std::cout << edge[0] << ' ' << edge[1] << std::endl;
    }
}

/*

Assignment on Graph -1

Write a function that does the following task.

Given a graph with A nodes.
The edges in the graph are given in a 2D array B.
There is an undirected edge between B[i][0] and B[i][1].
Find the number of connected components in the given graph.

Mention the time and space complexity of your solution.


Constraints:
1 <= A <= 10^5
1 <= |B| <= 10^5
1 <= B[i][0], B[i][1] <= A


Example 1:

A = 4
B =
[[1, 2],
[2, 3]]
Output : 2
Explanation: The two connected components are [1, 2, 3] and [4].

Example 2:

A = 3
B =
[[1, 2],
[2, 1]]
Output: 2
Explanation: The two connected components are [1, 2] and [3].

*/