class Solution {
public:
    string addBinary(string a, string b) {
      
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        
        string res = "";
        
        while(a.size()<b.size()){
            a += '0';
        }
        while(a.size()>b.size()){
            b += '0';
        }
        
        
        int carry = 0;
        for(int i =0; i<max(a.size(),b.size()); i++){
            if(a[i]-'0' +b[i]-'0' + carry == 0){
                res += '0';
                carry = 0;
            }
            else if(a[i]-'0' +b[i]-'0' + carry == 1){
                res += '1';
                carry = 0;
            }
            else if(a[i]-'0' +b[i]-'0' + carry == 2){
                res += '0';
                carry = 1;
            }
            else{
                res += '1';
                carry = 1;
            }
        }
        
        if(carry)res+= '1';
        reverse(res.begin(),res.end());
        return res;
    }
};