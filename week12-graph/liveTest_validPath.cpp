// Time complexity: O(n^2), because of the find(operation within "i" for-loop, &
// "j" is always constant) Space complexity: O(n)

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    // int nodes = 3;
    // int source = 0;
    // int destination = 2;
    // std::vector<std::vector<int>> edges = {
    //     {0, 1},
    //     {1, 2},
    //     {2, 0},
    // };
    int nodes = 6;
    int source = 0;
    int destination = 5;
    std::vector<std::vector<int>> edges = {
        {0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3},
    };

    std::vector<int> sourceCycle;
    std::vector<int> destinationCycle;

    for (int i = 0; i < edges.size(); i++) {
        for (int j = 0; j < edges[i].size(); j++) {
            if (edges[i][0] == source) {
                sourceCycle.push_back(edges[i][0]);
                sourceCycle.push_back(edges[i][1]);
            }
            if (edges[i][1] == source) {
                sourceCycle.push_back(edges[i][0]);
                sourceCycle.push_back(edges[i][1]);
            }

            if (edges[i][0] == destination) {
                destinationCycle.push_back(edges[i][0]);
                destinationCycle.push_back(edges[i][1]);
            }
            if (edges[i][1] == destination) {
                destinationCycle.push_back(edges[i][0]);
                destinationCycle.push_back(edges[i][1]);
            }

            // Searching if sourceCycle has edges[i][j]:
            auto itSourceCycle =
                std::find(sourceCycle.begin(), sourceCycle.end(), edges[i][j]);

            // If element was found, add to sourceCycle`:
            if (itSourceCycle != sourceCycle.end()) {
                sourceCycle.push_back(edges[i][j]);
            }

            // Searching if destinationCycle has edges[i][j]:
            auto itDestinationCycle = std::find(
                destinationCycle.begin(), destinationCycle.end(), edges[i][j]);

            // If element was found, add to destinationCycle:
            if (itDestinationCycle != destinationCycle.end()) {
                destinationCycle.push_back(edges[i][j]);
            }
        }
    }

    // for (int i = 0; i < edges.size(); i++) {
    //     for (int j = 0; j < edges[i].size(); j++) {
    //         std::cout << edges[i][j] << ' ';
    //     }
    //     std::cout << std::endl;
    // }

    for (int i = 0; i < sourceCycle.size(); i++) {
        std::cout << sourceCycle[i] << ' ';
    }
    std::cout << std::endl;
    for (int i = 0; i < destinationCycle.size(); i++) {
        std::cout << destinationCycle[i] << ' ';
    }
    std::cout << std::endl;

    std::string validPathExists = "false";

    //
    auto it = std::find(sourceCycle.begin(), sourceCycle.end(), destination);

    // If element was found within sourceCycle (or destinationCycle, if we
    // wish):
    if (it != sourceCycle.end()) {
        validPathExists = "true";
    } else {
        validPathExists = "false";
    }

    std::cout << validPathExists << std::endl;
}

/*

Write a function that does the following task.

There is a bi-directional graph with n vertices, where each vertex is labeled
from 0 to n - 1 (inclusive). The edges in the graph are represented as 2D
integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional
edge between vertex ui and vertex vi. Every vertex pair is connected by at most
one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to
vertex destination.

Given edges and the integers n, source, and destination, return true if there is
a valid path from source to destination, or false otherwise.

Mention the time and space complexity of your solution.

Constraints:
1 <= n <= 2 * 10^5
0 <= edges.length <= 2 * 10^5
edges[i].length == 2
0 <= ui, vi <= n - 1
ui != vi
0 <= source, destination <= n - 1
There are no duplicate edges.
There are no self edges.

Example 1:

Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2

Example 2:

Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination =
5 Output: false Explanation: There is no path from vertex 0 to vertex 5.

*/