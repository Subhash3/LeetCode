#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int getShortestDistToAChar(char c, int index, vector<int> indicesOfC)
    {
        int minDist = -1, i, size = indicesOfC.size(), dist;

        for (i = 0; i < size; i++)
        {
            dist = abs(index - indicesOfC[i]);
            if (minDist == -1 || minDist > dist)
            {
                minDist = dist;
            }
        }

        return minDist;
    }

    vector<int> shortestToChar(string s, char c)
    {
        vector<int> indicesOfC, shortestDistances;
        int i, stringLen, dist;

        stringLen = s.length();
        for (i = 0; i < stringLen; i++)
        {
            if (s[i] == c)
            {
                indicesOfC.push_back(i);
            }
        }

        for (i = 0; i < stringLen; i++)
        {
            dist = getShortestDistToAChar(c, i, indicesOfC);
            shortestDistances.push_back(dist);
        }

        return shortestDistances;
    }
};