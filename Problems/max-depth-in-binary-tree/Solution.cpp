#include <stdlib.h>

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
    void findMaxDepth(TreeNode *root, int depth, int *maxDepth)
    {
        if (root == NULL)
        {
            if (*maxDepth < depth)
            {
                *maxDepth = depth;
            }
            return;
        }

        this->findMaxDepth(root->left, depth + 1, maxDepth);
        this->findMaxDepth(root->right, depth + 1, maxDepth);
    }

    int maxDepth(TreeNode *root)
    {
        int maxDepth = -1;

        findMaxDepth(root, 0, &maxDepth);

        return maxDepth;
    }
};