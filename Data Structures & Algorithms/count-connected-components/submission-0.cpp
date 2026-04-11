class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
unordered_map<int,vector<int>>adj;
        for(auto&v:edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<int>vis(n);
        auto helper = [&](auto&&self,int node,int parent)->void{
            vis[node]=true;
            for(auto&el:adj[node]){
                if(el!=parent){
                    if(!vis[el]){self(self,el,node);}
                }
            }
            return ;
        };
        auto cnt = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                helper(helper,i,-1);
            }
        }
        return cnt;
    }
};
