class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> ans;
        for (char a : s) {
            ans[a]++;
        }
        string res;
        while (!ans.empty()) {
            char ch = '\0';
            int nu = 0;
            for (auto b : ans) {
                if (b.second > nu) {
                    nu = b.second;
                    ch = b.first;
                }
            }
            res.append(nu, ch);
            ans.erase(ch);
        }
        return res;
    }
};