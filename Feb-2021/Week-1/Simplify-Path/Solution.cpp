#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    void getDirectoriesList(string path, vector<string> *listOfDirs)
    {
        int i, pathLen;
        string dirname = "";

        pathLen = path.size();

        // Make a list of dir/file names without slashes '/'

        for (i = 0; i < pathLen; i++)
        {
            if (path[i] == '/')
            {
                if (dirname != "")
                {
                    listOfDirs->push_back(dirname);
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
            listOfDirs->push_back(dirname);
            dirname = "";
        }

        return;
    }

    string createCanonicalPath(vector<string> *listOfDirs)
    {
        stack<string> dirStack;
        int i, noOfDirs;
        string dirname, canonicalForm = "";

        noOfDirs = listOfDirs->size();
        for (i = 0; i < noOfDirs; i++)
        {
            dirname = (*listOfDirs)[i];
            // cout << "Dirname: " << dirname << endl;
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

    string simplifyPath(string path)
    {
        vector<string> listOfDirs;
        string canonicalForm;

        getDirectoriesList(path, &listOfDirs);
        canonicalForm = createCanonicalPath(&listOfDirs);

        return canonicalForm;
    }
};