#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void displayHashMap();

    int findLHS(vector<int> &nums)
    {
        unordered_map<int, int> numToFreqMap;
        vector<int> uniqueNumbers; // Basicaly this is the list of keys of numToFreqMap
        int i, size, noOfUniqueNumbers = 0;
        int len, maxLen = 0, a, b;

        // Computin the numToFreqMap
        size = nums.size();
        for (i = 0; i < size; i++)
        {
            // If num is not present in numToFreqMap
            if (numToFreqMap.find(nums[i]) == numToFreqMap.end())
            {
                numToFreqMap[nums[i]] = 1;
                uniqueNumbers.push_back(nums[i]);
                noOfUniqueNumbers++;
            }
            else
            {
                numToFreqMap[nums[i]] += 1;
            }
        }

        // Sort the uniqueNumbers array(keys)
        sort(uniqueNumbers.begin(), uniqueNumbers.end());

        // Main algo
        for (i = 0; i < noOfUniqueNumbers - 1; i++)
        {
            a = uniqueNumbers[i];
            b = uniqueNumbers[i + 1];

            // If difference == 1 => they make a harmonious subseq with len = sum(freqs of those two numbers)
            if ((b - a) == 1)
            {
                len = numToFreqMap[a] + numToFreqMap[b];
                if (maxLen == 0 || len > maxLen)
                {
                    maxLen = len;
                }
            }
        }

        return maxLen;
    }
};