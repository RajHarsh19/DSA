class Solution {
public:
    vector<int> generateRow(int numRows) {
        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(1); // inserting the 1st element

        // calculate the rest of the elements:
        for (int col = 1; col < numRows; col++) {
            ans = ans * (numRows - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }

    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;

        // store the entire Pascal's Triangle:
        for (int numRows = 1; numRows <= n; numRows++) {
            ans.push_back(generateRow(numRows));
        }
        return ans;
    }
};
