class Solution {
public:
        vector<pair<int,int>>directions = {{1,0},{-1,0},{0,1},{0,-1}};
    int dfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&grid){
        int n = vis.size(),m=vis[0].size();
        vis[i][j]=1;
        int cnt = 1;
        for(auto&dirs:directions){
            int ni = i+dirs.first;
            int nj = j+dirs.second;
            if(ni>=0 and nj>=0 and ni<n and nj<m and !vis[ni][nj] and grid[ni][nj]==1){
                cnt+=dfs(ni,nj,vis,grid);
            }
        }
        //cout<<i<<" "<<j<<endl;
        return cnt;
    };
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int res = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 and !vis[i][j]){
                    res=max(res,dfs(i,j,vis,grid));
                }
            }
        }
        return res;
    }

};

