class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int r = matrix.size();
        int c = matrix[0].size();


        int hi = r*c -1;
        int lo = 0;

        while(lo<hi){
            int mid = (hi - lo)/2 + lo;

            int i = mid/c;
            int j = mid%c;

            if(matrix[i][j] >= target){
                hi = mid;
            }
            else{
                lo = mid + 1;
            }
        }

        return matrix[lo/c][lo%c] == target ? true : false;
        
    }
};