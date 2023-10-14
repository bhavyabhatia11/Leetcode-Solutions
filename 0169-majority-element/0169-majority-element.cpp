class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int res =0;
        int c  = 0;
        
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            if(nums[res] == nums[i])c++;
            else c--;
            
            if(c==0){
                res = i;
                c++;
            }
        }
        
        return nums[res];
    }
};