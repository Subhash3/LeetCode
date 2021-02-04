#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

void displayVector(vector<int> arr);

int main()
{
    vector<int> nums;
    int val, longestHS;
    Solution solution;

    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }

        nums.push_back(val);
    }

    longestHS = solution.findLHS(nums);

    exit(0);
}

void displayVector(vector<int> arr)
{
    int i, size;

    size = arr.size();

    for (i = 0; i < size; i++)
    {
        cout << arr[i] << ", " << flush;
    }
    cout << "\b\b\n";

    return;
}