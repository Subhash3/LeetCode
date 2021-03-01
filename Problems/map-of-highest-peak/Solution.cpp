#include <vector>

using namespace std;

class Solution
{
public:
    int rows, cols;

    bool isValidCell(int i, int j)
    {
        return (i >= 0 && i < rows && j >= 0 && j < cols);
    }

    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        vector<vector<int>> heights;
        int rows, cols, i, j, unAssignedCells = 0, current = 0;

        rows = isWater.size();
        cols = isWater[0].size();

        this->rows = rows;
        this->cols = cols;

        for (i = 0; i < rows; i++)
        {
            vector<int> row;
            for (j = 0; j < cols; j++)
            {
                if (isWater[i][j] == 0)
                {
                    row.push_back(-1);
                    unAssignedCells += 1;
                }
                else
                {
                    row.push_back(0);
                }
            }
            heights.push_back(row);
        }

        while (unAssignedCells > 0)
        {
            for (i = 0; i < rows; i++)
            {
                for (j = 0; j < cols; j++)
                {
                    if (heights[i][j] == current)
                    {
                        if (isValidCell(i, j - 1) && heights[i][j - 1] == -1)
                        {
                            heights[i][j - 1] = current + 1;
                            unAssignedCells -= 1;
                        }
                        if (isValidCell(i, j + 1) && heights[i][j + 1] == -1)
                        {
                            heights[i][j + 1] = current + 1;
                            unAssignedCells -= 1;
                        }
                        if (isValidCell(i - 1, j) && heights[i - 1][j] == -1)
                        {
                            heights[i - 1][j] = current + 1;
                            unAssignedCells -= 1;
                        }
                        if (isValidCell(i + 1, j) && heights[i + 1][j] == -1)
                        {
                            heights[i + 1][j] = current + 1;
                            unAssignedCells -= 1;
                        }
                    }
                }
            }
            current += 1;
        }

        return heights;
    }
};