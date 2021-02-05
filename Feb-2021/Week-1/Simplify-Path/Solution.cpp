#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        int i, pathLen;
        string dirname = "", canonicalForm = "";
        stack<string> dirStack;

        pathLen = path.size();

        // Make a list of dir/file names without slashes '/'

        for (i = 0; i < pathLen; i++)
        {
            if (path[i] == '/')
            {
                if (dirname != "")
                {
                    if (dirname == ".")
                    {
                        // printf("This is current directory. Ignore\n");
                    }
                    else if (dirname == "..")
                    {
                        // printf("Go to the previous directory\n");
                        if (!dirStack.empty())
                        {
                            dirStack.pop();
                        }
                    }
                    else
                    {
                        dirStack.push(dirname);
                    }
                    dirname = "";
                }
            }
            else
            {
                dirname += path[i];
            }
        }
        if (dirname != "")
        {
            if (dirname == ".")
            {
                // printf("This is current directory. Ignore\n");
            }
            else if (dirname == "..")
            {
                // printf("Go to the previous directory\n");
                if (!dirStack.empty())
                {
                    dirStack.pop();
                }
            }
            else
            {
                dirStack.push(dirname);
            }
            dirname = "";
        }

        while (!dirStack.empty())
        {
            dirname = dirStack.top();
            dirStack.pop();
            // cout << "Popped: " << dirname << " from the stack" << endl;
            canonicalForm = "/" + dirname + canonicalForm;
            // cout << "cc: " << canonicalForm << endl;
        }

        if (canonicalForm == "")
        {
            canonicalForm = "/" + canonicalForm;
        }

        return canonicalForm;
    }
};