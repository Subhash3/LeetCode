#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        int i, noOfDistinctStrings, N;
        unordered_set<string> distinctStrings;
        string subString;

        noOfDistinctStrings = 0;
        N = s.length();
        for (i = 0; i + k <= N; i++)
        {
            if (noOfDistinctStrings == (1 << k))
            {
                return true;
            }

            subString = s.substr(i, k);
            if (distinctStrings.find(subString) == distinctStrings.end())
            {
                noOfDistinctStrings += 1;
                distinctStrings.insert(subString);
            }
        }

        return noOfDistinctStrings == (1 << k);
    }
};