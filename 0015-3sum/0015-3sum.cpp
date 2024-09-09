class Solution {
public:
    vector<vector<int>> sum2(vector<int> a, int i, int n, int t){
        sort(a.begin()+i, a.end());
        vector<vector<int>> ans;
        vector<int>v;
        int j=n-1;
        while(i<j){
            if(a[i]==a[j]){
                if(a[i]+a[j]==t){
                v.clear();
                v.push_back(a[i]);
                v.push_back(a[j]);
                ans.push_back(v);
                break;
            }
            }
            if(a[i]+a[j]==t){
                v.clear();
                v.push_back(a[i]);
                v.push_back(a[j]);
                ans.push_back(v);
                i++;
                j--;
            }
            else if(a[i]+a[j]<t)
                i++;
            else
                j--;
        }
        return ans;
    }
    vector<vector<int>> threeSum(vector<int>& a) {
        set<vector<int>>s;
        int target = 0;
        int n=a.size();
        vector<vector<int>> ans;
        vector<vector<int>> ans2;
        for(int i=0;i<n;i++){
            int t=target-a[i];
            vector<vector<int>> v;
            v = sum2(a,i+1,n,t);
            if(v.size()>0){
                for(int j=0;j<v.size();j++){
                    v[j].push_back(a[i]);
                    sort(v[j].begin(),v[j].end());
                    ans.push_back(v[j]);
                }
            }
        }
        int h=s.size();
        for(int i=0;i<ans.size();i++){
            s.insert(ans[i]);
            if(s.size()!=h){
                ans2.push_back(ans[i]);
            }
            h=s.size();
        }    
        return ans2;
    }
};