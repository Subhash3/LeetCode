#include <string>
#include <vector>
#include <iostream>
#include "Solution.cpp"

using namespace std;

int main()
{
    string path, canonicalForm;
    Solution solution;

    cout << "Enter a path: ";
    cin >> path;

    cout << path << endl;
    canonicalForm = solution.simplifyPath(path);

    cout << "Canonical form of " << path << " is " << canonicalForm << endl;

    exit(0);
}