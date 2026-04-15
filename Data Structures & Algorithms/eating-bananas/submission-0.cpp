class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = *max_element(piles.begin(),piles.end());
        int ans = hi;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            int totalTime = 0;
            int k = mid;
            for(int i=0;i<piles.size();i++){
                int time = (piles[i]+k-1)/k;
                totalTime+=time;
                if(totalTime>h)break;
            }

            if(totalTime<=h){
                ans = mid;
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};
