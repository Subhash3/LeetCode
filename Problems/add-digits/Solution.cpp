class Solution
{
public:
    int addDigits(int num)
    {
        if (num == 0)
            return 0;

        return ((num - 1) % 9) + 1;
    }
};

// Run main.cpp to take a look at the pattern