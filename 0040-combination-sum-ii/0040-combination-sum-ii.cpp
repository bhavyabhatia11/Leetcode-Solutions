class Solution {
public:
       void f(vector<int> &candidates,int target, int strt, int &cursum,vector<int> &vis, vector<int> cur, vector<vector<int>> &res){
        
        if(cursum > target)return;
        if(cursum == target){
            res.push_back(cur);
            return;
        }
        
        for(int i = strt ;i< candidates.size(); i++){
            if(i > strt && candidates[i] == candidates[i-1])continue;
            
                
                cursum += candidates[i];
                cur.push_back(candidates[i]);
                f(candidates,target,i+1,cursum,vis,cur,res);
                cur.pop_back();
                cursum -= candidates[i];
               
            }
            
            
        }
    


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        vector<int> vis(candidates.size(),0);
        int cursum = 0;
        sort(candidates.begin(),candidates.end());
        f(candidates,target,0,cursum,vis,cur,res);
        
        return res;
    }
};