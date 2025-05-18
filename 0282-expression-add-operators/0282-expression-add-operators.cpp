class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        backtrack(result, "", num, target, 0, 0, 0);
        return result;
    }

private:
    void backtrack(vector<string>& result, string expr, string num, int target, int pos, long currValue, long lastOperand) {
        if (pos == num.size()) {
            if (currValue == target) {
                result.push_back(expr);
            }
            return;
        }

        for (int i = pos; i < num.size(); ++i) {
            // Avoid numbers with leading zeros
            if (i != pos && num[pos] == '0') break;

            string currStr = num.substr(pos, i - pos + 1);
            long currNum = stol(currStr);

            if (pos == 0) {
                // First number, no operator
                backtrack(result, currStr, num, target, i + 1, currNum, currNum);
            } else {
                // Addition
                backtrack(result, expr + "+" + currStr, num, target, i + 1, currValue + currNum, currNum);
                // Subtraction
                backtrack(result, expr + "-" + currStr, num, target, i + 1, currValue - currNum, -currNum);
                // Multiplication
                backtrack(result, expr + "*" + currStr, num, target, i + 1, currValue - lastOperand + lastOperand * currNum, lastOperand * currNum);
            }
        }
    }
};