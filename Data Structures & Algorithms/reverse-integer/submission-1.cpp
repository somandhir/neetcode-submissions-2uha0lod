class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        if(x==INT_MIN) return 0;
        if(x<0){
            neg=true;x=-x;
        }
        string curr = to_string(x);
        std::reverse(curr.begin(),curr.end());
        long long ans = stoll(curr);
        if(neg) ans = -ans;
        if(ans<INT_MIN or ans>INT_MAX)return 0;
        return ans;
    }
};
