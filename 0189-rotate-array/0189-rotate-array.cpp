class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int j = nums.size();
        k = k % j;  
        reverse(nums.begin(), nums.end());  
        reverse(nums.begin(), nums.begin() + k); 
        reverse(nums.begin() + k, nums.end());  
    }
};
