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
    void computeGreaterSum(TreeNode *root, int *sum)
    {
        if (root == NULL)
        {
            return;
        }

        computeGreaterSum(root->right, sum);
        root->val += *sum;
        *sum = root->val;
        computeGreaterSum(root->left, sum);

        return;
    }

    TreeNode *convertBST(TreeNode *root)
    {
        int sum = 0;
        computeGreaterSum(root, &sum);

        return root;
    }
};