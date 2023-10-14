class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        
        vector<int> minsofar(n,INT_MAX);
        
        minsofar[0] = prices[0];
        int ans = 0;
        for(int i =1; i<n; i++){
            minsofar[i] = min(minsofar[i-1],prices[i]);
            ans = max(ans,prices[i]-minsofar[i]);
        }
        
        
        return ans;
        
    }
};