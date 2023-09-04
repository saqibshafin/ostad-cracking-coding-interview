// Time Complexity: O(n*m)
// Space Complexity: O(n)

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n; // input size
    cin >> n;
    vector<int> tickets;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tickets.push_back(x);
    }

    int k;
    cin >> k;

    queue<int> qTickets;
    for (int i = 0; i < n; i++) {
        qTickets.push(tickets[i]);
        // cout << qTickets.front();
    }

    int totalSeconds = 0;

    bool breakFree;
    while (!qTickets.empty()) {
        breakFree = false;

        int kk = 0;
        for (int i = 0; i < qTickets.size(); i++) {
            int front = qTickets.front() - 1;
            if (front > 0) {
                qTickets.pop();
                qTickets.push(front);
            } else {
                qTickets.pop();
            }
            totalSeconds++;

            if (kk >= k && front == 0) {
                // when ticketQuantity of people who was at 'k' becomes 0:
                breakFree = true;
                break;
            }

            kk++;
        }

        if (breakFree)
            break; // break the while loop
    }

    cout << totalSeconds << endl;

    return 0;
}

/*

Write a function that does the following task.

There are n people in a line queuing to buy tickets, where the 0-th person is at
the front of the line and the (n - 1)-th person is at the back of the line.

You are given an integer array tickets of length n where the number of tickets
that the i-th person would like to buy is tickets[i]. You are also given k, the
position of the target person in the queue.

Each person takes exactly 1 second to buy a ticket. A person can only buy 1
ticket at a time and has to go back to the end of the line (which happens
instantaneously) in order to buy more tickets. If a person does not have any
tickets left to buy, the person will leave the line.

Return the time taken for the person at position k to finish buying tickets.

Also, mention the Time and Space Complexity of your solution.



Constraints:

    n == tickets.length

    1 <= n <= 100

    1 <= tickets[i] <= 100

    0 <= k < n



Example 1:

Input: tickets = [2,3,2], k = 2

Output: 6

Explanation:

- In the first pass, everyone in the line buys a ticket and the line becomes [1,
2, 1].

- In the second pass, everyone in the line buys a ticket and the line becomes
[0, 1, 0].

The person at position 2 has successfully bought 2 tickets and it took 3 + 3 = 6
seconds.



Example 2:

Input: tickets = [5,1,1,1], k = 0

Output: 8

Explanation:

- In the first pass, everyone in the line buys a ticket and the line becomes [4,
0, 0, 0].

- In the next 4 passes, only the person in position 0 is buying tickets.

The person at position 0 has successfully bought 5 tickets and it took 4 + 1 + 1
+ 1 + 1 = 8 seconds.

*/