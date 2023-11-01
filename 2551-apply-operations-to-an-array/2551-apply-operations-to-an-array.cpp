class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        for(int i=0; i<n-1; i++){
            if(nums[i]==0)continue;

            if(nums[i] == nums[i+1]){
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }
int j = 0;
for (int i = 0; i < n - 1; i++) {
    j = max(i, j);

    // Check if j is within the bounds of the array
    if (j < n) {
        while (nums[j] == 0) {
            j++;
            // Check if j is still within the bounds of the array
            if (j >= n) {
                break;  // Avoid accessing out-of-bounds elements
            }
        }

        if (nums[i] == 0 && j < n) {
            swap(nums[j], nums[i]);
        }
    }
}

        return nums;

    }
};