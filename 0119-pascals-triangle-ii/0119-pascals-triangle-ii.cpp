class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans = {1};

        while(rowIndex--){
            vector<int> temp = {1}; 

            for(int i=1; i<ans.size(); i++){
                temp.push_back(ans[i]+ans[i-1]);
            }

            temp.push_back(1);

            ans = temp;
        }

        return ans;
    }
};