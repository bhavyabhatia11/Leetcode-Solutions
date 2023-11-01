class Solution {
public:
    long long minimumMoney(vector<vector<int>>& t) {
        int n = t.size();
        long long total_loss = 0;
        int k = 0;

        for(int i=0; i<n; i++){
            k = max(k, min(t[i][0],t[i][1]));
            total_loss += max(t[i][0]-t[i][1],0);
        }

        return total_loss + k;
    }
};