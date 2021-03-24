#include <vector>
#include <unordered_map>

using namespace std;

#define MODULO 1000000007
#define MAX_NUM 101

class Solution
{
public:
    int threeSumMulti(vector<int> &arr, int target)
    {
        int count, n, i, pairs;

        count = 0;
        n = arr.size();
        for (i = 0; i < n; i++)
        {
            pairs = countPairs(arr, n, target - arr[i], i + 1);
            count = (count + pairs % MODULO) % MODULO;
        }

        return count % MODULO;
    }

    int countPairs(vector<int> arr, int n, int sum, int start)
    {
        vector<int> numToFreqMap(MAX_NUM);
        int i, count;

        for (i = start; i < n; i++)
        {
            numToFreqMap[arr[i]] += 1;
        }

        count = 0;
        for (i = start; i < n; i++)
        {
            if (((sum - arr[i] < MAX_NUM) && (sum - arr[i] >= 0)) && (numToFreqMap[sum - arr[i]] != 0))
            {
                count += numToFreqMap[sum - arr[i]];
            }
            if (sum - arr[i] == arr[i])
            {
                count -= 1;
            }
        }

        return count / 2;
    }
};