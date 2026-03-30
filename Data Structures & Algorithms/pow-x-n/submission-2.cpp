class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1.0;
        if(n==1) return x;
        bool expNeg = false;
        if(n<0){
            expNeg = true;
            n = -n;
        }
        bool baseNeg = false;
        if(x<0){
            baseNeg = true;
            x = -x;
        }
        double res = 1;
        while(n>0){
            if(n&1)res*=x;
            x*=x;
            n>>=1;
        }
        cout<<res<<endl;
        if(expNeg){
            res = 1/res;
        }
        if(baseNeg and (n&1)){
            res = -res;
        }
        return res;
    }
};
