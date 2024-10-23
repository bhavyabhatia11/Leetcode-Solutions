class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i=0; i<n-2; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            
            int lo = i+1;
            int hi = n-1;

            while(lo < hi) {
                if(nums[lo]+nums[hi] + nums[i] > 0){
                    hi--;
                }
                else if(nums[lo]+nums[hi] + nums[i] < 0){
                    lo++;
                }
                else{
                    ans.push_back({nums[i], nums[lo], nums[hi]});
                    int first_lo = nums[lo];
                    int first_hi = nums[hi];
                    while(lo < n && nums[lo] == first_lo) lo++;
                    while(hi >= 0 && nums[hi] == first_hi) hi--;
                }
            }

        }

        return ans;
        
    }
};