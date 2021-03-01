#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution
{
public:
    int n;
    vector<vector<int>> grid;
    set<vector<int>> visitedCells;

    bool checkIfACellIsValid(int i, int j)
    {
        vector<int> cell;
        cell.push_back(i);
        cell.push_back(j);

        bool isVisited = (this->visitedCells.find(cell) != this->visitedCells.end());
        return (i >= 0 && i < this->n && j >= 0 && j < this->n && this->grid[i][j] == 0 && !isVisited);
    }

    void findShortestPath(int i, int j, int length, int *shortest)
    {
        // printf("f(length: %d)\n", length);
        vector<int> cell;
        cell.push_back(i);
        cell.push_back(j);

        if (!checkIfACellIsValid(i, j))
        {
            // printf("Cell (%d, %d) is not valid\n", i, j);
            return;
        }

        this->visitedCells.insert(cell);

        // printf("Cell (%d, %d) is VALID\n", i, j);
        if (i == this->n - 1 && j == this->n - 1)
        {
            printf("Reached the last cell.\n");
            if (*shortest == -1 || length < *shortest)
            {
                printf("Shortest: %d, length:%d\n", *shortest, length);
                *shortest = length;
            }
            this->visitedCells.erase(cell);
            return;
        }

        findShortestPath(i + 1, j + 1, length + 1, shortest);
        findShortestPath(i, j + 1, length + 1, shortest);
        findShortestPath(i + 1, j, length + 1, shortest);
        findShortestPath(i, j - 1, length + 1, shortest);
        findShortestPath(i - 1, j, length + 1, shortest);
        findShortestPath(i - 1, j - 1, length + 1, shortest);
        findShortestPath(i - 1, j + 1, length + 1, shortest);
        findShortestPath(i + 1, j - 1, length + 1, shortest);
        this->visitedCells.erase(cell);

        return;
    }

    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int shortest = -1;
        this->n = grid.size();
        this->grid = grid;
        findShortestPath(0, 0, 1, &shortest);

        return shortest;
    }
};