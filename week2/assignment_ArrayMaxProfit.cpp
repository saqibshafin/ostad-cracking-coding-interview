// Time complexity: O(n^2)
// Space complexity: O(1)

#include <iostream>

using namespace std;

int main (){
    int size;

    cin >> size;
    
    int prices[size];

    for (int i =0; i<size; i++) {
        int price;
        cin >> price;
        prices[i] = price;
    }

    for (int i:prices) {
        cout << i << " ";
    }
    cout << endl;
    for (int i=0; i<size; i++) {
        cout << prices[i] << " ";
    }
    cout << endl;

    // 1 2 5 6 7 3 4 2 4
    // 2 2 5 6 7 1 4 2 7
    // 6 5 5 6 7 1 4 2 4
    int maxProfit = 0;
    for (int i=0; i<size; i++) {
        int profit;
        // starting from 1 day after 'i':
        for (int j = i+1; j<size; j++) {
            profit = prices[j] - prices[i];
            if (profit > maxProfit) maxProfit = profit;
        }
    }

    cout << maxProfit << endl;

    return 0;
}



/*

Assignment on Array

    Write a function that does the following task.

    You are given an array prices where prices[i] is the price of a given stock on the ith day.

    You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

    Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

    Also, mention the Time and Space Complexity of your solution
    

    Constraints: 

    1 <= prices.length <= 105

    0 <= prices[i] <= 104
    

    Example 1:

    Input: prices = [7,1,5,3,6,4]

    Output: 5

    Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.

    Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.


    Example 2:

    Input: prices = [7,6,4,3,1]

    Output: 0

    Explanation: In this case, no transactions are done and the max profit = 0.

*/