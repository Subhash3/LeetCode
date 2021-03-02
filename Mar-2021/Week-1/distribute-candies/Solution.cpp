#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        unordered_set<int> differentCandyTypes;
        int n = 0, m = 0;

        for (int candy : candyType)
        {
            n += 1;
            if (differentCandyTypes.find(candy) == differentCandyTypes.end())
            {
                differentCandyTypes.insert(candy);
                m += 1;
            }
        }

        if (n / 2 >= m)
        {
            return m;
        }
        else
        {
            return n / 2;
        }
    }
};