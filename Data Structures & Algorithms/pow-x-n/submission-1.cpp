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
        auto helper = [](auto&&self,double x,int exp){
            if(exp==1) return x;
            double done = self(self,x,exp/2)*self(self,x,exp/2);
            if(exp&1){
                return done*x;
            }else{
                return done;
            }
        };
        double res = helper(helper,x,n);
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
