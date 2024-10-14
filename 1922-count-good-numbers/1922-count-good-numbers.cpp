class Solution {
    long long mod=1e9+7;
public:
    long long power(long long x,long long n){
        long long ans=1;
        while(n!=0){
            if (n&1)
                ans=(ans*x)%mod;
            x=(x*x)%mod;
            n=n>>1;       
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long even=(n/2)+(n%2);
        long long odd=n/2;
        long long evenx=power(5,even);
        long long oddx=power(4,odd);
        return (evenx*oddx)%mod;
        
    }
};