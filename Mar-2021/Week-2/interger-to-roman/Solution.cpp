#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    unordered_map<int, string> basicIntToRomanMap;

    void prepare()
    {
        basicIntToRomanMap[1] = "I";
        basicIntToRomanMap[4] = "IV";
        basicIntToRomanMap[5] = "V";
        basicIntToRomanMap[9] = "IX";
        basicIntToRomanMap[10] = "X";
        basicIntToRomanMap[40] = "XL";
        basicIntToRomanMap[50] = "L";
        basicIntToRomanMap[90] = "XC";
        basicIntToRomanMap[100] = "C";
        basicIntToRomanMap[400] = "CD";
        basicIntToRomanMap[500] = "D";
        basicIntToRomanMap[900] = "CM";
        basicIntToRomanMap[1000] = "M";
    }

    string convertToRoman(int num, int placeValue)
    {
        if (basicIntToRomanMap.find(num) != basicIntToRomanMap.end())
        {
            return basicIntToRomanMap[num];
        }

        string romanRepresentation;
        int i;

        romanRepresentation = "";
        if ((num / placeValue) <= 3)
        {
            for (i = 0; i < num / placeValue; i++)
            {
                romanRepresentation += basicIntToRomanMap[placeValue];
            }
        }
        else // num / placeValue = [6, 8]
        {
            romanRepresentation += basicIntToRomanMap[5 * placeValue];
            num -= 5 * placeValue;
            for (i = 0; i < num / placeValue; i++)
            {
                romanRepresentation += basicIntToRomanMap[placeValue];
            }
        }

        return romanRepresentation;
    }

    string intToRoman(int num)
    {
        prepare();

        int digit, placeValue;
        string romanRepresentation;

        romanRepresentation = "";
        placeValue = 1;
        while (num != 0)
        {
            digit = num % 10;
            romanRepresentation = convertToRoman(digit * placeValue, placeValue) + romanRepresentation;
            placeValue *= 10;
            num /= 10;
        }

        return romanRepresentation;
    }
};