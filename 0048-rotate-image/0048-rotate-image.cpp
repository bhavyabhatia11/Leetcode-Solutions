class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {  
        int n = matrix.size();
    
        // i, j  (n X n) => 90degree => j, n-1 - i
        // case 1. 0,0 => 0, 3, n = 4
        // case 2. 1,2 => 2, 2, n = 4

        for(int i=0; i<n/2; i++){
            for(int j=i; j<n-1-i; j++){
                int x = i;
                int y = j;
                int temp = matrix[x][y];

                for(int k =0; k<4; k++){
                    swap(matrix[y][n-1 - x],temp);
                    swap(x,y);
                    y = n-1 - y;
                }
            }
        }
        
        return;
    }
};