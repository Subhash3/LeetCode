#include <string>

using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        bool seenNonSpace = false, firstNonSpaceChar = true;
        int i, len, sign = 1, digit;
        long long number = 0;

        len = s.length();
        for (i = 0; i < len; i++)
        {
            if (s[i] == ' ')
            {
                // printf("It is a space\n");
                if (seenNonSpace)
                {
                    // printf("Occured in the middle. Stop reading!\n");
                    // Stop reading;
                    break;
                }
                else
                {
                    // printf("It is a leading space. Ignoring\n");
                    // Ignore space
                    continue;
                }
            }
            seenNonSpace = true;
            if (firstNonSpaceChar)
            {
                // printf("%c is the first non-space char\n", s[i]);
                firstNonSpaceChar = false;
                if (s[i] == '-')
                {
                    // printf("It is a -ve sign\n");
                    sign = -1;
                    continue;
                }
                if (s[i] == '+')
                {
                    // printf("It is a +ve sign\n");
                    sign = 1;
                    continue;
                }
            }
            if (isdigit(s[i]))
            {
                // printf("%c is a valid digit: %d\n", s[i], s[i] - '0');
                digit = s[i] - '0';

                if (number > INT32_MAX / 10 || (number == INT32_MAX / 10 && digit > 7))
                    number = abs(INT32_MAX);
                if (number < INT32_MIN / 10 || (number == INT32_MIN / 10 && digit < -8))
                    number = abs(INT32_MIN);

                number = number * 10 + digit;
            }
            else
            {
                // printf("Non digit char occured in the middle. Stop Reading.\n");
                break;
            }
        }

        number *= sign;
        if (number < INT32_MIN)
        {
            number = INT32_MIN;
        }
        if (number > INT32_MAX)
        {
            number = INT32_MAX;
        }

        return number;
    }
};