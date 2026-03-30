class Solution {
public:
    double myPow(double x, int n) {
        bool expNeg = false;
        if(n<0){
            expNeg = true;n=-n;
        }
        double res = 1;
        while(n>0){
            if(n&1)res*=x;
            x*=x;
            n>>=1;
        }
        if(expNeg)res = 1.0/res;
        return res;
    }
};
