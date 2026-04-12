class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        auto helper = [&](auto&&self,int idx,long long currAmt)->int{
            if(idx==coins.size()){
                if(currAmt==amount){
                    return 0;
                }else{
                    return 1e9;
                }
            }
            if(dp[idx][currAmt]!=-1)return dp[idx][currAmt];
            int rq = self(self,idx+1,currAmt);
            if(currAmt+(long long)coins[idx]<=amount)
            rq = min(rq,1+self(self,idx,currAmt+(long long)coins[idx]));
            return dp[idx][currAmt]= rq;
        };
        int res = helper(helper,0,0);
        if(res>=1e9)return -1;
        return res;
    }
};
