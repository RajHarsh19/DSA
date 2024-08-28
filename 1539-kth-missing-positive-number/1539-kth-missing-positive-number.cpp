class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ind = 0, ans = 1, n = arr.size();
        int count = 0;
        while (count != k) {
            if ((ind < n && ans < arr[ind]) || ind >= n) count++;
            if (ind < n && ans == arr[ind]) ind++;
            ans++;
        }
        return ans-1;
    }
};