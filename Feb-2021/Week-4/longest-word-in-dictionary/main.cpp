#include <string>
#include <vector>
#include <iostream>
#include "Solution.cpp"

using namespace std;

int main()
{
    string s, longestWord, word;
    vector<string> d;
    int noOfWords, i;
    Solution solution;

    printf("Enter the no. of words: ");
    cin >> noOfWords;
    printf("Enter a string: ");
    cin >> s;

    printf("Enter the words:\n");
    for (i = 0; i < noOfWords; i++)
    {
        printf(">> ");
        cin >> word;
        d.push_back(word);
    }
    printf("\n");

    longestWord = solution.findLongestWord(s, d);

    cout << "Longest word: " << longestWord << endl;

    exit(0);
}