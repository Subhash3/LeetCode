#include <iostream>
#include "Solution.cpp"

using namespace std;

int main()
{
    int num, steps;
    Solution solution;

    // printf("Enter num: ");
    // cin >> num;

    for (num = 1; num < 150; num++)
    {
        steps = solution.numberOfSteps(num);
        printf("Num: %d => Steps: %d\n", num, steps);
    }

    exit(0);
}