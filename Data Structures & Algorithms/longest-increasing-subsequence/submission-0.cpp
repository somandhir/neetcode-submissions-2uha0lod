class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>sub;
        for(auto&el:nums){
            auto it = lower_bound(sub.begin(),sub.end(),el);
            if(it==sub.end()){
                sub.push_back(el);
            }else{
                *it=el;
            }
        }
        return sub.size();
    }
};
