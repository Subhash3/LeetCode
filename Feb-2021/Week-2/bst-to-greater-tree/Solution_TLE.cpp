#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void traverseInorder(TreeNode *root, vector<int> &elements)
    {
        if (root == NULL)
        {
            return;
        }
        traverseInorder(root->left, elements);
        elements.push_back(root->val);
        traverseInorder(root->right, elements);

        return;
    }

    void alterTree(TreeNode *root, unordered_map<int, int> greaterSum)
    {
        if (root == NULL)
        {
            return;
        }
        root->val = greaterSum[root->val];
        alterTree(root->left, greaterSum);
        alterTree(root->right, greaterSum);

        return;
    }

    TreeNode *convertBST(TreeNode *root)
    {
        vector<int> sortedElements, prefixSum;
        int noOfElements, i, sumOfElements = 0;
        unordered_map<int, int> greaterSum;

        // Inorder traversal to sort the elements
        traverseInorder(root, sortedElements);
        noOfElements = sortedElements.size();

        // Prefix Sum
        for (i = 0; i < noOfElements; i++)
        {
            sumOfElements += sortedElements[i];
            if (i == 0)
            {
                prefixSum.push_back(sortedElements[i]);
            }
            else
            {
                prefixSum.push_back(sortedElements[i] + prefixSum[i - 1]);
            }
        }

        // Make the greater sum map
        for (i = 0; i < noOfElements; i++)
        {
            if (i == 0)
            {
                greaterSum[sortedElements[i]] = sumOfElements;
            }
            else
            {
                greaterSum[sortedElements[i]] = sumOfElements - prefixSum[i - 1];
            }
        }

        // Now update the tree
        alterTree(root, greaterSum);

        return root;
    }
};