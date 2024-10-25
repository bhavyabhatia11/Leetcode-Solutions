class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int pivot = n;
        for(int i=1; i<n; i++){
            if(nums[i] < nums[i-1]){
                pivot = i;
                break;
            }
        }

        int lo,hi;
        if(target >= nums[0]){
            lo = 0;
            hi = pivot - 1;
        }
        else{
            lo = pivot;
            hi = n-1;
        }

        while(lo<=hi){
            int mid = (lo+hi) >> 1;

            if(target > nums[mid]){
                lo = mid+1;
            }
            else if(target < nums[mid]){
                hi = mid-1;
            }
            else{
                return mid;
            }
        }

        return -1;
        
    }
};