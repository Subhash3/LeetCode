#include <string>
#include <unordered_map>
#include <cstdlib>

using namespace std;

class Solution
{
public:
    unordered_map<string, string> shortUrlToLongMap;

    int randRange(int min, int max) //range : [min, max]
    {
        static bool first = true;
        if (first)
        {
            srand(time(NULL)); //seeding for the first time only!
            first = false;
        }
        return min + rand() % ((max + 1) - min);
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        string validChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
        string encoded;
        int randNum, requiredLen, encodedLen, noOfValidChars;
        bool shoudIInclude;

        encoded = "";
        requiredLen = 10;
        encodedLen = 0;
        noOfValidChars = 62;
        while (encodedLen < requiredLen)
        {
            randNum = randRange(0, 62);
            shoudIInclude = randRange(1, 5);
            if (shoudIInclude == 1)
            {
                encoded += validChars[randNum];
                encodedLen += 1;
            }
        }

        shortUrlToLongMap[encoded] = longUrl;

        return encoded;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        return shortUrlToLongMap[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));