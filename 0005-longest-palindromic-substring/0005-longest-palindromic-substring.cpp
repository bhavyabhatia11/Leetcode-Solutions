class Solution {
public:
    string getLongestPal(string& s, int l, int r){
        int n = s.size();
        if(l>=n || l<0 || r>=n || r<0) return "";
        string ans = "";

        while(l>=0 && r<n){
            if(s[l] != s[r]){
                return ans;
            }
            ans = s.substr(l,r-l+1);
            l--;
            r++;
        }

        return ans;
    }
    string longestPalindrome(string s) {
        int n = s.size();

        string ans = "";
        for(int i=0; i<n; i++){
            string evenPal = getLongestPal(s,i,i+1);
            string oddPal = getLongestPal(s,i,i);

            if(ans.size() < evenPal.size()) ans = evenPal;
            if(ans.size() < oddPal.size()) ans = oddPal;
        }

        return ans;
    }
};