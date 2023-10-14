class Solution {
public:
    int reverse(int x) {
        bool negative = false;
        long long num = x;
        
        if(x<0){
            negative = true;
            num = -num;
        }
        
        long long rev = 0;
        
        while(num){
            int digit = num%10;
            num = num/10;
            rev = 10*rev + digit;
        }
        
        if(negative)rev = -rev;
        if(rev > INT_MAX || rev < INT_MIN)return 0;
        
        return rev;
    }
};