class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        
        vector<int> dp(n+1,0);
        dp[n] = 1;
        
        if(s[n-1]-'0'<=0 ){
            dp[n-1] = 0;
        }
        else{
            dp[n-1] = 1;
        }
        
        for(int i = n-2; i>=0 ; i--){
            
            if(s[i]-'0' == 0){
                continue;    
            }
            dp[i] = dp[i+1];
            
            if(10*(s[i]-'0') + (s[i+1]-'0')  <= 26){
                dp[i] += dp[i+2];
            }
        }
        return dp[0];
    }
};