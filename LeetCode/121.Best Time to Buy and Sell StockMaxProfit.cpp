/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit_1(vector<int>& prices)
    {
        int max_profit = 0;
        for (int i=0; i<prices.size()-1; ++i) {
            int i_max_profit = 0;
            for (int j=i+1; j<prices.size(); ++j) {
                int i_profit = prices[j] - prices[i];
                if (i_profit > i_max_profit)
                    i_max_profit = i_profit;
           }
            if (i_max_profit > max_profit)
                max_profit = i_max_profit;
        }
        return max_profit;
    }

    int maxProfit_2(vector<int>& prices)
    {
        int max_profit=0, begin=0, end=0, tmp=0;
        for(int i=0; i<prices.size(); ++i) {
            end = i;
            tmp = prices[end] - prices[begin];
            if(tmp <=0)
                begin = i;
            if(tmp > max_profit)
                max_profit = tmp;
        }
        return max_profit;
    }

    int maxProfit(vector<int>& prices)
    {
        return maxProfit_2(prices);
    }
};

int main()
{
    Solution SS;
    vector<int> prices;
    int a[] = {7, 1, 5, 3, 6, 4};
    for (int i=0; i<6; ++i){
         cout << a[i] << " ";
         prices.push_back(a[i]);
    }
    cout << endl;
    for(int i=0; i<prices.size(); ++i)
        cout << prices[i] << " ";
    cout << endl;
       
    cout << SS.maxProfit(prices) << endl;
    return 0;
}


