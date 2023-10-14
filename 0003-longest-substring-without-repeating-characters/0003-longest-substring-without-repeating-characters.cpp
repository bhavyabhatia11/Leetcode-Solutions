class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<unordered_map<char,int>> dp(n+1,unordered_map<char,int>());
        
        if(n==0)return 0;
        
        dp[0][s[0]] = 0; 
        int ans = 1;
        
        for(int i = 1; i<n ; i++){
            
            unordered_map<char,int> mp;
            char c = s[i];
            
            if(dp[i-1].find(c) != dp[i-1].end()){
                for(int j = dp[i-1][c]+1 ; j<=i ; j++){
                    dp[i][s[j]] = j;
                }
            }
            else{
                dp[i] = dp[i-1];
                dp[i][s[i]] = i;
            }
            
            ans = max(ans, int(dp[i].size())) ;
        }
        
        
        
        return ans;
    }
};