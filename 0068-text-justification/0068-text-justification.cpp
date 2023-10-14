class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        int i=0;
        vector<string> ans;
        while(i<n){
            int length = 0;
            int count = 0;
            int start = i;
            while(i<n && (length + words[i].size() + count) <= maxWidth){
                length += words[i].size();
                count++;
                i++;
            }
            int actualSpace = count > 1 ? (maxWidth - length)/(count-1) : 0;
            int extraSpaces = count > 1 ? (maxWidth - length)%(count-1) : 0;

            string res = "";
            if(i>=n){
                for(int j=start; j<i; j++){
                    if(j==i-1){
                        res += words[j];
                    }
                    else res += words[j] + ' ';
                }
                while(maxWidth > res.size()){
                    res += ' ';
                }
                ans.push_back(res);
            }
            else {
                string spaces = "";
                while(actualSpace--){
                    spaces += ' ';
                }
                for(int j=start; j<i; j++){
                    if(j==i-1 && i-start>1){
                        res += words[j];
                    }
                    else res += words[j] + spaces;

                    if(extraSpaces>0){
                        res += ' ';
                        extraSpaces--;
                    }
                }

                while(maxWidth > res.size()){
                    res += ' ';
                }

                ans.push_back(res);
            }
            
        }

        return ans;
    }
};