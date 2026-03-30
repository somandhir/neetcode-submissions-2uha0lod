class Solution {
public:
    bool isHappy(int n) {
        set<int>st;
        int curr = n;
        while(curr!=1){
            int temp = curr;
            int s = 0;
            while(curr){
                int lastDigit = curr%10;
                s+=(lastDigit*lastDigit);
                curr/=10;
            }
            if(st.count(s)){
                return false;
            }
            st.insert(s);
            curr = s;
        }
        return true;
    }
};
