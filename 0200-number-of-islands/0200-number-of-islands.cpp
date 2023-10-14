class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<int>> &vis){
        
        if(vis[i][j])return;
        
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = 1;
        
        if(i+1<n && grid[i+1][j]=='1')dfs(grid,i+1,j,vis);
        
        if(i-1>=0 && grid[i-1][j]=='1')dfs(grid,i-1,j,vis);
        
        if(j+1<m && grid[i][j+1]=='1')dfs(grid,i,j+1,vis);
        
        if(j-1>=0 && grid[i][j-1]=='1')dfs(grid,i,j-1,vis);
        
        return;
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans =0;
        
        for(int i =0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(grid,i,j,vis);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};