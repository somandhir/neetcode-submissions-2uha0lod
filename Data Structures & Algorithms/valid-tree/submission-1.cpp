class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        for(auto&v:edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<int>vis(n);
        auto helper = [&](auto&&self,int node,int parent)->bool{
            vis[node]=true;
            for(auto&el:adj[node]){
                if(el!=parent){
                    if(!vis[el]){if(!self(self,el,node))return false;}
                    else {cout<<node<<" "<<el<<endl;return false;}
                }
            }
            return true;
        };
        if(! helper(helper,0,-1))return false;
        for(auto&el:vis)if(el==0)return false;
        return true;
    }
};
