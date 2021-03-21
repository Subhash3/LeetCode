#include <iostream>
#include <vector>

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
    void printVector(vector<int> arr)
    {
        int i, n;

        n = arr.size();
        printf("[");
        fflush(NULL);
        for (i = 0; i < n; i++)
        {
            printf("%d, ", arr[i]);
            fflush(NULL);
        }
        printf("\b\b]\n");

        return;
    }

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

    vector<int> mergeSortedArrays(vector<int> nums1, vector<int> nums2)
    {
        int m, n;
        int i, j, k;
        vector<int> mergedArr;

        m = nums1.size();
        n = nums2.size();
        i = 0;
        j = 0;
        k = 0;
        mergedArr = vector<int>(m + n);
        while ((i < m) && (j < n))
        {
            if (nums1[i] < nums2[j])
            {
                mergedArr[k] = nums1[i];
                i++;
                k++;
            }
            else
            {
                mergedArr[k] = nums2[j];
                j++;
                k++;
            }
        }

        while (i < m)
        {
            mergedArr[k] = nums1[i];
            i++;
            k++;
        }

        while (j < n)
        {
            mergedArr[k] = nums2[j];
            j++;
            k++;
        }

        return mergedArr;
    }

    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> elements1, elements2, mergedArr;

        traverseInorder(root1, elements1);
        traverseInorder(root2, elements2);

        printVector(elements1);
        printVector(elements2);

        mergedArr = mergeSortedArrays(elements1, elements2);
        printVector(mergedArr);

        return mergedArr;
    }
};