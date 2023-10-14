class Solution {
public:
    void dfs(string digits, unordered_map<int,vector<char>> &dig,int strt, string cur , vector<string> &res){
        
        if(digits.size() == cur.size()){
            res.push_back(cur);
            return;
        }
        
        
        for(int i =strt ; i < digits.size() ; i++){
            vector<char> temp = dig[digits[i]-'0'];
            
            for(int j =0 ; j< temp.size() ; j++){
                cur.push_back(temp[j]);
                dfs(digits,dig,i+1,cur,res);
                cur.pop_back();
            }
        }

        return;
        
    }
    vector<string> letterCombinations(string digits) {
        
        if(digits.size() == 0)return {};
        
        unordered_map<int,vector<char>> dig;
        
        dig[2] = {'a', 'b' , 'c'};
        dig[3] = {'d', 'e' , 'f'};
        dig[4] = {'g', 'h' , 'i'};
        dig[5] = {'j', 'k' , 'l'};
        dig[6] = {'m', 'n' , 'o'};
        dig[7] = {'p', 'q' , 'r' , 's'};
        dig[8] = {'t', 'u' , 'v'};
        dig[9] = {'w', 'x' , 'y' , 'z'};
        
        
        vector<string> res;
        string cur;
        
        dfs(digits,dig,0,cur,res);
        
        return res;
        
    }
};