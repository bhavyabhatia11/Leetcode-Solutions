class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();


        for(int i=0; i<n; i++){
            int k = 0;
            while(k<n){
                if(nums[i] == i+1) break;
                swap(nums[i], nums[nums[i] -1]);
                k++;
            }
            if(k>=n){
                return nums[i];
            }
        }


        return 0;
    }
};