#include <vector>
#include <set>
#include <iostream>
#include <queue>

using namespace std;

/*
        VQ
        00
        01      V => Visited
        10      Q => On queue
        11
*/

#define VISITED 1  // 00000001
#define ON_QUEUE 2 // 00000010

class Solution
{
public:
    int n;
    vector<vector<int>> grid;
    set<vector<int>> visitedCells;
    vector<vector<int>> metadata;

    void setVisitedStatus(int i, int j)
    {
        this->metadata[i][j] = this->metadata[i][j] | VISITED;

        return;
    }

    void setOnQueueStatus(int i, int j)
    {
        this->metadata[i][j] = this->metadata[i][j] | ON_QUEUE;

        return;
    }

    void clearOnQueueStatus(int i, int j)
    {
        this->metadata[i][j] = this->metadata[i][j] & ~(ON_QUEUE);

        return;
    }

    vector<int> Cell(int i, int j)
    {
        vector<int> cell;

        cell.push_back(i);
        cell.push_back(j);

        return cell;
    }

    int getVisitedStatus(int i, int j)
    {
        // // printf("inside getVisitedStatus(%d, %d)\n", i, j);
        // // printf("VISITED: %d\n", VISITED);
        // // printf("metadata[i][j]: %d\n", this->metadata[i][j]);
        return this->metadata[i][j] & VISITED;
    }

    int getOnQueueStatus(int i, int j)
    {
        // // printf("inside getOnQueueStatus(%d, %d)\n", i, j);
        // // printf("ON_QUEUE: %d\n", ON_QUEUE);
        // // printf("metadata[i][j]: %d\n", this->metadata[i][j]);
        return this->metadata[i][j] & ON_QUEUE;
    }

    bool isValidCell(int i, int j)
    {
        // // printf("Inside isValidCell(%d, %d)\n", i, j);
        if (i >= 0 && i < this->n && j >= 0 && j < this->n)
        {
            // // printf("n: %d, grid[i][j]: %d\n", n, grid[i][j]);
            // // printf("visited: %d\n", getVisitedStatus(i, j));
            // // printf("on-queue: %d\n", getOnQueueStatus(i, j));
            if (this->grid[i][j] != 1 && !(getVisitedStatus(i, j)) && !(getOnQueueStatus(i, j)))
            {
                return true;
            }
        }
        return false;
    }

    vector<vector<int>> getValidChildren(int i, int j)
    {
        vector<vector<int>> children;

        // printf("Inside getValidChildren(%d, %d)\n", i, j);

        if (isValidCell(i - 1, j - 1))
        {
            children.push_back(Cell(i - 1, j - 1));
        }
        if (isValidCell(i - 1, j))
        {
            children.push_back(Cell(i - 1, j));
        }
        if (isValidCell(i - 1, j + 1))
        {
            children.push_back(Cell(i - 1, j + 1));
        }
        if (isValidCell(i, j - 1))
        {
            children.push_back(Cell(i, j - 1));
        }
        if (isValidCell(i, j + 1))
        {
            children.push_back(Cell(i, j + 1));
        }
        if (isValidCell(i + 1, j - 1))
        {
            children.push_back(Cell(i + 1, j - 1));
        }
        if (isValidCell(i + 1, j))
        {
            children.push_back(Cell(i + 1, j));
        }
        if (isValidCell(i + 1, j + 1))
        {
            children.push_back(Cell(i + 1, j + 1));
        }

        return children;
    }

    int bfs()
    {
        // printf("Inside BFS\n");
        int level = 0, k, levelSize;
        vector<int> cell;
        vector<vector<int>> children;
        queue<vector<int>> cellQueue;

        // printf("Pushing the first cell (0, 0)\n");
        cellQueue.push(Cell(0, 0));
        setVisitedStatus(0, 0);
        setOnQueueStatus(0, 0);

        while (!cellQueue.empty())
        {
            level += 1;
            levelSize = cellQueue.size();
            // printf("level: %d contains %d cells\n", level, levelSize);
            for (k = 0; k < levelSize; k++)
            {
                cell = cellQueue.front();
                // printf("\tFront cell: (%d, %d)\n", cell[0], cell[1]);
                children = getValidChildren(cell[0], cell[1]);
                // printf("\tFor each valid child: \n");
                for (auto child : children)
                {
                    if (child[0] == this->n - 1 && child[1] == this->n - 1)
                    {
                        return level + 1;
                    }
                    // printf("\t\tPushing the child (%d, %d)\n", child[0], child[1]);
                    cellQueue.push(child);
                    setVisitedStatus(child[0], child[1]);
                    setOnQueueStatus(child[0], child[1]);
                }
                // printf("Dequeuing (%d, %d)\n", cell[0], cell[1]);
                cellQueue.pop();
                clearOnQueueStatus(cell[0], cell[1]);
            }
        }

        if (getVisitedStatus(this->n - 1, this->n - 1))
        {
            // printf("Last cell has been visited\nRetuning %d\n", level);
            return level;
        }
        else
        {
            // printf("Last cell hasn't been visited\nRetuning -1\n");
            return -1;
        }
    }

    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int shortest, i, j;

        this->n = grid.size();
        this->grid = grid;
        if (grid[0][0] == 1 || grid[this->n - 1][this->n - 1] == 1)
        {
            return -1;
        }

        for (i = 0; i < this->n; i++)
        {
            vector<int> row;
            for (j = 0; j < this->n; j++)
            {
                row.push_back(0); // 00000000 => is not visited neither is it on queue.
            }
            this->metadata.push_back(row);
        }

        shortest = bfs();

        return shortest;
    }
};