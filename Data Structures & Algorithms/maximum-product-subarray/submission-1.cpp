class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        
        // .... 0 .... 0 ..... 0 .....   
        int res = 0;
        for(int i=0;i<nums.size();i++){
            int l = i;
            int r = i;
            while(r<nums.size() and nums[r]!=0){
                r++;
            }
            r--;
            if(r<l)continue;
            if(r==l){
                res=max(res,nums[r]);
                i=r+1;continue;
            }
            int neg = 0;
            for(int j=l;j<=r;j++){
                if(nums[j]<0)neg++;
            }
            if(neg&1){
                int res1 = 1;
                int cn = 0;
                for(int j=l;j<=r;j++){
                    if(nums[j]<0){
                        cn++;
                        if(cn==neg)break;
                    }
                    res1*=nums[j];
                }
                res=max(res,res1);
                 res1 = 1;
                 cn = 0;
                for(int j=r;j>=l;j--){
                    if(nums[j]<0){
                        cn++;
                        if(cn==neg)break;
                    }
                    res1*=nums[j];
                }
                res=max(res,res1);
            }else{
                int res1 = 1;
                for(int j=l;j<=r;j++){
                    res1*=nums[j];
                }
                res=max(res,res1);
            }
            i=r+1;
        }
        return res;
        
    }
};
