#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool doesWordOccurInStr(string word, string str)
    {
        int wordLen, strLen;
        int i, j;

        wordLen = word.length();
        strLen = str.length();

        j = 0;
        for (i = 0; i < strLen; i++)
        {
            if (str[i] == word[j])
            {
                j += 1;
                if (j == wordLen)
                {
                    return true;
                }
            }
        }

        return false;
    }

    string getLowestLexigraphicWord(string a, string b)
    {
        // Both a and b are of same length
        int i, j, len, charA, charB;

        len = a.length();

        for (i = 0, j = 0; i < len && j < len; i++, j++)
        {
            charA = a[i];
            charB = b[j];

            if (charA < charB)
            {
                return a;
            }
            else if (charB < charA)
            {
                return b;
            }
        }

        return a;
    }

    string findLongestWord(string s, vector<string> &d)
    {
        string word, longestWord = "";
        int i, noOfStrings, maxLen = -1, wordLen;
        bool occurs;

        noOfStrings = d.size();
        for (i = 0; i < noOfStrings; i++)
        {
            word = d[i];
            wordLen = word.length();
            occurs = doesWordOccurInStr(word, s);
            if (occurs)
            {
                if (wordLen > maxLen)
                {
                    maxLen = wordLen;
                    longestWord = word;
                }
                else if (wordLen == maxLen)
                {
                    longestWord = getLowestLexigraphicWord(word, longestWord);
                }
            }
        }

        return longestWord;
    }
};