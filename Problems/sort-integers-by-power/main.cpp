#include <iostream>
#include "Solution.cpp"

int main()
{
    int lo, hi, k, val;
    Solution solution;

    printf("Enter lo, hi and k: ");
    scanf("%d %d %d", &lo, &hi, &k);

    val = solution.getKth(lo, hi, k);

    printf("Val: %d\n", val);

    exit(0);
}