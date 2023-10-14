class Solution {
public:
    int mySqrt(int x) {
        
        
        int lo = 0;
        int hi = x;
        
        long long mid;
        
        while(lo < hi){
            mid = hi - (hi-lo)/2;
            
            if(mid*mid <= x){
                lo = mid;
            }
            
            else{
                hi = mid-1;
            }
        }
        
        
        return lo;
    }
};