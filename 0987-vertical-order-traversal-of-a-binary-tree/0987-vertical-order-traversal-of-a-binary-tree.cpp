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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
         vector<tuple<int, int, int>> nodes;

        function<void(TreeNode*, int, int)> dfs = [&](TreeNode* node, int x, int y) {
            if (!node) return;
            nodes.emplace_back(x, y, node->val);
            dfs(node->left, x - 1, y + 1);
            dfs(node->right, x + 1, y + 1);
        };

        dfs(root, 0, 0);

        sort(nodes.begin(), nodes.end());

        vector<vector<int>> res;
        int prev_x = INT_MIN;
        for (auto& [x, y, val] : nodes) {
            if (x != prev_x) {
                res.emplace_back();
                prev_x = x;
            }
            res.back().push_back(val);
        }

        return res;
    }
};
