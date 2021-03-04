#include <iostream>
#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lo, hi;
    unordered_map<int, int> lookup;

    int computePower(int x)
    {
        // printf("f(%d)\n", x);
        if (this->lookup.find(x) != this->lookup.end())
        {
            return this->lookup[x];
        }

        if (x == 1)
        {
            return 0;
        }

        int p, newX;

        if ((x & 1) == 0)
        {
            newX = x / 2;
        }
        else
        {
            newX = 3 * x + 1;
        }

        p = computePower(newX);
        this->lookup[newX] = p;
        this->lookup[x] = 1 + p;

        return 1 + p;
    }

    // Custom comparator
    static bool compare(int a, int b)
    {
        int powerA, powerB;
        Solution solution;

        powerA = solution.computePower(a);
        powerB = solution.computePower(b);
        if (powerA < powerB)
        {
            return true;
        }
        if (powerA == powerB)
        {
            if (a < b)
            {
                return true;
            }
        }
        return false;
    }

    int getKth(int lo, int hi, int k)
    {
        int num;
        int power;
        vector<int> arr;

        this->lo = lo;
        this->hi = hi;

        for (num = this->lo; num <= this->hi; num++)
        {
            arr.push_back(num);
            power = computePower(num);
            printf("%d => %d\n", num, power);
        }

        sort(arr.begin(), arr.end(), compare);
        for (int num : arr)
        {
            printf("%d: %d\n", num, lookup[num]);
        }

        // for (auto it : this->lookup)
        // {
        //     // printf("%d : %d\n", it.first, it.second);
        // }

        return arr[k - 1];
    }
};