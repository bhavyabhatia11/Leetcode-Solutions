class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size()-1;

        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            
            if(nums[mid] < target){
                lo = mid + 1;
            }
            else{
                hi = mid;
            }
        }

        if(lo>=nums.size() ||  nums[lo] != target) return {-1,-1};


        int firstIndex = lo;
        hi = nums.size()-1;

        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            
            if(nums[mid] > target){
                hi = mid;
            }
            else{
                lo = mid+1;
            }
        }

        if(nums[lo] == target) return {firstIndex, lo};
        return {firstIndex, lo-1};



    }
};