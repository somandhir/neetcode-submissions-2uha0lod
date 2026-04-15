class TimeMap {
public:
        map<string,vector<pair<int,string>>>mp;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(make_pair(timestamp,value));
    }
    
    string get(string key, int timestamp) {
        if(mp.count(key)){
            auto v = mp[key];
            auto it = lower_bound(v.begin(),v.end(),make_pair(timestamp,""));
            if(it==v.end() or ((*it).first)>timestamp){
                it--;
            }
            if(it==--v.begin())return "";
            return (*it).second;
        }
        return "";
    }
};
