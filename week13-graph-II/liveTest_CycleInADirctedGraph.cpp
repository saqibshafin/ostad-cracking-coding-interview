#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

int dfs(vector<list<int>> &adjacencyList, vector<bool> visited, int node) {
    for (auto v : adjacencyList[node]) {
        if (visited[v]) {
            return 1;
        }
        visited[v] = true;
        if (1 == dfs(adjacencyList, visited, v)) {
            return 1;
        }
        visited[v] = false;
    }
    return 0;
}

int main() {
    // vector<vector<int>> edges = {{1, 2}, {4, 1}, {2, 4},
    //                              {3, 4}, {5, 2}, {1, 3}}; // B
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {3, 4}, {4, 5}}; // B
    int A = 5;                                                    // A

    vector<list<int>> adjacencyList(A + 1);
    vector<bool> visited(A + 1, false);

    bool cycleFound = false;

    for (auto edge : edges) {
        adjacencyList[edge[0]].push_back(edge[1]);
        /*
            1 -> 2,3
            2 -> 4
            3 -> 4
            4 -> 1
            5 -> 2
            OR
            1 -> 2
            2 -> 3
            3 -> 4
            4 -> 5
        */
    }

    for (int u = 1; u <= A; u++) {
        if (visited[u]) {
            continue;
        }
        visited[u] = true;
        if (1 == dfs(adjacencyList, visited, u)) {
            cycleFound = true;
        }
        visited[u] = false;
    }

    cout << cycleFound << endl;

    return 0;
}

/*

Write a function that does the following task.



Given a directed graph having A nodes. A matrix B of size M x 2 is given which
represents the M edges such that there is an edge directed from node B[i][0] to
node B[i][1].



Find whether the graph contains a cycle or not, return 1 if cycle is present
else return 0.



Mention the time and space complexity of your solution.



NOTE:

    The cycle must contain at least two nodes.

    There are no self-loops in the graph.

    There are no multiple edges between two nodes.

    The graph may or may not be connected.

    Nodes are numbered from 1 to A.

    Your solution will run on multiple test cases. If you are using global
variables make sure to clear them.



Constraints:

    2 <= A <= 10^5

    1 <= M <= min(200000,A(A-1))

    1 <= B[i][0], B[i][1] <= A



Example 1:

Input:

A = 5

B = [  [1, 2], [4, 1], [2, 4], [3, 4], [5, 2], [1, 3] ]



Output: 1



Explanation: The given graph contain cycle 1 -> 3 -> 4 -> 1 or the cycle 1 -> 2
-> 4 -> 1



Example 2:

Input :

A = 5

B = [ [1, 2], [2, 3], [3, 4], [4, 5] ]



Output: 0



Explanation: The given graph doesn't contain any cycle.

*/