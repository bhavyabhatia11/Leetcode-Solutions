class Solution {
public:
    int myAtoi(string s) {

        int n = s.size();

        bool isReading = false;
        bool isNeg = false;

        long long ans = 0;
    
        for(int i=0; i<n; i++){
            if(s[i] > '9' || s[i] < '0'){
                if(isReading) break;

                if(s[i] == '-'){
                    isNeg = true;
                    isReading = true;
                }
                else if (s[i] == '+') {
                    isReading = true;
                }
                else if (s[i] == ' ') continue;
                else break;
            }
            else{
                isReading = true;
                ans = ans*10 + (s[i] - '0');

                if(isNeg && ans - 1 > INT_MAX) return INT_MIN;
                if(!isNeg && ans > INT_MAX) return INT_MAX;
            }
        }

         
        return isNeg ? -ans : ans;
        
    }
};