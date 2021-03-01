#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> sFreq, tFreq;
        int i, sLen, tLen;
        char letter;

        sLen = s.length();
        tLen = t.length();
        if (sLen != tLen)
        {
            return false;
        }

        for (letter = 97; letter <= 122; letter++)
        {
            sFreq[letter] = 0;
            tFreq[letter] = 0;
        }

        for (i = 0; i < sLen; i++)
        {
            letter = s[i];
            sFreq[letter] += 1;

            letter = t[i];
            tFreq[letter] += 1;
        }

        for (letter = 97; letter <= 122; letter++)
        {
            if (sFreq[letter] != tFreq[letter])
            {
                return false;
            }
        }

        return true;
    }
};