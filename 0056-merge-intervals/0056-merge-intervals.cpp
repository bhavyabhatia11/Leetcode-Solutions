class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        for(int i=0; i<n; i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            while(i<n && end >= intervals[i][0]){
                end = max(end, intervals[i][1]);
                i++;
            }

            ans.push_back({start,end});
            i--;
        }

        return ans;
    }
};