#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

// void dfs()

int main() {
    vector<vector<int>> edges = {{1, 2}, {1, 5}, {1, 6}, {2, 3}, {2, 4}};
    vector<int> goodBadList = {0, 0, 1, 0, 1, 1, 1};

    vector<list<int>> adjacencyList(6 + 1);
    vector<int> visited(6 + 1, 0);
    queue<int> q;

    for (auto edge : edges) {
        adjacencyList[edge[0]].push_back(edge[1]);
        /*
            1 -> 2,5,6
            2 -> 3,4
        */
    }

    q.push(1);
    visited[1] = 1;

    int count = 0;
    int branchCount = 0;

    while (!q.empty()) {

        int u = q.front();
        q.pop();

        if (adjacencyList[u].size() == 0) {
            cout << u << endl;
            continue;
        }

        for (auto v : adjacencyList[u]) {
            if (goodBadList[v] == 1) {

                branchCount++;
            }
            if (visited[v] == 0) {
                visited[v] = 1;
                q.push(v);
            }
        }
    }

    for (auto element : visited) {
        cout << element << " ";
    }
    cout << branchCount << " " << count << endl;
}

/*

Assignment on Graph - 2

Write a function that does the following task.

Given a tree with N nodes labeled from 1 to N.

Each node is either good or bad denoted by binary array A of size N where if
A[i] is 1 then i-th node is good else if A[i] is 0 then i-th node is bad.

Also the given tree is rooted at node 1 and you need to tell the number of root
to leaf paths in the tree that contain not more than C good nodes.

Mention the time and space complexity of your solution.

NOTE: Each edge in the tree is bi-directional.

Constraints:

    2 <= N <= 10^5

    A[i] = 0 or A[i] = 1

    0 <= C <= N

Example 1:

Input : A = [0, 1, 0, 1, 1, 1]

B = [ [1, 2], [1, 5], [1, 6], [2, 3], [2, 4] ]

C = 1

Output : 3

Explanation: Path (1 - 2 - 3) , (1 - 5) and (1 - 6) are the paths which contain
at most C nodes.

Example 2:

Input : A = [0, 1, 0, 1, 1, 1]

B = [ [1, 2], [1, 5], [1, 6], [2, 3], [2, 4] ]

C = 2

Output : 4

Explanation: Path (1 - 2 - 3), (1 - 2 - 4), (1 - 5) and (1 - 6) are the paths
which contain at most C nodes.

*/