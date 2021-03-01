class Solution
{
public:
    int numberOfSteps(int num)
    {
        int steps = 0;

        while (num != 0)
        {
            if (num & 1)
            {
                steps += 2;
            }
            else
            {
                steps += 1;
            }
            num >>= 1;
        }

        return steps - 1;
    }
};

/*
    Eg: 123
    Ans: 12

    We divide by 2 if it is even.
    We subtract 1 if it is odd.

    123 in binary is 
    1111010

    Same algo in binary terms :D
        - If last bit is 0, remove it (Right Shift. Equivalent to dividing 2)
        - If it is 1, make it 0 (Equivalent to subtracting 1).
    
    So, if at any point the last bit is 1, we make it zero. Which means in the next step we simply remove it.
    If 0, we simply remove it.

    Clearly, no. of steps = no. of 0s + 2 * no. of 1s
*/