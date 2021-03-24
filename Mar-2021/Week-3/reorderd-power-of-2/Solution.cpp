#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    unordered_map<int, int> getDigitsMap(int N, int &size)
    {
        unordered_map<int, int> digitsMap;
        int digit, n;

        n = 0;
        while (N != 0)
        {
            digit = N % 10;
            if (digitsMap.find(digit) == digitsMap.end())
            {
                digitsMap[digit] = 1;
            }
            else
            {
                digitsMap[digit] += 1;
            }
            n += 1;
            N /= 10;
        }

        size = n;
        return digitsMap;
    }

    bool reorderedPowerOf2(int N)
    {
        unordered_map<int, int> digitsMap, digitsMap2;
        vector<vector<int>> numLenToPowersMap;
        vector<int> powersArr;
        int numLen, n, power, noOfDigits, i;

        digitsMap = getDigitsMap(N, noOfDigits);

        power = 0;
        for (numLen = 1; numLen <= 9; numLen++)
        {
            n = 3;
            if (((numLen - 1) % 3) == 0)
            {
                n = 4;
            }
            vector<int> powersArr;
            while (n--)
            {
                powersArr.push_back(power);
                power += 1;
            }
            numLenToPowersMap.push_back(powersArr);
        }

        powersArr = numLenToPowersMap[noOfDigits - 1];
        for (int num : powersArr)
        {
            digitsMap2 = getDigitsMap(1 << num, noOfDigits);
            if (digitsMap == digitsMap2)
            {
                return true;
            }
        }

        return false;
    }
};