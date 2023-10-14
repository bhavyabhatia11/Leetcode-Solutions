class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        
        long long rev = 0;
        
        long long num = x;
        while(num){
            rev = 10*rev + num%10;
            num = num/10;
        }
        
        if(rev>INT_MAX)return false;
        
        if(rev == x)return true;
        
        return false;
    }
};