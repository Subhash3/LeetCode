#include <vector>

using namespace std;

class Solution
{
public:
    int m, n;

    void swap(int *a, int *b)
    {
        int temp = *a;

        *a = *b;
        *b = temp;

        return;
    }

    void shiftGrid(vector<vector<int>> &grid)
    {
        int i, j;

        for (i = 0; i < this->m; i++)
        {
            for (j = 0; j < this->n; j++)
            {
                swap(&grid[i][j], &grid[0][0]);
            }
        }

        return;
    }

    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        int i, j;

        this->m = grid.size();
        this->n = grid[0].size();

        k = k % (this->m * this->n);

        while (k--)
        {
            this->shiftGrid(grid);
        }

        return grid;
    }
};