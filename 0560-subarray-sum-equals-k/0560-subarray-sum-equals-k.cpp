class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       map<int,int>mpp;
       mpp[0]=1;
       int presum=0,count=0;
       int n=nums.size();
       for(int i=0;i<n;i++){
        presum+=nums[i];
        int remove=presum-k;
        count+=mpp[remove];
        mpp[presum]+=1;
       }
       return count;

    }
};
