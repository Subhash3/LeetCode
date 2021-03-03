#include <iostream>
#include <vector>
#include "Solution.cpp"

int main()
{
    vector<int> arr;
    int num, target, value;
    Solution solution;

    printf("Enter numbers separated by spaces. End with -1: \n");
    while (true)
    {
        scanf("%d", &num);
        if (num == -1)
        {
            break;
        }
        arr.push_back(num);
    }
    printf("Enter target: ");
    scanf("%d", &target);

    value = solution.findBestValue(arr, target);

    printf("Value: %d\n", value);

    exit(0);
}