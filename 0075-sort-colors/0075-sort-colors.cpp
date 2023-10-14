class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        int lo = 0;
        int hi = n-1;
        
        
        for(int i=lo; i<=hi; i++){
            if(nums[i] == 2){
                swap(nums[hi],nums[i]); 
                hi--;
                i--;
            }         
            
            else if(nums[i] == 0){
                swap(nums[lo],nums[i]);
                lo++;
            }
            
            
        }
        
        return;
    }
};