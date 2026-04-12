class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int ts = accumulate(nums.begin(),nums.end(),0);
        if(ts&1)return false;
        int rq = ts>>1;
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(rq+1,false));
        for(int i=0;i<n;i++)dp[i][0]=true;
        for(int i=0;i<nums.size();i++){
            for(int s=1;s<=rq;s++){
                if(i==0){
                    if(s==nums[0])dp[i][s]=true;
                    continue;
                }
                dp[i][s] = dp[i-1][s];
                if(!dp[i][s] and s-nums[i]>=0){
                    dp[i][s] = dp[i-1][s-nums[i]];
                }
            }
        }
        return dp[n-1][rq];
    }
};
