#include <iostream>
#include "Solution.cpp"

using namespace std;

int main()
{
    int num, digitSum, i;
    Solution solution;

    printf("Enter a number: ");
    scanf("%d", &num);

    for (i = 0; i < num; i++)
    {
        digitSum = solution.addDigits(i);
        printf("%d => %d\n", i, digitSum);
    }

    exit(0);
}