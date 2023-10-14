class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[row-1].size();

        vector<vector<int>> dp(row+1, vector<int>(col+1, INT_MAX));
        int ans = INT_MAX;

        for(int i=1; i<=row; i++){
            for(int j=1; j<=triangle[i-1].size(); j++){
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]);
                if(dp[i][j] != INT_MAX){
                    dp[i][j] += triangle[i-1][j-1];
                } 
                else{
                    dp[i][j] = triangle[i-1][j-1];
                }
                if(triangle[i-1].size()==col){
                    ans = min(ans, dp[i][j]);
                }
            }
        }

        return ans;        
    }
};