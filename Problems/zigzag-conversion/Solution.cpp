#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }

        vector<string> rows;
        int i;
        string ans;
        bool down = true;

        rows = vector<string>(numRows, "");

        i = 0;
        for (char ch : s)
        {
            rows[i] += ch;
            // printf("Adding %c to row %d\n", ch, i + 1);
            if (down)
            {
                i += 1;
                if (i >= numRows)
                {
                    i = numRows - 2;
                    down = false;
                }
            }
            else
            {
                i -= 1;
                if (i < 0)
                {
                    i = 1;
                    down = true;
                }
            }
        }

        ans = "";
        for (string row : rows)
        {
            ans += row;
        }

        return ans;
    }
};