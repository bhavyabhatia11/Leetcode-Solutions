class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> postMax(n,0);

        postMax[n-1] = 0;
        for(int i=n-2;i>=0; i--){
            postMax[i] = max(postMax[i+1], height[i+1]);
        }
        
        int preMax = 0;
        int ans = 0;
        for(int i=1; i<n; i++){
            preMax = max(preMax,height[i-1]);
            ans += max((min(preMax, postMax[i]) - height[i]), 0);
        }

        return ans;

    }
};