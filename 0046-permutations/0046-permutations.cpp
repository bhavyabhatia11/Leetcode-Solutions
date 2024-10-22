class Solution {
public:
    void solve(vector<int>& nums, vector<int>& vis, vector<int> cur, vector<vector<int>>& ans){
        // base case
        if(cur.size() == nums.size()){
            ans.push_back(cur);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(!vis[i]){
                vis[i] = 1;
                cur.push_back(nums[i]);
                solve(nums, vis, cur, ans);
                cur.pop_back();
                vis[i] = 0;
            }
        }

        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n,0);
        vector<int> cur;
        vector<vector<int>> ans;


        solve(nums, vis, cur, ans);
        return ans;
    }
};