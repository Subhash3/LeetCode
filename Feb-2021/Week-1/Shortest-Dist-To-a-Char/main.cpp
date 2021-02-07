#include <string>
#include <vector>
#include <iostream>
#include "Solution.cpp"

using namespace std;

int main()
{
    string s;
    char c;
    Solution solution;
    vector<int> shortestDistances;

    cout << "Enter a string: ";
    cin >> s;
    cout << "Enter a char: ";
    cin >> c;

    shortestDistances = solution.shortestToChar(s, c);
    for (int num : shortestDistances)
    {
        cout << num << ", " << flush;
    }
    cout << endl;

    exit(0);
}