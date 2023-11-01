class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {    
        int n = nums.size();

        unordered_set<int> s;
        unordered_map<int,int> mp;
        long long sum = 0;
        long long ans = 0;

        for(int i=0; i<n; i++){
            s.insert(nums[i]);
            mp[nums[i]]++;
            sum += nums[i];

            if(s.size() == k){
                ans = max(ans,sum);
            }

            if(i-k+1>=0){
                sum -= nums[i-k+1];
                mp[nums[i-k+1]]--;
                if(mp[nums[i-k+1]] == 0) s.erase(nums[i-k+1]);
            }
        }
        
        return ans;
    }
};