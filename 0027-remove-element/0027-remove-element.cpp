class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int n = nums.size();
        
        for(int i =0; i< n ; i++){
            int j=nums.size()-1;
            while(nums[i]==val){
                if(j<=i) return j;
                swap(nums[i],nums[j--]);
            }
        }
        
        return n;
    }
};