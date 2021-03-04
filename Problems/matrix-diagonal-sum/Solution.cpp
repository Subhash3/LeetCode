#include <vector>

using namespace std;

// Time: O(n), Space: O(1)
class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int n = mat.size(), sum = 0, i;

        for (i = 0; i < n; ++i)
        {
            sum += mat[i][i]; // Primary diagonal
            sum += mat[i][n - i - 1];
        }

        // n is odd
        if (n & 1)
        {
            sum -= mat[n / 2][n / 2];
        }

        return sum;
    }
};