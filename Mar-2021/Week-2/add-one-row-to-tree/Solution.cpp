#include <queue>

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
    TreeNode *addOneRow(TreeNode *root, int v, int d)
    {
        queue<TreeNode *> bfsQ;
        TreeNode *frontNode = NULL, *newLeft = NULL, *newRight = NULL;
        int i, level, levelSize;

        if (d == 1)
        {
            TreeNode *newRoot = new TreeNode(v);
            newRoot->left = root;

            return newRoot;
        }

        // printf("Pushing root: %d\n", root->val);
        bfsQ.push(root);
        level = 1;
        while (!bfsQ.empty())
        {
            if (level == d - 1)
            {
                break;
            }
            levelSize = bfsQ.size();
            // printf("Level size: %d\n", levelSize);
            for (i = 0; i < levelSize; ++i)
            {
                frontNode = bfsQ.front();
                // printf("Front node: %d\n", frontNode->val);
                if (frontNode->left != NULL)
                {
                    bfsQ.push(frontNode->left);
                }
                if (frontNode->right != NULL)
                {
                    bfsQ.push(frontNode->right);
                }
                bfsQ.pop();
            }

            level += 1;
        }

        levelSize = bfsQ.size();
        // printf("Level size: %d\n", levelSize);
        for (i = 0; i < levelSize; ++i)
        {
            frontNode = bfsQ.front();
            newLeft = new TreeNode(v);
            newRight = new TreeNode(v);

            newLeft->left = frontNode->left;
            newRight->right = frontNode->right;

            frontNode->left = newLeft;
            frontNode->right = newRight;

            bfsQ.pop();
        }

        return root;
    }
};