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
            if (reversed > INT_MAX/10 || reversed < INT_MIN/10)
                return 0;
            reversed=reversed*10+dig;
            x/=10;
        }
        if(neg)reversed = -reversed;
        if(reversed<INT_MIN or reversed>INT_MAX) return 0;
        return reversed;
    }
};
