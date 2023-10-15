class Solution {
public:
   
    int hr1(vector<int>& nums){
        int n = nums.size();
        
        if(n==1){
            return nums[0];
        }
        
        vector<int> dp(n+1,0);
        
        dp[n-1] = nums[n-1];
        
        
        
        for(int i = n-2; i>=0 ; i--){
            
            dp[i] = max(dp[i+2]+ nums[i] , dp[i+1]);
        }
        
     
        
        return dp[0];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1){
            return nums[0];
        }
        
        vector<int> n1(n-1,0);
        vector<int> n2(n-1,0);
        
        for(int i = 0 ; i< n-1 ; i++){
               n1[i] = nums[i];
           }
        
        for(int i = 1; i < n ; i++){
            n2[i-1] = nums[i];
        }
        
        int ans = max(hr1(n1),hr1(n2));
        
       
       
        return ans;
        
    }
};