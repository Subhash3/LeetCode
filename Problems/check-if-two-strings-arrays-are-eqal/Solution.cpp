#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        int w1, i, w2, j, s1, s2, l1, l2, parsed1 = 0, parsed2 = 0;

        w1 = 0;
        i = 0;
        w2 = 0;
        j = 0;
        s1 = word1[w1].size();
        s2 = word2[w2].size();
        l1 = word1.size();
        l2 = word2.size();

        parsed1 += s1;
        parsed2 += s2;

        while (true)
        {
            if (i >= s1)
            {
                i = 0;
                w1 += 1;
                if (w1 >= l1)
                {
                    break;
                }
                s1 = word1[w1].size();
                parsed1 += s1;
            }
            if (j >= s2)
            {
                j = 0;
                w2 += 1;
                if (w2 >= l2)
                {
                    break;
                }
                s2 = word2[w2].size();
                parsed2 += s2;
            }

            if (word1[w1][i] != word2[w2][j])
            {
                return false;
            }
            i += 1;
            j += 1;
        }

        if (parsed1 != parsed2)
        {
            return false;
        }

        return true;
    }
};