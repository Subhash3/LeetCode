#include <iostream>

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

using namespace std;

class Solution
{
public:
    int max(int a, int b)
    {
        return (a > b) ? a : b;
    }

    int max(int a, int b, int c)
    {
        return max(a, max(b, c));
    }

    void updateMaxSum(int val, int *maxSum)
    {
        // printf("Update maxSum: %d, val: %d\n", *maxSum, val);
        *maxSum = max(*maxSum, val);
        // printf("New maxSum: %d\n", *maxSum);
        return;
    }

    int findMaxPathSum(TreeNode *root, int *maxSum)
    {
        int leftSum, rightSum, current;

        if (root == NULL)
        {
            // printf("Root is null. Returning -2000\n");
            return -3000;
        }
        // printf("f(%d)\n", root->val);

        leftSum = findMaxPathSum(root->left, maxSum);
        rightSum = findMaxPathSum(root->right, maxSum);

        // printf("root: (%d), leftSum: %d, rightSum: %d, maxSum: %d\n", root->val, leftSum, rightSum, *maxSum);
        current = max(root->val, root->val + max(leftSum, rightSum, leftSum + rightSum));
        updateMaxSum(current, maxSum);
        // printf("Back after updating maxSum: %d\n", *maxSum);

        current = max(root->val, root->val + max(leftSum, rightSum));
        // printf("Returning %d\n", current);

        return current;
    }

    int maxPathSum(TreeNode *root)
    {
        int maxSum = -2000;

        findMaxPathSum(root, &maxSum);

        return maxSum;
    }
};