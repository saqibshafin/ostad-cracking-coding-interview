// Time complexity: O(n^2)
// Space complexity: O(n)

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int main() {
    // int nodes = 4;
    int nodes = 3;
    std::vector<std::vector<int>> edges = {
        {1, 2},
        // {2, 3},
        {2, 1},
    };
    // std::vector<int> x = {7};
    // edges.push_back({x});
    // edges.push_back({4, 6});
    // edges.push_back({5});

    // for (auto edge : edges) {
    //     std::cout << edge[0] << ' ' << edge[1] << std::endl;
    // }

    std::vector<int> allNodes;

    for (int i = 1; i <= nodes; i++) {
        allNodes.push_back(i);
    }
    // for (int i = 1; i <= nodes; i++) {
    //     std::cout << allNodes[i - 1];
    // }
    // std::cout << std::endl;

    std::vector<int> visited(allNodes.size(), 0);
    // for (int i = 0; i < nodes; i++) {
    //     std::cout << visited[i];
    // }
    // std::cout << std::endl;

    std::queue<int> qNodes;
    // for (int i = 1; i <= nodes; i++) {
    //     qNodes.push(i);
    // }
    // for (int i = 1; i <= nodes; i++) {
    //     std::cout << qNodes.front();
    //     qNodes.pop();
    // }
    // std::cout << std::endl;
    qNodes.push(edges[0][0]);

    // while (!qNodes.empty()) {
    //     int node = qNodes.front();
    //     qNodes.pop();

    //     for (int i = 0; i < edges[node].size(); i++) {
    //         int newNode = edges[node][i];

    //         if (!visited[newNode]) {
    //             visited[newNode] = 1;
    //             qNodes.push(newNode);
    //         }
    //     }
    // }

    for (int i = 0; i < edges.size(); i++) {

        for (int j = 0; j < edges[i].size(); j++) {
            int k = edges[i][j];
            auto it = std::find(allNodes.begin(), allNodes.end(), k);
            int index;

            // If element was found
            if (it != allNodes.end()) {

                // calculating the index
                // of K
                index = it - allNodes.begin();
                // std::cout << index << std::endl;
            } else {
                // If the element is not
                // present in the vector
                // std::cout << "-1" << std::endl;
            }

            if (!visited[index]) {
                visited[index] = 1;
            }
        }
    }

    int connectedComponents = 0;
    for (int i = 0; i < nodes; i++) {
        if (visited[i] == 0) {
            connectedComponents++;
        }
        // std::cout << visited[i];
    }
    // std::cout << std::endl;

    std::cout << (connectedComponents + 1) << std::endl;
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