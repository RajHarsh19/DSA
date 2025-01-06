class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        solution(1, k, n, curr, ans);
        return ans;
    }

private:
    void solution(int i, int k, int n, vector<int>& curr, vector<vector<int>>& ans) {
        if (n == 0 && k == 0) {
            ans.push_back(curr);
            return;
        }
        if (i > 9 || n < 0 || k < 0) return;

        curr.push_back(i);
        solution(i + 1, k - 1, n - i, curr, ans);
        curr.pop_back();

        solution(i + 1, k, n, curr, ans);
    }
};
