class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        vector<vector<int>> adj(numCourses, vector<int>(0,0));
        vector<unordered_set<int>> hashSet(numCourses);
        vector<bool> ans;

        int n = prerequisites.size();

        for(int i=0; i<n; i++){
           adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        for(int i= 0; i<numCourses; i++){
            vector<bool>visited(numCourses,false);
            queue<int> q;
            q.push(i);
            visited[i]=true;
            while(!q.empty()){
                int course = q.front();
                q.pop();
                for(int j=0; j<adj[course].size(); j++){
                    hashSet[i].insert(adj[course][j]);
                    if(!visited[adj[course][j]]){
                        visited[adj[course][j]]=true;
                        q.push(adj[course][j]);
                    }
                    
                }
            }
        }

        for(int i=0; i<queries.size(); i++){
            int v = queries[i][1];
            int u = queries[i][0];
            ans.push_back(hashSet[v].find(u) != hashSet[v].end());
        }

        return ans;
    }
};