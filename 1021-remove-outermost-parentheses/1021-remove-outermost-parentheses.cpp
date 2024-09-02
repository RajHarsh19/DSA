class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        string ans;
        int count=0;
        for(int i=0; i<n; i++){
            if(s[i] == '('){
            count++;
            if(count != 1)
            ans.push_back(s[i]);
            }
            if(s[i] == ')'){
                count--;
                if(count!=0)
                ans.push_back(s[i]);
            } 
            }
         return ans;
            }
};