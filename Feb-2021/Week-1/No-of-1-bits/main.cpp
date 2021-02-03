#include <iostream>
#include <cstdint>
#include "Solution.cpp"

using namespace std;

int main()
{
    uint32_t num;
    int noOfOnes;
    Solution solution;

    cout << "Enter a number: ";
    cin >> num;

    noOfOnes = solution.hammingWeight(num);
    cout << "No of 1s: " << noOfOnes << endl;

    exit(0);
}