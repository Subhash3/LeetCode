#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <bits/stdc++.h>

#define MODULO 1000000007

using namespace std;

class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        unordered_set<int> setRep(arr.begin(), arr.end());
        unordered_map<int, long> numToTreeCountMap;
        int n, i, j, sum;

        for (int num : arr)
        {
            numToTreeCountMap[num] = 1;
        }

        sort(arr.begin(), arr.end());
        n = arr.size();
        for (i = 0; i < n; i++)
        {
            numToTreeCountMap[arr[i]] = 1;
            for (j = 0; j < i; j++)
            {
                if ((arr[i] % arr[j]) == 0)
                {
                    if (setRep.find(arr[i] / arr[j]) != setRep.end())
                    {
                        numToTreeCountMap[arr[i]] += ((numToTreeCountMap[(arr[i] / arr[j])] % MODULO) * (numToTreeCountMap[arr[j]] % MODULO)) % MODULO;
                    }
                }
            }
        }

        sum = 0;
        for (auto it : numToTreeCountMap)
        {
            // printf("%d: %d\n", it.first, it.second);
            sum = (sum % MODULO + it.second % MODULO) % MODULO;
        }

        return sum % MODULO;
    }
};