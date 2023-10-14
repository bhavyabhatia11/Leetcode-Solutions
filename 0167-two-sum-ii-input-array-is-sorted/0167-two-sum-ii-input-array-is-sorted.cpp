class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        
        
        int n = nums.size();
        
        for(int i = 0; i< n; i++){
            int k = t-nums[i];
            
            int lo = 0;
            int hi = n-1;
            int mid;
            
            while(lo<hi){
                mid = lo + (hi-lo)/2;
                if(nums[mid] >= k && mid != i){
                    hi = mid;
                }
                else{
                    lo = mid+1;
                }      
            }
            
            if(nums[lo] + nums[i] == t){
                return {min(lo,i)+1,max(lo,i)+1};
            }
        }
        
        return {0,0};
        
        
        
        
    }
};