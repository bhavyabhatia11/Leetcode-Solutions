class Solution {
public:
    bool isPal(string sub){
        int n = sub.size();
        
        int hi=n-1,lo=0;
        
        while(lo<hi){
            if(sub[hi--]!=sub[lo++])return false;
        }
        return true;
    }
    void f(string &s, int strt, int len ,vector<string> cur, vector<vector<string>> &res){
        
        if(strt+ len > s.size()){
           
            res.push_back(cur);
            return;
        }
        
        while(strt<s.size() && strt+len<=s.size()){
            string sub = s.substr(strt,len);
            if(isPal(sub)){
                cur.push_back(sub);
                //cout << sub << endl;
                f(s, strt+len, 1 , cur, res);
                cur.pop_back();
            }
            len++;
        }
        
        
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        
        f(s,0,1,cur,res);
        
        cout << s.substr(1,1) << endl;
        
        return res;
    }
};