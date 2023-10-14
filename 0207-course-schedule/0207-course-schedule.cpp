class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        
        vector<unordered_set<int>> adj(numCourses,unordered_set<int>());
        
        int n = prereq.size();
        
        if(n==0)return true;
        
        
        
        for(int i=0; i < n ; i++){
            adj[prereq[i][0]].insert(prereq[i][1]);
        }
        
        queue<int> q;
        
        
        for(int i= 0; i<numCourses ; i++){
            if(adj[i].empty())q.push(i);
        }
        
        
        vector<int> vis(numCourses,0);
        
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            vis[temp] =1;
            
            for(int i =0; i< numCourses ;i++){
                if(adj[i].find(temp) != adj[i].end()){
                    adj[i].erase(temp);
                    if(adj[i].size() == 0)q.push(i);
                }
            }
        }
        
      
        
        for(int i =0; i< vis.size() ; i++){
            if(vis[i] == 0)return false;
        }
        
        return true;
        
    
    
    }
};