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