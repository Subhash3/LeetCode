#include <string>

using namespace std;

class Solution
{
public:
    int scoreOfParentheses(string S)
    {
        int depth = 0, score = 0, i;
        bool sawOpen;

        for (i = 0; i < S.length(); i++)
        {
            if (S[i] == '(')
            {
                sawOpen = true;
                depth += 1;
            }
            else
            {
                depth -= 1;
                if (sawOpen)
                {
                    score += (1 << depth);
                }
                sawOpen = false;
            }
        }

        return score;
    }
};