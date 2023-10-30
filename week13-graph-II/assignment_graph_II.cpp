// -----------------To OSTAD instructor: Don't check this version, see the
// Commit before 11:59PM.-----------------

#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

void dfs(int A,                            //
         vector<int> &visited,             //
         vector<list<int>> &adjacencyList, //
         int *branchCount,                 //
         int *count,                       //
         int C,                            //
         vector<int> &goodBadList) {
    if (adjacencyList[A].size() == 0) {
        int x = 0;

        if (goodBadList[A] == 1) {
            (*branchCount)++;
            /*
            Note that the parentheses are necessary to ensure that the
            dereference operator is applied before the increment operator.
            Otherwise, you would be incrementing the pointer itself, not the
            value it points to.
            */
            // *branchCount = *branchCount + 1;
            cout << *branchCount << endl;

            x = *branchCount;
            (*branchCount)--;
        }

        if (x <= C) {
            (*count)++;
        }

        return;
    }

    visited[A] = 1;
    if (goodBadList[A] == 1) {
        (*branchCount)++;
        // *branchCount = *branchCount + 1;
        cout << *branchCount << endl;
    }

    for (auto v : adjacencyList[A]) {
        if (visited[v] == 0) {
            visited[v] = 1;
            dfs(v, visited, adjacencyList, branchCount, count, C, goodBadList);
        }
    }

    if (goodBadList[A] == 1) {
        (*branchCount)--;
    }

    return;
}

int main() {
    vector<int> goodBadList = {0, 0, 1, 0, 1, 1, 1};                      // A
    vector<vector<int>> edges = {{1, 2}, {1, 5}, {1, 6}, {2, 3}, {2, 4}}; // B
    int C = 1;                                                            // C

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

    int x = 0;
    int *count = &x;
    int y = 0;
    int *branchCount = &y;

    dfs(1, visited, adjacencyList, branchCount, count, C, goodBadList);

    for (auto element : visited) {
        cout << element << " ";
    }
    cout << endl << *branchCount << " " << *count << endl;
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