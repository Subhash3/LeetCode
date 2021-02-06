#include <vector>
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
    vector<int> rightSideView(TreeNode *root)
    {
        if (root == NULL)
        {
            vector<int> lastNodes;
            return lastNodes;
        }
        queue<TreeNode *> q;
        int lastNodeVal;
        vector<int> lastNodes;
        TreeNode *topNode;

        q.push(root);

        while (q.empty() == false)
        {
            int noOfChildren = q.size();

            while (noOfChildren--)
            {
                topNode = q.front();
                lastNodeVal = topNode->val;
                q.pop();
                if (topNode->left != NULL)
                {
                    q.push(topNode->left);
                }
                if (topNode->right != NULL)
                {
                    q.push(topNode->right);
                }
            }
            lastNodes.push_back(lastNodeVal);
        }

        return lastNodes;
    }
};