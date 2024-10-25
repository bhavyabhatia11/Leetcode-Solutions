class Solution {
public:
    void solve(int n, int i,vector<vector<int>> cur, vector<vector<vector<int>>>& ans, vector<int> visCol, vector<int> visDiaL, vector<int> visDiaR){

        // base
        if(i == n){
            ans.push_back(cur);
            return;
        }


        for(int j =0; j<n; j++){
            if(!visCol[j] && !visDiaL[i+j] && !visDiaR[n-1 - i + j]){
                visCol[j] = 1;
                visDiaL[i+j] = 1;
                visDiaR[n-1-i+j] = 1;
                cur[i][j] = 1;

                solve(n,i+1,cur,ans,visCol,visDiaL,visDiaR);

                visCol[j] = 0;
                visDiaL[i+j] = 0;
                visDiaR[n-1-i+j] = 0;
                cur[i][j] = 0;
            }
        }


        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> cur(n,vector<int>(n,0));
        vector<vector<vector<int>>> ans;

        vector<int> visCol(n, 0);
        vector<int> visDiaL(2*n, 0);
        vector<int> visDiaR(2*n, 0);


        solve(n, 0, cur, ans, visCol, visDiaL, visDiaR);

        vector<vector<string>> res;
        for(auto board: ans){
            vector<string> strBoard; 
            for(int i=0; i<n; i++){
                string row = "";
                for(int j=0; j<n; j++){
                    row += board[i][j] == 1 ? 'Q' : '.';
                }
                strBoard.push_back(row);
            }
            res.push_back(strBoard);
        }
        return res;
    }
};