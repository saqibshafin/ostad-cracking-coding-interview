/*
Sorry, I am sick, and this program doesnt work as expected. Couldn't think
straight. Sorry.
*/

/* https://www.geeksforgeeks.org/stock-buy-sell/ */

// Time complexity:
// Space complexity:

#include <bits/stdc++.h>

using namespace std;

// Function to return the maximum profit
// that can be made after buying and
// selling the given stocks
int maxProfit(int price[], int start, int end) {

    // If the stocks can't be bought
    if (end <= start)
        return 0;

    // Initialise the profit
    int profit = 0;

    // The day at which the stock
    // must be bought
    for (int i = start; i < end; i++) {

        // The day at which the
        // stock must be sold
        for (int j = i + 1; j <= end; j++) {

            // If buying the stock at ith day and
            // selling it at jth day is profitable
            if (price[j] > price[i]) {

                // Update the current profit
                int curr_profit = price[j] - price[i] +
                                  maxProfit(price, start, i - 1) +
                                  maxProfit(price, j + 1, end);

                // Update the maximum profit so far
                profit = max(profit, curr_profit);
            }
        }
    }
    return profit;
}

// Driver code
int main() {
    int price[] = {100, 180, 260, 310, 40, 535, 695};
    int n = sizeof(price) / sizeof(price[0]);

    cout << maxProfit(price, 0, n - 1);

    return 0;
}

/*

Write a function that does the following task.



You are given an integer array prices where prices[i] is the price of a given
stock on the ith day.



On each day, you may decide to buy and/or sell the stock. You can only hold at
most one share of the stock at any time. However, you can buy it then
immediately sell it on the same day.



Find and return the maximum profit you can achieve.



Mention the time and space complexity of your solution.



Constraints:



    1 <= prices.length <= 3 * 10^4



    0 <= prices[i] <= 10^4





Example 1:

Input: prices = [7,1,5,3,6,4]

Output: 7

Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit =
5-1 = 4.

Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.

Total profit is 4 + 3 = 7.



Example 2:

Input: prices = [1,2,3,4,5]

Output: 4

Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit =
5-1 = 4.

Total profit is 4.



Example 3:

Input: prices = [7,6,4,3,1]

Output: 0

Explanation: There is no way to make a positive profit, so we never buy the
stock to achieve the maximum profit of 0.

*/