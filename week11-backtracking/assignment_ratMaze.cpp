// Time complexity:
// Space complexity:

// --------------------UNFINISHED, SORRY FOR THAT--------------------

#include <iostream>
#include <vector>

void navigateMaze(std::vector<std::vector<int>>, int, int, bool *);

int main() {
    std::vector<std::vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1},
    };

    bool pathFound = false;
    bool *ptrPathFound = &pathFound;

    navigateMaze(maze, 0, 0, ptrPathFound);
}

void navigateMaze(std::vector<std::vector<int>> theMaze, int indexH, int indexV,
                  bool *pathFound) {
    // base case:
    if (indexH == theMaze[0].size() - 1) {
        return;
    }

    if (indexV <= theMaze[indexH].size() - 1) {
        // traversing horizontally, to the right:
        if (theMaze[indexH][indexV] == theMaze[indexH][indexV + 1]) {
            *pathFound = true;
            navigateMaze(theMaze, indexH, indexV + 1, pathFound);
        }
        // traversing vertically, upwards:
        if (theMaze[indexH][indexV] == theMaze[indexH][indexV + 1]) {
            *pathFound = true;
            navigateMaze(theMaze, indexH, indexV + 1, pathFound);
        }
        // traversing vertically, downwards:
        if (theMaze[indexH][indexV] == theMaze[indexH + 1][0]) {
            *pathFound = true;
            navigateMaze(theMaze, indexH + 1, 0, pathFound);
        }
    } else {
        // traversing vertically, downwards:
        if (theMaze[indexH][indexV] == theMaze[indexH + 1][0]) {
            *pathFound = true;
            navigateMaze(theMaze, indexH + 1, 0, pathFound);
        }
    }
}

/*

Write a function that does the following task.



Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to
reach the destination at (N - 1, N - 1). Find if there is a path from source to
destination, return true if there is any path, and return false otherwise.

The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R'
(right). Value 0 at a cell in the matrix represents that it is blocked and rat
cannot move to it while value 1 at a cell in the matrix represents that rat can
travel through it.



Note: In a path, no cell can be visited more than one time. If the source cell
is 0, the rat cannot move to any other cell.



Mention the time and space complexity of your solution.



Example 1:



Input:

N = 4

m[][] =

{{1, 0, 0, 0},

{1, 1, 0, 1},

{1, 1, 0, 0},

{0, 1, 1, 1}}



Output: true



Explanation:

The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR
and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.



Example 2:



Input:

N = 2

m[][] =

{{1, 0},

{1, 0}}



Output: false



Explanation:

No path exists and the destination cell is blocked.

*/