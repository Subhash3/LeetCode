#include <map>

using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *duplicateNode(Node *node)
    {
        Node *newNode = new Node(node->val);

        return newNode;
    }

    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        Node *newHead = new Node(head->val);
        Node *curPtr = head, *newNode, *newPtr = newHead;
        Node *original, *duplicated, *originalRand, *originalRandsDup;
        map<Node *, Node *> oldToNewMap;

        oldToNewMap[curPtr] = newPtr;
        // printf("Mapping %d to %d\n", curPtr->val, newPtr->val);
        curPtr = curPtr->next;
        while (curPtr != NULL)
        {
            // newNode = duplicateNode(curPtr);
            newNode = new Node(curPtr->val);
            newPtr->next = newNode;
            newPtr = newPtr->next;
            oldToNewMap[curPtr] = newPtr;
            // printf("Mapping %d to %d\n", curPtr->val, newPtr->val);
            curPtr = curPtr->next;
        }

        for (auto it : oldToNewMap)
        {
            original = it.first;
            duplicated = it.second;
            // printf("%d maps to %d\n", original->val, duplicated->val);
            originalRand = original->random;
            if (originalRand == NULL)
            {
                originalRandsDup = NULL;
            }
            else
            {
                originalRandsDup = oldToNewMap[originalRand];
            }
            duplicated->random = originalRandsDup;
        }

        return newHead;
    }
};