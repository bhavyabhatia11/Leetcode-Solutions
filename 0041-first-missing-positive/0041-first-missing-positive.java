class Solution {
    public int firstMissingPositive(int[] nums) {
          int n = nums.length;
        int soFar = 1;
       
        
        Arrays.sort(nums);
        
        if(n==0 || nums[0]>1){
            return soFar;
        }
        
        for(int i =0; i<n ; i++){
            if(nums[i] == soFar){
                soFar++;
            }
            else if(nums[i]>soFar){
                return soFar;
            }
            else{
                continue;
            }
        }
        
        
        return soFar;
    }
}