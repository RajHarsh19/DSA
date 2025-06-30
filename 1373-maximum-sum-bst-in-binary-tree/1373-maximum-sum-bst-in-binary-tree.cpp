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
class Solution {
public:
    int maxSum = 0;

    tuple<bool, int, int, int> dfs(TreeNode* node) {
        if (!node)
            return {true, INT_MAX, INT_MIN, 0};

        auto [leftBST, leftMin, leftMax, leftSum] = dfs(node->left);
        auto [rightBST, rightMin, rightMax, rightSum] = dfs(node->right);

        if (leftBST && rightBST && leftMax < node->val && node->val < rightMin) {
            int currSum = node->val + leftSum + rightSum;
            maxSum = max(maxSum, currSum);
            return {true, min(leftMin, node->val), max(rightMax, node->val), currSum};
        } else {
            return {false, 0, 0, 0};
        }
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
