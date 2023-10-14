class Solution {
public:
    
    void f(int n, int k , int strt, vector<int> &vis, vector<int> cur, vector<vector<int>> &res){
        
        if(cur.size() == k){
            res.push_back(cur);
            return;
        }
        
        for(int i =strt ;i<=n; i++){
            if(!vis[i]){
                vis[i] = 1;
                cur.push_back(i);
                f(n,k,i+1,vis,cur,res);
                cur.pop_back();
                vis[i] = 0;
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        vector<int> vis(n+1,0);
        
        f(n,k,1,vis,cur,res);
        
        return res;
    }
};