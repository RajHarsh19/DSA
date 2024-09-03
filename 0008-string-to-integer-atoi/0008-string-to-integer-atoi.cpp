class Solution {
public:
    int myAtoi(string s) {
        int ans=0;
        int n= s.size();
        int i=0;
        int sign=1;
        // to move all front space
        while(s[i]==' ' && i<n)i++;
        // to check if any sign present after the space
        if(s[i]=='-' && i<n) {sign=-1; i++;}
        else if(s[i]=='+' && i<n) i++;
        //if first character is not a number simply zero(ex ="   +---45" ans=0)
        if(!(s[i]>='0' && s[i]<='9') && i<n) return 0;
        //extract the number
        while(i<n && (s[i]>='0' && s[i]<='9')){
            //check if the no is not extreme
            if(ans >INT_MAX/10)
                return INT_MAX;
            else if(ans < INT_MIN/10)
                return INT_MIN;
            //-2^31=2147483648   2^31-1 = 2147483647
            //ans = 214748364 now if the current digit is (8 or 9) then integer overflow
            if(ans==INT_MAX/10 and s[i]>='8')                
                return INT_MAX;              
            //ans = -214748364 now if the current digit is ( 9) then integer overflow  
            else if(ans== INT_MIN/10 and s[i]=='9')
                return INT_MIN; 
            //simply increase the number
            if(sign==-1)
             ans = ans*10 - (s[i]-'0');
            else
             ans = ans*10+(s[i]-'0');

            i++;
        }

        return ans;
    }
};