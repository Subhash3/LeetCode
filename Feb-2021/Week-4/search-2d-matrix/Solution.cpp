#include <vector>

using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int i, j, rows, cols;

        rows = matrix.size();
        cols = matrix[0].size();

        i = 0;
        j = cols - 1;
        while (i < rows && j >= 0)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
            if (matrix[i][j] > target)
            {
                j -= 1;
            }
            else
            {
                i += 1;
            }
        }

        return false;
    }
};