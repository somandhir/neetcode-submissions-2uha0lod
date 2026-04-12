class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)return 0;
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
      
        /* currAmt
          0 1 2 3 ...
        0
        1 
        2
        3 

        */
      
        for(int i=0;i<amount;i++){
            dp[n][i]=1e9;
        }
        for(int idx=n-1;idx>=0;idx--){
            for(int currAmount=amount;currAmount>=0;currAmount--){
                int rq = dp[idx+1][currAmount];
                if(currAmount+(long long)coins[idx]<=amount)
                rq = min(rq,1+dp[idx][currAmount+(long long)coins[idx]]);
                dp[idx][currAmount]= rq;
            }
        }
        return dp[0][0]>=1e9?-1:dp[0][0];

    }
};
