/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    const n = nums.length
    let dp = Array(n).fill(0);

    if(n==1) return nums[0];

    dp[0] = nums[0];
    dp[1] = nums[1];

    let ans = Math.max(dp[0], dp[1]);
    let lastMax = 0;
    for(let i = 2; i<n; i++){
        lastMax = Math.max(dp[i-2], lastMax);
        dp[i] = nums[i] + lastMax;

        ans = Math.max(ans,dp[i]);
    } 

    return ans;   

};