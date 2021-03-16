#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool endsWith(string str, string word)
    {
        int strLen, wordLen, i, j;

        strLen = str.length();
        wordLen = word.length();

        if (strLen < wordLen)
        {
            return false;
        }

        for (i = strLen - wordLen, j = 0; i < strLen; i++, j++)
        {
            if (str[i] != word[j])
            {
                return false;
            }
        }

        return true;
    }

    int minimumLengthEncoding(vector<string> &words)
    {
        unordered_set<string> uniqueWordsSet, duplicates;
        vector<string> uniqueWords;
        int len, i, j, ans, noOfDuplicates;

        len = words.size();
        noOfDuplicates = 0;

        for (i = 0; i < len; ++i)
        {
            if (uniqueWordsSet.find(words[i]) == uniqueWordsSet.end())
            {
                uniqueWords.push_back(words[i]);
            }
            else
            {
                noOfDuplicates += 1;
            }
            uniqueWordsSet.insert(words[i]);
        }

        len -= noOfDuplicates;

        for (i = 0; i < len; ++i)
        {
            for (j = 0; j < len; ++j)
            {
                if (i == j)
                {
                    continue;
                }
                if (endsWith(uniqueWords[i], uniqueWords[j]))
                {
                    duplicates.insert(uniqueWords[j]);
                }
            }
        }

        ans = 0;
        for (string word : uniqueWords)
        {
            if (duplicates.find(word) == duplicates.end())
            {
                ans += word.length();
                ans += 1; // # symbol
            }
        }

        return ans;
    }
};