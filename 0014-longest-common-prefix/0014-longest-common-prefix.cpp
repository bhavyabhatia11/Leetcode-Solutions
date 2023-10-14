class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        
        string ans = "";
        
        
        for(int i =0 ; i<200 ; i++){
            char val = strs[0][i];
            
            for(int j =0 ; j<n ; j++){    
                
                if(strs[j].size() > i){
                      if(strs[j][i] != val){
                        return ans;
                        }
                }
                else{
                    return ans;
                }
              
            }
            
            ans += val;
        }
        
        
        return ans;
    }
};