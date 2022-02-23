/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> result;
        int level = 0;
        largestValuesInner(root, result, level);
        return result;
    }

    void largestValuesInner(TreeNode *root, vector<int> &result, int level)
    {
        if (!root)
            return;
        if (level == result.size())
        {
            result.push_back(root->val);
        }
        else
        {
            if (level < result.size())
            {
                if (result[level] < root->val)
                    result[level] = root->val;
            }
            else
            {
                result.push_back(root->val);
            }
        }
        largestValuesInner(root->left, result, level + 1);
        largestValuesInner(root->right, result, level + 1);
    }
};