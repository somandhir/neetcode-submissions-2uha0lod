class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st(wordDict.begin(),wordDict.end());
        map<pair<int,string>,bool>mp;
        auto helper = [&](auto&&self,int idx,string curr){
            if(idx==s.size()){
                if(curr=="")return true;
                return false;
            }
            auto key = make_pair(idx,curr);
            if(mp.count(key))return mp[key];
            curr+=s[idx];
            if(self(self,idx+1,curr))return true;
            if(st.count(curr)){
                if(self(self,idx+1,""))return true;
            }
            return mp[key]=false;
        };
        return helper(helper,0,"");
    }
};
