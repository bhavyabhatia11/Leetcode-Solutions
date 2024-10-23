class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;

        if(n==0) return ans;
        if(n<0) x = 1/x;
        n = abs(n);
        
        if(n%2) ans = x*myPow(x, n-1);
        else ans = myPow(x*x, n/2);

        return ans;
    }
};