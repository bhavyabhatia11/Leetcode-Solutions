class Solution {
public:
    bool canJumpToIndex(vector<int>& nums, int index){
        if(index == 0) return true;

        for(int i=0; i<index; i++){
            if(canJumpToIndex(nums,i) && nums[i] + i >= index){
                return true;
            }
        }
        return false;
    };
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n,false);

        dp[0] = true;

        for(int i = 1; i<n; i++){
            for(int j = i-1; j>=0; j--){
                if(dp[j] && nums[j]+j >= i) {
                    dp[i] = true;
                    break;
                }

            }
        }

        return dp[n-1];
    }
};