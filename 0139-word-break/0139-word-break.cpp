class Solution {
public:
    bool wordBreakHelper(string s, unordered_set<string>& wordSet, int start) {
        if (start == s.size()) {
            return true;
        }

        for (int end = start + 1; end <= s.size(); ++end) {
            if (wordSet.find(s.substr(start, end - start)) != wordSet.end() && 
                wordBreakHelper(s, wordSet, end)) {
                return true;
            }
        }

        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return wordBreakHelper(s, wordSet, 0);
    }
};
