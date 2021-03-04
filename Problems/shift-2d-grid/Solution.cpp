#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int m, n;

    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k)
    {
        int i, j, count, t, mn;
        vector<int> arrForm, row;
        vector<vector<int>> newGrid;

        this->m = grid.size();
        this->n = grid[0].size();

        mn = this->m * this->n;

        k = k % (mn);

        for (i = 0; i < this->m; i++)
        {
            for (j = 0; j < this->n; j++)
            {
                arrForm.push_back(grid[i][j]);
            }
        }

        count = 0;
        t = mn - k;

        for (int i = 0; i < this->n; i++)
        {
            row.push_back(0);
        }

        while (count < mn)
        {
            if (t >= mn)
            {
                t = 0;
            }

            row[count % this->n] = arrForm[t];
            t += 1;
            count += 1;
            if (count % this->n == 0)
            {
                newGrid.push_back(row);
            }
        }

        return newGrid;
    }
};