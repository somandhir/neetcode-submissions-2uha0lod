class Solution {
public:
    int reverse(int x) {
        if(x==INT_MIN) return 0;
        bool neg = false;
        if(x<0){
            neg = true;
            x = -x;
        }
        int reversed = 0;
        while(x>0){
            int dig = x%10;
            if (reversed > INT_MAX/10 or reversed < INT_MIN/10)
                return 0;
            reversed=reversed*10+dig;
            x/=10;
        }
        if(neg)reversed = -reversed;
        return reversed;
    }
};
