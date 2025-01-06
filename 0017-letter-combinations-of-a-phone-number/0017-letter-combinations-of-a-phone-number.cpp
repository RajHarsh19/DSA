class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string output;
        int index=0;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solution(digits,output,index,ans,mapping);
        return ans;
    }
private:
     void solution(string digit,string output,int index,vector<string>&ans,string mapping[]){
         if(index >= digit.length()) {
            ans.push_back(output);
            return;
        }
        
        int number = digit[index] - '0';
        string value = mapping[number];
        
        for(int i=0; i<value.length(); i++) {
            output.push_back(value[i]);
            solution(digit, output, index+1, ans, mapping);
            output.pop_back();
        }
        
    }

};