#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        stack<int> A, B;
        char a, b;

        for (char a : S)
        {
            if (a == '#')
            {
                if (A.empty())
                {
                    continue;
                }
                A.pop();
            }
            else
            {
                A.push(a);
            }
        }

        for (char b : T)
        {
            if (b == '#')
            {
                if (B.empty())
                {
                    continue;
                }
                B.pop();
            }
            else
            {
                B.push(b);
            }
        }

        if (A.size() != B.size())
        {
            return false;
        }

        while (!A.empty())
        {
            a = A.top();
            b = B.top();

            if (a != b)
            {
                return false;
            }

            A.pop();
            B.pop();
        }

        return true;
    }
};