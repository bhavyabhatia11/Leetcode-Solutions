class Solution {
public:
    void find_sub(vector<int>& nums, vector<int> curr, int start, set<vector<int>>& ans){

        // base case
        ans.insert(curr);
        if(start == nums.size()){
          return;
        }

        for(int i=start; i<nums.size(); i++){
            curr.push_back(nums[i]);
            find_sub(nums, curr, i+1, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        
        vector<int> curr = {};
        set<vector<int>> ans;
        find_sub(nums, curr, 0, ans);


        vector<vector<int>> res;

        for(auto it: ans){
            res.push_back(it);
        }

        return res;
    }
};