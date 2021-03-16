#include <string>
#include <iostream>
#include "Solution.cpp"

using namespace std;

int main()
{
    int beautySum;
    Solution solution;
    string s;

    printf("Enter string: ");
    cin >> s;

    beautySum = solution.beautySum(s);
    printf("%d\n", beautySum);

    exit(0);
}