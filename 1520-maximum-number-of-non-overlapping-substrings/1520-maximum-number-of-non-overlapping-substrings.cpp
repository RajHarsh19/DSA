class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> start(26, n), end(26, -1);
        
        // Record the first and last occurrences of each character
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            start[c] = min(start[c], i);
            end[c] = max(end[c], i);
        }

        // Try to expand the interval to cover all characters that appear in it
        auto getInterval = [&](int i) -> pair<int, int> {
            int l = start[i], r = end[i];
            for (int j = l; j <= r; ++j) {
                int c = s[j] - 'a';
                if (start[c] < l) l = start[c], j = l;
                if (end[c] > r) r = end[c];
            }

            // Check if the interval is still valid
            for (int j = l; j <= r; ++j) {
                int c = s[j] - 'a';
                if (start[c] < l || end[c] > r) return {-1, -1};
            }

            return {l, r};
        };

        vector<pair<int, int>> intervals;
        for (int i = 0; i < 26; ++i) {
            if (start[i] <= end[i]) {
                auto [l, r] = getInterval(i);
                if (l != -1) intervals.emplace_back(l, r);
            }
        }

        // Sort by end to greedily pick non-overlapping substrings
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        vector<string> result;
        int lastEnd = -1;
        for (auto &[l, r] : intervals) {
            if (l > lastEnd) {
                result.push_back(s.substr(l, r - l + 1));
                lastEnd = r;
            }
        }

        return result;
    }
};
