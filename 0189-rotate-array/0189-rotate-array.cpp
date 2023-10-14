class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        
        int n = nums.size();
        
        vector<int> res;
        
        for(int i = (n-k)%n + n ; i< (n-k)%n + 2*n  ; i++){
            
            res.push_back(nums[i%n]);
        }
        
        nums = res;
    }
};