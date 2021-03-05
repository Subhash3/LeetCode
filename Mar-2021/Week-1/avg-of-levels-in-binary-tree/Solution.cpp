#include <vector>
#include <queue>
#include <iostream>

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
    vector<double> averageOfLevels(TreeNode *root)
    {
        queue<TreeNode *> bfsQ;
        TreeNode *frontNode = NULL;
        int levelSize, i;
        long long levelSum;
        vector<double> averages;

        if (root == nullptr)
        {
            return averages;
        }

        // printf("Pushing root: %d\n", root->val);
        bfsQ.push(root);
        while (!bfsQ.empty())
        {
            levelSize = bfsQ.size();
            // printf("Level size: %d\n", levelSize);
            levelSum = 0;
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
                levelSum += frontNode->val;
            }

            averages.push_back((double)levelSum / (double)levelSize);
        }

        return averages;
    }
};