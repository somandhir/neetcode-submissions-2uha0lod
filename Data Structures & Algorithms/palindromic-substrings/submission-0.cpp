class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;
        for(int i=0;i<n;i++){
            int curr = 1;
            int i1=i-1,i2=i+1;
            for(;i1>=0 and i2<n;i1--,i2++){
                if(s[i1]==s[i2])curr++;
                else break;
            }
            res+=curr;
            curr = 0;
            i1=i,i2=i+1;
            for(;i1>=0 and i2<n;i1--,i2++){
                if(s[i1]==s[i2])curr++;
                else break;
            }
            res+=curr;
            //cout<<str<<endl;
        }
        return res;
    }
};
