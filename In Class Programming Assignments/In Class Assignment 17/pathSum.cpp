// Juhwan Lee
// CS300: Elements of Software Engineering
// Professor Fei Xie
// In Class Programming Assignment 17

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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;
        else
        {
            bool result = false;
            int sum = 0;
            checkHasPathSum(root, result, targetSum, sum);
            return result;
        }
    }
    void checkHasPathSum(TreeNode *root, bool &result, int targetSum, int sum)
    {
        if (!root)
            return;
        sum += root->val;
        if (!root->left && !root->right)
        {
            if (sum == targetSum)
            {
                result = true;
                sum -= root->val;
                return;
            }
            else
            {
                sum -= root->val;
                return;
            }
        }
        checkHasPathSum(root->left, result, targetSum, sum);
        checkHasPathSum(root->right, result, targetSum, sum);
    }
};