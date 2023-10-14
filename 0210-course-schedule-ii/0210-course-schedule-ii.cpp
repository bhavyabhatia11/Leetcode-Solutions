class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq) {
        
        vector<unordered_set<int>> adj(numCourses,unordered_set<int>());
        vector<int> ans;
        int n = prereq.size();
        
        if(n==0){
            for(int i =0; i<numCourses ; i++){
                ans.push_back(i);
            }
            return ans;
        };
        
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
            ans.push_back(temp);
            
            for(int i =0; i< numCourses ;i++){
                if(adj[i].find(temp) != adj[i].end()){
                    adj[i].erase(temp);
                    if(adj[i].size() == 0)q.push(i);
                }
            }
        }
        
      
        
        for(int i =0; i< vis.size() ; i++){
            if(vis[i] == 0)return {};
        }
        
        return ans;
        
    }
};