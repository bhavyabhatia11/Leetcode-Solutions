class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        int h = haystack.size();
        if(n>h) return -1;

        for(int i = 0; i<=h-n; i++){
            if(haystack[i] == needle[0]){
                if(needle == haystack.substr(i,n)){
                    return i;
                }
            }
        }
        return -1;
    }
};