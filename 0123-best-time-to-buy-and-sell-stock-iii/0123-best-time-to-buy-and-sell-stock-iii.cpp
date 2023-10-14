class Solution {
public:
  
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        int minsofar = prices[0];
        int maxsofar = prices[n-1];
        
        for(int i = 1 ; i < n ; i++){
            minsofar = min(minsofar,prices[i]);
           left[i] = max(left[i-1],prices[i]-minsofar);
            
        }
        
        for(int i = n-2; i>=0 ; i--){
            maxsofar = max(maxsofar,prices[i]);
            
            right[i] = max(right[i+1], maxsofar-prices[i]);
        }
        int profit = 0;
        
        for(int i = 0 ; i < n ; i++){
            profit = max(profit,right[i]+left[i]);
        }
        
        return profit;
        
        
       
    }
};