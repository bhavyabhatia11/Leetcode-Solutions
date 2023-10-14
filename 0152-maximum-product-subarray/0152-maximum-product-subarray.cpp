class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n = nums.size();
        
        int maxDP = INT_MIN;
        int minDP = INT_MAX;

        minDP = nums[0];
        maxDP = nums[0];
        int ans = maxDP;
        for(int i=1; i<n; i++){
            int temp = maxDP;
            maxDP = max({maxDP * nums[i], minDP * nums[i], nums[i]});
            minDP = min({temp * nums[i], minDP * nums[i], nums[i]});
            ans = max(ans, maxDP);

        }

        return ans;
        
    }
};