class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(s[0]=='0')return 0;
        
        // 1| 2 0| 4 3 2 1
        // 1  2 1  1 
        // if 2 consec 0 -> res = 0
        vector<int>dp(n,-1);
        auto helper = [&](auto&&self,int idx){
            if(idx==n)return 1;
            if(dp[idx]!=-1)return dp[idx];
            if(s[idx]=='0')return dp[idx]=0;
            int curr = 0;
            curr+=self(self,idx+1);
            if(idx+1<n){
                int num = stoi(s.substr(idx,2));
                if(num>=10 and num<=26)curr+=self(self,idx+2);
            }
            return dp[idx]= curr;
        };
        return helper(helper,0);

    }
};
