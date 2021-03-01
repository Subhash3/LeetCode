#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> s;
        int len = pushed.size(), i, j = 0;

        for (i = 0; i < len;)
        {
            if (!s.empty() && s.top() == popped[j])
            {
                // // printf("Stack is not empty!.\n");
                // printf("Top: %d, j: %d, popped[j]: %d\n", s.top(), j, popped[j]);
                // printf("Popping %d\n", s.top());
                s.pop();
                j += 1;
            }
            else
            {
                // printf("i: %d, Pushing %d\n", i, pushed[i]);
                s.push(pushed[i]);
                i += 1;
            }
        }

        // printf("Ouside for\n");
        // printf("Top: %d, j: %d, popped[j]: %d\n", s.top(), j, popped[j]);
        while (!s.empty() && s.top() == popped[j])
        {
            // printf("Top: %d, j: %d, popped[j]: %d\n", s.top(), j, popped[j]);
            s.pop();
            j += 1;
        }

        return s.empty();
    }
};