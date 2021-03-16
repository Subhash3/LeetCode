#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    static bool compareStrings(string a, string b)
    {
        return a.size() > b.size();
    }
    int minimumLengthEncoding(vector<string> &words)
    {
        string str = "";
        sort(words.begin(), words.end(), compareStrings);
        for (string word : words)
        {
            int found = str.find(word);
            if (found == string::npos || str[found + word.size()] != '#')
            {
                str += word + "#";
            }
        }
        return str.size();
    }
};