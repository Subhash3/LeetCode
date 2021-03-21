#include <vector>

using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int i, j, bought, sold, n;

        n = prices.size();
        bought = 0;
        sold = -1 * prices[0];
        for (i = 1; i < n; i++)
        {
            bought = max(bought, sold + prices[i] - fee);
            sold = max(sold, bought - prices[i]);
        }

        return bought;
    }
};