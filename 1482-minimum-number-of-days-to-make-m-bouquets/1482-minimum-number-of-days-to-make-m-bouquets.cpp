class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        auto binarySearchOnAns = [&](int mid)
        {
            int day = 0, cnt = 0;
            for(auto val:bloomDay)
            {
                if(val <= mid) cnt++;
                else cnt = 0;
                if(cnt == k) cnt = 0, day++;
            }
            return day >= m;
        };
        
        int ans = -1, i = 0, j = *max_element(begin(bloomDay), end(bloomDay));
        while(i<=j)
        {
            int mid = i + (j-i)/2;
            if(binarySearchOnAns(mid)) ans = mid, j = mid-1;
            else i = mid+1;
        }
        return ans;
    }
};