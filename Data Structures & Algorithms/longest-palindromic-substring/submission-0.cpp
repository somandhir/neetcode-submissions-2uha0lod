class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int res = 1;
        string str = "";
        str+=s[0];
        for(int i=0;i<n;i++){
            int curr = 1;
            int i1=i-1,i2=i+1;
            for(;i1>=0 and i2<n;i1--,i2++){
                if(s[i1]==s[i2])curr+=2;
                else break;
            }
            if(curr>res){
                res=curr;
                str=s.substr(i1+1,i2-i1-1);
            }
            //cout<<str<<" ";
            curr = 0;
            i1=i,i2=i+1;
            for(;i1>=0 and i2<n;i1--,i2++){
                if(s[i1]==s[i2])curr+=2;
                else break;
            }
            if(curr>res){
                res=curr;
                str=s.substr(i1+1,i2-i1-1);
            }
            //cout<<str<<endl;
        }
        return str;
    }
};
